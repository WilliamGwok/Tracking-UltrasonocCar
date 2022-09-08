#include <REGX52.H>

/**
  * @brief  ��ʱ��0��ʼ����100us@12.000MHz
  * @param  ��
  * @retval ��
  */
void Timer0_Init(void)
{
//	TMOD=0x01;//0000 0001 �������ã��������λ�����㣬���Ʋ��˵�һ����ʱ��
//	TMOD&=0xF0;//��TMOD�ĵ���λ���㣬����λ���ֲ���
//	TMOD|=0x01;//��TMOD�����λ��1������λ���ֲ���
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

/*��ʱ���ж�ģ��
void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;
	TL0 = 0x9C;  //���ö�ʱ��ֵ
	TH0 = 0xFF;  //���ö�ʱ��ֵ
	T0Count++;
	if(T0Count>=1000)
	{
		T0Count=0;
	}
}

*/