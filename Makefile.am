#AM_CPPFLAGS = -std=c++0x  -pedantic -DREMOVE_ORPHAN_LINKS -I $(srcdir)/include/stpl -I $(srcdir)/include/stpl

AM_CPPFLAGS = -std=c++0x -pedantic -I $(srcdir)/include/ -DCROSSLINK

LTW_LIBS = -lpthread -L$(srcdir)  -lcurl -latire_api -lWN  -L/usr/lib64/mysql -lboost_regex @MYSQL_LIBS@ 
#LTW_LIBS ==-lgcj

SRC_DIR = src
INCLUDE_DIR = include
TOOLS_DIR = tools

utils_header = 	\
	$(INCLUDE_DIR)/extralib.h \
	$(INCLUDE_DIR)/template_algo.h \
	$(INCLUDE_DIR)/template_comparor.h \
	$(INCLUDE_DIR)/pattern_singleton.h \
	$(INCLUDE_DIR)/string_utils.h \
	$(INCLUDE_DIR)/xml.h \
	$(INCLUDE_DIR)/XML2TXT.h \
	$(INCLUDE_DIR)/str.h 

ltw_headers = \
	$(SRC_DIR)/run.h \
	$(SRC_DIR)/algorithm.h \
	$(SRC_DIR)/incoming_link.h \
	$(SRC_DIR)/link.h \
	$(SRC_DIR)/ant_link_term.h \
	$(SRC_DIR)/ant_link_posting.h \
	$(SRC_DIR)/ant_link.h \
	$(SRC_DIR)/ltw_run.h \
	$(SRC_DIR)/outgoing_link.h \
	$(SRC_DIR)/config.h \
	$(SRC_DIR)/run_config.h \
	$(SRC_DIR)/algorithm_config.h \
	$(SRC_DIR)/algorithm_ant_link_this.h \
	$(SRC_DIR)/algorithm_ant_crosslink_this.h \
	$(SRC_DIR)/algorithm_page_name.h \
	$(SRC_DIR)/algorithm_ant_link_this_and_page_name.h \
	$(SRC_DIR)/algorithm_ant_link_this_and_page_name2.h \
	$(SRC_DIR)/algorithm_ltw_incoming_search_tn.h \
	$(SRC_DIR)/algorithm_ltw_incoming_a2b_search_tn.h \
	$(SRC_DIR)/algorithm_ltw_tang.h \
	$(SRC_DIR)/algorithm_bep.h \
	$(SRC_DIR)/algorithm_out.h \
	$(SRC_DIR)/algorithm_ltara_base.h \
	$(SRC_DIR)/cmdline_options.h \
	$(SRC_DIR)/sys_file.h \
	$(SRC_DIR)/sys_files.h \
	$(SRC_DIR)/ir_task.h \
	$(SRC_DIR)/ltw_task.h \
	$(SRC_DIR)/links.h \
	$(SRC_DIR)/outgoing_links.h \
	$(SRC_DIR)/incoming_links.h \
	$(SRC_DIR)/topic.h \
	$(SRC_DIR)/ltw_topic.h \
	$(SRC_DIR)/xml2txt_client.h \
	$(SRC_DIR)/xml2txt.h \
	$(SRC_DIR)/corpus.h \
	$(SRC_DIR)/corpus_txt.h \
	$(SRC_DIR)/system_call.h \
	$(SRC_DIR)/language.h \
	$(SRC_DIR)/search_engine.h \
	$(SRC_DIR)/search_engine_ant.h \
	$(SRC_DIR)/search_engine_ant_remote.h \
	$(SRC_DIR)/wikipedia.h \
	$(SRC_DIR)/wikipedia_page.h \
	$(SRC_DIR)/wordnet.h \
	$(SRC_DIR)/database_mysql.h \
	$(SRC_DIR)/google_translator.h \
	$(SRC_DIR)/google_research_translator.h \
	$(SRC_DIR)/translation.h \
	$(SRC_DIR)/webpage_retriever.h \
	$(SRC_DIR)/application_out.h \
	$(SRC_DIR)/link_print.h \
	$(SRC_DIR)/urlcode.h \
	$(SRC_DIR)/session.h \
	$(SRC_DIR)/request.h \
	$(SRC_DIR)/anchor.h \
	$(SRC_DIR)/wikification.h \
	$(SRC_DIR)/target.h \
	$(SRC_DIR)/mime.h \
	$(SRC_DIR)/system_info.h

noinst_HEADERS = $(ltw_headers) $(utils_header)
	
