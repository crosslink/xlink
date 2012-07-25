
stpl_basic_headers=\
				stpl_doc.h \
				stpl_entity.h \
				stpl_exception.h \
				stpl_grammar.h \
				stpl_keyword.h \
				stpl_log.h \
				stpl_othertraits.h \
				stpl_parser.h \
				stpl_property.h \
				stpl_rule.h \
				stpl_scanner.h \
				stpl_simple.h \
				stpl_stream.h \
				stpl_typetraits.h \
				stpl_unichar.h \
				stpl_unigrammar.h \
				stpl_uniword.h \
				stpl_word.h
stpl_basic_sources=

stpl_xml_headers= \
				xml/stpl_xml_basic.h \
				xml/stpl_xml_entity.h \
				xml/stpl_xml.h
stpl_xml_sources=			
				
stpl_html_headers = \
				html/stpl_html_entity.h \
				html/stpl_html.h
stpl_html_sources =
				
stpl_misc_headers = \
				misc/stpl_trec.h
stpl_misc_sources =	
			
stpl_characters_headers = \
				lang/stpl_character.h \
				lang/stpl_chinese.h \
				lang/stpl_unicode.h \
				lang/stpl_uscanner.h				
stpl_characters_sources =		

stpl_stpl_sources = \
				$(stpl_basic_headers) \
				$(stpl_basic_sources) 
#				$(stpl_xml_headers) \
#				$(stpl_xml_sources)			
#				$(stpl_html_headers) \
#				$(stpl_html_sources) \
#				$(stpl_misc_headers) \
#				$(stpl_misc_sources) \
#				$(stpl_characters_headers) \
#				$(stpl_characters_sources)
				
							
includedir = $(prefix)/include/stpl/stpl
include_HEADERS = $(stpl_stpl_sources)
				
xmlincludedir = $(prefix)/include/stpl/stpl/xml
xmlinclude_HEADERS = \
				$(stpl_xml_headers) \
				$(stpl_xml_sources)
				
htmlincludedir = $(prefix)/include/stpl/stpl/html
htmlinclude_HEADERS = \
				$(stpl_html_headers) \
				$(stpl_html_sources)				

miscincludedir = $(prefix)/include/stpl/stpl/misc
miscinclude_HEADERS = \
				$(stpl_misc_headers) \
				$(stpl_misc_sources)
				
charactersincludedir = $(prefix)/include/stpl/stpl/characters
charactersinclude_HEADERS = \
				$(stpl_characters_headers) \
				$(stpl_characters_sources)			
				