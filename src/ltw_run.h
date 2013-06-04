/*
 * ltw_run.h
 *
 *  Created on: Aug 3, 2009
 *      Author: monfee
 */

#ifndef LTW_RUN_H_
#define LTW_RUN_H_

#include "run.h"
#include "ltw_task.h"

//struct MHD_Connection;
//struct MHD_Daemon;

#include <microhttpd.h>

namespace QLINK {

	/*
	 * Link-the-Wiki run
	 */
	class ltw_run : public run, public pattern_singleton<ltw_run> {
	private:
		ltw_task						*task_;
		struct MHD_Daemon	*daemon_;

	public:
		ltw_run();
		ltw_run(char *configfile);
		virtual ~ltw_run();

		void create();
		void print();
		ltw_task *get_task() { return task_; }

		void create_daemon(int port);
		void stop_daemon();

		void initialise();

		static int parse_request_arguments(void *cls, enum MHD_ValueKind kind, const char *key,
	               const char *value);

		static int response (void *cls, struct MHD_Connection *connection,
                const char *url,
                const char *method, const char *version,
                const char *upload_data,
                size_t *upload_data_size, void **con_cls);

	protected:
		void load(const char *configfile);
		std::string get_home(const char *name);

		void print_header();
		void print_links(long orphan_docid, char *orphan_name, long links_to_print, long max_targets_per_anchor, long mode);

	private:

	};

}
#endif /* LTW_RUN_H_ */
