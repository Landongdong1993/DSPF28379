//====================================================
//PID.h文件
//====================================================
#ifndef  PID_H
#define  PID_H

#include "C28x_FPU_FastRTS.h"

#define PID_DEBUG   0  //条件编译的判别条件
//-----------------------------------------------------------------------------
//定义PID计算用到的结构体对象类型，在创建多个实例时，只需将变量声明为PID_FUNC类型即可
//-----------------------------------------------------------------------------
typedef struct { 
	    		 float Give;     //输入：系统待调节量的给定值
				 float Feedback;  //输入：系统待调节量的反馈值
				 
                       //PID调节器部分   KP*T/TI--积分系数，  KP*T/TD---微分系数
				 float Kp;  //输入：对应式（15-53）中的Kp 比例系数
				 float Ti;   //输入：对应式（15-53）中的Ti  积分时间
				 float Td;  //输入：对应式（15-53）中的Td   微分时间

				 float T;   //输入：离散化系统的采样周期
				
				 float a0;  //输入：对应式（15-58）中的a0
				 float a1;  //输入：对应式（15-58）中的a1
				 float a2;  //输入：对应式（15-58）中的a2
                 
                 float Ek;     //中间变量：对应式（15-58）中的e(k)
				 float Ek_1;  //中间变量：对应式（15-58）中的e(k-1)
				 float Ek_2;  //中间变量：对应式（15-58）中的e(k-2)

                 float OutMax;  //输入：PID调节器的最大输出限幅
                 float OutMin;  //输入：PID调节器的最小输出限幅
                 float Output;  //输出：PID调节器的输出，对应式（15-58）中的u(k)
				 float LastOutput;  //中间变量：PID上一周期的输出值，对应式（15-58）中的u(k-1)         
				 void  (*calc)();	// 函数指针：指向计算过程
			   } PIDFUN;

//-----------------------------------------------------------------------------
//声明PID_FUNC_handle为CLARKE指针类型
//-----------------------------------------------------------------------------
typedef PIDFUN *PIDFUN_handle;


//-----------------------------------------------------------------------------
//定义PID调节器的初始值
//-----------------------------------------------------------------------------
#define PIDFUN_DEFAULTS {  0,0,\
                           0,0,0,\
                           0.0002,\
                           0,0,0,\
                           0,0,0,\
                           0,0,0,0\
						   (void (*)(Uint32))PIDfun_calc }

//-----------------------------------------------------------------------------
//  函数声明                               
//-----------------------------------------------------------------------------
void PIDfun_calc(PIDFUN_handle);

#endif
//==============================================================
//End of file.
//==============================================================
