/*
 * xml2txt.h
 *
 *  Created on: Sep 16, 2009
 *      Author: monfee
 */

#ifndef XML2TXT_H_
#define XML2TXT_H_

#include "xml2txt_client.h"

namespace QLINK {

	class xml2txt
	{
	private:
		xml2txt_client	client_;
		bool			connected_;

	public:
		xml2txt();
		virtual ~xml2txt();

		static xml2txt& instance();
		char *convert(char *xml);

		char *clean_tags(const char *xml, long lowercase = 0);

		char *gettext(const char *xmlfile, const char *txtfile, char *xml);
		char *gettext(long docid, char *xml = 0);

		char *gettearatext(const char *name, char *xml = 0);
	};

	inline xml2txt& xml2txt::instance() {
		static xml2txt inst;
		return inst;
	}
}

#endif /* XML2TXT_H_ */
