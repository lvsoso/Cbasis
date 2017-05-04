#include <stdio.h>

int main01()
{
	int* a[10];//定义一个指针数组，一共10个成员，其中每个成员都是int* 类型
	printf("%d, %d\n", sizeof(a), sizeof(a[0]));

	short* b[10];//定义一个指针数组，一共10个成员，其中每个成员都是short* 类型
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
	pp = &p;//定义了一个二级指针，指向了一个一级指针的地址
	**pp = 100;//通过二级指针修改内存的值
	//*pp = 10;//相当于将p指向了编号为10的这块内存,pp还是正常的指针，但p被修改成了野指针
	printf("a = %d\n", a);

	int ***ppp;
	ppp = &pp;//定义一个三级指针，指向一个二级指针的地址
	***ppp = 0;
	printf("a = %d\n", a);

	a = ppp;//等同于a = &pp
	printf("%d, %d, %d, %d\n", ***ppp, &p, &pp, &ppp);//
	return 0;

}