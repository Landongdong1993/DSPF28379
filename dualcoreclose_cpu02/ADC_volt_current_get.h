


#ifndef ADC_VOLT_CURRENT_GET_H
#define ADC_VOLT_CURRENT_GET_H

#include "C28x_FPU_FastRTS.h"
///Fc = 5000;Fs = 50000;order=3;wn=Fc/Fs;[b,a] = butter(order,wn,'low')
//AC Voltage - A phase sensing

float volt_gain_ac=0.331; //58/0.47*(3/4095)=0.0904
//float volt_gain_ac=0.1062; //660/0.785*(3/4095)=0.0904
float volt_gain_dc=0.036;//58/0.33*(3/4095)
//float current_gain=0.006;//1.95/0.34*(3/4095)
float current_gain=0.006;//1.95/0.34*(3/4095)

float temp0,temp1,temp2,temp3,temp4,temp5,temp6,tempc0,tempc1,tempc2;
//**********ADC gains********************//
//float volt_gain_ac=0.1046,voltc_gain_ac=0.1636,volt_gain_dc=0.1636,current_gain=0.0115;

/*float V_aoff=1620,V_boff=1620,V_coff=1620;
float Vc_aoff=1592.0,Vc_boff=1615.0,Vc_coff=1593.0;
float I_aoff=2265,I_boff=2265,I_coff=2265;*/

//float V_aoff=1580,V_boff=1550,V_coff=1592;
float V_aoff=1600,V_boff=1640,V_coff=1590;
float Vc_aoff=1567,Vc_boff=1603,Vc_coff=1660;
//float I_aoff=2095,I_boff=2050,I_coff=2044;
float I_aoff=2210,I_boff=2250,I_coff=2240,V_dcoff=1560;

float adc_scale=(3.0/4095); //(3/4095 = 0.0007326)




float V_a_b[4]={0.0016,0.0047,0.0047,0.0016};//{0.0004,0.0012,0.0012,0.0004};
float V_a_a[4]={1.0000,-2.4986,2.1153,-0.6041};//{1.0000,-2.6862,2.4197,-0.7302};
float V_a_x[4] = {0,0,0,0};
float V_a_y[4] = {0,0,0,0};
//AC voltage - B phase sensing
float V_b_b[4]={0.0016,0.0047,0.0047,0.0016};//{0.0004,0.0012,0.0012,0.0004};
float V_b_a[4]={1.0000,-2.4986,2.1153,-0.6041};//{1.0000,-2.6862,2.4197,-0.7302};
float V_b_x[4] = {0,0,0,0};
float V_b_y[4] = {0,0,0,0};
//AC voltage - C phase sensing
float V_c_b[4]={0.0016,0.0047,0.0047,0.0016};//{0.0181,0.0543,0.0543,0.0181};
float V_c_a[4]={1.0000,-2.4986,2.1153,-0.6041};//{1.0000,-2.6862,2.4197,-0.7302};
float V_c_x[4] = {0,0,0,0};
float V_c_y[4] = {0,0,0,0};


float Vc_a_b[4]={0.0016,0.0047,0.0047,0.0016};//{0.0004,0.0012,0.0012,0.0004};
float Vc_a_a[4]={1.0000,-2.4986,2.1153,-0.6041};//{1.0000,-2.6862,2.4197,-0.7302};
float Vc_a_x[4] = {0,0,0,0};
float Vc_a_y[4] = {0,0,0,0};
//AC voltage - B phase sensing
float Vc_b_b[4]={0.0016,0.0047,0.0047,0.0016};//{0.0004,0.0012,0.0012,0.0004};
float Vc_b_a[4]={1.0000,-2.4986,2.1153,-0.6041};//{1.0000,-2.6862,2.4197,-0.7302};
float Vc_b_x[4] = {0,0,0,0};
float Vc_b_y[4] = {0,0,0,0};
//AC voltage - C phase sensing
float Vc_c_b[4]={0.0016,0.0047,0.0047,0.0016};//{0.0181,0.0543,0.0543,0.0181};
float Vc_c_a[4]={1.0000,-2.4986,2.1153,-0.6041};//{1.0000,-2.6862,2.4197,-0.7302};
float Vc_c_x[4] = {0,0,0,0};
float Vc_c_y[4] = {0,0,0,0};


float I_a_b[4]={0.0016,0.0047,0.0047,0.0016};//{0.0004,0.0012,0.0012,0.0004};
float I_a_a[4]={1.0000,-2.4986,2.1153,-0.6041};//{1.0000,-2.6862,2.4197,-0.7302};
float I_a_x[4] = {0,0,0,0};
float I_a_y[4] = {0,0,0,0};
//AC voltage - B phase sensing
float I_b_b[4]={0.0016,0.0047,0.0047,0.0016};//{0.0004,0.0012,0.0012,0.0004};
float I_b_a[4]={1.0000,-2.4986,2.1153,-0.6041};//{1.0000,-2.6862,2.4197,-0.7302};
float I_b_x[4] = {0,0,0,0};
float I_b_y[4] = {0,0,0,0};
//AC voltage - C phase sensing
float I_c_b[4]={0.0016,0.0047,0.0047,0.0016};//{0.0181,0.0543,0.0543,0.0181};
float I_c_a[4]={1.0000,-2.4986,2.1153,-0.6041};//{1.0000,-2.6862,2.4197,-0.7302};
float I_c_x[4] = {0,0,0,0};
float I_c_y[4] = {0,0,0,0};


float V_dc_b[4]={0.0000561,0.0001682,0.0001682,0.000561};
float V_dc_a[4]={1.0000,-2.8431,2.6980,-0.8546};
float V_dc_x[4] = {0,0,0,0};
float V_dc_y[4] = {0,0,0,0};





