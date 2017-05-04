#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#pragma warning(disable:4996)

int main01(int argc, char *args[])
{
	//printf("%d\n", argc);
	//argc�������ִ�е�ʱ���м����������������Ʊ������һ������������argc��СֵΪ1
	//�ڶ���������һ��ָ�����飬����ÿ����Ա��������char *
	//printf("args[0] = %s\n", args[0]);
	//args��һ��ָ�����飬��ô���ĳ�Ա�����Ƕ����أ�argc����������Ǹ���main����args��������ж��ٳ�Ա��
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
		printf("�������㣬�����˳�\n");
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
		printf("�������㣬�����˳�\n");
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