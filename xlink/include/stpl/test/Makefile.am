# what flags you want to pass to the C compiler & linker
# CFLAGS = --pedantic -Wall -std=c99 -O2
#CPPFLAGS = -Wall -g -o2
# LDFLAGS =
#
# # this listpl the binaries to produce, the (non-PHONY, binary) targets in
# # the previous manual Makefile
AM_CPPFLAGS = -I$(srcdir)/../

noinst_PROGRAMS = test_xml test_trec test_attr test_html test_html_attr test_unicode test_unidoc \
				  test_fs test_text test_filestream

test_xml_SOURCES = test_xml.cpp

test_trec_SOURCES = test_trec.cpp

test_attr_SOURCES = test_attr.cpp

test_html_SOURCES = test_html.cpp

test_html_attr_SOURCES = test_html_attr.cpp

test_unicode_SOURCES = test_unicode.cpp

test_unidoc_SOURCES = test_unidoc.cpp

test_fs_SOURCES = test_fs.cpp

test_text_SOURCES = test_text.cpp

test_filestream_SOURCES = test_filestream.cpp

###########################################################################
#
#                  					TESTING
# 
##########################################################################
TESTS = test_xml test_trec test_attr test_html test_html_attr test_unicode test_unidoc \
		test_fs test_text test_filestream

