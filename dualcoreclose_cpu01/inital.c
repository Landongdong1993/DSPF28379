
#include "F2837xD_device.h"
#include "F2837xD_Examples.h"
#include "svpwm.h"


#define EPWM1_TIMER_TBPRD  3500  // Period register
#define EPWM1_MAX_CMPA     1950
#define EPWM1_MIN_CMPA       50
#define EPWM1_MAX_CMPB     1950
#define EPWM1_MIN_CMPB       50
#define EPWM_CMP_UP           1
#define EPWM_CMP_DOWN         0

extern int delay=0, DBR=0,DBF=0, CMPA1=400,CMPA2=1200,CMPA3=2000,CMPA4=2800,CMPA5=3600,CMPA6=500,CMPB1=800,CMPB2=1600,CMPB3=2400,CMPB4=3200,CMPB5=500,CMPB6=800;
//extern int delay=0, DBR=0,DBF=0, CMPA1=400,CMPA2=1200,CMPA3=1000,CMPA4=1800,CMPA5=1600,CMPA6=500,CMPB1=800,CMPB2=1600,CMPB3=1400,CMPB4=1200,CMPB5=500,CMPB6=800;
//

// InitEPwm - Initialize all EPWM
void InitEPwm1(void);
void InitEPwm2(void);
void InitEPwm3(void);
void InitEPwm4(void);
void InitEPwm5(void);
void InitEPwm6(void);
void InitEPwm7(void);
void InitEPwm8(void);
void InitEPwm9(void);
void InitEPwm10(void);
void InitEPwm11(void);
void InitEPwm12(void);

//
void InitEPwms(void)
{
	   InitEPwm1();
	   InitEPwm2();
	   InitEPwm3();
	   InitEPwm4();
	   InitEPwm5();
	   InitEPwm6();

	   InitEPwm7();
	   InitEPwm8();
	   InitEPwm9();
	   InitEPwm10();
	   InitEPwm11();
	   InitEPwm12();
}

//
// InitEPwm1Gpio - Initialize EPWM1 GPIOs
//
void InitEPwm1(void)
{
	   // Setup TBCLK
	     //
	     EPwm1Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP; // Count up
	     EPwm1Regs.TBPRD = EPWM1_TIMER_TBPRD;       // Set timer period
	     EPwm1Regs.TBCTL.bit.PHSEN = TB_DISABLE;    // Disable phase loading
	     EPwm1Regs.TBPHS.bit.TBPHS = 0x0000;        // Phase is 0
	     EPwm1Regs.TBCTR = 0x0000;                  // Clear counter
	     EPwm1Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;   // Clock ratio to SYSCLKOUT
	     EPwm1Regs.TBCTL.bit.CLKDIV = TB_DIV1;

	     EPwm1Regs.ETSEL.bit.SOCAEN = 1;        // Enable SOC on A group
	     EPwm1Regs.ETSEL.bit.SOCASEL = 2;       //   TBPRD
	     EPwm1Regs.ETPS.bit.SOCAPRD = 1;

	     // Set Compare values
	     //
	     EPwm1Regs.CMPA.bit.CMPA = CMPA1; // Set compare A value
	     //EPwm1Regs.CMPA
	     EPwm1Regs.CMPB.bit.CMPB = CMPB1;    // Set Compare B value

	     //
	     // Set actions
	     //
	     //EPwm1Regs.AQCTLA.bit.ZRO = AQ_SET;            // Set PWM1A on Zero
	     EPwm1Regs.AQCTLA.bit.CAU = AQ_SET;          // Clear PWM1A on event A,
	     EPwm1Regs.AQCTLA.bit.CBU = AQ_CLEAR;                                              // up count

	     EPwm1Regs.AQCTLB.bit.CAU = AQ_SET;            // Set PWM1B on Zero
	     EPwm1Regs.AQCTLB.bit.CBU = AQ_CLEAR;          // Clear PWM1B on event B,
	                                                   // up count
	     //EPwm1Regs.DBCTL.bit.POLSEL=0;
	     //EPwm1Regs.DBCTL.bit.OUT_MODE=3;
	     EPwm1Regs.DBRED.bit.DBRED=DBR;
	     EPwm1Regs.DBFED.bit.DBFED=DBF;

}

