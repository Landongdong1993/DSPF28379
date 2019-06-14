
#include "F2837xD_device.h"
#include "F2837xD_Examples.h"
#include "svpwm.h"




void svpwm_calc(SVPWM *P)
{
    switch (P->sector){


     case 1:
    	/* EPwm1Regs.DBCTL.bit.POLSEL=3;
    	 EPwm2Regs.DBCTL.bit.POLSEL=0;
    	 EPwm3Regs.DBCTL.bit.POLSEL=3;
    	 EPwm4Regs.DBCTL.bit.POLSEL=0;
    	 EPwm5Regs.DBCTL.bit.POLSEL=3;
    	 EPwm6Regs.DBCTL.bit.POLSEL=0;
    	 EPwm7Regs.DBCTL.bit.POLSEL=3;
    	 EPwm8Regs.DBCTL.bit.POLSEL=0;
    	 EPwm9Regs.DBCTL.bit.POLSEL=3;
    	 EPwm10Regs.DBCTL.bit.POLSEL=0;
    	 EPwm11Regs.DBCTL.bit.POLSEL=3;
    	 EPwm12Regs.DBCTL.bit.POLSEL=0;*/

         EPwm1Regs.AQCTLA.bit.ZRO= AQ_SET;
         EPwm4Regs.AQCTLA.bit.ZRO = AQ_SET;

         EPwm2Regs.AQCTLA.bit.ZRO= AQ_CLEAR;
         EPwm5Regs.AQCTLA.bit.ZRO = AQ_CLEAR;

         EPwm3Regs.AQCTLA.bit.ZRO= AQ_CLEAR;
         EPwm6Regs.AQCTLA.bit.ZRO = AQ_CLEAR;


    	 EPwm1Regs.CMPA.bit.CMPA = t8;     // Set compare A value
    	 EPwm2Regs.CMPA.bit.CMPA = t1;     // Set compare A value
    	 EPwm3Regs.CMPA.bit.CMPA = t7;     // Set compare A value
    	 EPwm4Regs.CMPA.bit.CMPA = t4;     // Set compare A value
    	 EPwm5Regs.CMPA.bit.CMPA = t5;     // Set compare A value
    	 EPwm6Regs.CMPA.bit.CMPA = t3;     // Set compare A value
    	 EPwm7Regs.CMPA.bit.CMPA = t6;     // Set compare A value
    	 EPwm8Regs.CMPA.bit.CMPA = t1;     // Set compare A value
    	 EPwm9Regs.CMPA.bit.CMPA = t7;     // Set compare A value
    	 EPwm10Regs.CMPA.bit.CMPA = t2;     // Set compare A value
    	 EPwm11Regs.CMPA.bit.CMPA = t5;     // Set compare A value
    	 EPwm12Regs.CMPA.bit.CMPA = t3;     // Set compare A value

    	 EPwm1Regs.CMPB.bit.CMPB = t5;     // Set compare A value
    	 EPwm2Regs.CMPB.bit.CMPB = t2;     // Set compare A value
    	 EPwm3Regs.CMPB.bit.CMPB = t8;     // Set compare A value
    	 EPwm4Regs.CMPB.bit.CMPB = t1;     // Set compare A value
    	 EPwm5Regs.CMPB.bit.CMPB = t6;     // Set compare A value
    	 EPwm6Regs.CMPB.bit.CMPB = t4;     // Set compare A value
    	 EPwm7Regs.CMPB.bit.CMPB = t7;     // Set compare A value
    	 EPwm8Regs.CMPB.bit.CMPB = t2;     // Set compare A value
    	 EPwm9Regs.CMPB.bit.CMPB = t8;     // Set compare A value
    	 EPwm10Regs.CMPB.bit.CMPB = t3;     // Set compare A value
    	 EPwm11Regs.CMPB.bit.CMPB = t6;     // Set compare A value
    	 EPwm12Regs.CMPB.bit.CMPB = t4;     // Set compare A value

    	 break;
     case 2 :
         EPwm2Regs.AQCTLA.bit.ZRO= AQ_SET;
         EPwm5Regs.AQCTLA.bit.ZRO = AQ_SET;

         EPwm1Regs.AQCTLA.bit.ZRO= AQ_CLEAR;
         EPwm4Regs.AQCTLA.bit.ZRO = AQ_CLEAR;

         EPwm3Regs.AQCTLA.bit.ZRO= AQ_CLEAR;
         EPwm6Regs.AQCTLA.bit.ZRO = AQ_CLEAR;

    	 EPwm1Regs.CMPA.bit.CMPA = t1;     // Set compare A value
    	 EPwm2Regs.CMPA.bit.CMPA = t8;     // Set compare A value
    	 EPwm3Regs.CMPA.bit.CMPA = t3;     // Set compare A value
    	 EPwm4Regs.CMPA.bit.CMPA = t5;     // Set compare A value
    	 EPwm5Regs.CMPA.bit.CMPA = t4;     // Set compare A value
    	 EPwm6Regs.CMPA.bit.CMPA = t7;     // Set compare A value
    	 EPwm7Regs.CMPA.bit.CMPA = t1;     // Set compare A value
    	 EPwm8Regs.CMPA.bit.CMPA = t6;     // Set compare A value
    	 EPwm9Regs.CMPA.bit.CMPA = t3;     // Set compare A value
    	 EPwm10Regs.CMPA.bit.CMPA = t5;     // Set compare A value
    	 EPwm11Regs.CMPA.bit.CMPA = t2;     // Set compare A value
    	 EPwm12Regs.CMPA.bit.CMPA = t7;     // Set compare A value

    	 EPwm1Regs.CMPB.bit.CMPB = t2;     // Set compare A value
    	 EPwm2Regs.CMPB.bit.CMPB = t5;     // Set compare A value
    	 EPwm3Regs.CMPB.bit.CMPB = t4;     // Set compare A value
    	 EPwm4Regs.CMPB.bit.CMPB = t6;     // Set compare A value
    	 EPwm5Regs.CMPB.bit.CMPB = t1;     // Set compare A value
    	 EPwm6Regs.CMPB.bit.CMPB = t8;     // Set compare A value
    	 EPwm7Regs.CMPB.bit.CMPB = t2;     // Set compare A value
    	 EPwm8Regs.CMPB.bit.CMPB = t7;     // Set compare A value
    	 EPwm9Regs.CMPB.bit.CMPB = t4;     // Set compare A value
    	 EPwm10Regs.CMPB.bit.CMPB = t6;     // Set compare A value
    	 EPwm11Regs.CMPB.bit.CMPB = t3;     // Set compare A value
    	 EPwm12Regs.CMPB.bit.CMPB = t8;     // Set compare A value

         break;
     case 3:
    	/* EPwm1Regs.DBCTL.bit.POLSEL=0;
    	 EPwm2Regs.DBCTL.bit.POLSEL=3;
    	 EPwm3Regs.DBCTL.bit.POLSEL=0;
    	 EPwm4Regs.DBCTL.bit.POLSEL=3;
    	 EPwm5Regs.DBCTL.bit.POLSEL=0;
    	 EPwm6Regs.DBCTL.bit.POLSEL=3;
    	 EPwm7Regs.DBCTL.bit.POLSEL=0;
    	 EPwm8Regs.DBCTL.bit.POLSEL=3;
    	 EPwm9Regs.DBCTL.bit.POLSEL=0;
    	 EPwm10Regs.DBCTL.bit.POLSEL=3;
    	 EPwm11Regs.DBCTL.bit.POLSEL=0;
    	 EPwm12Regs.DBCTL.bit.POLSEL=3;*/

         EPwm2Regs.AQCTLA.bit.ZRO= AQ_SET;
         EPwm5Regs.AQCTLA.bit.ZRO = AQ_SET;

         EPwm1Regs.AQCTLA.bit.ZRO= AQ_CLEAR;
         EPwm4Regs.AQCTLA.bit.ZRO = AQ_CLEAR;

         EPwm3Regs.AQCTLA.bit.ZRO= AQ_CLEAR;
         EPwm6Regs.AQCTLA.bit.ZRO = AQ_CLEAR;

    	 EPwm1Regs.CMPA.bit.CMPA = t3;     // Set compare A value
    	 EPwm2Regs.CMPA.bit.CMPA = t8;     // Set compare A value
    	 EPwm3Regs.CMPA.bit.CMPA = t1;     // Set compare A value
    	 EPwm4Regs.CMPA.bit.CMPA = t7;     // Set compare A value
    	 EPwm5Regs.CMPA.bit.CMPA = t4;     // Set compare A value
    	 EPwm6Regs.CMPA.bit.CMPA = t5;     // Set compare A value
    	 EPwm7Regs.CMPA.bit.CMPA = t3;     // Set compare A value
    	 EPwm8Regs.CMPA.bit.CMPA = t6;     // Set compare A value
    	 EPwm9Regs.CMPA.bit.CMPA = t1;     // Set compare A value
    	 EPwm10Regs.CMPA.bit.CMPA = t7;     // Set compare A value
    	 EPwm11Regs.CMPA.bit.CMPA = t2;     // Set compare A value
    	 EPwm12Regs.CMPA.bit.CMPA = t5;     // Set compare A value

    	 EPwm1Regs.CMPB.bit.CMPB = t4;     // Set compare A value
    	 EPwm2Regs.CMPB.bit.CMPB = t5;     // Set compare A value
    	 EPwm3Regs.CMPB.bit.CMPB = t2;     // Set compare A value
    	 EPwm4Regs.CMPB.bit.CMPB = t8;     // Set compare A value
    	 EPwm5Regs.CMPB.bit.CMPB = t1;     // Set compare A value
    	 EPwm6Regs.CMPB.bit.CMPB = t6;     // Set compare A value
    	 EPwm7Regs.CMPB.bit.CMPB = t4;     // Set compare A value
    	 EPwm8Regs.CMPB.bit.CMPB = t7;     // Set compare A value
    	 EPwm9Regs.CMPB.bit.CMPB = t2;     // Set compare A value
    	 EPwm10Regs.CMPB.bit.CMPB = t8;     // Set compare A value
    	 EPwm11Regs.CMPB.bit.CMPB = t3;     // Set compare A value
    	 EPwm12Regs.CMPB.bit.CMPB = t6;     // Set compare A value

         break;

     case 4:
    	/* EPwm1Regs.DBCTL.bit.POLSEL=3;
    	 EPwm2Regs.DBCTL.bit.POLSEL=0;
    	 EPwm3Regs.DBCTL.bit.POLSEL=3;
    	 EPwm4Regs.DBCTL.bit.POLSEL=0;
    	 EPwm5Regs.DBCTL.bit.POLSEL=3;
    	 EPwm6Regs.DBCTL.bit.POLSEL=0;
    	 EPwm7Regs.DBCTL.bit.POLSEL=3;
    	 EPwm8Regs.DBCTL.bit.POLSEL=0;
    	 EPwm9Regs.DBCTL.bit.POLSEL=3;
    	 EPwm10Regs.DBCTL.bit.POLSEL=0;
    	 EPwm11Regs.DBCTL.bit.POLSEL=3;
    	 EPwm12Regs.DBCTL.bit.POLSEL=0;*/

         EPwm3Regs.AQCTLA.bit.ZRO= AQ_SET;
         EPwm6Regs.AQCTLA.bit.ZRO = AQ_SET;

         EPwm2Regs.AQCTLA.bit.ZRO= AQ_CLEAR;
         EPwm5Regs.AQCTLA.bit.ZRO = AQ_CLEAR;

         EPwm1Regs.AQCTLA.bit.ZRO= AQ_CLEAR;
         EPwm4Regs.AQCTLA.bit.ZRO = AQ_CLEAR;

    	 EPwm1Regs.CMPA.bit.CMPA = t7;     // Set compare A value
    	 EPwm2Regs.CMPA.bit.CMPA = t1;     // Set compare A value
    	 EPwm3Regs.CMPA.bit.CMPA = t8;     // Set compare A value
    	 EPwm4Regs.CMPA.bit.CMPA = t3;     // Set compare A value
    	 EPwm5Regs.CMPA.bit.CMPA = t5;     // Set compare A value
    	 EPwm6Regs.CMPA.bit.CMPA = t4;     // Set compare A value
    	 EPwm7Regs.CMPA.bit.CMPA = t7;     // Set compare A value
    	 EPwm8Regs.CMPA.bit.CMPA = t1;     // Set compare A value
    	 EPwm9Regs.CMPA.bit.CMPA = t6;     // Set compare A value
    	 EPwm10Regs.CMPA.bit.CMPA = t3;     // Set compare A value
    	 EPwm11Regs.CMPA.bit.CMPA = t5;     // Set compare A value
    	 EPwm12Regs.CMPA.bit.CMPA = t2;                                                                                                                                                                                                                   ;     // Set compare A value

    	 EPwm1Regs.CMPB.bit.CMPB = t8;     // Set compare A value
    	 EPwm2Regs.CMPB.bit.CMPB = t2;     // Set compare A value
    	 EPwm3Regs.CMPB.bit.CMPB = t5;     // Set compare A value
    	 EPwm4Regs.CMPB.bit.CMPB = t4;     // Set compare A value
    	 EPwm5Regs.CMPB.bit.CMPB = t6;     // Set compare A value
    	 EPwm6Regs.CMPB.bit.CMPB = t1;     // Set compare A value
    	 EPwm7Regs.CMPB.bit.CMPB = t8;     // Set compare A value
    	 EPwm8Regs.CMPB.bit.CMPB = t2;     // Set compare A value
    	 EPwm9Regs.CMPB.bit.CMPB = t7;     // Set compare A value
    	 EPwm10Regs.CMPB.bit.CMPB = t4;     // Set compare A value
    	 EPwm11Regs.CMPB.bit.CMPB = t6;     // Set compare A value
    	 EPwm12Regs.CMPB.bit.CMPB = t3;     // Set compare A value

    	 break;

       case 5:

           EPwm3Regs.AQCTLA.bit.ZRO= AQ_SET;
           EPwm6Regs.AQCTLA.bit.ZRO = AQ_SET;

           EPwm2Regs.AQCTLA.bit.ZRO= AQ_CLEAR;
           EPwm5Regs.AQCTLA.bit.ZRO = AQ_CLEAR;

           EPwm1Regs.AQCTLA.bit.ZRO= AQ_CLEAR;
           EPwm4Regs.AQCTLA.bit.ZRO = AQ_CLEAR;

      	 EPwm1Regs.CMPA.bit.CMPA = t5;     // Set compare A value
      	 EPwm2Regs.CMPA.bit.CMPA = t3;     // Set compare A value
      	 EPwm3Regs.CMPA.bit.CMPA = t8;     // Set compare A value
      	 EPwm4Regs.CMPA.bit.CMPA = t1;     // Set compare A value
      	 EPwm5Regs.CMPA.bit.CMPA = t7;     // Set compare A value
      	 EPwm6Regs.CMPA.bit.CMPA = t4;     // Set compare A value
      	 EPwm7Regs.CMPA.bit.CMPA = t5;     // Set compare A value
      	 EPwm8Regs.CMPA.bit.CMPA = t3;     // Set compare A value
      	 EPwm9Regs.CMPA.bit.CMPA = t6;     // Set compare A value
      	 EPwm10Regs.CMPA.bit.CMPA = t1;     // Set compare A value
      	 EPwm11Regs.CMPA.bit.CMPA = t7;     // Set compare A value
      	 EPwm12Regs.CMPA.bit.CMPA = t2;     // Set compare A value

      	 EPwm1Regs.CMPB.bit.CMPB = t6;     // Set compare A value
      	 EPwm2Regs.CMPB.bit.CMPB = t4;     // Set compare A value
      	 EPwm3Regs.CMPB.bit.CMPB = t5;     // Set compare A value
      	 EPwm4Regs.CMPB.bit.CMPB = t2;     // Set compare A value
      	 EPwm5Regs.CMPB.bit.CMPB = t8;     // Set compare A value
      	 EPwm6Regs.CMPB.bit.CMPB = t1;     // Set compare A value
      	 EPwm7Regs.CMPB.bit.CMPB = t6;     // Set compare A value
      	 EPwm8Regs.CMPB.bit.CMPB = t4;     // Set compare A value
      	 EPwm9Regs.CMPB.bit.CMPB = t7;     // Set compare A value
      	 EPwm10Regs.CMPB.bit.CMPB = t2;     // Set compare A value
      	 EPwm11Regs.CMPB.bit.CMPB = t8;     // Set compare A value
      	 EPwm12Regs.CMPB.bit.CMPB = t3;     // Set compare A value

	     break;

       case 6:

           EPwm1Regs.AQCTLA.bit.ZRO= AQ_SET;
           EPwm4Regs.AQCTLA.bit.ZRO = AQ_SET;

           EPwm2Regs.AQCTLA.bit.ZRO= AQ_CLEAR;
           EPwm5Regs.AQCTLA.bit.ZRO = AQ_CLEAR;

           EPwm3Regs.AQCTLA.bit.ZRO= AQ_CLEAR;
           EPwm6Regs.AQCTLA.bit.ZRO = AQ_CLEAR;

      	 EPwm1Regs.CMPA.bit.CMPA = t4;     // Set compare A value
      	 EPwm2Regs.CMPA.bit.CMPA = t7;     // Set compare A value
      	 EPwm3Regs.CMPA.bit.CMPA = t1;     // Set compare A value
      	 EPwm4Regs.CMPA.bit.CMPA = t8;     // Set compare A value
      	 EPwm5Regs.CMPA.bit.CMPA = t3;     // Set compare A value
      	 EPwm6Regs.CMPA.bit.CMPA = t5;     // Set compare A value
      	 EPwm7Regs.CMPA.bit.CMPA = t2;     // Set compare A value
      	 EPwm8Regs.CMPA.bit.CMPA = t7;     // Set compare A value
      	 EPwm9Regs.CMPA.bit.CMPA = t1;     // Set compare A value
      	 EPwm10Regs.CMPA.bit.CMPA = t6;     // Set compare A value
      	 EPwm11Regs.CMPA.bit.CMPA = t3;     // Set compare A value
      	 EPwm12Regs.CMPA.bit.CMPA = t5;     // Set compare A value

      	 EPwm1Regs.CMPB.bit.CMPB = t1;     // Set compare A value
      	 EPwm2Regs.CMPB.bit.CMPB = t8;     // Set compare A value
      	 EPwm3Regs.CMPB.bit.CMPB = t2;     // Set compare A value
      	 EPwm4Regs.CMPB.bit.CMPB = t5;     // Set compare A value
      	 EPwm5Regs.CMPB.bit.CMPB = t4;     // Set compare A value
      	 EPwm6Regs.CMPB.bit.CMPB = t6;     // Set compare A value
      	 EPwm7Regs.CMPB.bit.CMPB = t3;     // Set compare A value
      	 EPwm8Regs.CMPB.bit.CMPB = t8;     // Set compare A value
      	 EPwm9Regs.CMPB.bit.CMPB = t2;     // Set compare A value
      	 EPwm10Regs.CMPB.bit.CMPB = t7;     // Set compare A value
      	 EPwm11Regs.CMPB.bit.CMPB = t4;     // Set compare A value
      	 EPwm12Regs.CMPB.bit.CMPB = t6;     // Set compare A value

         break;
       case 7:
      	/* EPwm1Regs.DBCTL.bit.POLSEL=0;
      	 EPwm2Regs.DBCTL.bit.POLSEL=3;
      	 EPwm3Regs.DBCTL.bit.POLSEL=0;
      	 EPwm4Regs.DBCTL.bit.POLSEL=3;
      	 EPwm5Regs.DBCTL.bit.POLSEL=0;
      	 EPwm6Regs.DBCTL.bit.POLSEL=3;
      	 EPwm7Regs.DBCTL.bit.POLSEL=0;
      	 EPwm8Regs.DBCTL.bit.POLSEL=3;
      	 EPwm9Regs.DBCTL.bit.POLSEL=0;
      	 EPwm10Regs.DBCTL.bit.POLSEL=3;
      	 EPwm11Regs.DBCTL.bit.POLSEL=0;
      	 EPwm12Regs.DBCTL.bit.POLSEL=3;*/

           EPwm1Regs.AQCTLA.bit.ZRO= AQ_SET;
           EPwm4Regs.AQCTLA.bit.ZRO = AQ_SET;

           EPwm2Regs.AQCTLA.bit.ZRO= AQ_CLEAR;
           EPwm5Regs.AQCTLA.bit.ZRO = AQ_CLEAR;

           EPwm3Regs.AQCTLA.bit.ZRO= AQ_CLEAR;
           EPwm6Regs.AQCTLA.bit.ZRO = AQ_CLEAR;

      	 EPwm1Regs.CMPA.bit.CMPA = t4;     // Set compare A value
      	 EPwm2Regs.CMPA.bit.CMPA = t5;     // Set compare A value
      	 EPwm3Regs.CMPA.bit.CMPA = t3;     // Set compare A value
      	 EPwm4Regs.CMPA.bit.CMPA = t8;     // Set compare A value
      	 EPwm5Regs.CMPA.bit.CMPA = t1;     // Set compare A value
      	 EPwm6Regs.CMPA.bit.CMPA = t7;     // Set compare A value
      	 EPwm7Regs.CMPA.bit.CMPA = t2;     // Set compare A value
      	 EPwm8Regs.CMPA.bit.CMPA = t5;     // Set compare A value
      	 EPwm9Regs.CMPA.bit.CMPA = t3;     // Set compare A value
      	 EPwm10Regs.CMPA.bit.CMPA = t6;     // Set compare A value
      	 EPwm11Regs.CMPA.bit.CMPA = t1;     // Set compare A value
      	 EPwm12Regs.CMPA.bit.CMPA = t7;     // Set compare A value

      	 EPwm1Regs.CMPB.bit.CMPB = t1;     // Set compare A value
      	 EPwm2Regs.CMPB.bit.CMPB = t6;     // Set compare A value
      	 EPwm3Regs.CMPB.bit.CMPB = t4;     // Set compare A value
      	 EPwm4Regs.CMPB.bit.CMPB = t5;     // Set compare A value
      	 EPwm5Regs.CMPB.bit.CMPB = t2;     // Set compare A value
      	 EPwm6Regs.CMPB.bit.CMPB = t8;     // Set compare A value
      	 EPwm7Regs.CMPB.bit.CMPB = t3;     // Set compare A value
      	 EPwm8Regs.CMPB.bit.CMPB = t6;     // Set compare A value
      	 EPwm9Regs.CMPB.bit.CMPB = t4;     // Set compare A value
      	 EPwm10Regs.CMPB.bit.CMPB = t7;     // Set compare A value
      	 EPwm11Regs.CMPB.bit.CMPB = t2;     // Set compare A value
      	 EPwm12Regs.CMPB.bit.CMPB = t8;     // Set compare A value

    	   break;


       case 8:
        	/* EPwm1Regs.DBCTL.bit.POLSEL=3;
        	 EPwm2Regs.DBCTL.bit.POLSEL=0;
        	 EPwm3Regs.DBCTL.bit.POLSEL=3;
        	 EPwm4Regs.DBCTL.bit.POLSEL=0;
        	 EPwm5Regs.DBCTL.bit.POLSEL=3;
        	 EPwm6Regs.DBCTL.bit.POLSEL=0;
        	 EPwm7Regs.DBCTL.bit.POLSEL=3;
        	 EPwm8Regs.DBCTL.bit.POLSEL=0;
        	 EPwm9Regs.DBCTL.bit.POLSEL=3;
        	 EPwm10Regs.DBCTL.bit.POLSEL=0;
        	 EPwm11Regs.DBCTL.bit.POLSEL=3;
        	 EPwm12Regs.DBCTL.bit.POLSEL=0;*/

           EPwm2Regs.AQCTLA.bit.ZRO= AQ_SET;
           EPwm5Regs.AQCTLA.bit.ZRO = AQ_SET;

           EPwm1Regs.AQCTLA.bit.ZRO= AQ_CLEAR;
           EPwm4Regs.AQCTLA.bit.ZRO = AQ_CLEAR;

           EPwm3Regs.AQCTLA.bit.ZRO= AQ_CLEAR;
           EPwm6Regs.AQCTLA.bit.ZRO = AQ_CLEAR;

      	 EPwm1Regs.CMPA.bit.CMPA = t5;     // Set compare A value
      	 EPwm2Regs.CMPA.bit.CMPA = t4;     // Set compare A value
      	 EPwm3Regs.CMPA.bit.CMPA = t7;     // Set compare A value
      	 EPwm4Regs.CMPA.bit.CMPA = t1;     // Set compare A value
      	 EPwm5Regs.CMPA.bit.CMPA = t8;     // Set compare A value
      	 EPwm6Regs.CMPA.bit.CMPA = t3;     // Set compare A value
      	 EPwm7Regs.CMPA.bit.CMPA = t5;     // Set compare A value
      	 EPwm8Regs.CMPA.bit.CMPA = t2;     // Set compare A value
      	 EPwm9Regs.CMPA.bit.CMPA = t7;     // Set compare A value
      	 EPwm10Regs.CMPA.bit.CMPA = t1;     // Set compare A value
      	 EPwm11Regs.CMPA.bit.CMPA = t6;     // Set compare A value
      	 EPwm12Regs.CMPA.bit.CMPA = t3;     // Set compare A value

      	 EPwm1Regs.CMPB.bit.CMPB = t6;     // Set compare A value
      	 EPwm2Regs.CMPB.bit.CMPB = t1;     // Set compare A value
      	 EPwm3Regs.CMPB.bit.CMPB = t8;     // Set compare A value
      	 EPwm4Regs.CMPB.bit.CMPB = t2;     // Set compare A value
      	 EPwm5Regs.CMPB.bit.CMPB = t5;     // Set compare A value
      	 EPwm6Regs.CMPB.bit.CMPB = t4;     // Set compare A value
      	 EPwm7Regs.CMPB.bit.CMPB = t6;     // Set compare A value
      	 EPwm8Regs.CMPB.bit.CMPB = t3;     // Set compare A value
      	 EPwm9Regs.CMPB.bit.CMPB = t8;     // Set compare A value
      	 EPwm10Regs.CMPB.bit.CMPB = t2;     // Set compare A value
      	 EPwm11Regs.CMPB.bit.CMPB = t7;     // Set compare A value
      	 EPwm12Regs.CMPB.bit.CMPB = t4;     // Set compare A value

    	   break;
       case 9:
           EPwm2Regs.AQCTLA.bit.ZRO= AQ_SET;
           EPwm5Regs.AQCTLA.bit.ZRO = AQ_SET;

           EPwm1Regs.AQCTLA.bit.ZRO= AQ_CLEAR;
           EPwm4Regs.AQCTLA.bit.ZRO = AQ_CLEAR;

           EPwm3Regs.AQCTLA.bit.ZRO= AQ_CLEAR;
           EPwm6Regs.AQCTLA.bit.ZRO = AQ_CLEAR;

      	 EPwm1Regs.CMPA.bit.CMPA = t7;     // Set compare A value
      	 EPwm2Regs.CMPA.bit.CMPA = t4;     // Set compare A value
      	 EPwm3Regs.CMPA.bit.CMPA = t5;     // Set compare A value
      	 EPwm4Regs.CMPA.bit.CMPA = t3;     // Set compare A value
      	 EPwm5Regs.CMPA.bit.CMPA = t8;     // Set compare A value
      	 EPwm6Regs.CMPA.bit.CMPA = t1;     // Set compare A value
      	 EPwm7Regs.CMPA.bit.CMPA = t7;     // Set compare A value
      	 EPwm8Regs.CMPA.bit.CMPA = t2;     // Set compare A value
      	 EPwm9Regs.CMPA.bit.CMPA = t5;     // Set compare A value
      	 EPwm10Regs.CMPA.bit.CMPA = t3;     // Set compare A value
      	 EPwm11Regs.CMPA.bit.CMPA = t6;     // Set compare A value
      	 EPwm12Regs.CMPA.bit.CMPA = t1;     // Set compare A value

      	 EPwm1Regs.CMPB.bit.CMPB = t8;     // Set compare A value
      	 EPwm2Regs.CMPB.bit.CMPB = t1;     // Set compare A value
      	 EPwm3Regs.CMPB.bit.CMPB = t6;     // Set compare A value
      	 EPwm4Regs.CMPB.bit.CMPB = t4;     // Set compare A value
      	 EPwm5Regs.CMPB.bit.CMPB = t5;     // Set compare A value
      	 EPwm6Regs.CMPB.bit.CMPB = t2;     // Set compare A value
      	 EPwm7Regs.CMPB.bit.CMPB = t8;     // Set compare A value
      	 EPwm8Regs.CMPB.bit.CMPB = t3;     // Set compare A value
      	 EPwm9Regs.CMPB.bit.CMPB = t6;     // Set compare A value
      	 EPwm10Regs.CMPB.bit.CMPB = t4;     // Set compare A value
      	 EPwm11Regs.CMPB.bit.CMPB = t7;     // Set compare A value
      	 EPwm12Regs.CMPB.bit.CMPB = t2;     // Set compare A value

    	   break;


       case 10:

           EPwm3Regs.AQCTLA.bit.ZRO= AQ_SET;
           EPwm6Regs.AQCTLA.bit.ZRO = AQ_SET;

           EPwm2Regs.AQCTLA.bit.ZRO= AQ_CLEAR;
           EPwm5Regs.AQCTLA.bit.ZRO = AQ_CLEAR;

           EPwm1Regs.AQCTLA.bit.ZRO= AQ_CLEAR;
           EPwm4Regs.AQCTLA.bit.ZRO = AQ_CLEAR;

      	 EPwm1Regs.CMPA.bit.CMPA = t3;     // Set compare A value
      	 EPwm2Regs.CMPA.bit.CMPA = t5;     // Set compare A value
      	 EPwm3Regs.CMPA.bit.CMPA = t4;     // Set compare A value
      	 EPwm4Regs.CMPA.bit.CMPA = t7;     // Set compare A value
      	 EPwm5Regs.CMPA.bit.CMPA = t1;     // Set compare A value
      	 EPwm6Regs.CMPA.bit.CMPA = t8;     // Set compare A value
      	 EPwm7Regs.CMPA.bit.CMPA = t3;     // Set compare A value
      	 EPwm8Regs.CMPA.bit.CMPA = t5;     // Set compare A value
      	 EPwm9Regs.CMPA.bit.CMPA = t2;     // Set compare A value
      	 EPwm10Regs.CMPA.bit.CMPA = t7;     // Set compare A value
      	 EPwm11Regs.CMPA.bit.CMPA = t1;     // Set compare A value
      	 EPwm12Regs.CMPA.bit.CMPA = t6;     // Set compare A value

      	 EPwm1Regs.CMPB.bit.CMPB = t4;     // Set compare A value
      	 EPwm2Regs.CMPB.bit.CMPB = t6;     // Set compare A value
      	 EPwm3Regs.CMPB.bit.CMPB = t1;     // Set compare A value
      	 EPwm4Regs.CMPB.bit.CMPB = t8;     // Set compare A value
      	 EPwm5Regs.CMPB.bit.CMPB = t2;     // Set compare A value
      	 EPwm6Regs.CMPB.bit.CMPB = t5;     // Set compare A value
      	 EPwm7Regs.CMPB.bit.CMPB = t4;     // Set compare A value
      	 EPwm8Regs.CMPB.bit.CMPB = t6;     // Set compare A value
      	 EPwm9Regs.CMPB.bit.CMPB = t3;     // Set compare A value
      	 EPwm10Regs.CMPB.bit.CMPB = t8;     // Set compare A value
      	 EPwm11Regs.CMPB.bit.CMPB = t2;     // Set compare A value
      	 EPwm12Regs.CMPB.bit.CMPB = t7;     // Set compare A value

         break;

      case 11:
       	 /*EPwm1Regs.DBCTL.bit.POLSEL=0;
       	 EPwm2Regs.DBCTL.bit.POLSEL=3;
       	 EPwm3Regs.DBCTL.bit.POLSEL=0;
       	 EPwm4Regs.DBCTL.bit.POLSEL=3;
       	 EPwm5Regs.DBCTL.bit.POLSEL=0;
       	 EPwm6Regs.DBCTL.bit.POLSEL=3;
       	 EPwm7Regs.DBCTL.bit.POLSEL=0;
       	 EPwm8Regs.DBCTL.bit.POLSEL=3;
       	 EPwm9Regs.DBCTL.bit.POLSEL=0;
       	 EPwm10Regs.DBCTL.bit.POLSEL=3;
       	 EPwm11Regs.DBCTL.bit.POLSEL=0;
       	 EPwm12Regs.DBCTL.bit.POLSEL=3;*/
          EPwm3Regs.AQCTLA.bit.ZRO= AQ_SET;
          EPwm6Regs.AQCTLA.bit.ZRO = AQ_SET;

          EPwm2Regs.AQCTLA.bit.ZRO= AQ_CLEAR;
          EPwm5Regs.AQCTLA.bit.ZRO = AQ_CLEAR;

          EPwm1Regs.AQCTLA.bit.ZRO= AQ_CLEAR;
          EPwm4Regs.AQCTLA.bit.ZRO = AQ_CLEAR;

     	 EPwm1Regs.CMPA.bit.CMPA = t1;     // Set compare A value
     	 EPwm2Regs.CMPA.bit.CMPA = t7;     // Set compare A value
     	 EPwm3Regs.CMPA.bit.CMPA = t4;     // Set compare A value
     	 EPwm4Regs.CMPA.bit.CMPA = t5;     // Set compare A value
     	 EPwm5Regs.CMPA.bit.CMPA = t3;     // Set compare A value
     	 EPwm6Regs.CMPA.bit.CMPA = t8;     // Set compare A value
     	 EPwm7Regs.CMPA.bit.CMPA = t1;     // Set compare A value
     	 EPwm8Regs.CMPA.bit.CMPA = t7;     // Set compare A value
     	 EPwm9Regs.CMPA.bit.CMPA = t2;     // Set compare A value
     	 EPwm10Regs.CMPA.bit.CMPA = t5;     // Set compare A value
     	 EPwm11Regs.CMPA.bit.CMPA = t3;     // Set compare A value
     	 EPwm12Regs.CMPA.bit.CMPA = t6;     // Set compare A value

     	 EPwm1Regs.CMPB.bit.CMPB = t2;     // Set compare A value
     	 EPwm2Regs.CMPB.bit.CMPB = t8;     // Set compare A value
     	 EPwm3Regs.CMPB.bit.CMPB = t1;     // Set compare A value
     	 EPwm4Regs.CMPB.bit.CMPB = t6;     // Set compare A value
     	 EPwm5Regs.CMPB.bit.CMPB = t4;     // Set compare A value
     	 EPwm6Regs.CMPB.bit.CMPB = t5;     // Set compare A value
     	 EPwm7Regs.CMPB.bit.CMPB = t2;     // Set compare A value
     	 EPwm8Regs.CMPB.bit.CMPB = t8;     // Set compare A value
     	 EPwm9Regs.CMPB.bit.CMPB = t3;     // Set compare A value
     	 EPwm10Regs.CMPB.bit.CMPB = t6;     // Set compare A value
     	 EPwm11Regs.CMPB.bit.CMPB = t4;     // Set compare A value
     	 EPwm12Regs.CMPB.bit.CMPB = t7;     // Set compare A value

         break;


      default :
     	/* EPwm1Regs.DBCTL.bit.POLSEL=3;
     	 EPwm2Regs.DBCTL.bit.POLSEL=0;
     	 EPwm3Regs.DBCTL.bit.POLSEL=3;
     	 EPwm4Regs.DBCTL.bit.POLSEL=0;
     	 EPwm5Regs.DBCTL.bit.POLSEL=3;
     	 EPwm6Regs.DBCTL.bit.POLSEL=0;
     	 EPwm7Regs.DBCTL.bit.POLSEL=3;
     	 EPwm8Regs.DBCTL.bit.POLSEL=0;
     	 EPwm9Regs.DBCTL.bit.POLSEL=3;
     	 EPwm10Regs.DBCTL.bit.POLSEL=0;
     	 EPwm11Regs.DBCTL.bit.POLSEL=3;
     	 EPwm12Regs.DBCTL.bit.POLSEL=0;*/

         EPwm1Regs.AQCTLA.bit.ZRO= AQ_SET;
         EPwm4Regs.AQCTLA.bit.ZRO = AQ_SET;

         EPwm2Regs.AQCTLA.bit.ZRO= AQ_CLEAR;
         EPwm5Regs.AQCTLA.bit.ZRO = AQ_CLEAR;

         EPwm3Regs.AQCTLA.bit.ZRO= AQ_CLEAR;
         EPwm6Regs.AQCTLA.bit.ZRO = AQ_CLEAR;


     	 EPwm1Regs.CMPA.bit.CMPA = t8;     // Set compare A value
     	 EPwm2Regs.CMPA.bit.CMPA = t3;     // Set compare A value
     	 EPwm3Regs.CMPA.bit.CMPA = t5;     // Set compare A value
     	 EPwm4Regs.CMPA.bit.CMPA = t4;     // Set compare A value
     	 EPwm5Regs.CMPA.bit.CMPA = t7;     // Set compare A value
     	 EPwm6Regs.CMPA.bit.CMPA = t1;     // Set compare A value
     	 EPwm7Regs.CMPA.bit.CMPA = t6;     // Set compare A value
     	 EPwm8Regs.CMPA.bit.CMPA = t3;     // Set compare A value
     	 EPwm9Regs.CMPA.bit.CMPA = t5;     // Set compare A value
     	 EPwm10Regs.CMPA.bit.CMPA = t2;     // Set compare A value
     	 EPwm11Regs.CMPA.bit.CMPA = t7;     // Set compare A value
     	 EPwm12Regs.CMPA.bit.CMPA = t1;     // Set compare A value

     	 EPwm1Regs.CMPB.bit.CMPB = t5;     // Set compare A value
     	 EPwm2Regs.CMPB.bit.CMPB = t4;     // Set compare A value
     	 EPwm3Regs.CMPB.bit.CMPB = t6;     // Set compare A value
     	 EPwm4Regs.CMPB.bit.CMPB = t1;     // Set compare A value
     	 EPwm5Regs.CMPB.bit.CMPB = t8;     // Set compare A value
     	 EPwm6Regs.CMPB.bit.CMPB = t2;     // Set compare A value
     	 EPwm7Regs.CMPB.bit.CMPB = t7;     // Set compare A value
     	 EPwm8Regs.CMPB.bit.CMPB = t4;     // Set compare A value
     	 EPwm9Regs.CMPB.bit.CMPB = t6;     // Set compare A value
     	 EPwm10Regs.CMPB.bit.CMPB = t3;     // Set compare A value
     	 EPwm11Regs.CMPB.bit.CMPB = t8;     // Set compare A value
     	 EPwm12Regs.CMPB.bit.CMPB = t2;     // Set compare A value

          break;
              }
  }



