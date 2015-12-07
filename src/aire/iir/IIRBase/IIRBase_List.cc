
// Copyright (c) The University of Cincinnati.  
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

#include "IIRBase_List.hh"

IIRBase_List::IIRBase_List() {}
IIRBase_List::~IIRBase_List() {}

IIRRef
IIRBase_List::convert_tree(plugin_class_factoryRef factory) {
  IIR_ListRef new_list = my_dynamic_pointer_cast<IIR_List>(converted_node);

  //   If we didn't find it in the existing element list, 
  // then it must be a new element
  if (new_list == nullptr) {
    // Clone the list itself
    new_list = my_dynamic_pointer_cast<IIR_List>(IIRBase::convert_tree(factory));

    // Now clone it's contents
    IIRBaseRef    old_node = my_dynamic_pointer_cast<IIRBase>(first());
    IIRRef        new_node;
    while (old_node != NULL) {
      // Check for circular dependencies
      if ((new_node = old_node->converted_node) == nullptr) {
        new_node = old_node->convert_tree(factory);
      }
      
      // Add the newly cloned node to the list
      new_list->append(new_node);
      
      old_node = my_dynamic_pointer_cast<IIRBase>(successor(old_node));
    }
  }
  return new_list;
}

IIR_Boolean 
IIRBase_List::is_resolved(){
  IIR_Boolean retval = TRUE;

  IIRRef current_element = my_dynamic_pointer_cast<IIR>(first());
  while( current_element != nullptr ){
    if( current_element->is_resolved() == FALSE ){
      retval = FALSE;
      break;
    }
    current_element = my_dynamic_pointer_cast<IIR>(successor( current_element ));
  }

  return retval;
}

ostream &
IIRBase_List::print( ostream &os ){

  IIRRef list_element = first(); 
  while( list_element != nullptr ){
    os << list_element;
    list_element = successor(list_element);
    if( list_element != nullptr ){
      os << ",";
    }
  }
  return os;
}

void 
IIRBase_List::publish_vhdl_decl(ostream &vhdl_out, const char *separator ) {
  IIRBaseRef list_element = my_dynamic_pointer_cast<IIRBase>(first());
  while( list_element != nullptr ){
    list_element->publish_vhdl_decl(vhdl_out);
    list_element = my_dynamic_pointer_cast<IIRBase>(successor( list_element ));
    
    if( separator != NULL && list_element != nullptr ){
      vhdl_out << separator;
    }
  }
}

void 
IIRBase_List::publish_vhdl( ostream &vhdl_out, const char *separator ) {
  IIRBaseRef list_element = my_dynamic_pointer_cast<IIRBase>(first());
  while( list_element != nullptr ){
    list_element->publish_vhdl(vhdl_out);
    list_element = my_dynamic_pointer_cast<IIRBase>(successor( list_element ));

    if( list_element != nullptr && separator != NULL ){
      vhdl_out << separator;
    }
  }
}

void 
IIRBase_List::publish_vhdl( ostream &vhdl_out ){
  publish_vhdl( vhdl_out, "\n" );
}
