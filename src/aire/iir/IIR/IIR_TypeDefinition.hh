
#ifndef IIR_TYPE_DEFINITION_HH
#define IIR_TYPE_DEFINITION_HH

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
#include "IIR.hh"

REF_FORWARD_DECL(IIR_Name);
REF_FORWARD_DECL(IIR_ScalarTypeDefinition);
REF_FORWARD_DECL(IIR_FunctionDeclaration);

namespace savant {
  template <class type> class set;
}

class IIR_TypeDefinition : public virtual IIR {
public:
  virtual ~IIR_TypeDefinition() {}
    
  virtual void                          set_base_type( IIR_TypeDefinitionRef ) = 0;
  virtual IIR_TypeDefinitionRef get_base_type() = 0;
  virtual IIR_TypeDefinitionRef get_resolved_base_type() = 0;

  virtual IIR_DeclarationRef get_declaration() = 0;
  virtual void               set_declaration( IIR_DeclarationRef ) = 0;

  virtual IIR_TypeDefinitionRef get_type_mark() = 0;
  virtual void                  set_type_mark( IIR_TypeDefinitionRef ) = 0;

  virtual IIR_Boolean                   is_element() = 0;
  virtual IIR_Boolean                   is_unconstrained_array_type() = 0;
  virtual IIR_Boolean                   is_incomplete_type_definition() = 0;
  virtual IIR_Boolean                   is_anonymous() = 0;

  virtual IIR_ScalarTypeDefinitionRef get_resolved_index_subtype() = 0;
  virtual void                        set_index_subtype(IIR_ScalarTypeDefinitionRef ) = 0;

  /** If this is an array type (or an access to an array type?), returns
      it's element subtype.  Otherwise, it complains and aborts! */
  virtual IIR_TypeDefinitionRef get_element_subtype() = 0;
  virtual void                  set_element_subtype(IIR_TypeDefinitionRef ) = 0;

  // A scalar subtype may return NULL as it's left even if it has a range
  // constraint.  These methods will travel down to the first base type
  // that has a left defined.  Similarly for right and direction.
  virtual IIRRef                       get_base_type_left() = 0;
  virtual IIRRef                       get_base_type_direction() = 0;
  virtual IIRRef                       get_base_type_right() = 0;

  /** This method returns a pointer to the most constrained common
   subtype of "this" type, and the one passed in.  It returns NULL if
   the types are not compatible at all. */
  virtual IIR_TypeDefinitionRef is_compatible( IIR_TypeDefinitionRef ) = 0;
  virtual IIR_TypeDefinitionRef check_special_compatible( IIR_TypeDefinitionRef ) = 0;
  
  virtual IIR_TypeDefinitionRef get_bottom_base_type() = 0;

  virtual savant::set<IIR_DeclarationRef> find_declarations( IIR_NameRef ) = 0;
  virtual savant::set<IIR_DeclarationRef> find_declarations( IIR_TextLiteralRef ) = 0;

  virtual IIR_FunctionDeclarationRef get_resolution_function() = 0;
};

typedef refcount<IIR_TypeDefinition> IIR_TypeDefinitionRef;

#endif
