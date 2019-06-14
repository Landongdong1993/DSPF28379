/*
 * park.h
 *
 *  Created on: 23 Jun 2016
 *      Author: e0009082
 */

#ifndef PARK_H_
#define PARK_H_



#include "C28x_FPU_FastRTS.h"

//-----------------------------------------------------------------------------
//  Define the structure of the POSSPEED Object   alpha beta to DQ
//-----------------------------------------------------------------------------
typedef struct {  float32  Alpha;  		// Output: stationary d-axis stator variable
				  float32  Beta;		// Output: stationary q-axis stator variable
				  float32  Cos;		// Input: rotating angle (pu)
				  float32  Sin;
				  float32  Ds;			// Input: rotating d-axis stator variable
				  float32  Qs;			// Input: rotating q-axis stator variable
		 	 	  void  (*calc)();	// Pointer to calculation function
				 } PARK;

//-----------------------------------------------------------------------------
// Define a POSSPEED_handle
//-----------------------------------------------------------------------------
typedef PARK *PARK_handle;


//-----------------------------------------------------------------------------
// Default initializer for the POSSPEED Object.
//-----------------------------------------------------------------------------
#define PARK_DEFAULTS {  0, \
                          0, \
                          0, \
                          0, \
                          0, \
						  0, \
              			  (void (*)(Uint32))park_calc }
//-----------------------------------------------------------------------------
//  Prototypes for the functions in posspeed.c
//-----------------------------------------------------------------------------
void park_calc(PARK_handle);











#endif /* PARK_H_ */
