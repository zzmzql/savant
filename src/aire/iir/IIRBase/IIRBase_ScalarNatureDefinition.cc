
// Copyright (c) 2002 The University of Cincinnati.
// All rights reserved.
 
// UC MAKES NO REPRESENTATIONS OR WARRANTIES ABOUT THE SUITABILITY OF THE
// SOFTWARE, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
// IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, OR
// NON-INFRINGEMENT.  UC SHALL NOT BE LIABLE FOR ANY DAMAGES SUFFERED BY
// LICENSEE AS A RESULT OF USING, RESULT OF USING, MODIFYING OR DISTRIBUTING
// THIS SOFTWARE OR ITS DERIVATIVES.
 
// By using or copying this Software, Licensee agrees to abide by the
// intellectual property laws, and all other applicable laws of the U.S., and
// the terms of this license.
  
// You may modify, distribute, and use the software contained in this package
// under the terms of the "GNU LIBRARY GENERAL PUBLIC LICENSE" version 2, June
// 1991. A copy of this license agreement can be found in the file "LGPL",
// distributed with this archive.
 
// Authors: Sivakumar Gowrisankar             gowriss@ececs.uc.edu
//          Vinod Chamarty                    chamarv@ececs.uc.edu
//          Vasudevan Shanmugasundaram
//          Kathiresan Nellayappan
 
//---------------------------------------------------------------------------

#include "savant.hh"
#include "IIRBase_ScalarNatureDefinition.hh"
#include "IIR_TextLiteral.hh"

IIRBase_ScalarNatureDefinition::IIRBase_ScalarNatureDefinition() {}
IIRBase_ScalarNatureDefinition::~IIRBase_ScalarNatureDefinition() {}

void
IIRBase_ScalarNatureDefinition::set_across(IIR_TypeDefinitionRef across_type){
  this->across = across_type;
}

IIR_TypeDefinitionRef
IIRBase_ScalarNatureDefinition::get_across(){
  return across;
}

void
IIRBase_ScalarNatureDefinition::set_through( IIR_TypeDefinitionRef new_through ){
  through = new_through;
}

IIR_TypeDefinitionRef
IIRBase_ScalarNatureDefinition::get_through(){
  return through;
}

void
IIRBase_ScalarNatureDefinition::set_reference_terminal( IIR_TerminalDeclarationRef new_ref_term ){
  reference_terminal = new_ref_term;
}

IIR_TerminalDeclarationRef
IIRBase_ScalarNatureDefinition::get_reference_terminal(){
  return reference_terminal ;
}

IIRRef
IIRBase_ScalarNatureDefinition::convert_tree(plugin_class_factoryRef factory) {
  // Get the node itself
  IIRBase_ScalarNatureDefinitionRef new_node = my_dynamic_pointer_cast<IIRBase_ScalarNatureDefinition>(IIRBase_NatureDefinition::convert_tree(factory));

  // Process the variables
  new_node->across = my_dynamic_pointer_cast<IIR_TypeDefinition>(convert_node(across, factory));
  new_node->through = my_dynamic_pointer_cast<IIR_TypeDefinition>(convert_node(through, factory));
  new_node->reference_terminal = my_dynamic_pointer_cast<IIR_TerminalDeclaration>(convert_node(reference_terminal, factory));
  new_node->across_tolerance = convert_node(across_tolerance, factory);
  new_node->through_tolerance = convert_node(through_tolerance, factory);

  return new_node;
}

void
IIRBase_ScalarNatureDefinition::publish_vhdl_decl(ostream &vhdl_out) {

  get_across()->publish_vhdl(vhdl_out);
  vhdl_out << " across " ;
  get_through()->publish_vhdl(vhdl_out);
  vhdl_out << " through " ;
  get_reference_terminal()->get_declarator()->publish_vhdl(vhdl_out);
  vhdl_out << " reference " ;

}
