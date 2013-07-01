/*
 * target.cpp
 *
 *  Created on: 01/07/2013
 *      Author: monfee
 */

#include "target.h"

namespace QLINK {

target::target() {
}

target::target(std::string lang, std::string a_target) : lang_(lang), target_(a_target) {
}

target::~target() {
}

} /* namespace QLINK */
