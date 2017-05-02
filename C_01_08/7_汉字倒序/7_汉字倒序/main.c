#include <stdio.h>
#include <string.h>


int main()
{
	char str[100] = "你好我也好"; //对于VS的汉字是GBK编码，
	//一个汉字2个字节，对于QT汉字是UTF-8编码，一个汉字是3个字节

	//通过指针将汉字字符串逆置
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