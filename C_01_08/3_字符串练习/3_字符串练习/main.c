#include <stdio.h>

int main() 
{
	char s1[100] = "hello";
	char s2[100] = "world";

	//��ָ������һ���ַ����ĳ���
	//��ָ������s1��s2�ϲ�Ϊһ���ַ������������s1��

	char* p1 = s1;
	int len = 0;
	while (*p1)//*p1������Ϊ0��ʱ�򣬱�ʾ�ַ���������
	{
		p1++;
		len++;
	}

	printf("len = %d\n", len);

	char *p2 = s2;
	while (*p2)
	{
		*p1++ = *p2++;//��s1�����ʼ����s2����Ԫ�ؿ�ʼ
	}

	printf("s1 = %s\n", s1);

	return 0;
}