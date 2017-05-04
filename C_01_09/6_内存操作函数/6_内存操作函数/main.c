#include <stdio.h>
#include <string.h>

int main01()
{
	int buf[1024] = { 0 };//只能用于定义数组的时候同时初始化内容
	buf[0] = 8;
	buf[1] = 9;
	buf[4] = 8;

	//想将这个buf再一次初始化为0；
	//buf[10] = { 0 };错误的语法
	int i;
	//for (i = 0; i < 10; i++)
	//{
	//	buf[i] = 0;
	//}

	memset(buf, 0, sizeof(buf));//第一个参数是要设置的内存地址，第二个参数是要设置的值，第三个参数是内存大小，单位：字节
								//将一块内存初始化为0，最常见的方法
	for (i = 0; i < 10; i++)
	{
		printf("buf[%d] = %d\n", i, buf[i]);
	}
	return 0;
}

int main02()
{
	int buf1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int buf2[10];
	//memcpy(buf2, buf1, sizeof(buf1));//将buf1的内存内容全部拷贝到buf2,拷贝大小为第三个参数：字节
	memmove(buf2, buf1, sizeof(buf1));
	int i;
	for (i = 0; i < 10; i++)
	{
		printf("%d\n", buf2[i]);
	}
	printf("--------------------\n");

	for (i = 0; i < 10; i++)
	{
		printf("%d\n", buf1[i]);
	}
	return 0;
}

int main03()
{
	int buf[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int *start = buf + 3;
	int *end = buf + 5;
	memcpy(start, end, 4*4);


	int i;
	for (i = 0; i < 10; i++)
	{
		printf("buf[%d] = %d\n", i, buf[i]);
	}
	return 0;
}


int main04()
{
	int *p[3];//定义了一个指针数组，有3个成员，每个成员都是int *
	int a = 1;
	int b = 2;
	int c = 3;
	p[0] = &a;
	p[1] = &b;
	p[2] = &c;

	*p[0] = 10;//通过指针数组成员访问指针指向内存的值

	printf("%d\n", a);

	//int(*p)[3];//定义了一个数组指针，是一个名字叫p的指针变量，他指向int [3]这种数据类型
	//数组指针大多数情况下用在指向一个二维数组

	int buf1[5][3];
	int buf2[7][3];//只要二维数组的第一维是int [3]这种类型，那么都可以用int (*p)[3]来指向他
}

void swap(int *a, int *b)
{
	//int tmp = *a;
	//*a = *b;
	//*b = tmp;
	*a += *b;
	*b = *a - *b;
	*a = *a - *b;

}

int main()
{
	int a = 10;
	int b = 20;
	swap(&a, &b);
	printf("a = %d, b = %d\n", a, b);


	int buf[3][4] = { { 1, 2, 3, 4 },{ 5, 6 , 7, 8 },{ 9, 10, 11, 12 } };
	int(*p)[4];//p++移动了4 * sizeof(int)这么多的字节，(*p)++，那么他移动了sizeof(int)这么多的字节
	p = buf;

	//p是连长
	//*p是排长

	printf("%p, %p, %p, %p, %p\n", buf, buf[0], &buf[0][0], p, *p);
	p++;
	printf("%u, %u, %u, %u, %u\n", buf, buf[1], &buf[1][0], p, *p);
	printf("%u, %u\n", (p + 1), (*p + 1));

	//*(*a + 3);
	//*(*(a + 1) + 2),
	return 0;
}