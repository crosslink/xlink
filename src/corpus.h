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
 * corpus.h
 *
 *  Created on: Sep 16, 2009
 *
 */

#ifndef CORPUS_H_
#define CORPUS_H_

#include <map>
#include <string>

namespace QLINK {

	class corpus
	{
	public:
		typedef std::map<unsigned long, std::string> 	doc_map;
		typedef std::map<std::string, std::string> 		teara_map;

	private:
		const char 							*doclist_;

	protected:
		doc_map								doc_map_;
		teara_map							teara_map_;
		bool										load_;
		std::string								home_;
		std::string								base_;
		std::string								teara_home_;
		std::string								lang_;

		bool										exists_;

	public:
		corpus();
		corpus(const char *doclist);
		virtual ~corpus();

		void home(std::string path) { home_ = path; }
		void base(std::string path) { base_ = path; }
		void teara_home(std::string path) { teara_home_ = path; }
		void load();
		virtual void load_teara_map();
		void lang(std::string what) { lang_ = what; }
		std::string& lang() { return lang_; }

		virtual std::string id2doc(unsigned long id);
		virtual std::string id2dir(unsigned long id);
		virtual std::string id2docpath(unsigned long id);
		virtual std::string id2docpath(unsigned long id, std::string lang);
		virtual std::string name2docpath(const char *name);
		virtual std::string name2docpath(const std::string& home, const char *name);
		virtual std::string name2tearapath(const char *name);
		virtual std::string ext() { return ".xml"; }
		virtual std::string wildcard() { return "*.[xX][mM][lL]"; }

		std::string gettitle(unsigned long id);
		std::string gettitle(std::string filename);

		bool exist(unsigned long id);
		bool exist(unsigned long id, std::string lang);

		bool exists() { return exists_; }
		void exists(bool has_it) { exists_ = has_it; }

		static corpus& instance();

	private:
		void init();
	};

	inline corpus& corpus::instance() {
		static corpus inst;
		return inst;
	}
}

#endif /* CORPUS_H_ */