//
// InitEPwm2Gpio - Initialize EPWM2 GPIOs
//
void InitEPwm2(void)
{
    EPwm2Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP; // Count up
    EPwm2Regs.TBPRD = EPWM1_TIMER_TBPRD;       // Set timer period
    EPwm2Regs.TBCTL.bit.PHSEN = TB_DISABLE;    // Disable phase loading
    EPwm2Regs.TBPHS.bit.TBPHS = 0x0000;        // Phase is 0
    EPwm2Regs.TBCTR = 0x0000;                  // Clear counter
    EPwm2Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;   // Clock ratio to SYSCLKOUT
    EPwm2Regs.TBCTL.bit.CLKDIV = TB_DIV1;

    // Set Compare values
    //
    EPwm2Regs.CMPA.bit.CMPA = CMPA2; // Set compare A value
    //EPwm1Regs.CMPA
    EPwm2Regs.CMPB.bit.CMPB = CMPB2;    // Set Compare B value

    //
    // Set actions
    //
    //EPwm1Regs.AQCTLA.bit.ZRO = AQ_SET;            // Set PWM1A on Zero
    EPwm2Regs.AQCTLA.bit.CAU = AQ_SET;          // Clear PWM1A on event A,
    EPwm2Regs.AQCTLA.bit.CBU = AQ_CLEAR;                                              // up count

    EPwm2Regs.AQCTLB.bit.CAU = AQ_SET;            // Set PWM1B on Zero
    EPwm2Regs.AQCTLB.bit.CBU = AQ_CLEAR;          // Clear PWM1B on event B,
                                                  // up count

    //EPwm2Regs.DBCTL.bit.POLSEL=0;
    //EPwm2Regs.DBCTL.bit.OUT_MODE=3;
    EPwm2Regs.DBRED.bit.DBRED=DBR;
    EPwm2Regs.DBFED.bit.DBFED=DBF;

    EPwm2Regs.ETSEL.bit.INTSEL = ET_CTR_PRD;       // Select INT on Zero event
     EPwm2Regs.ETSEL.bit.INTEN = 1;                  // Enable INT
     EPwm2Regs.ETPS.bit.INTPRD = ET_2ND;             // Generate INT on 3rd event
}

//
// InitEPwm3Gpio - Initialize EPWM3 GPIOs
//
void InitEPwm3(void)
{
    EPwm3Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP; // Count up
    EPwm3Regs.TBPRD = EPWM1_TIMER_TBPRD;       // Set timer period
    EPwm3Regs.TBCTL.bit.PHSEN = TB_DISABLE;    // Disable phase loading
    EPwm3Regs.TBPHS.bit.TBPHS = 0x0000;        // Phase is 0
    EPwm3Regs.TBCTR = 0x0000;                  // Clear counter
    EPwm3Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;   // Clock ratio to SYSCLKOUT
    EPwm3Regs.TBCTL.bit.CLKDIV = TB_DIV1;


    // Set Compare values
    //
    EPwm3Regs.CMPA.bit.CMPA = CMPA3; // Set compare A value
    //EPwm1Regs.CMPA
    EPwm3Regs.CMPB.bit.CMPB = CMPB3;    // Set Compare B value

    //
    // Set actions
    //
    //EPwm1Regs.AQCTLA.bit.ZRO = AQ_SET;            // Set PWM1A on Zero
    EPwm3Regs.AQCTLA.bit.CAU = AQ_SET;          // Clear PWM1A on event A,
    EPwm3Regs.AQCTLA.bit.CBU = AQ_CLEAR;                                              // up count

    EPwm3Regs.AQCTLB.bit.CAU = AQ_SET;            // Set PWM1B on Zero
    EPwm3Regs.AQCTLB.bit.CBU = AQ_CLEAR;          // Clear PWM1B on event B,

    //EPwm3Regs.DBCTL.bit.POLSEL=0;
    //EPwm3Regs.DBCTL.bit.OUT_MODE=3;
    EPwm3Regs.DBRED.bit.DBRED=DBR;
    EPwm3Regs.DBFED.bit.DBFED=DBF;
}

