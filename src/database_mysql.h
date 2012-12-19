/*
 * databasemysql.h
 *
 *  Created on: Apr 20, 2012
 *      Author: monfee
 */

#ifndef DATABASEMYSQL_H_
#define DATABASEMYSQL_H_

#include "pattern_singleton.h"

#include <mysql/mysql.h>

#include <string>
#include <vector>

class database_mysql : public pattern_singleton<database_mysql> {
public:
	const static int DEFAULT_NUMBER_OF_DOC_PER_REQUEST = 5;
	const static char *DEFAULT_CORPUS_TABLE;

private:
    std::string server;
    std::string user;
    std::string password;
    std::string database;

    MYSQL *connection;

    int number_of_doc;
    bool connected;

    std::string corpus_table;

public:
	database_mysql();
	virtual ~database_mysql();

	int connect();

	void execute_query(std::string);

	void fill(std::vector<long>& container, const char *source_lang);
	void finish(std::vector<long>& container, const char *source_lang);
	void fail(std::vector<long>& container, const char *source_lang);
	void processing(std::vector<long>& container, const char *source_lang);

	void finish(long id, const char *source_lang);
	void fail(long id, const char *source_lang);

	std::string get_google_translate_key();

	void update_status(std::vector<long>& container, int type, int value, const char *source_lang);
	void update_translation(long id, const char *translation, const char *target_lang, const char *source_lang);
	void update_google_translate_key(const char *key);

	bool is_connected() { return connected; }
	void error_message();

	std::string escape_string(const char *in);

	void set_corpus_table(std::string table_name) { corpus_table = table_name; }

private:
	void init();


};

#endif /* DATABASEMYSQL_H_ */