ltw_sources = \
	$(SRC_DIR)/sys_file.cpp \
	$(SRC_DIR)/sys_files.cpp \
	$(SRC_DIR)/system_info.cpp	\
	$(SRC_DIR)/run.cpp \
	$(SRC_DIR)/algorithm.cpp \
	$(SRC_DIR)/incoming_link.cpp \
	$(SRC_DIR)/link.cpp \
	$(SRC_DIR)/ant_link_term.cpp \
	$(SRC_DIR)/ant_link_posting.cpp \
	$(SRC_DIR)/ltw_run.cpp \
	$(SRC_DIR)/outgoing_link.cpp \
	$(SRC_DIR)/config.cpp \
	$(SRC_DIR)/run_config.cpp \
	$(SRC_DIR)/algorithm_config.cpp \
	$(SRC_DIR)/algorithm_ant_link_this.cpp \
	$(SRC_DIR)/algorithm_ant_crosslink_this.cpp\
	$(SRC_DIR)/algorithm_page_name.cpp \
	$(SRC_DIR)/algorithm_ant_link_this_and_page_name.cpp \
	$(SRC_DIR)/algorithm_ant_link_this_and_page_name2.cpp \
	$(SRC_DIR)/algorithm_ltw_tang.cpp \
	$(SRC_DIR)/algorithm_ltw_incoming_search_tn.cpp \
	$(SRC_DIR)/algorithm_ltw_incoming_a2b_search_tn.cpp \
	$(SRC_DIR)/algorithm_bep.cpp \
	$(SRC_DIR)/algorithm_out.cpp \
	$(SRC_DIR)/algorithm_ltara_base.cpp \
	$(SRC_DIR)/cmdline_options.cpp \
	$(SRC_DIR)/ltw_task.cpp \
	$(SRC_DIR)/links.cpp \
	$(SRC_DIR)/outgoing_links.cpp \
	$(SRC_DIR)/incoming_links.cpp \
	$(SRC_DIR)/topic.cpp \
	$(SRC_DIR)/ltw_topic.cpp \
	$(SRC_DIR)/xml2txt_client.cpp \
	$(SRC_DIR)/xml2txt.cpp \
	$(SRC_DIR)/corpus.cpp \
	$(SRC_DIR)/corpus_txt.cpp \
	$(SRC_DIR)/system_call.cpp \
	$(SRC_DIR)/language.cpp \
	$(SRC_DIR)/search_engine.cpp \
	$(SRC_DIR)/search_engine_ant.cpp \
	$(SRC_DIR)/search_engine_ant_remote.cpp \
	$(SRC_DIR)/proxy.cpp \
	$(SRC_DIR)/porter.cpp \
	$(SRC_DIR)/wikipedia.cpp \
	$(SRC_DIR)/wikipedia_page.cpp \
	$(SRC_DIR)/wordnet.cpp \
	$(SRC_DIR)/translation.cpp \
	$(SRC_DIR)/database_mysql.cpp \
	$(SRC_DIR)/google_translator.cpp \
	$(SRC_DIR)/google_research_translator.cpp \
	$(SRC_DIR)/webpage_retriever.cpp \
	$(SRC_DIR)/application_out.cpp \
	$(SRC_DIR)/link_print.cpp \
	$(SRC_DIR)/urlcode.cpp \
	$(SRC_DIR)/session.cpp \
	$(SRC_DIR)/request.cpp \
	$(SRC_DIR)/anchor.cpp \
	$(SRC_DIR)/wikification.cpp \
	$(SRC_DIR)/target.cpp \
	$(SRC_DIR)/mime.cpp \
	$(SRC_DIR)/ltw.cpp

noinst_PROGRAMS = ltw collection_link_finder urlencoder wikify

ltw_SOURCES = $(ltw_sources)
ltw_LDADD = ${LTW_LIBS}
ltw_CFLAGS = $(AM_CFLAGS)
#ltw_LDFLAGS = -static

collection_link_finder_SOURCES = $(TOOLS_DIR)/collection_link_finder.cpp

urlencoder_SOURCES = $(TOOLS_DIR)/urlencoder.cpp \
									 $(SRC_DIR)/urlcode.cpp
urlencoder_LDADD =
urlencoder_CFLAGS =			

wikify_SOURCES = $(SRC_DIR)/sys_file.cpp \
									 $(SRC_DIR)/anchor.cpp \
									 $(SRC_DIR)/target.cpp \
									 $(SRC_DIR)/wikification.cpp \
									 $(TOOLS_DIR)/wikify.cpp
									 
wikify_LDADD =
wikify_CFLAGS =								
