// Included Files
#include "F28x_Project.h"
#include "C28x_FPU_FastRTS.h"
#include "F2837xD_SWPrioritizedIsrLevels.h"
#include "math.h"
#include "IQmathLib.h"
#include "Solar_F.h"
#include "F2837xD_Adc.h"
#include "F2837xD_Device.h"
#include <math.h>
#include "ipark.h"
#include "ADC_volt_current_get.h"
//
// Function Prototypes
//
void ConfigureADC(void);
interrupt void adca1_isr(void);

long int thetaarray[400];
long int icarray[400];
Uint16 strcnt=0;

ABC_DQ0_POS_F abc_dq0_pos1,abc_dq0_pos2,abc_dq0_pos3; // ABC TO DQ transformation
SPLL_3ph_SRF_F spll1,spll2;

IPARK  Udq_to_Ualphabeta = IPARK_DEFAULTS; //反Park变换：电压ud uq向uα uβ变换对应的结构体变量

float PI_out_dframe[2]={0.0,0.0};//PI value register
float PI_out_qframe[2]={0.0,0.0};

float PI_out_dc[2]={0.0,0.0};//PI value register


float dq_A_0; //First order hold : Kp[(Wpi*T_sample/2)+1]  kp=3.118 T=kp/Ki= 6.48e-5
float dq_A_1; //First order hold : Kp[(Wpi*T_sample/2)-1]   kp=3.118 T=kp/Ki= 6.48e-5
float dc_A_0; //First order hold : Kp[(Wpi*T_sample/2)+1]  kp=3.118 T=kp/Ki= 6.48e-5
float dc_A_1; //First order hold : Kp[(Wpi*T_sample/2)-1]   kp=3.118 T=kp/Ki= 6.48e-5

float I_d_err[2]={0.0,0.0};
float I_q_err[2]={0.0,0.0};

float V_dc_err[2]={0.0,0.0};


float dq_K_p=0.001;
float dq_K_i=5;

float dc_K_p=0.0017;
float dc_K_i=1;

float I_d_ref= 0.5;
float I_q_ref= 0.5;

float V_dc_ref=5;
int I,sector=1;

float alpha=0,mm,thetata=0,THETA;//=75000000/1500=50000 Khz 用于计算开关导通时间， 50k是开关周期频率
int kx=0,im, angle,angle1,acount=0,flag=0,count=0,tcount=0;

float xd=0.1,xq=0.1,vd=0,vq=0,k2=1.5166,w0=1.044,w1=3.5473E-4,w2=1.7717E-4,w3=4.7E-7,Ro=50,x,y,Vdc=10;
ADC_VOLT_CURRENT_GET  Volt_current ;

//******For internal sine wave*****//

int state=0,i=0;
float t=0,cc=0;
float k=0.8;
float sine_test;
float T_s=2.0000e-05;//1/50000;

float V_a,V_b,V_c ;   // phase voltages

float theta=0.0,theta1=0.0;
float V_d,V_q,Vc_d,Vc_q,I_d,I_q;


void adcsetup();

