
#ifndef IIR_ZTF_ATTRIBUTE_HH
#define IIR_ZTF_ATTRIBUTE_HH

// Copyright (c) 2002-2003 The University of Cincinnati.
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

// Authors: Prashanth Cherukuri cherukps@ececs.uc.edu

//---------------------------------------------------------------------------

#include "savant_config.hh"
#include "IIR_Attribute.hh"

class IIR_ZTFAttribute : public virtual IIR_Attribute {
public:
  virtual ~IIR_ZTFAttribute() {};

  /** Set the numerator coefficients from the static expression. */
  virtual void set_num(IIRRef numerator) = 0;

  /** Return the numerator coefficients. */
  virtual IIRRef get_num() = 0;

  /** Set the denominator coefficients from the static expression.  */
  virtual void set_den(IIRRef denominator) = 0;

  /** Return the denominator coefficients.  */
  virtual IIRRef get_den() = 0;

  /** Set the sampling frequency. */ 
  virtual void set_t(IIRRef period) = 0;

  /** Return the sampling frequency. */ 
  virtual IIRRef get_t() = 0;

  /** Set the initial_delay specifying the time of the first sampling. If
      omitted, it defaults to 0.0. */
  virtual void set_initial_delay(IIRRef initial_delay) = 0;

  /** Return the initial_delay specifying the time of the first sampling. */
  virtual IIRRef get_initial_delay() = 0;  
protected:
private:
};

typedef refcount<IIR_ZTFAttribute> IIR_ZTFAttributeRef;

#endif
