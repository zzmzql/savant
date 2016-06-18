#ifndef IIRBASE_CONCURRENT_ASSERTION_STATEMENT_HH
#define IIRBASE_CONCURRENT_ASSERTION_STATEMENT_HH

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

#include "IIRBase_ConcurrentStatement.hh"
#include "IIR_ConcurrentAssertionStatement.hh"

class IIRBase_ConcurrentAssertionStatement : public virtual IIRBase_ConcurrentStatement, public virtual IIR_ConcurrentAssertionStatement{

public:
  IIR_Kind get_kind() const {return IIR_CONCURRENT_ASSERTION_STATEMENT;}
  const IIR_Char *get_kind_text() const {return "IIR_ConcurrentAssertionStatement";}

  void set_postponed( IIR_Boolean predicate );
  IIR_Boolean get_postponed() const;

  void set_assertion_condition( IIR_Statement *condition );
  IIR_Statement *get_assertion_condition() const;

  void set_report_expression( IIR_Statement *expression );
  IIR_Statement *get_report_expression() const;

  void set_severity_expression(  IIR_Statement *expression );
  IIR_Statement *get_severity_expression() const;

  IIR_Statement *convert_tree(plugin_class_factory *factory);

  void publish_vhdl(ostream &);
protected:
  IIRBase_ConcurrentAssertionStatement();
  virtual ~IIRBase_ConcurrentAssertionStatement() = 0;
    
private:
  IIR_Boolean predicate;
  IIR_Statement *assertion_condition;
  IIR_Statement *report_expression;
  IIR_Statement *severity_expression;
};
#endif
