
#ifndef IIRBASE_ENUMERATION_SUBTYPE_DEFINITION_HH
#define IIRBASE_ENUMERATION_SUBTYPE_DEFINITION_HH

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
#include "IIRBase_EnumerationTypeDefinition.hh"
#include "IIR_EnumerationSubtypeDefinition.hh"

REF_FORWARD_DECL(IIR_EnumerationLiteral);
class IIR_EnumerationLiteralList;
class IIR_FunctionDeclaration;

// class IIRBase_SubtypeDefinition provides the resolution_function methods.
class IIRBase_EnumerationSubtypeDefinition : public virtual IIRBase_EnumerationTypeDefinition,
					     public virtual IIR_EnumerationSubtypeDefinition {
public:
  // List Accessor(s)
  IIR_Kind get_kind() const override { return IIR_ENUMERATION_SUBTYPE_DEFINITION; }
  IIR_CharConstRef get_kind_text() const override { return IIR_CharConstRef("IIR_EnumerationSubtypeDefinition"); }

  
  static IIR_EnumerationSubtypeDefinitionRef 
  get( IIR_EnumerationTypeDefinitionRef base_type,
       IIR_EnumerationLiteralRef left_limit,
        IIR_EnumerationLiteralRef right_limit);

  void set_resolution_function( IIR_FunctionDeclarationRef );
  IIR_FunctionDeclarationRef get_resolution_function();

  IIRRef convert_tree(plugin_class_factoryRef factory);

  IIR_Boolean is_subtype();

  void publish_vhdl_decl(ostream &);
protected:
  IIRBase_EnumerationSubtypeDefinition();
  virtual ~IIRBase_EnumerationSubtypeDefinition() = 0;
    
private:
  // List Variable(s)
  IIR_EnumerationLiteralListRef enumeration_literals;

  IIR_FunctionDeclarationRef my_resolution_function;
};

typedef refcount<IIRBase_EnumerationSubtypeDefinition> IIRBase_EnumerationSubtypeDefinitionRef;

#endif
