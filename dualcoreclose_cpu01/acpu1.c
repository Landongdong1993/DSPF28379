
// Included Files
#include "F28x_Project.h"
#include "C28x_FPU_FastRTS.h"
#include "F2837xD_SWPrioritizedIsrLevels.h"
#include "math.h"
#include "IQmathLib.h"
#include "Solar_F.h"
#include "F2837xD_Device.h"
#include "svpwm.h"

void ConfigureEPWM(void);

SVPWM svm = SVPWM_DEFAULTS;  // define SVM

#define PWM1_INT_ENABLE  1
#define PWM2_INT_ENABLE  1

// Prototype statements for functions found within this file.
__interrupt void epwm2_isr(void);

extern void InitEPwms(void);


// Global variables used in this example
Uint32  EPwm2TimerIntCount;


interrupt void ipc0_isr(void);

float alpha=0,m;//=100000000/2000=50000 Khz 用于计算开关导通时间， 50k是开关周期频率
float ta,tb,t0,tt; // SWITCHING TIME


//int T=4000,t1=200,t2=900,t3=1100,t4=1800,t5=2200,t6=2900,t7=3100,t8=3800,total,beta,sector,count=0,si=0,sm;
//int T=5000,t1=400,t2=750,t3=1750,t4=2100,t5=2900,t6=3250,t7=4250,t8=4600,total,beta,sector,count=0,si=0,sm;
//int T=5556,t1=444,t2=833,t3=1944,t4=2333,t5=3222,t6=3611,t7=4722,t8=5111,total,beta,sector,count=0,si=0,sm;
//int T=4000,t1=400,t2=800,t3=1200,t4=1600,t5=2400,t6=2800,t7=3200,t8=3600,total,beta,sector,count=0,si=0,sm;
int T=3500,t1=150,t2=675,t3=825,t4=1350,t5=1650,t6=2175,t7=2325,t8=2850,total,beta,sector,count=0,si=0,sm;
//int T=2000,t1=100,t2=450,t3=550,t4=900,t5=1100,t6=1450,t7=1550,t8=1900,total,beta,sector,count=0,si=0,sm;
//int T=6000,t1=300,t2=1350,t3=1650,t4=2700,t5=3300,t6=4350,t7=4650,t8=5700,total,beta,sector,count=0,si=0,sm;
//int T=8000,t1=400,t2=1800,t3=2200,t4=3600,t5=4400,t6=5800,t7=6200,t8=7600,total,beta,sector,count=0,si=0,sm;
//int T=10000,t1=500,t2=2250,t3=2750,t4=4500,t5=5500,t6=7250,t7=7750,t8=9500,total,beta,sector,count=0,si=0,sm;
void delay_loop()
{
	si++;
}

