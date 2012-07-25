/*
 * run.cpp
 *
 *  Created on: Aug 3, 2009
 *      Author: monfee
 */

#include "run.h"
#include "corpus.h"
#include "sys_file.h"
#include "application_out.h"

using namespace QLINK;

run::run(char *configfile) /*: run_conf_(configfile)*/
{
	run_conf_ = static_cast<run_config *>(&run_config::instance());
	run_conf_->load(configfile);
	run_conf_->show();
	init();
}

run::~run()
{

}

void run::init()
{
	affiliation = get_config().get_value("affiliation");
	run_name = get_config().get_value("name");
	task = get_config().get_value("task");
	id = get_config().get_value("id");

	run_id = affiliation + "_" + task + "_" + run_name + "_" + id;

	header = get_config().get_value("header");
	footer = get_config().get_value("footer");

	// set the corpus home
	std::string home = get_config().get_value("CORPUS_HOME");
	if (home.length() > 0) {
//		home = ".";
		home.append(sys_file::SEPARATOR);
		corpus::instance().home(home);
	}
	else
		cerr << "No CORPUS HOME is given!" << endl;
}

void run::print_header()
{
	//printf(header.c_str());
	aout << header;
}

/*
	PRINT_FOOTER()
	--------------
*/
void run::print_footer()
{
	//puts(footer.c_str());
	aout << footer;
}
