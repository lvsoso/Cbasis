#include <stdio.h>

int main() 
{
	char s1[100] = "hello";
	char s2[100] = "world";

	//用指针来求一个字符串的长度
	//用指针来将s1和s2合并为一个字符串，结果存入s1中

	char* p1 = s1;
	int len = 0;
	while (*p1)//*p1的内容为0的时候，表示字符串结束了
	{
		p1++;
		len++;
	}

	printf("len = %d\n", len);

	char *p2 = s2;
	while (*p2)
	{
		*p1++ = *p2++;//从s1的最后开始，从s2的首元素开始
	}

	printf("s1 = %s\n", s1);

	return 0;
}