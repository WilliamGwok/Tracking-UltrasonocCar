#include <REGX52.H>

/**
  * @brief  定时器0初始化，100us@12.000MHz
  * @param  无
  * @retval 无
  */
void Timer0_Init(void)
{
//	TMOD=0x01;//0000 0001 这样不好，会令高四位都清零，控制不了第一个定时器
//	TMOD&=0xF0;//把TMOD的低四位清零，高四位保持不变
//	TMOD|=0x01;//把TMOD的最低位置1，高四位保持不变
	TMOD &= 0xF0;		
	TMOD |= 0x01;		
	TL0 = 0x9C;
	TH0 = 0xFF;	
	TF0 = 0;		
	TR0 = 1;		
	ET0=1;
	EA=1;
	PT0=0;
}

/*定时器中断模板
void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;
	TL0 = 0x9C;  //设置定时初值
	TH0 = 0xFF;  //设置定时初值
	T0Count++;
	if(T0Count>=1000)
	{
		T0Count=0;
	}
}

*/