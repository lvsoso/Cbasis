#include <stdio.h>

//#pragma warning(disable:4996)

int add(int a, int b)
{
	return a + b;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

void print_array(int * s, int n)
{
	int i;
	for (i = 0; i < n;i++)
	{
		printf("%d\n", s[i]);
	}
}


int main01()
{
	void *p(int, char *);//声明了一个函数，函数的名字叫p,函数的返回值是void *,函数的参数是int和char *
	//void (*p)(int, char *);//定义了一个指向参数为int和char*，返回值为void的函数指针

	//定义一个参数为int * 返回值为int *的指向函数的指针
	//int *(*p)(int *);

	//int *p(int *);//声明了一个函数，返回值是int *,参数是int *

	//void (*p1)(int* , int);
	int(*p)(int, int);//定义了一个指向函数的指针,可以指向两个参数，都是int，返回值也是int这种类型的函数
	
	int status = 0;
	scanf("%d", &status);

	//p = add;//直接写函数的名字，代表函数的地址,将add这个函数的地址复制给指针变量p
	//p = max;
	
	if (status == 1)
		p = max;
	else
		p = add;
	
	int i = 0;
	//编译在编译i = p(5,7)的时候，根本就不知道要调用什么代码
	i = p(5, 7);//通过指针变量间接调用指针指向的函数
	printf("i = %d\n", i);
	
	//类型不同的赋值，这种语句在C++中是编译通不过的
	p = print_array;
	int buf[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	p(buf, 10);
	return 0;
}


/////////////////////////////////////

void man()
{
	printf("抽烟\n");
	printf("喝酒\n");
	printf("打牌\n");
}

void woman()
{
	printf("化妆\n");
	printf("逛街\n");
	printf("网购\n");
}

int main02()
{
	void(*p)();//定义一个指向没有参数，没有返回值的指向函数的指针
	int i = 0;
	scanf("%d", &i);
	if (i == 0)
		p = man;
	else
		p = woman;
	p();//这段代码是程序运行的时候才能决定到底调用哪个函数的
	return 0;
}


int func1(int(*p)(int, int), int a, int b)//第一个参数是指向函数的指针
{
	return p(a, b);//通过指向函数的指针调用一个函数
}

int main()
{
	int i = func1(add, 6, 9);//add函数在这里就叫回调函数
	printf("i = %d\n", i);
	return 0;
}