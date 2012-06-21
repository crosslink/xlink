/*
 * proxy.cpp
 *
 *  Created on: Oct 5, 2009
 *      Author: monfee
 */

#include "ltw_task.h"
#include "algorithm_bep.h"
#include "link_print.h"

#ifdef WITH_JNI

#include <gcj/cni.h>
#include <java/lang/Throwable.h>
#include <java/lang/String.h>

extern "C" void initJava() {
        try {
                if (JvCreateJavaVM(NULL) < 0) {
                        fputs("Error creating the JVM!\n", stderr);
                        return;
                }
                JvAttachCurrentThread(NULL, NULL);
                fputs("Java initialized...\n", stderr);
        } catch (java::lang::Throwable *t) {
        	fputs("Unhandled Java exception!\n", stderr);
        }
        return;
}

#endif

using namespace QLINK;

ltw_task::ltw_algorithm_map ltw_task::alorithm_names;
ltw_task::ltw_task_type_map ltw_task::task_names;

algorithm_bep::bep_algorithm_map algorithm_bep::alorithm_names;

class proxy {
public:
   proxy(){
	   ltw_task::alorithm_names[""] = ltw_task::LTW_NONE;
	   ltw_task::alorithm_names["LTW_ANT"] = ltw_task::LTW_ANT;
	   ltw_task::alorithm_names["LTW_PAGE_NAME"] = ltw_task::LTW_PAGE_NAME;
	   ltw_task::alorithm_names["LTW_ANT_AND_PAGE"] = ltw_task::LTW_ANT_AND_PAGE;
	   ltw_task::alorithm_names["LTW_TEARA_BASE"] = ltw_task::LTW_TEARA_BASE;
	   ltw_task::alorithm_names["LTW_TANG"] = ltw_task::LTW_TANG;
	   ltw_task::alorithm_names["LTW_INCOMING_SEARCH_TN"] = ltw_task::LTW_INCOMING_SEARCH_TN;
	   ltw_task::alorithm_names["LTW_A2B_INCOMING_SEARCH_TN"] = ltw_task::LTW_A2B_INCOMING_SEARCH_TN;
	   ltw_task::alorithm_names["LTW_ANT_CROSSLINK"] = ltw_task::LTW_ANT_CROSSLINK;

	   ltw_task::task_names[""] = ltw_task::LTW_TASK_NONE;
	   ltw_task::task_names["LTW_F2F"] = ltw_task::LTW_LTW_F2F;
	   ltw_task::task_names["LTW_A2B"] = ltw_task::LTW_LTW_A2B;
	   ltw_task::task_names["F2F"] = ltw_task::LTW_LTW_F2F;
	   ltw_task::task_names["A2F"] = ltw_task::LTW_LTW_A2B;
	   ltw_task::task_names["A2B"] = ltw_task::LTW_LTW_A2B;
	   ltw_task::task_names["LTAra_A2B"] = ltw_task::LTW_LTAra_A2B;
	   ltw_task::task_names["LTAraTW_A2B"] = ltw_task::LTW_LTAraTW_A2B;

	   algorithm_bep::alorithm_names[""] = algorithm_bep::BEP_MATCH;
	   algorithm_bep::alorithm_names["BEP_MATCH"] = algorithm_bep::BEP_MATCH;
	   algorithm_bep::alorithm_names["BEP_GRAPH"] = algorithm_bep::BEP_GRAPH;

//	   initJava();
   }
};
// our one instance of the proxy
proxy p;
