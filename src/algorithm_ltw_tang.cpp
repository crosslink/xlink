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
 * algorithm_ltw_tang.cpp
 *
 *  Created on: Aug 13, 2009
 *
 */

#include "algorithm_ltw_tang.h"
#include <iostream>

using namespace std;
using namespace QLINK;


algorithm_ltw_tang::algorithm_ltw_tang(ltw_task *task) : algorithm_out(task)
{

}

algorithm_ltw_tang::~algorithm_ltw_tang()
{
}

int algorithm_ltw_tang::init()
{
	cerr << "creating run using LTW_TANG algorithm..." << endl;
}
