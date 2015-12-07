
#ifndef IIRSCRAM_MULTIPLICATION_OPERATOR_HH
#define IIRSCRAM_MULTIPLICATION_OPERATOR_HH

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

//---------------------------------------------------------------------------

#include "savant_config.hh"
#include "IIRScram_MultiplicationOperators.hh"
#include "IIRBase_MultiplicationOperator.hh"

class IIRScram_MultiplicationOperator : public virtual IIRScram_MultiplicationOperators,
					public virtual IIRBase_MultiplicationOperator{
public:
  /// Accept visitations \Ref{_accept_visitor}.
  visitor_return_type* _accept_visitor(node_visitor *, visitor_argument_type *);

  IIRScramRef _clone();

protected:
private:
};

typedef refcount<IIRScram_MultiplicationOperator> IIRScram_MultiplicationOperatorRef;

#endif
