#include <REGX52.H>

sbit TC1=P2^0;//���
sbit TC2=P2^1;//�ұ�

unsigned char Tracking(void)
{
	if(TC1==1 && TC2==1)//��߲ⲻ�����ߣ���ȷ���ұ߲ⲻ�����ߣ���ȷ����ֱ��
	{
		return 0;
	}
	else if(TC1==0 && TC2==1)//��߲⵽���ߣ�����ȷ���ұ߲ⲻ�����ߣ���ȷ������ת
	{
		return 1;
	}
	else if(TC1==1 && TC2==0)//��߲ⲻ�����ߣ���ȷ���ұ߲⵽���ߣ�����ȷ������ת
	{
		return 2;
	}
	else//���⵽����,����
	{
		return 3;
	}
}