/*float V_a_b[4]={0.00002915,0.00008744,0.00008744,0.00002915};//{0.0004,0.0012,0.0012,0.0004};
float V_a_a[4]={1.0000,-2.8744,2.7565,-0.8819};//{1.0000,-2.6862,2.4197,-0.7302};
float V_a_x[4] = {0,0,0,0};
float V_a_y[4] = {0,0,0,0};
//AC voltage - B phase sensing
float V_b_b[4]={0.00002915,0.00008744,0.00008744,0.00002915};//{0.0004,0.0012,0.0012,0.0004};
float V_b_a[4]={1.0000,-2.8744,2.7565,-0.8819};//{1.0000,-2.6862,2.4197,-0.7302};
float V_b_x[4] = {0,0,0,0};
float V_b_y[4] = {0,0,0,0};
//AC voltage - C phase sensing
float V_c_b[4]={0.00002915,0.00008744,0.00008744,0.00002915};//{0.0181,0.0543,0.0543,0.0181};
float V_c_a[4]={1.0000,-2.8744,2.7565,-0.8819};//{1.0000,-2.6862,2.4197,-0.7302};
float V_c_x[4] = {0,0,0,0};
float V_c_y[4] = {0,0,0,0};

//AC Voltage - A phase sensing
float Vc_a_b[4]={0.00002915,0.00008744,0.00008744,0.00002915};
float Vc_a_a[4]={1.0000,-2.8744,2.7565,-0.8819};
float Vc_a_x[4] = {0,0,0,0};
float Vc_a_y[4] = {0,0,0,0};
//AC voltage - B phase sensing
float Vc_b_b[4]={0.00002915,0.00008744,0.00008744,0.00002915};
float Vc_b_a[4]={1.0000,-2.8744,2.7565,-0.8819};
float Vc_b_x[4] = {0,0,0,0};
float Vc_b_y[4] = {0,0,0,0};
//AC voltage - C phase sensing
float Vc_c_b[4]={0.00002915,0.00008744,0.00008744,0.00002915};
float Vc_c_a[4]={1.0000,-2.8744,2.7565,-0.8819};
float Vc_c_x[4] = {0,0,0,0};
float Vc_c_y[4] = {0,0,0,0};

float I_a_b[4]={0.00002915,0.00008744,0.00008744,0.00002915};
float I_a_a[4]={1.0000,-2.8744,2.7565,-0.8819};
float I_a_x[4] = {0,0,0,0};
float I_a_y[4] = {0,0,0,0};
//AC CURRENT - B phase sensing
float I_b_b[4]={0.00002915,0.00008744,0.00008744,0.00002915};
float I_b_a[4]={1.0000,-2.8744,2.7565,-0.8819};
float I_b_x[4] = {0,0,0,0};
float I_b_y[4] = {0,0,0,0};
//AC CURRENT - C phase sensing
float I_c_b[4]={0.00002915,0.00008744,0.00008744,0.00002915};
float I_c_a[4]={1.0000,-2.8744,2.7565,-0.8819};
float I_c_x[4] = {0,0,0,0};
float I_c_y[4] = {0,0,0,0};
//DC voltage sensing
float V_dc_b[4]={0.00002915,0.00008744,0.00008744,0.00002915};
float V_dc_a[4]={1.0000,-2.8744,2.7565,-0.8819};
float V_dc_x[4] = {0,0,0,0};
float V_dc_y[4] = {0,0,0,0};*/

//-----------------------------------------------------------------------------
//  Define the structure of the POSSPEED Object 
//-----------------------------------------------------------------------------
typedef struct {float Vdc;  //Output: DC bus voltage of CSR
                //float Vpo;
				//float Von;

                float Ua;  //Output: CSR input line voltage Uab
                float Ub;  //Output:
				float Uc;  //Output:
				float Ia;   //Output: CSR input line current Ia
				float Ib;   //Output: 
				float Ic;   //Output: 
				float Uca;   //Output: csr capacitor voltage
				float Ucb;   //Output:
				float Ucc;   //Output:


                float Volt_channelA0;//Output:DSP A通道8个管脚上的电压值
				float Volt_channelA1;
				float Volt_channelA2;
				float Volt_channelA3;
				float Volt_channelA4;
				float Volt_channelA5;
				float Volt_channelA6;
				float Volt_channelA7;

				float Volt_channelB0;
				float Volt_channelB1;
				float Volt_channelB2;
				float Volt_channelB3;
				float Volt_channelB4;
				float Volt_channelB5;
				float Volt_channelB6;
				float Volt_channelB7;

                void (*init)();       // Pointer to the init function 
                void (*read)();       // Pointer to the read function 
               }ADC_VOLT_CURRENT_GET;


//-----------------------------------------------------------------------------
// Define a POSSPEED_handle
//-----------------------------------------------------------------------------
typedef ADC_VOLT_CURRENT_GET  *ADC_VOLT_CURRENT_GET_handle;


//-----------------------------------------------------------------------------
// Default initializer for the POSSPEED Object.
//-----------------------------------------------------------------------------
#define ADC_VOLT_CURRENT_GET_DEFAULTS {0,0,0,\
                                       0,0,0,\
                                       0,0,0,\
                                       0,0,0,\
                                       0,0,\
                                       0,0,0,0,0,0,0,0,\
                                       0,0,0,0,0,0,0,0,\
									 (void (*)(long))ADC_volt_current_get_Init,\
									 (void (*)(long))ADC_volt_current_get_Calc}
//-----------------------------------------------------------------------------
//  Prototypes for the functions in posspeed.c                                 
//-----------------------------------------------------------------------------
void ADC_volt_current_get_Init();
void ADC_volt_current_get_Calc(ADC_VOLT_CURRENT_GET_handle); 




#endif

//==============================================================
//End of file.
//==============================================================



