#include <stdio.h>

#pragma warning(disable:4700)


int main0() 
{
	int a = 0;
	int b = 1;
	char buf[10];
	printf("%p, %p, %p\n", &a, &b, buf);//&ȡ������ַ

	int p = &a; //�õ�����a�ĵ�ַ������ַ��ֵ������
	printf("%X\n", p);
	//��ַ��Ȼ��һ������������ַ��һ��������������ǲ���ֱ��ͨ��������������
	int *p1; //����һ�����������ֽ�p1, ������ָ��һ�� int �ĵ�ַ
	p1 = &b;//ָ�������ֵһ�㲻��ֱ�Ӹ�ֵ��һ������������ͨ��ȡ������ַ�ķ�ʽ��ֵ

	//��ǰ*p����˼��ָ���ַ��ֵ
	int f = *p1;
	printf("%d\n", f);
	*p1 = 10;//ͨ��ָ�����޸�ָ����ָ��ı�����ֵ
	printf("a = %d\n", b);

	printf("--------------------------------------------\n");

	
	printf("%u, %u, %u, %u,\n", buf, &buf[0], &buf[1], &buf[2]);
	int buf1[10];
	printf("%u, %u, %u, %u,\n", buf1, &buf1[0], &buf1[1], &buf1[2]);


	char c = 0;
	char *p2 = &c;

	void *p3; //������ָ�룬ֻ��һ��ָ�����������ָ���κξ������������
	p3 = NULL;//��ָ�븳ֵNULL�� ֵΪHULL��ָ�룬 �׳ƿ�ָ�룻 û�о���ָ���κα�����ַ��ָ���Ұָ��
	printf("%d\n", sizeof(p3));
	return 0;
}

int main1() 
{
	int a = 10;
	int *p;
	//p = &a; //���Ұָ�룬 �����ÿ���ָ��һ����Ч�ĵ�ַ
	// Ұָ���ǵ��³����������Ҫԭ��
	//
	*p = 1;
	printf("a = %d\n", a);
	return 0;
}

int main2()
{
	int a = 2;
	int b = 4;
	int c = 7;
	int *p;
	
	p = &a;
	*p = 10;

	p = &b;
	*p = 20;

	p = &c;
	*p = 30;

	printf("a = %d, b = %d, c = %d\n", a, b, c);
	return 0;
}

int main3()
{
	int a = 0x1310;
	char b = 2;
	char *p = &a;//����ʼ����: �ӡ�int *������char *�������Ͳ�����
	int *p1 = &b;
	printf("%d\n", *p);
	printf("%X\n", *p1);

	int *p2;
	char *p3;
	char buf[10] = { 0x12, 0x34, 0x56, 0x78, 5, 6, 7, 8, 9, 10 };
	p2 = buf;
	p3 = buf;
	printf("%X\n", *p2);
	printf("%X\n", *p3);
	return 0;
}

int main4() 
{
	float a = 3.14;
	int i = a;//�Զ���������ת��������������С����������

	int *p = &a;//���صĴ�����Ϊָ�����Ͳ�����
	printf("%d\n", *p);
	return 0;
}


int main5()//ָ������ָ��
{
	int a = 0;
	int b = 30;
	const int* p = &a; //p ���ָ��ֻ��ָ��һ������
	//*p = 20; ����ͨ�� *p �ķ����޸�һ��constָ��
	a = 20;
	printf("a = %d\n", *p);//*p �Ǹ�ֻ����ֵ�� �����޸�
	printf("a = %d\n", a);
	p = &b;
	printf("a = %d\n", *p);
	return 0;
}

int main()//����ָ��
{
	int a = 10;
	int b = 30;
	int* const p = &a; // ����һ������ָ�룬����ͨ������ָ���޸Ļ��߶�ȡһ��������ֵ
	*p = 20;
	//p = &b; //���� ����ָ��һ�������ˣ���ô�Ͳ����޸���ָ��ı���
	printf("a = %d\n", *p);
	return 0;
}