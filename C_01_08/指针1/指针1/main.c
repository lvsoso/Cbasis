#include <stdio.h>

#pragma warning(disable:4700)


int main0() 
{
	int a = 0;
	int b = 1;
	char buf[10];
	printf("%p, %p, %p\n", &a, &b, buf);//&取变量地址

	int p = &a; //得到变量a的地址，将地址赋值给变量
	printf("%X\n", p);
	//地址虽然是一个整数，但地址是一个特殊的整数，是不能直接通过整数来操作的
	int *p1; //定义一个变量，名字叫p1, 它可以指向一个 int 的地址
	p1 = &b;//指针变量的值一般不能直接赋值给一个整数，而是通过取变量地址的方式赋值

	//当前*p的意思是指向地址的值
	int f = *p1;
	printf("%d\n", f);
	*p1 = 10;//通过指针间接修改指针所指向的变量的值
	printf("a = %d\n", b);

	printf("--------------------------------------------\n");

	
	printf("%u, %u, %u, %u,\n", buf, &buf[0], &buf[1], &buf[2]);
	int buf1[10];
	printf("%u, %u, %u, %u,\n", buf1, &buf1[0], &buf1[1], &buf1[2]);


	char c = 0;
	char *p2 = &c;

	void *p3; //无类型指针，只是一个指针变量，而不指向任何具体的数据类型
	p3 = NULL;//将指针赋值NULL， 值为HULL的指针， 俗称空指针； 没有具体指向任何变量地址的指针叫野指针
	printf("%d\n", sizeof(p3));
	return 0;
}

int main1() 
{
	int a = 10;
	int *p;
	//p = &a; //造成野指针， 运气好可能指向一个有效的地址
	// 野指针是导致程序崩溃的主要原因
	//
	*p = 1;
	printf("a = %d\n", a);
	return 0;
}

int main2()
{
	int a = 2;
	int b = 4;
	int c = 7;
	int *p;
	
	p = &a;
	*p = 10;

	p = &b;
	*p = 20;

	p = &c;
	*p = 30;

	printf("a = %d, b = %d, c = %d\n", a, b, c);
	return 0;
}

int main3()
{
	int a = 0x1310;
	char b = 2;
	char *p = &a;//“初始化”: 从“int *”到“char *”的类型不兼容
	int *p1 = &b;
	printf("%d\n", *p);
	printf("%X\n", *p1);

	int *p2;
	char *p3;
	char buf[10] = { 0x12, 0x34, 0x56, 0x78, 5, 6, 7, 8, 9, 10 };
	p2 = buf;
	p3 = buf;
	printf("%X\n", *p2);
	printf("%X\n", *p3);
	return 0;
}

int main4() 
{
	float a = 3.14;
	int i = a;//自动数据类型转化，将浮点数的小数部分舍弃

	int *p = &a;//严重的错误，因为指针类型不兼容
	printf("%d\n", *p);
	return 0;
}


int main5()//指向常量的指针
{
	int a = 0;
	int b = 30;
	const int* p = &a; //p 这个指针只能指向一个常量
	//*p = 20; 不能通过 *p 的方法修改一个const指针
	a = 20;
	printf("a = %d\n", *p);//*p 是个只读的值， 不能修改
	printf("a = %d\n", a);
	p = &b;
	printf("a = %d\n", *p);
	return 0;
}

int main()//常量指针
{
	int a = 10;
	int b = 30;
	int* const p = &a; // 定义一个常量指针，可以通过常量指针修改或者读取一个变量的值
	*p = 20;
	//p = &b; //错误， 常量指针一旦定义了，那么就不能修改其指向的变量
	printf("a = %d\n", *p);
	return 0;
}