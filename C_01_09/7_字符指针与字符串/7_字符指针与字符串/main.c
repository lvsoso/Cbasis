#include<stdio.h>

void print_array(int *p, int n)//���������һ��int���飬��ô�ͱ��봫�ݵڶ�������������ʾ����ĳ���
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("p[%d] = %d\n", i, p[i]);
	}
}

void print_str(char *s)//��������Ǹ��ַ�������ô�Ͳ���Ҫ�����ڶ���������
					   //��Ϊ�ַ�������ȷ����'\0'��β�ģ����ԣ��ں����ڲ�������������Ϊѭ����ֹ���ݵ�
{
	int i = 0;
	while (s[i])
	{
		printf("%c", s[i++]);
	}
}

void print_str_a(char *s, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%c", s[i]);
	}
}

int main()
{
	char s[] = "hello world";
	s[3] = 0;
	//print_str(s);
	//printf("s = %s\n", s);
	print_str_a(s, strlen(s));
	return 0;

	int array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	print_array(array, 10);
	return 0;

	char buf[100] = "hello world";
	char *p = buf;
	//*(p + 5) = 'a';
	//p[5] = 'b';
	p += 5;
	*p = 'c';
	p[3] = ' ';
	printf("buf = %s\n", buf);
	return 0;
}