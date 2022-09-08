#include <REGX52.H>
#include <INTRINS.H>

sbit Trig=P0^0;
sbit Echo=P0^1;

unsigned int sum;//超声波测距结果
unsigned int mindistance=20;//与障碍物的限制距离

//void Delay1000ms()		//@11.0592MHz
//{
//	unsigned char i, j, k;

//	_nop_();
//	i = 8;
//	j = 1;
//	k = 243;
//	do
//	{
//		do
//		{
//			while (--k);
//		} while (--j);
//	} while (--i);
//}

void Delay12us()		//@11.0592MHz
{
	unsigned char i;

	i = 3;
	while (--i);
}

unsigned int HC_SR04_Init()
{
	TMOD=0x11;
	TL1=0;
	TH1=0;
	
	Trig=1;
	Delay12us();
	Trig=0;
	
	while(!Echo);
	TR1=1;
	while(Echo);
	TR1=0;
	
	sum=((TH1*256+TL1)*0.034)/2+1;//计算距离
	if(mindistance<sum)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
