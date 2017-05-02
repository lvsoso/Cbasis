#include <stdio.h>

void bubble(int *s)
{
	int i;
	int j;
	for (i = 0; i < 10; i++)
	{
		for (j = 1; j < 10 - i; j++)
		{
			if (*(s + j) < *(s + j - 1))
			{
				int tmp = *(s + j);
				*(s + j) = *(s + j - 1);
				*(s + j - 1) = tmp;
			}
		}
	}

}

void print_buf(int *s)
{
	int i;
	for (i = 0; i < 10; i++)
	{
		printf("%d\n", *(s + i));
	}
}

int max(int *s)
{
	int value = *s;
	int i;
	for (i = 1; i < 10; i++)
	{
		if (value < *(s + i))
		{
			value = *(s + i);
		}
	}
	return value;
}


void reverse(int* s, int n) 
{
	int *start = s;
	int *end = start + n;
	while (start < end)
	{
		int tmp = *start;
		*start = *end;
		*end = tmp;
		start ++ ;
		end --;
	}
}

int smax(int *s,int n)//求数组中第二大元素
{
	//不可以出现[]
	//最大为 max
	//第二大为 s_max
	//第一步：定义两个变量，分别为最大和第二大
	int max = 0;
	int s_max = 0;
	//第二步：先默认第一个和第二个元素分别为最大和第二大
	//如果有最大的元素
	if (*s > *(s + 1)) 
	{
		max = *s;
		s_max = *(s+1);
	}
	else
	{
		max = *(s+1);
		s_max = *s;
	}//将max等于s[0] 和 s[1] 中大的那个元素的值
	int i;
	//遍历数组
	for (i = 2; i <= n; i++) 
	{
		//当遇到大于max的元素
		//s_max = max
		//max = 大于max的元素
		if (max < *(s+i))
		{
			s_max = max;
			max = *(s + i);
		}
		//如果遇到小于max但大于s_max的元素，那么就让s_max等于该元素
		else if (max > *(s + i) && s_max < *(s + i))
		{
			s_max = *(s + i);
		}
	}

	return s_max;

}


int main()
{
	int buf[10] = {34, 21, 56, 23, 13, 67, 17, 48, 29, 22};

	int i = max(buf);
	printf("i = %d\n", i);

	bubble(buf);
	print_buf(buf);
	
	
	/*int low = 0;
	int high = 9;
	while (low < high) 
	{
		int tmp = buf[low];
		buf[low] = buf[high];
		buf[high] = tmp;
		low ++;
		high --;
	}*/
	
	printf("===================\n");
	reverse(buf, 9);
	print_buf(buf);
	
	int s_max = 0;
	s_max = smax(buf, 9);
	printf("%d\n", s_max);
	return 0;

	
	int* p = buf;
	int* p1 = &buf[1];
	char* p2 = buf;
	
	printf("%d, %d\n", p, p1);

	p++;
	printf("%d\n", p);

	p = (int)p + 3;
	printf("%d\n", p);

	p2 += 4;
	printf("%d, %d\n", p2, &buf[1]);


	//long *pp1 = &buf[1];
	//long *pp2 = &buf[3];
	//printf("%d\n", pp2 - pp1); 1 相差8个字节，一个long
	int *pp1 = &buf[1];
	int *pp2 = &buf[3];
	printf("%d\n", pp2 - pp1);//两个指针相减可以得到两个数组元素的相对距离
	printf("%d\n", (int)pp2 - (int)pp1);

	return 0;
}