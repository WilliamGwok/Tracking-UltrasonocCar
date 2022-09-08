#include <REGX52.H>

sbit TC1=P2^0;//左边
sbit TC2=P2^1;//右边

unsigned char Tracking(void)
{
	if(TC1==1 && TC2==1)//左边测不到黑线（正确）右边测不到黑线（正确），直走
	{
		return 0;
	}
	else if(TC1==0 && TC2==1)//左边测到黑线（不正确）右边测不到黑线（正确），左转
	{
		return 1;
	}
	else if(TC1==1 && TC2==0)//左边测不到黑线（正确）右边测到黑线（不正确），右转
	{
		return 2;
	}
	else//都测到黑线,减速
	{
		return 3;
	}
}
