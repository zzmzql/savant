
#ifndef IIRBASE_COMMENT_LIST_HH
#define IIRBASE_COMMENT_LIST_HH

// Copyright (c) 1996-2003 The University of Cincinnati.  
// All rights reserved.

// UC MAKES NO REPRESENTATIONS OR WARRANTIES ABOUT THE SUITABILITY OF THE
// SOFTWARE, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
// IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE,
// OR NON-INFRINGEMENT.  UC SHALL NOT BE LIABLE FOR ANY DAMAGES SUFFERED BY
// LICENSEE AS A RESULT OF USING, RESULT OF USING, MODIFYING OR
// DISTRIBUTING THIS SOFTWARE OR ITS DERIVATIVES.

// By using or copying this Software, Licensee agrees to abide by the
// intellectual property laws, and all other applicable laws of the U.S.,
// and the terms of this license.

// You may modify, distribute, and use the software contained in this
// package under the terms of the "GNU LIBRARY GENERAL PUBLIC LICENSE"
// version 2, June 1991. A copy of this license agreement can be found in
// the file "LGPL", distributed with this archive.

// Authors: Philip A. Wilsey	philip.wilsey@ieee.org
//          Dale E. Martin	dmartin@cliftonlabs.com

//---------------------------------------------------------------------------

#include "savant_config.hh"
#include "IIRBase_List.hh"
#include "IIR_CommentList.hh"

/** Captures a set of VHDL comments.  Typically these comments are
    collected by the lexer and placed with each design unit. */
class IIRBase_CommentList : public virtual IIRBase_List, public virtual IIR_CommentList{

public:
  IIR_Kind get_kind() const override { return IIR_COMMENT_LIST; }
  IIR_CharConstRef get_kind_text() const override { return IIR_CharConstRef("IIR_CommentList"); }

  IIRRef first();
  IIRRef successor(IIR_CommentRef);
  void append_element(IIR_CommentRef);

  void publish_vhdl(ostream &);
protected:
  IIRBase_CommentList();
  virtual ~IIRBase_CommentList() = 0;
    
private:
};

typedef refcount<IIRBase_CommentList> IIRBase_CommentListRef;

#endif
