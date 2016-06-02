
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
//          Timothy J. McBrayer 
//          Umesh Kumar V. Rajasekaran
//          Krishnan Subramani  
//          Malolan Chetlur     
//          Narayanan Thondugulam

//---------------------------------------------------------------------------

#include "IIRScram_DesignFile.hh"
#include "IIRScram_ExitStatement.hh"
#include "IIRScram_Identifier.hh"
#include "IIRScram_Label.hh"
#include "IIRScram_List.hh"
#include "resolution_func.hh"
#include "set.hh"


IIRScram_ExitStatement::~IIRScram_ExitStatement() {}

void
IIRScram_ExitStatement::_type_check() {
  if( _get_condition() != NULL ){
    set_condition( _type_check_and_resolve_boolean_condition( _get_condition() ) );
  }
}

IIRScram *
IIRScram_ExitStatement::_get_condition() {
  return dynamic_cast<IIRScram *>(get_condition());
}

IIRScram_SequentialStatement *
IIRScram_ExitStatement::_get_enclosing_loop() {
  return dynamic_cast<IIRScram_SequentialStatement *>(get_enclosing_loop());
}
