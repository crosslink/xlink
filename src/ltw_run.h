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
#include "request.h"

//struct MHD_Connection;
//struct MHD_Daemon;

#include <microhttpd.h>
#include <map>

namespace QLINK {

	/*
	 * Link-the-Wiki run
	 */
	class ltw_run : public run, public pattern_singleton<ltw_run> {
	public:
		typedef std::map<std::string, request> request_type;

	private:
		ltw_task											*task_;
		struct MHD_Daemon						*daemon_;

		static ltw_run									*instance_ptr_;

		request_type										requests_;

	public:
		ltw_run();
		ltw_run(char *configfile);
		virtual ~ltw_run();

		void create();
		void print();
		ltw_task *get_task() { return task_; }

		static void setup_instance(ltw_run *instance_ptr) { instance_ptr_ = instance_ptr; };

		void create_daemon(int port);
		void stop_daemon();

		void global_initialise();
		void request_initialise(const char *url);

		void setup_output(ostream *out);

		static int parse_request_arguments(void *cls, enum MHD_ValueKind kind, const char *key,
	               const char *value);

		static int response_request (void *cls, struct MHD_Connection *connection,
                const char *url,
                const char *method, const char *version,
                const char *upload_data,
                size_t *upload_data_size, void **con_cls);

		void load_config(const char *config_file);
		void load_config();

		const std::map<std::string, request>& get_requests() const {
			return requests_;
		}

		protected:
			std::string get_home(const char *name);

			void print_header();
			void print_links(long orphan_docid, char *orphan_name, long links_to_print, long max_targets_per_anchor, long mode);

		private:
			void init();
	};

}
#endif /* LTW_RUN_H_ */
