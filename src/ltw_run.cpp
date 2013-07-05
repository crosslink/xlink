/******************************************************************************
 * This file is part of the XLINK - The Link Discovery Toolkit.
 * (c) Copyright 2013 Queensland University of Technology
 *
 * This file may be distributed and/or modified under the terms of the
 * BSD 3-cause LICENSE appearing in the file BSD.txt included in the
 * packaging of this file.
 *
 * This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 * WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 *******************************************************************************
 *
 * @author				Eric Tang
 *
 *******************************************************************************/
 /*
 * ltw_run.cpp
 *
 *  Created on: Aug 3, 2009
 *
 */

#include "ltw_run.h"
#include "corpus_txt.h"
#include "corpus.h"
#include "sys_file.h"
#include "application_out.h"
#include "google_research_translator.h"
#include "webpage_retriever.h"
#include "urlcode.h"
#include "wikipedia.h"
#include "mime.h"

#include <string>
#include <ctime>
#include <assert.h>

#include <sys/types.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <microhttpd.h>

#include <sys/stat.h>
#include <fcntl.h>


using namespace std;

QLINK::ltw_run* QLINK::ltw_run::instance_ptr_ = NULL;

QLINK::ltw_run::ltw_run()
{
	task_ = NULL;
}

QLINK::ltw_run::ltw_run(char *configfile)
{
	task_ = NULL;
	load_config(configfile);
}

QLINK::ltw_run::~ltw_run()
{
	if (task_) {
		delete task_;
		task_ = NULL;
	}

	if (aout_) {
		delete aout_;
		aout_ = NULL;
	}

	request_type::const_iterator it  = requests_.begin();
	while (it != requests_.end()) {
		delete it->second;
		++it;
	}
	stop_daemon();
}

void QLINK::ltw_run::init() {

}

void QLINK::ltw_run::load_config(const char *configfile)
{
	run::load_config(configfile);

	load_config();
}

void QLINK::ltw_run::setup_output(ostream* out) {
	aout_ = new application_out(out);
}

void QLINK::ltw_run::load_config()
{
	// set the corpus txt home
	run::load_config();

	if (get_config().get_value("TEARA_HOME").length() > 0) {
		corpus::instance().teara_home(get_home("TEARA_HOME"));
		corpus::instance().load_teara_map();
	}

	corpus_txt::instance().home(get_home("CORPUS_TXT"));
	if (get_config().get_value("TEARA_TXT").length() > 0) {
		corpus_txt::instance().teara_home(get_home("TEARA_TXT"));
		corpus_txt::instance().load_teara_map();
	}

	if (get_config().get_value("load_on_startup") == "true")
		this->global_initialise();

//	if ((pos = taskname.find("F2F")) != string::npos)
//		task_ = new task_f2f(taskname, out_algor_name, in_algor_name);
//	else if ((pos = taskname.find("A2B")) != string::npos)
//		task_ = new task_a2b(taskname, out_algor_name, in_algor_name);
//	else
//		throw std::runtime_error("No recognizable task given.");
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
		task_->perform(*aout_);
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
	aout_->printbuf(local_buf);
	delete [] local_buf;
}

void QLINK::ltw_run::create_daemon(int port) {
//	struct MHD_Daemon *daemon;

	if (instance_ptr_  != NULL) {
		daemon_ = MHD_start_daemon (MHD_USE_SELECT_INTERNALLY,  port, NULL, NULL,
									 &ltw_run::response_request, NULL, MHD_OPTION_END);

		if (daemon_ == NULL)
			cerr << "Failed to create xlink daemon!" << endl;
		else {
			cerr << "Xlink daemon created" << endl;
			 (void) getc (stdin);
//			while (1)
//				usleep(1000000);
		}
	}
	else
		cerr << "LTW Run wasn't created properly" << endl;
}

void QLINK::ltw_run::stop_daemon() {
	if (daemon_ != NULL) {
		getchar ();
		MHD_stop_daemon(daemon_);
		daemon_ = NULL;
	}
}

