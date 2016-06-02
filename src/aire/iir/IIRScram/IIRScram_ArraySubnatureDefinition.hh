#ifndef IIRSCRAM_ARRAY_SUBNATURE_DEFINITION_HH
#define IIRSCRAM_ARRAY_SUBNATURE_DEFINITION_HH

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

// Author: Sivakumar Gowrisankar             gowriss@ececs.uc.edu

//---------------------------------------------------------------------------

#include "IIRBase_ArraySubnatureDefinition.hh"
#include "IIRScram_ArrayNatureDefinition.hh"

class IIRScram_ArraySubnatureDefinition : public virtual IIRScram_ArrayNatureDefinition, public virtual IIRBase_ArraySubnatureDefinition {

public:
  IIRScram_ArraySubnatureDefinition(){}
  virtual ~IIRScram_ArraySubnatureDefinition();

  virtual IIRScram *_clone();
};

#endif
