#include <stdio.h>

#pragma warning(disable:4700)

int main01()
{
	int a = 10;
	int *p = &a;
	//int *p;
	//p = &a;

	//int *p;//野指针
	//*p = &a;//给野指针指向的内存赋值

	//p = NULL;//NULL其实就是0
	int *p1;//避免使用野指针，更不能读写野指针指向的内存
	if (p1)
	{
		printf("true\n");
	}
	else
	{
		printf("false\n");
	}
	return 0;
}

int main02()
{
	
	int a = 0x00001234;
	char *p = &a;//数据的丢失
	p += 2;
	printf("%x\n", *p);

	float f = 3.14;
	p = &f;
	printf("%x,%x,%x,%x\n", *p, *(p + 1), *(p + 2), *(p + 3));

	return 0;
	
}

int main03()
{
	int aaa = 20;
	int* const aaap = &aaa;//指针常量的意思是一旦定义之后就固定的指向一个地址，这个地址是不能在程序运行期间改变的


	const int abc = 100;
	//abc = 10;
	int *abcp = &abc;
	*abcp = 10;//典型的C语言的问题，不够严谨
	printf("abc = %d\n", abc);
	return 0;


	int a = 100;
	const int* p = &a;
	//*p = 10;//不能将const int *做为左值使用
	int *p1 = p;//这个是C语言不够严谨的地方
	*p1 = 10;
	printf("a = %d\n", a);
	return 0;
}

int main04()
{
	int a = 100000000;
	char *cp = &a;
	printf("%x, %x, %x, %x\n", *cp, *(cp + 1), *(cp + 2), *(cp + 3));
	printf("%x, %x, %x, %x\n", cp[0], cp[1], cp[2], cp[3]);

	cp += 5;//在内存中位移了5个sizeof(char)
	return 0;

	int buf[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int *p = buf;
	//p++;
	//buf++; //buf = buf + 1;buf是数组名，是一个常量，常量不能做左值
	//printf("%d\n", *p);
	printf("%d, %d\n", sizeof(p), sizeof(buf));// 4, 40

	p += 1;//4个字节
	p += 2;//8个字节
	p += 5;// 5 * sizeof(int) = 20个字节

	int i;
	for (i = 0; i < 10; i++)
	{
		printf("%d\n", p[i]);//C语言允许指针通过数组下标的方法访问数组成员
	}
	return 0;
}

int main()
{
	int buf[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int *p = buf;
	//方法一
	*(p + 3) = 20;//将数组中下标为3的成员赋值
				  //方法二
	p[5] = 30;//将数组中下标为5的成员赋值
			  //方法三
	p += 7;
	*p = 40;//将数组中下标为7的成员赋值

			//方法一和方法二都没有改变p指向的内存地址、但方法三修改了p指向的值

	p[2] = 100;//这个时候修改是下标为多少的数组成员
			   //*(p + 2) = 100;

	int i;
	for (i = 0; i < 10; i++)
	{
		printf("%d\n", buf[i]);
	}

}

