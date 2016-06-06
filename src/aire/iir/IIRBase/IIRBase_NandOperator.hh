#ifndef IIRBASE_NAND_OPERATOR_HH
#define IIRBASE_NAND_OPERATOR_HH

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

#include "IIRBase_DyadicOperator.hh"
#include "IIR_NandOperator.hh"

class IIRBase_NandOperator : public virtual IIRBase_DyadicOperator,
			     public virtual IIR_NandOperator{

public:

  IIR_Kind get_kind() const {return IIR_NAND_OPERATOR;}
  const IIR_Char *get_kind_text() const {return "IIR_NandOperator";}
  const string &get_operator_string() const;

  Precedence  get_precedence();
  IIR_Boolean is_logical_operator(){ return TRUE; }
  IIR_Boolean is_left_associative(){ return false; }
  bool is_associative(IIR_Kind);

protected:
  
  IIRBase_NandOperator();
  virtual ~IIRBase_NandOperator() = 0;
    
private:
};
#endif
