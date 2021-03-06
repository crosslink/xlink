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
 * ltw_task.cpp
 *
 *  Created on: Aug 16, 2009
 *
 */

#include "ltw_task.h"
#include "algorithm_ant_link_this.h"
#include "algorithm_ant_crosslink_this.h"
#include "algorithm_ant_link_this_and_page_name.h"
#include "algorithm_ant_link_this_and_page_name2.h"
#include "algorithm_ltw_tang.h"
#include "algorithm_page_name.h"
#include "algorithm_bep.h"
#include "algorithm_ltw_incoming_search_tn.h"
#include "algorithm_ltw_incoming_a2b_search_tn.h"
#include "algorithm_ltara_base.h"
#include "sys_files.h"
#include "cmdline_options.h"
#include "ltw_topic.h"
#include "incoming_links.h"
#include "outgoing_links.h"
#include "corpus.h"
#include "corpus_txt.h"

#include <iostream>

using namespace std;
using namespace QLINK;

int ltw_task::topic_param_start = 1;

ltw_task::ltw_task(config& config_ref, std::string& name, std::string& out_algor_name, std::string& in_algor_name)
	: system_config_(&config_ref), name_(name), algor_out_name_(out_algor_name), algor_in_name_(in_algor_name)
{
	outgoings_ = NULL;
	incomings_ = NULL;

	algor_out_ = NULL;
	algor_in_ = NULL;
	algor_bep_ = NULL;

	init();
}

ltw_task::~ltw_task()
{
	if (outgoings_)
		delete outgoings_;
	if (incomings_)
		delete incomings_;

	if (algor_out_)
		delete algor_out_;

	if (algor_in_)
		delete algor_in_;

	if (algor_bep_)
		delete algor_bep_;
}

void ltw_task::init()
{
	//topic_param_start_ = 1;
	type(IR_TASK_LTW);

//	incomings_ = new links();
//	outgoings_ = new links();

	set_alorithm_bep(system_config_->get_value("algorithm_bep"));

	/*TODO
	 * no time to fix it, it can be done in the algorithm class
	 */
//	string links_to_print_str = system_config_->get_value("anchors_number");
//	if (links_to_print_str.length() > 0)
//		set_links_to_print(atol(links_to_print_str.c_str()));
//
//	string beps_to_print_str = system_config_->get_value("anchor_links_number");
//	if (beps_to_print_str.length() > 0)
//		set_beps_to_print(atol(beps_to_print_str.c_str()));

	string source_lang = system_config_->get_value("source_lang");
	set_source_lang(source_lang.length() > 0 ? source_lang : "en");
	if (source_lang == "zh" || source_lang == "ko" || source_lang == "ja")
		is_cjk_lang(true);
	else
		is_cjk_lang(false);

//	lang = system_config_->get_value("target_lang");
	string target_lang = system_config_->get_value("target_lang");
	set_target_lang(target_lang.length() > 0 ? target_lang : get_source_lang());

	need_crosslink_ = source_lang != target_lang;

	switch (get_algorithm_outgoing_type()) {
	case LTW_ANT:
		algor_out_ = new algorithm_ant_link_this(this);
		//topic_param_start = algor_out_->init();
		break;
	case LTW_ANT_CROSSLINK:
		algor_out_ = new algorithm_ant_crosslink_this(this);
		break;
	case LTW_PAGE_NAME:
		algor_out_ = new algorithm_page_name(this);
		break;
	case LTW_ANT_AND_PAGE:
		algor_out_ = new algorithm_ant_link_this_and_page_name(this);
		break;
	case LTW_ANT_AND_PAGE2:
		algor_out_ = new algorithm_ant_link_this_and_page_name2(this);
		break;
	case LTW_TANG:
		//algor_out_ = new algorithm_ltw_tang();
		break;
	case LTW_TEARA_BASE:
		algor_out_ = new algorithm_ltara_base(this);
		break;
	case LTW_NONE:
	default:
		cerr << "No algorithm for generating outgoing links specified" << endl;
		break;
	}

	if (algor_out_) {
		this->topic_param_start = algor_out_->init_params();
	}

	switch (get_algorithm_incoming_type()) {
	case LTW_A2B_INCOMING_SEARCH_TN:
		algor_in_ = new algorithm_ltw_incoming_a2b_search_tn(this);
		break;
	case LTW_INCOMING_SEARCH_TN:
		algor_in_ = new algorithm_ltw_incoming_search_tn(this);
		break;
	case LTW_TANG:
		algor_in_ = new algorithm(this);
		break;
	case LTW_NONE:
	default:
		cerr << "No algorithm for gernerating incoming links specified" << endl;
		break;
	}
}

void ltw_task::set_alorithm_bep(string name)
{
	if (name.length() > 0)
		algor_bep_ = new algorithm_bep(name);
}



void ltw_task::perform(application_out& aout)
{
	int count = 0;
	long param = topic_param_start;
	for (; param < cmdline_options::argc; param++) {
		sys_files disk;
		disk.pattern("*.[xX][mM][lL]");
		char *filename = cmdline_options::argv[param];
		disk.list(filename);
		if (disk.isdir(filename)) {
			corpus::instance().base(filename);
			corpus_txt::instance().base(filename);
		}
		const char *name = NULL;

		for (name = disk.first(); name != NULL ; name = disk.next())
		{
			count++;
			//cerr << "Processing #" << count << ": " << name << endl;
			//char *file = disk.read_entire_file(name);
			const char *content = sys_file::read_entire_file(name);
			wikify(content, aout);

			delete [] content;
		}
	}
//	outgoings_->create();
//	incomings_->create();
}

void ltw_task::print_links()
{
	//if (algor_out_name_ != "LTW_ANT")
//		outgoings_->print();
//
//	incomings_->print();
}

void QLINK::ltw_task::wikify(const char * topic_text, application_out& aout) {
	ltw_topic a_topic(topic_text);
	a_topic.xml_to_text();
	a_topic.set_ltw_task(this);
	a_topic.print_header(aout);

	if (algor_out_) {
		if (outgoings_) {
			delete outgoings_;
			outgoings_ = NULL;
		}
		outgoings_ = new outgoing_links(&a_topic, need_crosslink_);
		outgoings_->set_application_out(aout);
		outgoings_->set_bep_algorithm(algor_bep_);
		outgoings_->set_algorithm(algor_out_);

//				if (links_to_print_ > 0)
//					outgoings_->set_links_to_print(links_to_print_);
//				if (beps_to_print_ > 0)
//					outgoings_->set_beps_to_print(beps_to_print_);

		algor_out_->set_links_container(outgoings_);
		algor_out_->set_stage(algorithm::FIND_ANCHOR);

		algor_out_->process_topic(&a_topic);
	//if (algor_out_name_ != "LTW_ANT")
		//if (is_a2b_task())

			outgoings_->find_anchor();

		// output
		algor_out_->set_stage(algorithm::PRINT_LINK);
		outgoings_->print();
	}
	if (algor_in_) {
		if (incomings_) {
			delete incomings_;
			incomings_ = NULL;
		}
		incomings_ = new incoming_links(&a_topic);
//				if (links_to_print_ > 0)
//					incomings_->set_links_to_print(links_to_print_);
//				if (beps_to_print_ > 0)
//					incomings_->set_beps_to_print(beps_to_print_);

		incomings_->set_bep_algorithm(algor_bep_);
		algor_in_->set_links_container(incomings_);
		algor_in_->process_topic(&a_topic);
		//if (is_a2b_task())
			incomings_->find_anchor();

		// output
		incomings_->print();
	}
	a_topic.print_footer(aout);
}