//
// InitEPwm4Gpio - Initialize EPWM4 GPIOs
//
void InitEPwm4(void)
{
    EPwm4Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP; // Count up
    EPwm4Regs.TBPRD = EPWM1_TIMER_TBPRD;       // Set timer period
    EPwm4Regs.TBCTL.bit.PHSEN = TB_DISABLE;    // Disable phase loading
    EPwm4Regs.TBPHS.bit.TBPHS = 0x0000;        // Phase is 0
    EPwm4Regs.TBCTR = 0x0000;                  // Clear counter
    EPwm4Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;   // Clock ratio to SYSCLKOUT
    EPwm4Regs.TBCTL.bit.CLKDIV = TB_DIV1;


    // Set Compare values
    //
    EPwm4Regs.CMPA.bit.CMPA = CMPA4; // Set compare A value
    //EPwm1Regs.CMPA
    EPwm4Regs.CMPB.bit.CMPB = CMPB4;    // Set Compare B value

    //
    // Set actions
    //
    //EPwm1Regs.AQCTLA.bit.ZRO = AQ_SET;            // Set PWM1A on Zero
    EPwm4Regs.AQCTLA.bit.CAU = AQ_SET;          // Clear PWM1A on event A,
    EPwm4Regs.AQCTLA.bit.CBU = AQ_CLEAR;                                              // up count

    EPwm4Regs.AQCTLB.bit.CAU = AQ_SET;            // Set PWM1B on Zero
    EPwm4Regs.AQCTLB.bit.CBU = AQ_CLEAR;          // Clear PWM1B on event B,

    //EPwm4Regs.DBCTL.bit.POLSEL=0;
    //EPwm4Regs.DBCTL.bit.OUT_MODE=3;
    EPwm4Regs.DBRED.bit.DBRED=DBR;
    EPwm4Regs.DBFED.bit.DBFED=DBF;
}

//
// InitEPwm5Gpio - Initialize EPWM5 GPIOs
//
void InitEPwm5(void)
{
    EPwm5Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP; // Count up
    EPwm5Regs.TBPRD = EPWM1_TIMER_TBPRD;       // Set timer period
    EPwm5Regs.TBCTL.bit.PHSEN = TB_DISABLE;    // Disable phase loading
    EPwm5Regs.TBPHS.bit.TBPHS = 0x0000;        // Phase is 0
    EPwm5Regs.TBCTR = 0x0000;                  // Clear counter
    EPwm5Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;   // Clock ratio to SYSCLKOUT
    EPwm5Regs.TBCTL.bit.CLKDIV = TB_DIV1;



    // Set Compare values
    //
    EPwm5Regs.CMPA.bit.CMPA = CMPA5; // Set compare A value
    //EPwm1Regs.CMPA
    EPwm5Regs.CMPB.bit.CMPB = CMPB5;    // Set Compare B value

    //
    // Set actions
    //
    //EPwm1Regs.AQCTLA.bit.ZRO = AQ_SET;            // Set PWM1A on Zero
    EPwm5Regs.AQCTLA.bit.CAU = AQ_SET;          // Clear PWM1A on event A,
    EPwm5Regs.AQCTLA.bit.CBU = AQ_CLEAR;                                              // up count

    EPwm5Regs.AQCTLB.bit.CAU = AQ_SET;            // Set PWM1B on Zero
    EPwm5Regs.AQCTLB.bit.CBU = AQ_CLEAR;          // Clear PWM1B on event B,

    //EPwm5Regs.DBCTL.bit.POLSEL=0;
    //EPwm5Regs.DBCTL.bit.OUT_MODE=3;
    EPwm5Regs.DBRED.bit.DBRED=DBR;
    EPwm5Regs.DBFED.bit.DBFED=DBF;
}

