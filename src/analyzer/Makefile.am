# Process this file with automake to produce Makefile.in

# Copyright (c) 1999-2001 The University of Cincinnati.  
# All rights reserved.

# UC MAKES NO REPRESENTATIONS OR WARRANTIES ABOUT THE SUITABILITY OF THE
# SOFTWARE, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
# IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE,
# OR NON-INFRINGEMENT.  UC SHALL NOT BE LIABLE FOR ANY DAMAGES SUFFERED BY
# LICENSEE AS A RESULT OF USING, RESULT OF USING, MODIFYING OR
# DISTRIBUTING THIS SOFTWARE OR ITS DERIVATIVES.

# By using or copying this Software, Licensee agrees to abide by the
# intellectual property laws, and all other applicable laws of the U.S.,
# and the terms of this license.

# You may modify, distribute, and use the software contained in this
# package under the terms of the "GNU LIBRARY GENERAL PUBLIC LICENSE"
# version 2, June 1991. A copy of this license agreement can be found in
# the file "LGPL", distributed with this archive.

# Authors: Philip A. Wilsey	phil.wilsey@uc.edu
# 	    Dale E. Martin	dmartin@clifton-labs.com
#	    Magnus Danielson	cfmd@swipnet.se
#---------------------------------------------------------------------------

include $(top_srcdir)/Makefile.am.common

SRC_OUTPUT_DIR = $(top_builddir)/src/analyzer
SRC_INPUT_DIR = $(top_srcdir)/src/analyzer
VHDL_GG = $(SRC_INPUT_DIR)/vhdl.gg

man_MANS = $(top_srcdir)/doc/scram.1

BUILT_SOURCES = \
	vhdl.cpp			\
	VHDLParser.cpp			\
	VHDLParser.h			\
	VHDLTokenTypes.hh \
	VHDLLexer.cc

noinst_LTLIBRARIES = libscram.la

libscram_la_CPPFLAGS = \
   -I$(top_srcdir)/src/aire/iir/IIRScram \
   -I$(top_srcdir)/src/aire/iir/IIRBase \
   -I$(top_srcdir)/src \
   -I$(top_srcdir)/src/util \
   -I$(top_srcdir)/src/aire/iir/IIR \
   -I$(top_srcdir)/src/aire \
   -I$(top_srcdir)/src/aire/iir/visitor

libscram_la_SOURCES = \
	VHDLLexer.hh \
	VHDLLexerBits.cc \
	VHDLToken.hh \
	declaration_chain.hh \
	library_manager.cc \
	scram.cc	\
	scram_func.hh \
	StandardPackage.cc \
	symbol_lookup.cc \
	symbol_table.cc \
	vhdl.hh \
	antlr_error_func.cc \
	$(BUILT_SOURCES)

libscram_la_LIBADD = \
	$(top_builddir)/src/util/libsavantutils.la

# Location for the library installation
# With this first command I specify the folder that the "library_include"
# should use for the installation.
library_includedir = $(includedir)/savant
# Now, I specify the headers to install.
library_include_HEADERS =		\
	StandardPackage.hh		\
	library_manager.hh		\
	scram.hh

DO_ANTLR = $(ANTLR) -gx -k 2 -CC -ft VHDLTokenTypes.hh \
	 $(VHDL_GG) -o $(SRC_OUTPUT_DIR)

DO_LEX =	$(LEX) -+ -i -Cfe -o$(SRC_OUTPUT_DIR)/$@ $(SRC_INPUT_DIR)/VHDLLexer.flex

VHDLTokenTypes.hh: $(VHDL_GG)
	$(DO_ANTLR)

VHDLParser.cpp:  $(VHDL_GG)
	$(DO_ANTLR)

VHDLParser.h: $(VHDL_GG)
	$(DO_ANTLR)

vhdl.cpp: $(VHDL_GG)
	$(DO_ANTLR)

VHDLLexer.cc: VHDLLexer.hh VHDLLexer.flex
	$(DO_LEX)

clean-local:
	rm -f $(BUILT_SOURCES)

$(DEPDIR)/scram.Plo: $(BUILT_SOURCES)
