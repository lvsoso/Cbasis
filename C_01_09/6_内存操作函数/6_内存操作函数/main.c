#include <stdio.h>
#include <string.h>

int main01()
{
	int buf[1024] = { 0 };//ֻ�����ڶ��������ʱ��ͬʱ��ʼ������
	buf[0] = 8;
	buf[1] = 9;
	buf[4] = 8;

	//�뽫���buf��һ�γ�ʼ��Ϊ0��
	//buf[10] = { 0 };������﷨
	int i;
	//for (i = 0; i < 10; i++)
	//{
	//	buf[i] = 0;
	//}

	memset(buf, 0, sizeof(buf));//��һ��������Ҫ���õ��ڴ��ַ���ڶ���������Ҫ���õ�ֵ���������������ڴ��С����λ���ֽ�
								//��һ���ڴ��ʼ��Ϊ0������ķ���
	for (i = 0; i < 10; i++)
	{
		printf("buf[%d] = %d\n", i, buf[i]);
	}
	return 0;
}

int main02()
{
	int buf1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int buf2[10];
	//memcpy(buf2, buf1, sizeof(buf1));//��buf1���ڴ�����ȫ��������buf2,������СΪ�������������ֽ�
	memmove(buf2, buf1, sizeof(buf1));
	int i;
	for (i = 0; i < 10; i++)
	{
		printf("%d\n", buf2[i]);
	}
	printf("--------------------\n");

	for (i = 0; i < 10; i++)
	{
		printf("%d\n", buf1[i]);
	}
	return 0;
}

int main03()
{
	int buf[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int *start = buf + 3;
	int *end = buf + 5;
	memcpy(start, end, 4*4);


	int i;
	for (i = 0; i < 10; i++)
	{
		printf("buf[%d] = %d\n", i, buf[i]);
	}
	return 0;
}


int main04()
{
	int *p[3];//������һ��ָ�����飬��3����Ա��ÿ����Ա����int *
	int a = 1;
	int b = 2;
	int c = 3;
	p[0] = &a;
	p[1] = &b;
	p[2] = &c;

	*p[0] = 10;//ͨ��ָ�������Ա����ָ��ָ���ڴ��ֵ

	printf("%d\n", a);

	//int(*p)[3];//������һ������ָ�룬��һ�����ֽ�p��ָ���������ָ��int [3]������������
	//����ָ���������������ָ��һ����ά����

	int buf1[5][3];
	int buf2[7][3];//ֻҪ��ά����ĵ�һά��int [3]�������ͣ���ô��������int (*p)[3]��ָ����
}

void swap(int *a, int *b)
{
	//int tmp = *a;
	//*a = *b;
	//*b = tmp;
	*a += *b;
	*b = *a - *b;
	*a = *a - *b;

}

int main()
{
	int a = 10;
	int b = 20;
	swap(&a, &b);
	printf("a = %d, b = %d\n", a, b);


	int buf[3][4] = { { 1, 2, 3, 4 },{ 5, 6 , 7, 8 },{ 9, 10, 11, 12 } };
	int(*p)[4];//p++�ƶ���4 * sizeof(int)��ô����ֽڣ�(*p)++����ô���ƶ���sizeof(int)��ô����ֽ�
	p = buf;

	//p������
	//*p���ų�

	printf("%p, %p, %p, %p, %p\n", buf, buf[0], &buf[0][0], p, *p);
	p++;
	printf("%u, %u, %u, %u, %u\n", buf, buf[1], &buf[1][0], p, *p);
	printf("%u, %u\n", (p + 1), (*p + 1));

	//*(*a + 3);
	//*(*(a + 1) + 2),
	return 0;
}