#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#pragma warning(disable:4996)

int main01(int argc, char *args[])
{
	//printf("%d\n", argc);
	//argc代表程序执行的时候有几个参数，程序名称本身就是一个参数，所以argc最小值为1
	//第二个参数是一个指针数组，其中每个成员的类型是char *
	//printf("args[0] = %s\n", args[0]);
	//args是一个指针数组，那么他的成员数量是多少呢？argc这个参数就是告诉main函数args这个数组有多少成员的
	int i;
	for (i = 0; i < argc; i++)
	{
		printf("args[%d] = %s\n", i, args[i]);
	}

	return 0;
}

int main02(int argc, char *args[])
{
	char buf[100] = "dir";
	int i;
	for (i = 1; i < argc; i++)
	{
		strcat(buf, " ");
		strcat(buf, args[i]);
	}
	system(buf);
	//printf("buf = %s\n", buf);
	return 0;
}

int main03(int argc, char *args[])
{
	if (argc < 3)
	{
		printf("参数不足，程序退出\n");
		return 0;
	}
	int a = atoi(args[1]);
	int b = atoi(args[2]);
	printf("%d\n", a + b);
	return 0;
}

int main(int argc, char *args[])
{
	if (argc < 4)
	{
		printf("参数不足，程序退出\n");
		return 0;
	}

	int a = atoi(args[1]);
	int b = atoi(args[3]);

	//char *s = args[2];
	//char c = s[0];

	switch (args[2][0])
	{
	case '+':
		printf("%d\n", a + b);
		break;
	case '-':
		printf("%d\n", a - b);
		break;
	case '*':
		printf("%d\n", a * b);
		break;
	case '/':
		if (b)
		{
			printf("%d\n", a / b);
		}
	}
	return 0;
}