void main(void)
{
		     // Step 1. Initialize System Control:

















	InitSysCtrl();
			   EALLOW;
			   ClkCfgRegs.PERCLKDIVSEL.bit.EPWMCLKDIV=0X0;
			   EDIS;
			   EALLOW;
			   CpuSysRegs.PCLKCR0.bit.TBCLKSYNC = 0;      // Stop all the TB clocks
			   EDIS;

			// Step 2. Initalize GPIO:

			   //InitGpio();
			    InitEPwm1Gpio();
			    InitEPwm2Gpio();
			    InitEPwm3Gpio();
			    InitEPwm4Gpio();
			    InitEPwm5Gpio();
			    InitEPwm6Gpio();
			    InitEPwm7Gpio();
			    InitEPwm8Gpio();
			    InitEPwm9Gpio();
			    InitEPwm10Gpio();
			    InitEPwm11Gpio();
			    InitEPwm12Gpio();

			    InitEPwms();

				EALLOW;
				CpuSysRegs.PCLKCR0.bit.TBCLKSYNC = 1;        // Start all the timers synced
				EDIS;
			   //setupGpio();
			   EALLOW;
			   EDIS;
			// Step 3. Clear all interrupts and initialize PIE vector table:
			// Disable CPU interrupts
			   DINT;
			// Initialize the PIE control registers to their de·fault state.
			   InitPieCtrl();
			// Disable CPU interrupts and clear all CPU interrupt flags:
			   IER = 0x0000;
			   IFR = 0x0000;
			// Initialize the PIE vector table with pointers to the shell Interrupt
			   InitPieVectTable();



			    EALLOW;
			    DevCfgRegs.CPUSEL11.bit.ADC_A = 1;
			    DevCfgRegs.CPUSEL11.bit.ADC_B = 1;
			    EDIS;

			   GPIO_SetupPinOptions(34, GPIO_OUTPUT, GPIO_PUSHPULL);
			   GPIO_SetupPinMux(34, GPIO_MUX_CPU2, 0);

			  // GPIO_SetupPinOptions(35, GPIO_OUTPUT, GPIO_PUSHPULL);
			   //GPIO_SetupPinMux(35, GPIO_MUX_CPU1, 0);



			   EALLOW;
			   PieVectTable.EPWM2_INT = &epwm2_isr;//switching happens
			   PieVectTable.IPC0_INT = &ipc0_isr;// IPC1 interrupt
			   EDIS;



			   EPwm2TimerIntCount = 0;

               IpcRegs.IPCCLR.all = 0xFFFFFFFF;

			  IER |= M_INT1;     //开CPU中断1 for cputimertimer 0
			  IER |= M_INT3;        // enable group3 interrupt fpr epwm3

			  PieCtrlRegs.PIEIER3.bit.INTx2 = 1;//EPWM
			  PieCtrlRegs.PIEIER1.bit.INTx13 = 1;	    // IPC1 ISR
			   // Enable global Interrupts and higher priority real-time debug events:
			   EINT;   // Enable Global interrupt INTM
			   ERTM;   // Enable Global realtime interrupt DBGM


//				while (IpcRegs.IPCSTS.bit.IPC17 == 0) ;	// Wait for CPU02 to set IPC17
//				IpcRegs.IPCACK.bit.IPC17 = 1;			// Acknowledge and clear IPC17

			   	m=0.7;
			   	svm.sector=1;

				//t1=250;
				//t2=250;
				//t3=167;
				//t4=333;

			   	while(1)
			   			   {

			   			   }
}




__interrupt void epwm2_isr(void)
{

    // Update the CMPA and CMPB values


    EPwm2TimerIntCount++;

    //GpioDataRegs.GPBTOGGLE.bit.GPIO34 = 1;

     svm.calc(&svm);


    // Clear INT flag for this timer

     EPwm2Regs.ETCLR.bit.INT = 1;

     // Acknowledge this interrupt to receive more interrupts from group 3

     PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
}

interrupt void ipc0_isr(void)
{
	count++;
	 //GpioDataRegs.GPATOGGLE.bit.GPIO13 = 1;
	// Read IPC channel 0 and write to DACB
	svm.sector = (Uint16) IpcRegs.IPCRECVADDR;	// Read data on IPC ADDR register
    sm= IpcRegs.IPCRECVCOM;	// Read data on IPC com register
    beta=(Uint16) IpcRegs.IPCRECVDATA;	// Read data on IPC data register
    //m=(float)sm*0.01;
	tb= m*sin(beta*0.0175)*T;//tb = m*sin(alpha*6.283/360)*T;
	ta= m * sin(1.05-beta*0.0175 )*T;//ta = m * cos(alpha*6.283/360 + 0.52359877559829882)*T;
	//t0 = T - ta - tb;
  if(ta<100)
    {ta=100;}
	if(tb<100)
	{tb=100;}
	if(ta>3000)
	    {ta=3000;}
		if(tb>3000)
		{tb=3000;}

		  if(svm.sector%2==1)
		    {

			 GpioDataRegs.GPBCLEAR.bit.GPIO35=1;
		    }

   if(svm.sector%2==0)
    {
	 t0=ta;
	 ta=tb;
	 tb=t0;
	 GpioDataRegs.GPBSET.bit.GPIO35=1;
    }

    t0 = T - ta - tb;



	t1=ta*0.25;
	t2=t1+tb*0.25;
	t3=t2+t0*0.5;
	t4=t3+tb*0.25;
	t5=t4+ta*0.5;
	t6=t5+tb*0.25;
	t7=t6+t0*0.5;
	t8=t7+tb*0.25;



	// Return from interrupt
	IpcRegs.IPCACK.bit.IPC0 = 1;				// Clear IPC1 bit
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;		// Acknowledge PIE group 1 to enable further interrupts
}
