#include <stdio.h>

#pragma warning(disable:4700)

int main01()
{
	int a = 10;
	int *p = &a;
	//int *p;
	//p = &a;

	//int *p;//Ұָ��
	//*p = &a;//��Ұָ��ָ����ڴ渳ֵ

	//p = NULL;//NULL��ʵ����0
	int *p1;//����ʹ��Ұָ�룬�����ܶ�дҰָ��ָ����ڴ�
	if (p1)
	{
		printf("true\n");
	}
	else
	{
		printf("false\n");
	}
	return 0;
}

int main02()
{
	
	int a = 0x00001234;
	char *p = &a;//���ݵĶ�ʧ
	p += 2;
	printf("%x\n", *p);

	float f = 3.14;
	p = &f;
	printf("%x,%x,%x,%x\n", *p, *(p + 1), *(p + 2), *(p + 3));

	return 0;
	
}

int main03()
{
	int aaa = 20;
	int* const aaap = &aaa;//ָ�볣������˼��һ������֮��͹̶���ָ��һ����ַ�������ַ�ǲ����ڳ��������ڼ�ı��


	const int abc = 100;
	//abc = 10;
	int *abcp = &abc;
	*abcp = 10;//���͵�C���Ե����⣬�����Ͻ�
	printf("abc = %d\n", abc);
	return 0;


	int a = 100;
	const int* p = &a;
	//*p = 10;//���ܽ�const int *��Ϊ��ֵʹ��
	int *p1 = p;//�����C���Բ����Ͻ��ĵط�
	*p1 = 10;
	printf("a = %d\n", a);
	return 0;
}

int main04()
{
	int a = 100000000;
	char *cp = &a;
	printf("%x, %x, %x, %x\n", *cp, *(cp + 1), *(cp + 2), *(cp + 3));
	printf("%x, %x, %x, %x\n", cp[0], cp[1], cp[2], cp[3]);

	cp += 5;//���ڴ���λ����5��sizeof(char)
	return 0;

	int buf[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int *p = buf;
	//p++;
	//buf++; //buf = buf + 1;buf������������һ��������������������ֵ
	//printf("%d\n", *p);
	printf("%d, %d\n", sizeof(p), sizeof(buf));// 4, 40

	p += 1;//4���ֽ�
	p += 2;//8���ֽ�
	p += 5;// 5 * sizeof(int) = 20���ֽ�

	int i;
	for (i = 0; i < 10; i++)
	{
		printf("%d\n", p[i]);//C��������ָ��ͨ�������±�ķ������������Ա
	}
	return 0;
}

int main()
{
	int buf[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int *p = buf;
	//����һ
	*(p + 3) = 20;//���������±�Ϊ3�ĳ�Ա��ֵ
				  //������
	p[5] = 30;//���������±�Ϊ5�ĳ�Ա��ֵ
			  //������
	p += 7;
	*p = 40;//���������±�Ϊ7�ĳ�Ա��ֵ

			//����һ�ͷ�������û�иı�pָ����ڴ��ַ�����������޸���pָ���ֵ

	p[2] = 100;//���ʱ���޸����±�Ϊ���ٵ������Ա
			   //*(p + 2) = 100;

	int i;
	for (i = 0; i < 10; i++)
	{
		printf("%d\n", buf[i]);
	}

}