void main(void)
{


		     // Step 1. Initialize System Control:
			   InitSysCtrl();
			// Step 2. Initalize GPIO:
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

			   ConfigureADC();
               adcsetup();
			   // sync ePWM
			   EALLOW;
			   CpuSysRegs.PCLKCR0.bit.TBCLKSYNC = 1;
			   EDIS;


			   EALLOW;
			   //PieVectTable.TIMER0_INT=&cpu_timer0_isr;//triger ADC
			   PieVectTable.ADCA1_INT=&adca1_isr;
			   EDIS;



			   //CpuTimer0Regs.TCR.all = 0x4001; // Use write-only instruction to set TSS bit = 0
              // startCpuTimer0();
			   //IER |= M_INT7 ;
			  // PieCtrlRegs.PIEIER7.bit.INTx1 = 1;     //使能PIE模块中的CPU定时器0的中断
			   PieCtrlRegs.PIEIER1.bit.INTx7 = 1;		// ADC interrupt
			   PieCtrlRegs.PIEIER1.bit.INTx1 = 1;

			   IpcRegs.IPCCLR.bit.IPC2 = 1;
			   PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;

			// Enable global interrupts and higher priority real-time debug events:
				IER |= M_INT1; 						// Enable group 1 interrupts
				EINT;       						// Enable Global interrupt INTM
				ERTM;   							// Enable Global real-time interrupt DBGM

			// Let CPU1 know that CPU2 is ready
				//IpcRegs.IPCSET.bit.IPC17 = 1;		// Set IPC17 to release CPU1

			   // Enable global Interrupts and higher priority real-time debug events:




			     	// Clear Table


			    ABC_DQ0_POS_F_init(&abc_dq0_pos1);
			   	ABC_DQ0_POS_F_init(&abc_dq0_pos2);
			   	ABC_DQ0_POS_F_init(&abc_dq0_pos3);
			   	SPLL_3ph_SRF_F_init(400,((float)(T_s)),&spll1);

			   	for (i=0;i<400;)
			   	{i++;

			   	thetaarray[i]=0;}


			   	while(1)
			   			   {

			   			   }
}





