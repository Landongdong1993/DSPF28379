/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * svpwm.h
 *
 * Code generation for function 'svpwm'
 *
 */

#ifndef __SVPWM_H__
#define __SVPWM_H__

/* Include files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "svpwm_types.h"

#include "C28x_FPU_FastRTS.h"

//-----------------------------------------------------------------------------
//  Define the structure of the POSSPEED Object
//-----------------------------------------------------------------------------
extern int t1,t2,t3,t4,t5,t6,t7,t8,total,beta,sector,count,si;
//extern double ta,tb,t0,tt;
typedef struct {  double  m;  	// output: phase-a stator variable
				  double  cta;		// output: phase-b stator variable
				  int sector;
		 	 	  void  (*calc)();	// Pointer to calculation function
				 } SVPWM;

//-----------------------------------------------------------------------------
// Define a _handle
//-----------------------------------------------------------------------------
typedef SVPWM *SVPWM_handle;


//-----------------------------------------------------------------------------
// Default initializer for the  Object.
//-----------------------------------------------------------------------------

#define SVPWM_DEFAULTS { 0.5, \
                          0, \
                          1, \
                 	  (void (*)(Uint32))svpwm_calc }

//-----------------------------------------------------------------------------
//  Prototypes for the functions in .c
//-----------------------------------------------------------------------------
void svpwm_calc(SVPWM_handle);



#endif
