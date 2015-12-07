
#ifndef IIR_PROCESS_STATEMENT_HH
#define IIR_PROCESS_STATEMENT_HH

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
#include "IIR_ConcurrentStatement.hh"

REF_FORWARD_DECL(IIR_DeclarationList);
REF_FORWARD_DECL(IIR_SequentialStatementList);

class IIR_ProcessStatement : public virtual IIR_ConcurrentStatement{

public:
  virtual ~IIR_ProcessStatement() {}    

  // List accessor(s)
  virtual IIR_DeclarationListRef         get_process_declarative_part() = 0;
  virtual IIR_SequentialStatementListRef get_process_statement_part() = 0;
  virtual void                           set_process_declarative_part(IIR_DeclarationListRef ) = 0;
  virtual void                           set_process_statement_part(IIR_SequentialStatementListRef ) = 0;

  virtual void set_postponed( IIR_Boolean postponed) = 0;
  virtual IIR_Boolean get_postponed() = 0;

  virtual savant::set<IIR_DeclarationRef> find_declarations( IIR_NameRef ) = 0;
};

typedef refcount<IIR_ProcessStatement> IIR_ProcessStatementRef;

#endif
