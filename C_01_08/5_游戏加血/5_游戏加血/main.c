
__declspec(dllexport) //加了这个关键字，代表go函数是可以在其他程序中调用的dll函数

void go()
{
	int* p = 0x1CF88808;//得到植物大战僵尸游戏中的阳光变量地址
	//这个是地址是植物大战僵尸的地址，自己写的程序是没有权利改变其他程序的地址内容
	while (1)
	{
		if (*p <= 100) 
		{
			*p = 300;
		}
	}
}