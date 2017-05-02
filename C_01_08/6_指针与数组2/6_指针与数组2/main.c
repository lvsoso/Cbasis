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

int smax(int *s,int n)//�������еڶ���Ԫ��
{
	//�����Գ���[]
	//���Ϊ max
	//�ڶ���Ϊ s_max
	//��һ�������������������ֱ�Ϊ���͵ڶ���
	int max = 0;
	int s_max = 0;
	//�ڶ�������Ĭ�ϵ�һ���͵ڶ���Ԫ�طֱ�Ϊ���͵ڶ���
	//���������Ԫ��
	if (*s > *(s + 1)) 
	{
		max = *s;
		s_max = *(s+1);
	}
	else
	{
		max = *(s+1);
		s_max = *s;
	}//��max����s[0] �� s[1] �д���Ǹ�Ԫ�ص�ֵ
	int i;
	//��������
	for (i = 2; i <= n; i++) 
	{
		//����������max��Ԫ��
		//s_max = max
		//max = ����max��Ԫ��
		if (max < *(s+i))
		{
			s_max = max;
			max = *(s + i);
		}
		//�������С��max������s_max��Ԫ�أ���ô����s_max���ڸ�Ԫ��
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
	//printf("%d\n", pp2 - pp1); 1 ���8���ֽڣ�һ��long
	int *pp1 = &buf[1];
	int *pp2 = &buf[3];
	printf("%d\n", pp2 - pp1);//����ָ��������Եõ���������Ԫ�ص���Ծ���
	printf("%d\n", (int)pp2 - (int)pp1);

	return 0;
}