#include <stdio.h>

int main01()
{
	int* a[10];//����һ��ָ�����飬һ��10����Ա������ÿ����Ա����int* ����
	printf("%d, %d\n", sizeof(a), sizeof(a[0]));

	short* b[10];//����һ��ָ�����飬һ��10����Ա������ÿ����Ա����short* ����
	printf("%d, %d\n", sizeof(b), sizeof(b[0]));

	int a1;
	short a2;
	
	a[0] = &a1;
	b[0] = &a2;


	return 0;
}

int main()
{
	int a = 10;
	int *p = &a;
	int **pp;
	pp = &p;//������һ������ָ�룬ָ����һ��һ��ָ��ĵ�ַ
	**pp = 100;//ͨ������ָ���޸��ڴ��ֵ
	//*pp = 10;//�൱�ڽ�pָ���˱��Ϊ10������ڴ�,pp����������ָ�룬��p���޸ĳ���Ұָ��
	printf("a = %d\n", a);

	int ***ppp;
	ppp = &pp;//����һ������ָ�룬ָ��һ������ָ��ĵ�ַ
	***ppp = 0;
	printf("a = %d\n", a);

	a = ppp;//��ͬ��a = &pp
	printf("%d, %d, %d, %d\n", ***ppp, &p, &pp, &ppp);//
	return 0;

}