//
// InitEPwm6Gpio - Initialize EPWM6 GPIOs
//
void InitEPwm6(void)
{
    EPwm6Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP; // Count up
    EPwm6Regs.TBPRD = EPWM1_TIMER_TBPRD;       // Set timer period
    EPwm6Regs.TBCTL.bit.PHSEN = TB_DISABLE;    // Disable phase loading
    EPwm6Regs.TBPHS.bit.TBPHS = 0x0000;        // Phase is 0
    EPwm6Regs.TBCTR = 0x0000;                  // Clear counter
    EPwm6Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;   // Clock ratio to SYSCLKOUT
    EPwm6Regs.TBCTL.bit.CLKDIV = TB_DIV1;



    // Set Compare values
    //
    EPwm6Regs.CMPA.bit.CMPA = CMPA6; // Set compare A value
    //EPwm1Regs.CMPA
    EPwm6Regs.CMPB.bit.CMPB = CMPB6;    // Set Compare B value

    //
    // Set actions
    //
    //EPwm1Regs.AQCTLA.bit.ZRO = AQ_SET;            // Set PWM1A on Zero
    EPwm6Regs.AQCTLA.bit.CAU = AQ_SET;          // Clear PWM1A on event A,
    EPwm6Regs.AQCTLA.bit.CBU = AQ_CLEAR;                                              // up count

    EPwm6Regs.AQCTLB.bit.CAU = AQ_SET;            // Set PWM1B on Zero
    EPwm6Regs.AQCTLB.bit.CBU = AQ_CLEAR;          // Clear PWM1B on event B,

    //EPwm6Regs.DBCTL.bit.POLSEL=0;
    //EPwm6Regs.DBCTL.bit.OUT_MODE=3;
    EPwm6Regs.DBRED.bit.DBRED=DBR;
    EPwm6Regs.DBFED.bit.DBFED=DBF;
}

//
// InitEPwm7Gpio - Initialize EPWM7 GPIOs
//
void InitEPwm7(void)
{
    EPwm7Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP; // Count up
    EPwm7Regs.TBPRD = EPWM1_TIMER_TBPRD;       // Set timer period
    EPwm7Regs.TBCTL.bit.PHSEN = TB_DISABLE;    // Disable phase loading
    EPwm7Regs.TBPHS.bit.TBPHS = 0x0000;        // Phase is 0
    EPwm7Regs.TBCTR = 0x0000;                  // Clear counter
    EPwm7Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;   // Clock ratio to SYSCLKOUT
    EPwm7Regs.TBCTL.bit.CLKDIV = TB_DIV1;



    // Set Compare values
    //
    EPwm7Regs.CMPA.bit.CMPA = CMPA6; // Set compare A value
    //EPwm1Regs.CMPA
    EPwm7Regs.CMPB.bit.CMPB = CMPB6;    // Set Compare B value

    //
    // Set actions
    //
    //EPwm1Regs.AQCTLA.bit.ZRO = AQ_SET;            // Set PWM1A on Zero
    EPwm7Regs.AQCTLA.bit.CAU = AQ_SET;          // Clear PWM1A on event A,
    EPwm7Regs.AQCTLA.bit.CBU = AQ_CLEAR;                                              // up count

    EPwm7Regs.AQCTLB.bit.CAU = AQ_SET;            // Set PWM1B on Zero
    EPwm7Regs.AQCTLB.bit.CBU = AQ_CLEAR;          // Clear PWM1B on event B,

    //EPwm7Regs.DBCTL.bit.POLSEL=0;
    //EPwm7Regs.DBCTL.bit.OUT_MODE=3;
    EPwm7Regs.DBRED.bit.DBRED=DBR;
    EPwm7Regs.DBFED.bit.DBFED=DBF;
}

//
// InitEPwm8Gpio - Initialize EPWM8 GPIOs
//
void InitEPwm8(void)
{
    EPwm8Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP; // Count up
    EPwm8Regs.TBPRD = EPWM1_TIMER_TBPRD;       // Set timer period
    EPwm8Regs.TBCTL.bit.PHSEN = TB_DISABLE;    // Disable phase loading
    EPwm8Regs.TBPHS.bit.TBPHS = 0x0000;        // Phase is 0
    EPwm8Regs.TBCTR = 0x0000;                  // Clear counter
    EPwm8Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;   // Clock ratio to SYSCLKOUT
    EPwm8Regs.TBCTL.bit.CLKDIV = TB_DIV1;



    // Set Compare values
    //
    EPwm8Regs.CMPA.bit.CMPA = CMPA6; // Set compare A value
    //EPwm1Regs.CMPA
    EPwm8Regs.CMPB.bit.CMPB = CMPB6;    // Set Compare B value

    //
    // Set actions
    //
    //EPwm1Regs.AQCTLA.bit.ZRO = AQ_SET;            // Set PWM1A on Zero
    EPwm8Regs.AQCTLA.bit.CAU = AQ_SET;          // Clear PWM1A on event A,
    EPwm8Regs.AQCTLA.bit.CBU = AQ_CLEAR;                                              // up count

    EPwm8Regs.AQCTLB.bit.CAU = AQ_SET;            // Set PWM1B on Zero
    EPwm8Regs.AQCTLB.bit.CBU = AQ_CLEAR;          // Clear PWM1B on event B,

    //EPwm8Regs.DBCTL.bit.POLSEL=0;
    //EPwm8Regs.DBCTL.bit.OUT_MODE=3;
    EPwm8Regs.DBRED.bit.DBRED=DBR;
    EPwm8Regs.DBFED.bit.DBFED=DBF;
}

