#include<stdio.h>
#include<string.h>

void test(int *n)
{
	(*n)++;
}

void swap(int *a, int *b) 
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main01()
{
	int a = 10;
	int b = 20;
	swap(&a, &b);
	printf("a = %d, b = %d\n", a, b);
	return 0;

	int i = 100;
	test(&i);
	printf("i = %d\n", i);
	//scanf("%d", &i);//所有需要在函数内部修改实参的值，都需要通过将指针做为函数参数调用实现
	return 0;

	//经常用指针访问数组
	//int a = 10;
	int *p = &a;
	*p = 100;
	printf("%d\n", *p);
	//很少直接用指针指向一个变量，然后通过*方式访问变量
	return 0;
}

void set_array(int buf[])//数组名代表数组的首地址
//void set_array(int *buf)//数组名代表数组的首地址
//当数组名做为函数的参数时，数组名其实就是一个指针变量
{
	printf("buf = %d\n", sizeof(buf));
	*buf = 100;
	buf++;
	*buf = 200;
	//buf[0] = 100;
	//buf[1] = 200;
}

void print_array(const int *buf, int n)//n主要的功能是告诉函数内部，这个数组的维度
									   //通过const标示，不需要修改参数的值
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("buf[%d] = %d\n", i, buf[i]);
	}
}

void print_buf1(int(*p)[5], int a, int b)//将二维数组做为函数参数传递的时候，定义的指针类型
										 //void print_buf1(int p[][5], int a, int b)
{
	int i;
	int j;
	for (i = 0; i < a; i++)
	{
		for (j = 0; j < b; j++)
		{
			printf("p[%d][%d] = %d\n", i, j, p[i][j]);
		}
	}
}

void mystrcat(char *s1, const char *s2)//第一个参数是要被修改的，第二个参数不要被修改
{
	int len = 0;
	while (s2[len])
	{
		//s2++;
		len++;
	}
	while (*s1)
	{
		s1++;
	}
	int i;
	for (i = 0; i < len; i++)
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = '\0';
}

char *mystrchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return s;
		s++;
	}
	return NULL;
}

char *mystrstr(char *s, const char *str)//在s中查找相关的子串
{
	return NULL;
}

int main()
{
	//size_t strlen(const char *s);
	//strcpy(char *s1, const char *s2);
	char str[100] = "hello world";
	char *s = mystrchr(str, 'l');
	printf("s = %s\n", s);
	return 0;

	char s1[10] = "abc";
	char s2[10] = "bcd";
	mystrcat(s1, s2);
	printf("s1 = %s\n", s1);

	return 0;
	int buf1[3][5] = { { 1,2,3 },{ 4,5,6 } };
	//printf("%d\n", sizeof(buf1[0]) / sizeof(int));
	print_buf1(buf1, sizeof(buf1) / sizeof(buf1[0]), sizeof(buf1[0]) / sizeof(int));

	int buf[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	set_array(buf);
	print_array(buf, sizeof(buf)/sizeof(int));
	return 0;
}