// ConfigureADC - Write ADC configurations and power up the ADC for both
//                ADC A and ADC B
//
void ConfigureADC(void)
{
    EALLOW;
    //write configurations
    //
    AdcaRegs.ADCCTL2.bit.PRESCALE = 6; //set ADCCLK divider to /4
    AdcbRegs.ADCCTL2.bit.PRESCALE = 6; //set ADCCLK divider to /4
    AdcSetMode(ADC_ADCA, ADC_RESOLUTION_12BIT, ADC_SIGNALMODE_SINGLE);
    AdcSetMode(ADC_ADCB, ADC_RESOLUTION_12BIT, ADC_SIGNALMODE_SINGLE);

    //
    //Set pulse positions to late
    //
    AdcaRegs.ADCCTL1.bit.INTPULSEPOS = 1;
    AdcbRegs.ADCCTL1.bit.INTPULSEPOS = 1;
    //
    //power up the ADC
    //
    AdcaRegs.ADCCTL1.bit.ADCPWDNZ = 1;
    AdcbRegs.ADCCTL1.bit.ADCPWDNZ = 1;

    //
    //delay for 1ms to allow ADC time to power up
    //

    EDIS;
}
void adcsetup(void)
{
    Uint16 acqps;

    //
    //determine minimum acquisition window (in SYSCLKS) based on resolution
    //
    if(ADC_RESOLUTION_12BIT == AdcaRegs.ADCCTL2.bit.RESOLUTION)
    {
        //acqps = 14; //75ns
        acqps = 14; //75ns
    }
    else //resolution is 16-bit
    {
        acqps = 63; //320ns
    }

    //
    //Select the channels to convert and end of conversion flag
    //ADCA
    //
    EALLOW;
    AdcaRegs.ADCSOC0CTL.bit.CHSEL = 0;  //SOC0 will convert pin A0
    AdcaRegs.ADCSOC0CTL.bit.TRIGSEL = 5;
    AdcaRegs.ADCSOC0CTL.bit.ACQPS = acqps; //sample window is acqps +
                                           //1 SYSCLK cycles


    AdcaRegs.ADCSOC1CTL.bit.CHSEL = 1;  //SOC1 will convert pin A1
    AdcaRegs.ADCSOC1CTL.bit.TRIGSEL = 5;
    AdcaRegs.ADCSOC1CTL.bit.ACQPS = acqps; //sample window is acqps +
                                           //1 SYSCLK cycles
    AdcaRegs.ADCSOC2CTL.bit.CHSEL = 2;  //SOC0 will convert pin A0
    AdcaRegs.ADCSOC2CTL.bit.TRIGSEL = 5;
    AdcaRegs.ADCSOC2CTL.bit.ACQPS = acqps; //sample window is acqps +
                                              //1 SYSCLK cycles
    AdcaRegs.ADCSOC3CTL.bit.CHSEL = 3;  //SOC1 will convert pin A1
    AdcaRegs.ADCSOC3CTL.bit.TRIGSEL = 5;
    AdcaRegs.ADCSOC3CTL.bit.ACQPS = acqps; //sample window is acqps +
                                              //1 SYSCLK cycles
    AdcaRegs.ADCSOC4CTL.bit.CHSEL = 4;  //SOC0 will convert pin A0
    AdcaRegs.ADCSOC4CTL.bit.TRIGSEL = 5;
    AdcaRegs.ADCSOC4CTL.bit.ACQPS = acqps; //sample window is acqps +
                                              //1 SYSCLK cycles
    AdcaRegs.ADCSOC5CTL.bit.CHSEL = 5;  //SOC1 will convert pin A1
    AdcaRegs.ADCSOC5CTL.bit.TRIGSEL = 5;
    AdcaRegs.ADCSOC5CTL.bit.ACQPS = acqps; //sample window is acqps +
                                              //1 SYSCLK cycles
    AdcaRegs.ADCINTSEL1N2.bit.INT1SEL = 1; //end of SOC1 will set INT1 flag
    AdcaRegs.ADCINTSEL1N2.bit.INT1E = 1;   //enable INT1 flag
    AdcaRegs.ADCINTFLGCLR.bit.ADCINT1 = 1; //make sure INT1 flag is cleared
    //ADCB
    AdcbRegs.ADCSOC0CTL.bit.CHSEL = 0;  //SOC0 will convert pin B0
    AdcbRegs.ADCSOC0CTL.bit.TRIGSEL = 5;
    AdcbRegs.ADCSOC0CTL.bit.ACQPS = acqps; //sample window is acqps +
                                           //1 SYSCLK cycles
    AdcbRegs.ADCSOC1CTL.bit.CHSEL = 1;  //SOC1 will convert pin B1
    AdcbRegs.ADCSOC1CTL.bit.TRIGSEL = 5;
    AdcbRegs.ADCSOC1CTL.bit.ACQPS = acqps; //sample window is acqps +
                                           //1 SYSCLK cycles
    AdcbRegs.ADCSOC2CTL.bit.CHSEL = 2;  //SOC0 will convert pin B0
    AdcbRegs.ADCSOC2CTL.bit.TRIGSEL = 5;
    AdcbRegs.ADCSOC2CTL.bit.ACQPS = acqps; //sample window is acqps +
                                           //1 SYSCLK cycles
    AdcbRegs.ADCSOC3CTL.bit.CHSEL = 3;  //SOC0 will convert pin B0
    AdcbRegs.ADCSOC3CTL.bit.TRIGSEL = 5;
    AdcbRegs.ADCSOC3CTL.bit.ACQPS = acqps; //sample window is acqps +
                                           //1 SYSCLK cycles


    AdcbRegs.ADCINTSEL1N2.bit.INT1SEL = 1; //end of SOC1 will set INT1 flag
    AdcbRegs.ADCINTSEL1N2.bit.INT1E = 1;   //enable INT1 flag
    AdcbRegs.ADCINTFLGCLR.bit.ADCINT1 = 1; //make sure INT1 flag is cleared
    EDIS;
}
// ConfigureEPWM - Configure EPWM SOC and compare values