//
// InitEPwm9Gpio - Initialize EPWM9 GPIOs
//
void InitEPwm9(void)
{
    EPwm9Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP; // Count up
    EPwm9Regs.TBPRD = EPWM1_TIMER_TBPRD;       // Set timer period
    EPwm9Regs.TBCTL.bit.PHSEN = TB_DISABLE;    // Disable phase loading
    EPwm9Regs.TBPHS.bit.TBPHS = 0x0000;        // Phase is 0
    EPwm9Regs.TBCTR = 0x0000;                  // Clear counter
    EPwm9Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;   // Clock ratio to SYSCLKOUT
    EPwm9Regs.TBCTL.bit.CLKDIV = TB_DIV1;



    // Set Compare values
    //
    EPwm9Regs.CMPA.bit.CMPA = CMPA6; // Set compare A value
    //EPwm1Regs.CMPA
    EPwm9Regs.CMPB.bit.CMPB = CMPB6;    // Set Compare B value

    //
    // Set actions
    //
    //EPwm1Regs.AQCTLA.bit.ZRO = AQ_SET;            // Set PWM1A on Zero
    EPwm9Regs.AQCTLA.bit.CAU = AQ_SET;          // Clear PWM1A on event A,
    EPwm9Regs.AQCTLA.bit.CBU = AQ_CLEAR;                                              // up count

    EPwm9Regs.AQCTLB.bit.CAU = AQ_SET;            // Set PWM1B on Zero
    EPwm9Regs.AQCTLB.bit.CBU = AQ_CLEAR;          // Clear PWM1B on event B,

    //EPwm9Regs.DBCTL.bit.POLSEL=0;
    //EPwm9Regs.DBCTL.bit.OUT_MODE=3;
    EPwm9Regs.DBRED.bit.DBRED=DBR;
    EPwm9Regs.DBFED.bit.DBFED=DBF;
}

//
// InitEPwm10Gpio - Initialize EPWM10 GPIOs
//
void InitEPwm10(void)
{
    EPwm10Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP; // Count up
    EPwm10Regs.TBPRD = EPWM1_TIMER_TBPRD;       // Set timer period
    EPwm10Regs.TBCTL.bit.PHSEN = TB_DISABLE;    // Disable phase loading
    EPwm10Regs.TBPHS.bit.TBPHS = 0x0000;        // Phase is 0
    EPwm10Regs.TBCTR = 0x0000;                  // Clear counter
    EPwm10Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;   // Clock ratio to SYSCLKOUT
    EPwm10Regs.TBCTL.bit.CLKDIV = TB_DIV1;



    // Set Compare values
    //
    EPwm10Regs.CMPA.bit.CMPA = CMPA6; // Set compare A value
    //EPwm1Regs.CMPA
    EPwm10Regs.CMPB.bit.CMPB = CMPB6;    // Set Compare B value

    //
    // Set actions
    //
    //EPwm1Regs.AQCTLA.bit.ZRO = AQ_SET;            // Set PWM1A on Zero
    EPwm10Regs.AQCTLA.bit.CAU = AQ_SET;          // Clear PWM1A on event A,
    EPwm10Regs.AQCTLA.bit.CBU = AQ_CLEAR;                                              // up count

    EPwm10Regs.AQCTLB.bit.CAU = AQ_SET;            // Set PWM1B on Zero
    EPwm10Regs.AQCTLB.bit.CBU = AQ_CLEAR;          // Clear PWM1B on event B,

    //EPwm10Regs.DBCTL.bit.POLSEL=0;
    //EPwm10Regs.DBCTL.bit.OUT_MODE=3;
    EPwm10Regs.DBRED.bit.DBRED=DBR;
    EPwm10Regs.DBFED.bit.DBFED=DBF;
}

