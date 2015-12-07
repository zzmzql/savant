
#ifndef IIRBASE_DECLARATION_LIST_HH
#define IIRBASE_DECLARATION_LIST_HH

// Copyright (c) 1996-1999 The University of Cincinnati.  
// All rights reserved.

// UC MAKES NO REPRESENTATIONS OR WARRANTIES ABOUT THE SUITABILITY OF 
// THE SOFTWARE, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
// TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
// PARTICULAR PURPOSE, OR NON-INFRINGEMENT.  UC SHALL NOT BE LIABLE
// FOR ANY DAMAGES SUFFERED BY LICENSEE AS A RESULT OF USING,
// RESULT OF USING, MODIFYING OR DISTRIBUTING THIS SOFTWARE OR ITS
// DERIVATIVES.

// By using or copying this Software, Licensee agrees to abide by the
// intellectual property laws, and all other applicable laws of the
// U.S., and the terms of this license.


// You may modify, distribute, and use the software contained in this package
// under the terms of the "GNU LIBRARY GENERAL PUBLIC LICENSE" version 2,
// June 1991. A copy of this license agreement can be found in the file
// "LGPL", distributed with this archive.

// Authors: Philip A. Wilsey	phil.wilsey@uc.edu
//          Dale E. Martin	dmartin@cliftonlabs.com

//---------------------------------------------------------------------------

#include "savant_config.hh"
#include "IIRBase_List.hh"
#include "IIR_DeclarationList.hh"

REF_FORWARD_DECL(IIR_Declaration);

class IIRBase_DeclarationList : public virtual IIRBase_List, public virtual IIR_DeclarationList{

public:
  IIR_Kind get_kind() const override { return IIR_DECLARATION_LIST; }
  IIR_CharConstRef get_kind_text() const override { return IIR_CharConstRef("IIR_DeclarationList"); }

  void append( IIR_DeclarationRef );
  void prepend( IIR_DeclarationRef );

  IIRRef successor( IIR_DeclarationRef );
  IIRRef predecessor( IIR_DeclarationRef );

  IIRRef first();
  IIRRef last();

  IIRRef get_nth_element( IIR_Int32 );

  savant::set<IIR_DeclarationRef> find_declarations( IIR_NameRef );
  savant::set<IIR_DeclarationRef> find_declarations( IIR_TextLiteralRef );

  /**
     Makes the declarative region of all of the elements in this list point
     to the new region passed in.
  */
  void set_declarative_region( IIRRef );

  void publish_vhdl_decl(ostream&);
  void publish_vhdl(ostream&);
protected:
  IIRBase_DeclarationList();
  virtual ~IIRBase_DeclarationList() = 0;
  
private:

};

typedef refcount<IIRBase_DeclarationList> IIRBase_DeclarationListRef;

#endif
