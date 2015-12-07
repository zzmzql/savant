
#ifndef IIRBASE_RECORD_TYPE_DEFINITION_HH
#define IIRBASE_RECORD_TYPE_DEFINITION_HH

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
//          Malolan Chetlur     mal@ece.uc.edu

//---------------------------------------------------------------------------

#include "savant_config.hh"
#include "IIRBase_TypeDefinition.hh"
#include "IIR_RecordTypeDefinition.hh"

class IIR_ElementDeclarationList;
class IIR_FunctionDeclaration;
template <class type> class set;

class IIRBase_RecordTypeDefinition : public virtual IIRBase_TypeDefinition, public virtual IIR_RecordTypeDefinition{
public:
  // List Accessor(s)
  IIR_ElementDeclarationListRef get_element_declarations();
  void                       set_element_declarations(IIR_ElementDeclarationListRef new_element_declarations);

  IIR_Kind get_kind() const override { return IIR_RECORD_TYPE_DEFINITION; }
  IIR_CharConstRef get_kind_text() const override { return IIR_CharConstRef("IIR_RecordTypeDefinition"); }

  IIR_FunctionDeclarationRef get_resolution_function();
  void set_resolution_function( IIR_FunctionDeclarationRef );

  IIRRef convert_tree(plugin_class_factoryRef factory);

  IIR_Boolean is_record_type() { return TRUE; }
  IIR_Boolean is_subtype();
  IIR_Boolean is_locally_static();

  IIR_ScalarTypeDefinitionRef get_resolved_index_subtype();
  
  // This method returns the subtype of the "nth" element.
  IIR_TypeDefinitionRef get_element_subtype( int );

  savant::set<IIR_DeclarationRef> find_declarations( IIR_NameRef );

  ostream &print( ostream & );
  void publish_vhdl_decl(ostream &);
  void publish_vhdl_subtype_decl(ostream &);
protected:
  IIRBase_RecordTypeDefinition();
  virtual ~IIRBase_RecordTypeDefinition() = 0;
    
private:
  // List Variable(s)
  IIR_ElementDeclarationListRef element_declarations;
  IIR_FunctionDeclarationRef my_resolution_function;
};

typedef refcount<IIRBase_RecordTypeDefinition> IIRBase_RecordTypeDefinitionRef;

#endif
