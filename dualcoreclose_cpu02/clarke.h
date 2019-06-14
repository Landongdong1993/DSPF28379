

#ifndef CLARKE_H
#define CLARKE_H

#include "C28x_FPU_FastRTS.h"

//-----------------------------------------------------------------------------
//  Define the structure of the POSSPEED Object   A B C TO ALPHA BETA
//-----------------------------------------------------------------------------

typedef struct {  float32  As;  	// Input: phase-a stator variable  
				  float32  Bs;		// Input: phase-b stator variable  
				  float32  Cs;		// Input: phase-b stator variable 
				  float32  Alpha;	// Output: stationary d-axis stator variable 
				  float32  Beta;	// Output: stationary q-axis stator variable 
		 	 	  void  (*calc)();	// Pointer to calculation function
				 } CLARKE;	

//-----------------------------------------------------------------------------
// Define a _handle
//-----------------------------------------------------------------------------
typedef CLARKE *CLARKE_handle;


//-----------------------------------------------------------------------------
// Default initializer for the  Object.
//-----------------------------------------------------------------------------

#define CLARKE_DEFAULTS { 0, \
                          0, \
                          0, \
                          0, \
						  0, \
              			  (void (*)(Uint32))clarke_calc }

//-----------------------------------------------------------------------------
//  Prototypes for the functions in .c                                 
//-----------------------------------------------------------------------------
void clarke_calc(CLARKE_handle);



#endif

//==============================================================
//End of file.
//==============================================================



