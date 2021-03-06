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
 * anchor.cpp
 *
 *  Created on: 13/06/2013
 *
 */

#include "anchor.h"

namespace QLINK {

anchor::anchor() {

}

anchor::anchor(std::string &name, long offset) : name_(name), offset_(offset) {
}

anchor::~anchor() {
}

} /* namespace QLINK */