// adca1_isr - Read ADC Buffer in ISR
//
interrupt void adca1_isr(void)
{

   if(Volt_current.Ic>=0)
    {
	GpioDataRegs.GPBSET.bit.GPIO34 = 1;}
    if(Volt_current.Ic<0)
    {GpioDataRegs.GPBCLEAR.bit.GPIO34 = 1;}

   //GpioDataRegs.GPBTOGGLE.bit.GPIO34 = 1;

    EINT;

    IER &=0xefff;









       V_a_x[0]= (AdcaResultRegs.ADCRESULT0-V_aoff)*volt_gain_ac;	// store results global
	V_a_y[0] = V_a_b[0]*V_a_x[0] + V_a_b[1]*V_a_x[1] + V_a_b[2]*V_a_x[2] + V_a_b[3]*V_a_x[3] - V_a_a[1]*V_a_y[1] - V_a_a[2]*V_a_y[2] - V_a_a[3]*V_a_y[3]; //transfer function

	Volt_current.Ua= V_a_y[0];   //Final value assignment
	V_a_x[3] = V_a_x[2]; V_a_x[2] = V_a_x[1]; V_a_x[1] = V_a_x[0]; V_a_y[3] = V_a_y[2];V_a_y[2] = V_a_y[1];	V_a_y[1] = V_a_y[0]; //Previous values
	// My voltage sensing circuit offset=1640  - B phase sensing

	V_b_x[0] = (AdcaResultRegs.ADCRESULT1-V_boff)*volt_gain_ac;	// store results global
	V_b_y[0] = V_b_b[0]*V_b_x[0] + V_b_b[1]*V_b_x[1] + V_b_b[2]*V_b_x[2] + V_b_b[3]*V_b_x[3] - V_b_a[1]*V_b_y[1] - V_b_a[2]*V_b_y[2] - V_b_a[3]*V_b_y[3]; //transfer function
	Volt_current.Ub= V_b_y[0];  //Final value assignment
	V_b_x[3] = V_b_x[2]; V_b_x[2] = V_b_x[1]; V_b_x[1] = V_b_x[0]; V_b_y[3] = V_b_y[2];V_b_y[2] = V_b_y[1];	V_b_y[1] = V_b_y[0]; //Previous values

// My voltage sensing circuit offset=1640  - C phase sensing
	V_c_x[0] = (AdcaResultRegs.ADCRESULT2-V_coff)*volt_gain_ac;	// store results global
	V_c_y[0] = V_c_b[0]*V_c_x[0] + V_c_b[1]*V_c_x[1] + V_c_b[2]*V_c_x[2] + V_c_b[3]*V_c_x[3] - V_c_a[1]*V_c_y[1] - V_c_a[2]*V_c_y[2] - V_c_a[3]*V_c_y[3]; //transfer function
	Volt_current.Uc= V_c_y[0]; //Final value assignment
    V_c_x[3] = V_c_x[2]; V_c_x[2] = V_c_x[1]; V_c_x[1] = V_c_x[0]; V_c_y[3] = V_c_y[2];V_c_y[2] = V_c_y[1];	V_c_y[1] = V_c_y[0]; //Previous values
	//Ac Voltage sensing after filter***************

 	// My voltage sensing circuit offset=1640  - A phase sensing
   /* Vc_a_x[0] = (AdcbResultRegs.ADCRESULT0-Vc_aoff)*volt_gain_ac;	// store results global

		Vc_a_y[0] = Vc_a_b[0]*Vc_a_x[0] + Vc_a_b[1]*Vc_a_x[1] + Vc_a_b[2]*Vc_a_x[2] + Vc_a_b[3]*Vc_a_x[3] - Vc_a_a[1]*Vc_a_y[1] - Vc_a_a[2]*Vc_a_y[2] - Vc_a_a[3]*Vc_a_y[3];
	 Volt_current.Uca=Vc_a_y[0];//Final value assignment
	 Vc_a_x[3] = Vc_a_x[2]; Vc_a_x[2] = Vc_a_x[1]; Vc_a_x[1] = Vc_a_x[0]; Vc_a_y[3] = Vc_a_y[2];Vc_a_y[2] = Vc_a_y[1];	Vc_a_y[1] = Vc_a_y[0]; //Previous values
	 // My voltage sensing circuit offset=1640  - B phase sensing
	 Vc_b_x[0]= (AdcbResultRegs.ADCRESULT1-Vc_boff)*volt_gain_ac;	// store results global

	 		Vc_b_y[0] = Vc_b_b[0]*Vc_b_x[0] + Vc_b_b[1]*Vc_b_x[1] + Vc_b_b[2]*Vc_b_x[2] + Vc_b_b[3]*Vc_b_x[3] - Vc_b_a[1]*Vc_b_y[1] - Vc_b_a[2]*Vc_b_y[2] - Vc_b_a[3]*Vc_b_y[3];
	 Volt_current.Ucb=Vc_b_y[0]; //Final value assignment
	 Vc_b_x[3] = Vc_b_x[2]; Vc_b_x[2] = Vc_b_x[1]; Vc_b_x[1] = Vc_b_x[0]; Vc_b_y[3] = Vc_b_y[2];Vc_b_y[2] = Vc_b_y[1];	Vc_b_y[1] = Vc_b_y[0]; //Previous values
	 // My voltage sensing circuit offset=1640  - C phase sensing
	 Vc_c_x[0] = (AdcbResultRegs.ADCRESULT2-Vc_coff)*volt_gain_ac;	// store results global

	 Vc_c_y[0] = Vc_c_b[0]*Vc_c_x[0] + Vc_c_b[1]*Vc_c_x[1] + Vc_c_b[2]*Vc_c_x[2] + Vc_c_b[3]*Vc_c_x[3] - Vc_c_a[1]*Vc_c_y[1] - Vc_c_a[2]*Vc_c_y[2] - Vc_c_a[3]*Vc_c_y[3];
	Volt_current.Ucc=Vc_c_y[0]; //Final value assignment
	Vc_c_x[3] = Vc_c_x[2]; Vc_c_x[2] = Vc_c_x[1]; Vc_c_x[1] = Vc_c_x[0]; Vc_c_y[3] = Vc_c_y[2];Vc_c_y[2] = Vc_c_y[1];	Vc_c_y[1] = Vc_c_y[0]; //Previous values*/


	 // My Current sensing circuit offset=2260  - A phase sensing
	   I_a_x[0] = (AdcbResultRegs.ADCRESULT0-I_aoff)*current_gain;

	 			I_a_y[0] = I_a_b[0]*I_a_x[0] + I_a_b[1]*I_a_x[1] + I_a_b[2]*I_a_x[2] + I_a_b[3]*I_a_x[3] - I_a_a[1]*I_a_y[1] - I_a_a[2]*I_a_y[2] - I_a_a[3]*I_a_y[3];
      Volt_current.Ia=I_a_y[0]; //Final value assignment
      I_a_x[3] = I_a_x[2]; I_a_x[2] = I_a_x[1]; I_a_x[1] = I_a_x[0]; I_a_y[3] = I_a_y[2];I_a_y[2] = I_a_y[1];	I_a_y[1] = I_a_y[0]; //Previous values
     // My Current sensing circuit offset=2260  - B phase sensing

      I_b_x[0] = (AdcbResultRegs.ADCRESULT1-I_boff)*current_gain;

	 			I_b_y[0] = I_b_b[0]*I_b_x[0] + I_b_b[1]*I_b_x[1] + I_b_b[2]*I_b_x[2] + I_b_b[3]*I_b_x[3] - I_b_a[1]*I_b_y[1] - I_b_a[2]*I_b_y[2] - I_b_a[3]*I_b_y[3];
     Volt_current.Ib=I_b_y[0]; //Final value assignment
     I_b_x[3] = I_b_x[2]; I_b_x[2] = I_b_x[1]; I_b_x[1] = I_b_x[0]; I_b_y[3] = I_b_y[2];I_b_y[2] = I_b_y[1];	I_b_y[1] = I_b_y[0]; //Previous values

     // My Current sensing circuit offset=2260  - C phase sensing
     I_c_x[0] = (AdcbResultRegs.ADCRESULT2-I_coff)*current_gain;
	 I_c_y[0] = I_c_b[0]*I_c_x[0] + I_c_b[1]*I_c_x[1] + I_c_b[2]*I_c_x[2] + I_c_b[3]*I_c_x[3] - I_c_a[1]*I_c_y[1] - I_c_a[2]*I_c_y[2] - I_c_a[3]*I_c_y[3];
    Volt_current.Ic=I_c_y[0]; //Final value assignment
    I_c_x[3] = I_c_x[2]; I_c_x[2] = I_c_x[1]; I_c_x[1] = I_c_x[0]; I_c_y[3] = I_c_y[2];I_c_y[2] = I_c_y[1];	I_c_y[1] = I_c_y[0]; //Previous values


	 // My Voltage sensing circuit offset=1530  - DC bus sensing
    Volt_current.Vdc =(AdcbResultRegs.ADCRESULT3-V_dcoff)*volt_gain_dc;

	//if(abs(V_dc_x[0]-V_dc_x[1])>5)
	//{V_dc_x[0]=V_dc_x[1];}
	//V_dc_y[0] = V_dc_b[0]*V_dc_x[0] + V_dc_b[1]*V_dc_x[1] + V_dc_b[2]*V_dc_x[2] + V_dc_b[3]*V_dc_x[3] - V_dc_a[1]*V_dc_y[1] - V_dc_a[2]*V_dc_y[2] - V_dc_a[3]*V_dc_y[3]; //transfer function
	//V_dc_x[3] = V_dc_x[2]; V_dc_x[2] = V_dc_x[1]; V_dc_x[1] = V_dc_x[0]; V_dc_y[3] = V_dc_y[2];V_dc_y[2] = V_dc_y[1];	V_dc_y[1] = V_dc_y[0];

	//Volt_current.Vdc=(V_dc_y[0]+V_dc_y[1]+V_dc_y[2]+V_dc_y[3])/4;



 //input voltage transformation
abc_dq0_pos1.a=Volt_current.Ua;
abc_dq0_pos1.b=Volt_current.Ub;
abc_dq0_pos1.c=Volt_current.Uc;
abc_dq0_pos1.sin = (float)sin((spll1.theta[1]));
abc_dq0_pos1.cos = (float)cos((spll1.theta[1]));


ABC_DQ0_POS_F_FUNC(&abc_dq0_pos1);// three phase input voltage transfomation

V_d=abc_dq0_pos1.d;
V_q=abc_dq0_pos1.q;
//3phase PLL
spll1.v_q[0] = (abc_dq0_pos1.q);

SPLL_3ph_SRF_F_FUNC(&spll1); // initilization is done in the main function, only q information is need for calculation

theta=spll1.theta[1];
/*

//Volt_current.Ua;
//ibarray[strcnt]=Volt_current.Ib;
icarray[strcnt]=Volt_current.Ic;
// thetaarray[strcnt]=Volt_current.Ua;
if(strcnt>399)
 {
	 strcnt=0;
 }
 else if(strcnt<400)
 {
	 //thetaarray[strcnt]=(long int)(sector);
	 // vaarray[strcnt]=(long int)(Volt_current.Ua);
	 icarray[strcnt]=(long int)(Volt_current.Ic);
	 strcnt=strcnt+1;
 }

if (flag==0)

{ theta=spll1.theta[1];}

if (abs(spll1.theta[1]-3.14)<=0.05)
      {flag=1;}
else
{flag=0;}*/




 //cap voltage transformation
/*abc_dq0_pos2.a=Volt_current.Uca;
abc_dq0_pos2.b=Volt_current.Ucb;
abc_dq0_pos2.c=Volt_current.Ucc;
abc_dq0_pos2.sin = (float)sin(theta);
abc_dq0_pos2.cos = (float)cos(theta);

ABC_DQ0_POS_F_FUNC(&abc_dq0_pos2);// three phase capacitor voltage transfomation

Vc_d=abc_dq0_pos2.d;
Vc_q=abc_dq0_pos2.q;*/







 //input current transformation
		abc_dq0_pos3.a=Volt_current.Ia;
		abc_dq0_pos3.b=Volt_current.Ib;
		abc_dq0_pos3.c=Volt_current.Ic;
		abc_dq0_pos3.sin = (float)sin(theta);
		abc_dq0_pos3.cos = (float)cos(theta);


			ABC_DQ0_POS_F_FUNC(&abc_dq0_pos3); // three phase input current transfomation


		  I_d=abc_dq0_pos3.d;
		  I_q=abc_dq0_pos3.q;




		/*	V_dc_err[0]=V_dc_ref-Volt_current.Vdc;

			  dc_A_0=dc_K_p*(((dc_K_i*T_s)/(2*dc_K_p))+1);
			  dc_A_1=dc_K_p*(((dc_K_i*T_s)/(2*dc_K_p))-1);

			  	  		PI_out_dc[0]=(dc_A_0*V_dc_err[0])+(dc_A_1*V_dc_err[1])+PI_out_dc[1];

			  	  		if(PI_out_dc[0]>10.0) PI_out_dc[0]=10.0; if(PI_out_dc[0]<(-10.0)) PI_out_dc[0]=-10.0;

			  	  		V_dc_err[1]=V_dc_err[0]; PI_out_dc[1]=PI_out_dc[0];



			  	  	I_d_ref=(PI_out_dc[1]+PI_out_dc[0])/2;*/

			  I_d_err[0]=I_d_ref-I_d; I_q_err[0]=I_q_ref-I_q;

			  dq_A_0=dq_K_p*(((dq_K_i*T_s)/(2*dq_K_p))+1);
			  dq_A_1=dq_K_p*(((dq_K_i*T_s)/(2*dq_K_p))-1);

			  	  		PI_out_dframe[0]=(dq_A_0*I_d_err[0])+(dq_A_1*I_d_err[1])+PI_out_dframe[1];

			  	  		if(PI_out_dframe[0]>10) PI_out_dframe[0]=10; if(PI_out_dframe[0]<(-10)) PI_out_dframe[0]=-10;

			  	  		I_d_err[1]=I_d_err[0]; PI_out_dframe[1]=PI_out_dframe[0];


			  	  		PI_out_qframe[0]=(dq_A_0*I_q_err[0])+(dq_A_1*I_q_err[1])+PI_out_qframe[1];

			  	  		if(PI_out_qframe[0]>10) PI_out_qframe[0]=10; if(PI_out_qframe[0]<0) PI_out_qframe[0]=0;

			  	  		I_q_err[1]=I_q_err[0]; PI_out_qframe[1]=PI_out_qframe[0];




			        //xd=k2* PI_out_dframe[1] -k2*abc_dq0_pos3.d +w0*abc_dq0_pos3.d +w1*abc_dq0_pos2.q-w2*abc_dq0_pos1.q;
			  	// xq=k2* PI_out_qframe[1] -k2*abc_dq0_pos3.q +w0*abc_dq0_pos3.q -w1*abc_dq0_pos2.d+w2*abc_dq0_pos1.d;

			  	  //	vd=PI_out_dframe[1]+0.0075*V_q;
			  	  //  vq=PI_out_qframe[1]-0.0075*V_d;

			  	  		vd= PI_out_dframe[1]*0.1;
			  	  	    vq=PI_out_qframe[1]*0.1;

			  	  		   	 //vd=xd*0.1;
			  	  	   	 // vq=xq*0.1;//Ro/Vdc;


			  	  			   	    /*   if (vd>1.0)
			  	  			   	        	vd=1.0;
			  	  			   	        else if (vd<-1)
			  	  			   	        	vd=-1;
			  	  			   	        if (vq>1.0)
			  	  			   	  	        vq=1.0;
			  	  			   	  	  		else if (vq<-1.0)
			  	  			   	  	  		vq=-1.0;*/




			  	  			   	      Udq_to_Ualphabeta.Ds=vd;
			  	  			   	      Udq_to_Ualphabeta.Qs=vq;
			  	  			   	      Udq_to_Ualphabeta.Cos=cos(theta);
			  	  			   	  	  Udq_to_Ualphabeta.Sin=sin(theta);

			  	  			   	    	Udq_to_Ualphabeta.calc(&Udq_to_Ualphabeta);
			  	  			   	      y=Udq_to_Ualphabeta.Beta*Udq_to_Ualphabeta.Beta;
			  	  			   	    x=Udq_to_Ualphabeta.Alpha*Udq_to_Ualphabeta.Alpha;
			  	  			   	  	mm=sqrt(y+x);
			  	  			   	  	if(mm>0.9)
			  	  			   	  	{mm=0.9;}
			  	  			   	  	if (mm<0.1)
			  	  			   	  	{mm=0.1;}

			  	  			   		THETA=atan2(Udq_to_Ualphabeta.Beta,Udq_to_Ualphabeta.Alpha);



			  	  			    im= mm*100;


  	                           angle1=((theta)*57.3+360+thetata);
  			   	               angle=angle1%360;


 		   		 			  if ((angle >= 0.0) && (angle < 30.0))
  			   		 			     {
  			   		 			     	sector = 1;
  			   		 			     } else if ((angle >= 30.0) && (angle < 60.0)) {
  			   		 			        sector = 2;
  			   		 			     } else if ((angle >= 60.0) && (angle < 90.0)) {
  			   		 			        sector = 3;
  			   		 			     } else if ((angle >= 90.0) && (angle < 120.0)) {
  			   		 			     	sector = 4;
  			   		 			     } else if ((angle >= 120.0) && (angle < 150.0)) {
  			   		 			     	sector = 5;
  			   		 			     } else if ((angle >= 150.0) && (angle < 180.0)) {
  			   		 			     	sector = 6;
  			   		 			     } else if ((angle >= 180.0) && (angle < 210.0)) {
  			   		 			     	sector = 7;
  			   		 			     } else if ((angle >= 210.0) && (angle < 240.0)) {
  			   		 			     	sector = 8;
  			   		 			     } else if ((angle >= 240.0) && (angle < 270.0)) {
  			   		 			     	sector = 9;
  			   		 			     } else if ((angle >= 270.0) && (angle < 300.0)) {
  			   		 			     	sector = 10;
  			   		 			     } else if ((angle >= 300.0) && (angle < 330.0)) {
  			   		 			     	sector = 11;
  			   		 			     } else if (angle >= 330.0)  {

  			   		 				   sector = 12;
  			   		 			     } else {

  			   		 			        sector = 12;

  			   		 			     }






  			   		 			 alpha=angle%60;

  			   		 		IpcRegs.IPCSENDADDR = (Uint16) sector;
  			   		 		IpcRegs.IPCSENDCOM =  (Uint16) im;
  			   		 		IpcRegs.IPCSENDDATA = (Uint16) alpha;


  			   		/* 	if(flag==1)
  			   		 	{   count++;
  			   		 		theta+=count*0.0628;
  			   		 	}
  			   		 	if (count==100)
  			   		 	{
  			   		 		theta=0;
  			   		 		count=0;
  			   		 		tcount++;
  			   		 	}
  			   		       if (tcount==40)
  			   		  	{
  			   		    	   tcount=0;
  			   		  		flag=0;
  			   		  	  }*/


  		 		   		 	    IpcRegs.IPCSET.bit.IPC0 = 1;				// Set IPC1 bit for CPU1
                                cc++;

  			   		 		    AdcaRegs.ADCINTFLGCLR.bit.ADCINT1 = 1; //clear INT1 flag
  			   		 			PieCtrlRegs.PIEACK.all = PIEACK_GROUP1; // Acknowledge interrupt to PIE*/

  			   		 			//Reinitialize for next ADC sequence
  			   		 			IER |= M_INT13;

    AdcaRegs.ADCINTFLGCLR.bit.ADCINT1 = 1; //clear INT1 flag
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}
//
// End of file


void ipark_calc(IPARK *p)
{

   p->Alpha = p->Ds * p->Cos - p->Qs * p->Sin;
   p->Beta  = p->Qs * p->Cos + p->Ds * p->Sin;

}