void QLINK::ltw_run::global_initialise() {
	if (task_ == NULL) {
		string taskname = get_config().get_value("task");
		string out_algor_name = get_config().get_algorithm_outgoing_name();
		string in_algor_name = get_config().get_algorithm_incoming_name();
		string::size_type pos = string::npos;
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
}

const char *QLINK::ltw_run::check_request(const char *page_url) {
	 webpage_retriever page_fetcher;
	 char *decoded_url = url_decode(page_url);
	 const char *external_page = NULL;

	 request_type& requests = instance_ptr_->get_requests();
	 request_type::const_iterator it = requests.find(page_url) ;
	 request_type::const_iterator end = requests.end();
	 request* rsq_ptr;
	 if (it != end) {
		 rsq_ptr = const_cast<request *>(it->second);
	 }
	 else
	 {
		 external_page = page_fetcher.retrieve(decoded_url);
		 rsq_ptr = new request(page_url, external_page);
//		 rsq.set_page(external_page);
//		 pair<string, *request> rsq_p = make_pair(string(page_url), rsq);
//		 requests.insert(rsq_p);
		 requests_.insert(std::pair<string, request *>(page_url, rsq_ptr));

		 aout_->reset();
		 task_->wikify(external_page, *aout_);

		 string links_xml = aout_->to_string();
		 rsq_ptr->apply_links(links_xml);

//				 requests [page_url] = rsq;
	 }

	 const string &wikified_page = rsq_ptr->get_wikified_page();
//	 cerr << "Wikified page:" << endl;
//	 cerr << wikified_page << endl;

	 return wikified_page.c_str();
}

int QLINK::ltw_run::parse_request_arguments(void* cls, enum MHD_ValueKind kind,
		const char* key, const char* value) {
	  fprintf (stderr, "%s: %s\n", key, value);
	  return MHD_YES;
}

int QLINK::ltw_run::response_request(void* cls, struct MHD_Connection* connection,
		const char* url, const char* method, const char* version,
		const char* upload_data, size_t* upload_data_size, void** con_cls) {

	 cerr << "Attempt to answer the connection" << endl;
	 
	/*
	 *  load necessary tables into memory and do some preparation work
	 */
	instance_ptr_ ->global_initialise();

	// get the arguments passed from the GET, POST methods
	// MHD_GET_ARGUMENT_KIND
	// MHD_HEADER_KIND
//	  MHD_get_connection_values (connection, MHD_GET_ARGUMENT_KIND, parse_request_arguments,
//	                             NULL);
	// or if we know what we are looking for
	 int operation = OPERATION_NONE;
	 stringstream page_buf;

	 const char *external_page = NULL;
	 char *result = NULL;
	 int fd;
	 
	 if (strlen(url) == 1 && *url == '/') {
		 const char *page_url = NULL;
		 page_url = (char *)MHD_lookup_connection_value(connection, MHD_GET_ARGUMENT_KIND, "page");
		 operation = OPERATION_WIKIFY;
		 if (page_url != NULL)
			 page_buf << instance_ptr_->check_request(page_url);
		 /*
		  * TODO
		  * else then response with some error information
		  */
	 }
	 else if (strlen(url) == 4 && strcmp(url, "/get") == 0) {
		 const char *what = (char *)MHD_lookup_connection_value(connection, MHD_GET_ARGUMENT_KIND, "pageid");
		 const char *lang = (char *)MHD_lookup_connection_value(connection, MHD_GET_ARGUMENT_KIND, "lang");

		 if (what && lang) {
			 page_buf << wikipedia::get_article_abstract_by_id(lang, what);
		 }
		 else
			 create_info_page("pageid or lang is not specified!", page_buf);
		 operation = OPERATION_WIKIAPI_ACCESS;
	 }
	 else if ((fd = look_for_static_file(url + 1)) > -1) {
		 operation = OPERATION_STATIC_FILE;
		 return response_with_result(connection, (void *)&fd, operation, mime::get_mime_type(url));
	 }
	 else {
		 create_info_page(string("url: ") + url, page_buf);
	 }

		result = strdup(page_buf.str().c_str());
//	 }

//	struct MHD_Response *response =  MHD_create_response_from_buffer (strlen(result),
//            (void*) result,  MHD_RESPMEM_PERSISTENT);

//	response = MHD_create_response_from_buffer (strlen(result),
//	                                            (void*) result,  MHD_RESPMEM_PERSISTENT);
		return response_with_result(connection, result, operation, "text/html");
}

int QLINK::ltw_run::response_with_result(struct MHD_Connection* connection, void *result, int operation, const char *mime_type) {
	struct MHD_Response *response  = NULL;
	int fd = -1;
	switch (operation) {
	case OPERATION_STATIC_FILE:
		fd = *((int *)result);
		struct stat sbuf;
		if (0 == fstat (fd, &sbuf)) {
			response =
			    MHD_create_response_from_fd (sbuf.st_size, fd);
			MHD_add_response_header (response, "Content-Type", mime_type);
		}
		result = NULL;
		break;
	default:
		response = MHD_create_response_from_data (strlen((char *)result),
				(char *)result,  MHD_NO, MHD_YES);

		MHD_add_response_header (response, "Content-Type", mime_type);
		break;
	}

	int ret;
    if (response == NULL)
    	ret =MHD_NO;
    else {
		ret = MHD_queue_response (connection, MHD_HTTP_OK, response);
		MHD_destroy_response (response);
    }

//	if (operation == OPERATION_STATIC_FILE && fd > 0)
//		close(fd);
    if (result != NULL)
		free(result);
	return ret;
}

void QLINK::ltw_run::create_info_page(std::string info, std::ostream& out) {
	time_t t = ::time(0);   // get time now
	struct tm * now = localtime( & t );
	std::stringstream datetime;
	datetime << (now->tm_year + 1900) << '-'
			 << (now->tm_mon + 1) << '-'
			 <<  now->tm_mday
			 << " "
			 << now->tm_hour << ':'  << now->tm_min << ':' << now->tm_sec;


//	page_buf << "Content-Type: text/html" << endl;
	out << "<html><body>";
	out<< datetime.str() <<endl;
	out<< "<br>";
	out<< info << endl;
	out<< "</body></html>";
}

int QLINK::ltw_run::look_for_static_file(const char *file) {
	if (sys_file::exist(file))
		return open(file, O_RDONLY);
	return -1;
}
