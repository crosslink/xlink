/*
 * ltw.cpp
 *
 *  Created on: Aug 3, 2009
 *      Author: monfee
 */

#include <iostream>

#include "ltw_run.h"
#include "cmdline_options.h"
#include "application_out.h"
#include "algorithm_out.h"
#include "database_mysql.h"

#include <string.h>

#include <signal.h>

#define DEFAULT_PORT 8888

using namespace QLINK;
using namespace std;


enum {RECOMMEND_ANCHOR, CREATE_RUN};

ltw_run *run_ptr = NULL;

void clean_up() {
	if (run_ptr != NULL)
		delete run_ptr;
}

void catch_signal(int sig) {
	cerr << "signal: " << sig << " received!" << endl;
	if (run_ptr != NULL)
		run_ptr->stop_daemon();
//	clean_up();
}

void create_run(int argc, char **argv)
{
	char *config_file = NULL;

	int index_argv_param = 1;
	int next_argv_param = 0;
	int cmd = CREATE_RUN;
	for (; index_argv_param < argc; index_argv_param++) {
		char *what = argv[index_argv_param];
		if (strncmp(what, "-conf", 5) == 0) {
			next_argv_param = index_argv_param + 1;
			if (*argv[next_argv_param] != '-')
				config_file = argv[++index_argv_param];
		} else if (strncmp(what, "-index", 6) == 0) {
			++index_argv_param;
		}else if (*what == '-') {
//			if (!strchr(what, ':'))
//				index_argv_param++;
		} else
			break;
	}
	ltw_task::topic_param_start = index_argv_param;

	database_mysql::instance().connect();

//	ltw_run *run = NULL;
	if (config_file == NULL)
		config_file = "ltw.conf";

	ltw_run ltw_run_instance(config_file);

	run_ptr = &ltw_run_instance;

//	ltw_run::set_instance_ptr(ltw_run_instance);

	if (run_ptr->get_config().get_value("run_mode") == "web") {
		int port = DEFAULT_PORT;
//		  if (NULL == daemon) return 1;

		signal(SIGABRT, &catch_signal);
		signal(SIGTERM, &catch_signal);
		signal(SIGINT, &catch_signal);

		run_ptr->create_daemon(port);
	}
	else {
		run_ptr->create();
		switch (cmd) {
			case RECOMMEND_ANCHOR:
			{
				application_out anchor_out;
				run_ptr->get_task()->get_algor_out()->list_anchors(anchor_out);
				//run_ptr->get_task()->get_algor_out()->recommend_anchors()
				break;
			}
			case CREATE_RUN:
			default:
				aout.flush();
				break;
		}
	}
//	clean_up();
}

int main(int argc, char **argv)
{
//    if ( argc == 1 ) {
//        std::cout
//            << "Usage: "
//            << argv[ 0 ]
//            << " run_config_file"
//            << std::endl
//            ;
//        return 1;
//    }
    cmdline_options::argc = argc;
    cmdline_options::argv = argv;

	create_run(argc, argv);
	return 0;
}
