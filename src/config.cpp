/*
 * config.cpp
 *
 *  Created on: Aug 4, 2009
 *      Author: monfee
 */

#include "config.h"
#include "sys_file.h"

#include <stpl/stpl_property.h>
#include <stpl/stpl_parser.h>
#include <iostream>

using namespace std;
using namespace stpl;
using namespace QLINK;


config::config(const char *name) {
	name_ = name;
	load();
}

config::~config() {
	name_.clear();
}

void config::load(const char *name)
{
	name_ = name;
	load();
}

void config::load()
{
	// create a STPL parser for reading the property file
	if (sys_file::exist(name_.c_str())) {
		properties_.read(name_);
		PropertiesFileParser property_parser(&properties_);

		property_parser.parse();
	}
	else {
		cerr << "WARNING:" << endl;
		cerr << name_ << " doesn't exist." << endl;
	}
}

void config::show()
{
#ifdef DEBUG
	cerr << "------------------------- PROGRAM SETTINGS ------------------------------------" << endl;
	PropertiesFile::entity_iterator it = properties_.iter_begin();
	for (; it != properties_.iter_end(); it++)
		cerr << (*it)->name() << ":" << (*it)->value() << endl;
	cerr << "-------------------------------------------------------------------------------" << endl;
#endif
}

config::string_type	config::get_value(string_type name)
{
	stpl::PropertiesFile::entity_iterator it = properties_.find(name);
	return it != properties_.iter_end() ? (*it)->value() : "";
}
