#include <stdio.h>
#include <string.h>


int main()
{
	char str[100] = "�����Ҳ��"; //����VS�ĺ�����GBK���룬
	//һ������2���ֽڣ�����QT������UTF-8���룬һ��������3���ֽ�

	//ͨ��ָ�뽫�����ַ�������
	short *str_start = &str[0];
	short *str_end = &str[strlen(str) - 2];

	while (str_start < str_end)
	{
		char *tmp = *str_start;
		*str_start = *str_end;
		*str_end = tmp;
		str_start++;
		str_end--;
	}

	printf("%s\n", str);
	return 0;
}