//
// InitEPwm11Gpio - Initialize EPWM11 GPIOs
//
void InitEPwm11(void)
{
    EPwm11Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP; // Count up
    EPwm11Regs.TBPRD = EPWM1_TIMER_TBPRD;       // Set timer period
    EPwm11Regs.TBCTL.bit.PHSEN = TB_DISABLE;    // Disable phase loading
    EPwm11Regs.TBPHS.bit.TBPHS = 0x0000;        // Phase is 0
    EPwm11Regs.TBCTR = 0x0000;                  // Clear counter
    EPwm11Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;   // Clock ratio to SYSCLKOUT
    EPwm11Regs.TBCTL.bit.CLKDIV = TB_DIV1;



    // Set Compare values
    //
    EPwm11Regs.CMPA.bit.CMPA = CMPA6; // Set compare A value
    //EPwm1Regs.CMPA
    EPwm11Regs.CMPB.bit.CMPB = CMPB6;    // Set Compare B value

    //
    // Set actions
    //
    //EPwm1Regs.AQCTLA.bit.ZRO = AQ_SET;            // Set PWM1A on Zero
    EPwm11Regs.AQCTLA.bit.CAU = AQ_SET;          // Clear PWM1A on event A,
    EPwm11Regs.AQCTLA.bit.CBU = AQ_CLEAR;                                              // up count

    EPwm11Regs.AQCTLB.bit.CAU = AQ_SET;            // Set PWM1B on Zero
    EPwm11Regs.AQCTLB.bit.CBU = AQ_CLEAR;          // Clear PWM1B on event B,

    //EPwm11Regs.DBCTL.bit.POLSEL=0;
    //EPwm11Regs.DBCTL.bit.OUT_MODE=3;
    EPwm11Regs.DBRED.bit.DBRED=DBR;
    EPwm11Regs.DBFED.bit.DBFED=DBF;
}

//
// InitEPwm12Gpio - Initialize EPWM12 GPIOs
//
void InitEPwm12(void)
{
    EPwm12Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP; // Count up
    EPwm12Regs.TBPRD = EPWM1_TIMER_TBPRD;       // Set timer period
    EPwm12Regs.TBCTL.bit.PHSEN = TB_DISABLE;    // Disable phase loading
    EPwm12Regs.TBPHS.bit.TBPHS = 0x0000;        // Phase is 0
    EPwm12Regs.TBCTR = 0x0000;                  // Clear counter
    EPwm12Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;   // Clock ratio to SYSCLKOUT
    EPwm12Regs.TBCTL.bit.CLKDIV = TB_DIV1;



    // Set Compare values
    //
    EPwm12Regs.CMPA.bit.CMPA = CMPA6; // Set compare A value
    //EPwm1Regs.CMPA
    EPwm12Regs.CMPB.bit.CMPB = CMPB6;    // Set Compare B value

    //
    // Set actions
    //
    //EPwm1Regs.AQCTLA.bit.ZRO = AQ_SET;            // Set PWM1A on Zero
    EPwm12Regs.AQCTLA.bit.CAU = AQ_SET;          // Clear PWM1A on event A,
    EPwm12Regs.AQCTLA.bit.CBU = AQ_CLEAR;                                              // up count

    EPwm12Regs.AQCTLB.bit.CAU = AQ_SET;            // Set PWM1B on Zero
    EPwm12Regs.AQCTLB.bit.CBU = AQ_CLEAR;          // Clear PWM1B on event B,

    //EPwm12Regs.DBCTL.bit.POLSEL=0;
    //EPwm12Regs.DBCTL.bit.OUT_MODE=3;
    EPwm12Regs.DBRED.bit.DBRED=DBR;
    EPwm12Regs.DBFED.bit.DBFED=DBF;
}




