


#ifndef IPARK_H
#define IPARK_H

#include "C28x_FPU_FastRTS.h"

//-----------------------------------------------------------------------------
//  Define the structure of the POSSPEED Object 
//-----------------------------------------------------------------------------
typedef struct {  float32  Alpha;  		// Output: stationary d-axis stator variable
				  float32  Beta;		// Output: stationary q-axis stator variable
				  float32  Cos;		// Input: rotating angle (pu)
				  float32  Sin;
				  float32  Ds;			// Input: rotating d-axis stator variable
				  float32  Qs;			// Input: rotating q-axis stator variable
		 	 	  void  (*calc)();	// Pointer to calculation function
				 } IPARK;
				 	 
//-----------------------------------------------------------------------------
// Define a POSSPEED_handle
//-----------------------------------------------------------------------------
typedef IPARK *IPARK_handle;


//-----------------------------------------------------------------------------
// Default initializer for the POSSPEED Object.
//-----------------------------------------------------------------------------
#define IPARK_DEFAULTS {  0, \
                          0, \
                          0, \
                          0, \
                          0, \
						  0, \
              			  (void (*)(Uint32))ipark_calc }
//-----------------------------------------------------------------------------
//  Prototypes for the functions in posspeed.c                                 
//-----------------------------------------------------------------------------
void ipark_calc(IPARK_handle);




#endif

//==============================================================
//End of file.
//==============================================================



