#include <REGX52.H>
#include "Tracking.h"
#include "HC_SR04.h"
#include "Timer0.h"

sbit Motor_L_IN1=P1^0;
sbit Motor_L_IN2=P1^1;
sbit Motor_R_IN3=P1^2;
sbit Motor_R_IN4=P1^3;

unsigned int Counter,Speed_L,Speed_R;

void main()
{
	Timer0_Init();
	while(1)
	{
		Speed_L=0;
		Speed_R=0;//前方有障碍物则停下
		while(HC_SR04_Init()==1)
		{
			if(Tracking()==0)//直走
			{
				Speed_L=30;
				Speed_R=30;
			}
			else if(Tracking()==1)//左转
			{
				Speed_L=20;
				Speed_R=30;
			}
			else if(Tracking()==2)//右转
			{
				Speed_L=30;
				Speed_R=20;
			}
			else if(Tracking()==3)//减速
			{
				Speed_L=20;
				Speed_R=20;
			}
		}
	}
}


void Timer0_Routine() interrupt 1
{
	TL0 = 0x9C;  //设置定时初值
	TH0 = 0xFF;  //设置定时初值65436（每0.1ms溢出一次，即每0.1ms进一次中断）
	Counter++;
	Counter%=100;//到100时清零，即周期为10ms
	if(Counter<Speed_L)
	{
		Motor_L_IN1=1;
		Motor_L_IN2=0;
	}
	else
	{
		Motor_L_IN1=0;
		Motor_L_IN2=0;
	}
	
	if(Counter<Speed_R)
	{
		Motor_R_IN3=1;
		Motor_R_IN4=0;
	}
	else
	{
		Motor_R_IN3=0;
		Motor_R_IN4=0;
	}
}

