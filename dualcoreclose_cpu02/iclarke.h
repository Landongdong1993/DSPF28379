/*
 DESCRIPTION:



 TEST RESULT: Passed the test;

 DESIGNED TIME: 2011-08-21

 DESIGNER: ZhuHongshun

*/



#ifndef iCLARKE_H
#define iCLARKE_H

#include "C28x_FPU_FastRTS.h"

//-----------------------------------------------------------------------------
//  Define the structure of the POSSPEED Object 
//-----------------------------------------------------------------------------

typedef struct {  float32  As;  	// output: phase-a stator variable
				  float32  Bs;		// output: phase-b stator variable
				  float32  Cs;		// output: phase-b stator variable
				  float32  Alpha;	// input: stationary d-axis stator variable
				  float32  Beta;	// input: stationary q-axis stator variable
		 	 	  void  (*calc)();	// Pointer to calculation function
				 } ICLARKE;

//-----------------------------------------------------------------------------
// Define a _handle
//-----------------------------------------------------------------------------
typedef ICLARKE *ICLARKE_handle;


//-----------------------------------------------------------------------------
// Default initializer for the  Object.
//-----------------------------------------------------------------------------

#define ICLARKE_DEFAULTS { 0, \
                          0, \
                          0, \
                          0, \
						  0, \
              			  (void (*)(Uint32))iclarke_calc }

//-----------------------------------------------------------------------------
//  Prototypes for the functions in .c                                 
//-----------------------------------------------------------------------------
void iclarke_calc(ICLARKE_handle);



#endif

//==============================================================
//End of file.
//==============================================================



