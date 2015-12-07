
#ifndef IIR_CONDITIONAL_WAVEFORM_HH
#define IIR_CONDITIONAL_WAVEFORM_HH

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

#include "savant_config.hh"
#include "IIR_Tuple.hh"

REF_FORWARD_DECL(IIR_WaveformList);

class IIR_ConditionalWaveform : public virtual IIR_Tuple{

public:
  virtual ~IIR_ConditionalWaveform() {}
    
  // List accessor(s)
  virtual IIR_WaveformListRef get_waveform() = 0;

  virtual void set_condition( IIRRef condition ) = 0;
  virtual IIRRef get_condition() = 0;
};

typedef refcount<IIR_ConditionalWaveform> IIR_ConditionalWaveformRef;

#endif
