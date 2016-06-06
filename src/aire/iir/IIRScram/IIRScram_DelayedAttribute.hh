#ifndef IIRSCRAM_DELAYED_ATTRIBUTE_HH
#define IIRSCRAM_DELAYED_ATTRIBUTE_HH

// Copyright (c) 1996-2000 The University of Cincinnati.  
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
//          Timothy J. McBrayer tmcrbaye@ece.uc.edu
//          Umesh Kumar V. Rajasekaran urajasek@ece.uc.edu
//          Malolan Chetlur     mal@ece.uc.edu

//---------------------------------------------------------------------------

#include "IIRScram_Attribute.hh"
#include "IIRBase_DelayedAttribute.hh"

class IIRScram_TypeDefinition;
class IIRScram_TextLiteral;
class IIRScram_Declaration;

class IIRScram_DelayedAttribute : public virtual IIRScram_Attribute, public virtual IIRBase_DelayedAttribute {

public:
  IIR_Boolean is_signal(){ return true; }

  IIR_Boolean has_suffix(){ return true; }
  void _set_suffix( IIRScram *new_suffix );
  IIRScram *_get_suffix();

  IIRScram_TypeDefinition *_get_subtype();

  IIRScram_Declaration *_get_implicit_declaration( const string &, IIRScram_TypeDefinition * );

  virtual IIR_Boolean _is_delayed_attribute() { return true; }

  IIR_Boolean _is_signal_attribute(){ return true; }

protected:
  void _resolve_suffix_special();
};

#endif
