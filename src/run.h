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
 * run.h
 *
 *  Created on: Aug 3, 2009
 *      Author: monfee
 */

#ifndef RUN_H_
#define RUN_H_

#include "system_info.h"
#include "run_config.h"
#include "application_out.h"

#include <string>

namespace QLINK {

	/*
	 *
	 */
	class run {
	private:
		run_config				*run_conf_;
		const char				*config_file_;

	protected:
		application_out			*aout_;

	public:
		std::string					affiliation;
		std::string					id;
		std::string					run_id;
		std::string					run_name;
		std::string					task;
		std::string					header;
		std::string					footer;
		system_info				system_information;

	private:

	protected:
		virtual void print_header();
		virtual void print_footer();
		//virtual void print() = 0;

	public:
		run();
		run(char *configfile);
		virtual ~run();

		virtual void create() = 0;
		virtual void print() = 0;

		virtual void load_config(const char *config_file);
		virtual void load_config();

		void set_config_file(const char *config_file);
		const run_config& get_config() const { return *run_conf_; }
		run_config& get_config() { return *run_conf_; }
	};

}

#endif /* RUN_H_ */
