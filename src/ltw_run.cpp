/*
 * ltw_run.cpp
 *
 *  Created on: Aug 3, 2009
 *      Author: monfee
 */

#include "ltw_run.h"
#include "corpus_txt.h"
#include "corpus.h"
#include "sys_file.h"
#include "application_out.h"
#include "google_research_translator.h"

#include <string>
#include <ctime>
#include <assert.h>

#include <sys/types.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <microhttpd.h>

using namespace std;

QLINK::ltw_run::ltw_run(char *configfile) : run(configfile)
{
	task_ = NULL;
//	init();
}

QLINK::ltw_run::~ltw_run()
{
	if (task_) {
		delete task_;
		task_ = NULL;
	}

	stop_daemon();
}

void QLINK::ltw_run::init()
{
	// set the corpus txt home
	if (get_config().get_value("TEARA_HOME").length() > 0) {
		corpus::instance().teara_home(get_home("TEARA_HOME"));
		corpus::instance().load_teara_map();
	}

	corpus_txt::instance().home(get_home("CORPUS_TXT"));
	if (get_config().get_value("TEARA_TXT").length() > 0) {
		corpus_txt::instance().teara_home(get_home("TEARA_TXT"));
		corpus_txt::instance().load_teara_map();
	}

	string taskname = get_config().get_value("task");
	string out_algor_name = get_config().get_algorithm_outgoing_name();
	string in_algor_name = get_config().get_algorithm_incoming_name();
	string::size_type pos = string::npos;

//	if ((pos = taskname.find("F2F")) != string::npos)
//		task_ = new task_f2f(taskname, out_algor_name, in_algor_name);
//	else if ((pos = taskname.find("A2B")) != string::npos)
//		task_ = new task_a2b(taskname, out_algor_name, in_algor_name);
//	else
//		throw std::runtime_error("No recognizable task given.");
	task_ = new ltw_task(get_config(), taskname, out_algor_name, in_algor_name);

	string source_lang = task_->get_source_lang();
	string target_lang = task_->get_target_lang();

//	string target_lang = get_config().get_value("target_lang");
	corpus::instance().lang(target_lang.length() > 0 ? target_lang : "en");
	assert(corpus::instance().lang().length() <= 4);

	string lang_pair = string(source_lang) + ":" + string(target_lang);
	google_research_translator::instance().set_lang_pair(lang_pair.c_str());

	string s_code;
	string t_code;

	if (source_lang == "zh")
	  s_code="C";
	else if (source_lang == "en")
	  s_code="E";
	else if (source_lang == "ja")
	  s_code="J";
	else if (source_lang == "ko")
	  s_code="K";
	else
		s_code = toupper(source_lang[0]);


	if (target_lang == "zh")
	  t_code="C";
	else if (target_lang == "en")
	  t_code="E";
	else if (target_lang == "ja")
	  t_code="J";
	else if (target_lang == "ko")
	  t_code="K";
	else
		t_code = toupper(target_lang[0]);

	run_id = affiliation + "_" + s_code + "2" + t_code + "_" + task + "_" + id + "_" + run_name;
}

std::string QLINK::ltw_run::get_home(const char *name)
{
	string home = get_config().get_value(name);
	if (home.length() == 0)
		home = ".";
	home.append(sys_file::SEPARATOR);
	return home;
}

void QLINK::ltw_run::create()
{
	print_header();

	if (task_) {
		task_->perform();
	}

	print_footer();
}

void QLINK::ltw_run::print()
{
	print_header();

	if (task_) {
		task_->print_links();
	}

	print_footer();
}

void QLINK::ltw_run::print_header()
{
	char *local_buf = new char[1024 * 1024]; // = {""};
	sprintf(local_buf, header.c_str(), affiliation.c_str(), run_id.c_str(), task.c_str(), task_->get_target_lang().c_str(), task_->get_source_lang().c_str());
	aout << local_buf;
	delete [] local_buf;
}

void QLINK::ltw_run::create_daemon(int port) {
//	struct MHD_Daemon *daemon;

	daemon_ = MHD_start_daemon (MHD_USE_SELECT_INTERNALLY,  port, NULL, NULL,
	                             &ltw_run::response, NULL, MHD_OPTION_END);

	if (daemon_ == NULL)
		cerr << "Failed to create xlink daemon!";
	else {
		cerr << "Xlink daemon created";
		while (1)
			usleep(1000000);
	}
}

void QLINK::ltw_run::stop_daemon() {
	if (daemon_ != NULL) {
		getchar ();
		MHD_stop_daemon(daemon_);
		daemon_ = NULL;
	}
}

void QLINK::ltw_run::initialise() {
	if (task_ == NULL)
		init();
}

int QLINK::ltw_run::response(void* cls, struct MHD_Connection* connection,
		const char* url, const char* method, const char* version,
		const char* upload_data, size_t* upload_data_size, void** con_cls) {
	time_t t = time(0);   // get time now
	struct tm * now = localtime( & t );
	std::stringstream datetime;
	datetime << (now->tm_year + 1900) << '-'
	         << (now->tm_mon + 1) << '-'
	         <<  now->tm_mday
	         << " "
	         << now->tm_hour << ':'  << now->tm_min << ':' << now->tm_sec;

	stringstream page_buf;
//	page_buf << "Content-Type: text/html" << endl;
	page_buf  << "<html><body>" << datetime.str() << "</body></html>";

	struct MHD_Response *response;
	int ret;

	string page = page_buf.str();

//	response = MHD_create_response_from_buffer (page.length(),
//	                                            (void*) (page.c_str()),  MHD_RESPMEM_PERSISTENT);
	response = MHD_create_response_from_data (page.length(),
	                                            (void*) (page.c_str()),  MHD_NO, MHD_YES);

	MHD_add_response_header (response, "Content-Type", "text/html");
	ret = MHD_queue_response (connection, MHD_HTTP_OK, response);
	MHD_destroy_response (response);
	 return ret;
}
