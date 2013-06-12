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
 * run.cpp
 *
 *  Created on: Aug 3, 2009
 *      Author: monfee
 */

#include "run.h"
#include "corpus.h"
#include "sys_file.h"

using namespace QLINK;

run::run() {

}

run::run(char *configfile) : config_file_(configfile)/*: run_conf_(configfile)*/
{
	load_config(configfile);
}

run::~run()
{

}

void run::load_config(const char *config_file)
{
	run_conf_ = static_cast<run_config *>(&run_config::instance());
	set_config_file(config_file);
	load_config();
}

void run::load_config()
{
	affiliation = get_config().get_value("affiliation");
	run_name = get_config().get_value("name");
	task = get_config().get_value("task");
	id = get_config().get_value("id");

	header = get_config().get_value("header");
	footer = get_config().get_value("footer");

	// set the corpus home
	std::string home = get_config().get_value("CORPUS_HOME");
	if (home.length() > 0) {
//		home = ".";
		home.append(sys_file::SEPARATOR);
		corpus::instance().home(home);
		corpus::instance().exists(true);
	}
	else {
		cerr << "No CORPUS HOME is given!" << endl;
		corpus::instance().exists(false);
	}
}

void run::print_header()
{
	//printf(header.c_str());
//	(*aout_) << header;
	aout_->printbuf(header.c_str());
}

/*
	PRINT_FOOTER()
	--------------
*/
void run::print_footer()
{
	//puts(footer.c_str());
//	(*aout_) << footer;
	aout_->printbuf(footer.c_str());
}

void run::set_config_file(const char* config_file) {
	config_file_ = config_file;

	run_conf_->load(config_file_);
	run_conf_->show();
}
