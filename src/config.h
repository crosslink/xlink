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
 * config.h
 *
 *  Created on: Aug 4, 2009
 *
 */

#ifndef CONFIG_H_
#define CONFIG_H_

#include <spec/property.h>

#include "pattern_singleton.h"

namespace QLINK {
	/*
	 *
	 */
	class config : public pattern_singleton<config> {
	public:
		typedef stpl::PropertiesFile::string_type	string_type;

	protected:
		stpl::PropertiesFile	properties_;
		std::string				name_; // the full path name of the config file

	public:
		config() {};
		config(const char *name);
		virtual ~config();

		void load();
		void load(const char *name);
		void show();
		string_type	get_value(string_type name);
	};

}
#endif /* CONFIG_H_ */
