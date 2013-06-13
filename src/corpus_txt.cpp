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
 * corpus_txt.cpp
 *
 *  Created on: Sep 21, 2009
 *
 */

#include "corpus_txt.h"
#include "system_call.h"

#include <string>
#include <sstream>
#include <iostream>

using namespace QLINK;
using namespace std;

corpus_txt::corpus_txt()
{

}

corpus_txt::~corpus_txt()
{

}

//string corpus_txt::id2docpath(unsigned long id)
//{
//	if (load_)
//		return home_ + id2doc(id) + ".txt";
//
//
//	if (id == 22)
//		cout << "I caught you" << endl;
//	std::ostringstream stm;
//	stm << id;
//	string cmd("/home/monfee/workspace/qlink/src/scripts/doc2txtpath.sh ");
//	cmd.append(stm.str());
//
//	return system_call::instance().execute(cmd.c_str());
//}
