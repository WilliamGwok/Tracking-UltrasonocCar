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
		Speed_R=0;//ǰ�����ϰ�����ͣ��
		while(HC_SR04_Init()==1)
		{
			if(Tracking()==0)//ֱ��
			{
				Speed_L=30;
				Speed_R=30;
			}
			else if(Tracking()==1)//��ת
			{
				Speed_L=20;
				Speed_R=30;
			}
			else if(Tracking()==2)//��ת
			{
				Speed_L=30;
				Speed_R=20;
			}
			else if(Tracking()==3)//����
			{
				Speed_L=20;
				Speed_R=20;
			}
		}
	}
}


void Timer0_Routine() interrupt 1
{
	TL0 = 0x9C;  //���ö�ʱ��ֵ
	TH0 = 0xFF;  //���ö�ʱ��ֵ65436��ÿ0.1ms���һ�Σ���ÿ0.1ms��һ���жϣ�
	Counter++;
	Counter%=100;//��100ʱ���㣬������Ϊ10ms
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

