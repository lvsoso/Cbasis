#include <stdio.h>

//#pragma warning(disable:4996)

int add(int a, int b)
{
	return a + b;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

void print_array(int * s, int n)
{
	int i;
	for (i = 0; i < n;i++)
	{
		printf("%d\n", s[i]);
	}
}


int main01()
{
	void *p(int, char *);//������һ�����������������ֽ�p,�����ķ���ֵ��void *,�����Ĳ�����int��char *
	//void (*p)(int, char *);//������һ��ָ�����Ϊint��char*������ֵΪvoid�ĺ���ָ��

	//����һ������Ϊint * ����ֵΪint *��ָ������ָ��
	//int *(*p)(int *);

	//int *p(int *);//������һ������������ֵ��int *,������int *

	//void (*p1)(int* , int);
	int(*p)(int, int);//������һ��ָ������ָ��,����ָ����������������int������ֵҲ��int�������͵ĺ���
	
	int status = 0;
	scanf("%d", &status);

	//p = add;//ֱ��д���������֣��������ĵ�ַ,��add��������ĵ�ַ���Ƹ�ָ�����p
	//p = max;
	
	if (status == 1)
		p = max;
	else
		p = add;
	
	int i = 0;
	//�����ڱ���i = p(5,7)��ʱ�򣬸����Ͳ�֪��Ҫ����ʲô����
	i = p(5, 7);//ͨ��ָ�������ӵ���ָ��ָ��ĺ���
	printf("i = %d\n", i);
	
	//���Ͳ�ͬ�ĸ�ֵ�����������C++���Ǳ���ͨ������
	p = print_array;
	int buf[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	p(buf, 10);
	return 0;
}


/////////////////////////////////////

void man()
{
	printf("����\n");
	printf("�Ⱦ�\n");
	printf("����\n");
}

void woman()
{
	printf("��ױ\n");
	printf("���\n");
	printf("����\n");
}

int main02()
{
	void(*p)();//����һ��ָ��û�в�����û�з���ֵ��ָ������ָ��
	int i = 0;
	scanf("%d", &i);
	if (i == 0)
		p = man;
	else
		p = woman;
	p();//��δ����ǳ������е�ʱ����ܾ������׵����ĸ�������
	return 0;
}


int func1(int(*p)(int, int), int a, int b)//��һ��������ָ������ָ��
{
	return p(a, b);//ͨ��ָ������ָ�����һ������
}

int main()
{
	int i = func1(add, 6, 9);//add����������ͽлص�����
	printf("i = %d\n", i);
	return 0;
}