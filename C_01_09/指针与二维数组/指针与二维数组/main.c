#include<stdio.h>

int main01()
{
	int buf[2][3] = { {1, 2, 3}, {4, 5, 6} };

	//int* [p];//指针数组
	int(*p)[3];//定义了一个指针，指向int [3]这种数据类型，指向二维数组的指针

	p = buf;//p指向了二维数组中的第一行
			//p++;//指向了第二行
	printf("%d\n", sizeof(p));
	printf("%d, %d\n", p, p + 2);//位移了2 * sizeof(int [3])

	int i;
	int j;
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%d\n", *(*(p + i) + j));
			printf("%d\n", p[i][j]);
		}
	}

	return 0;

}

int main()
{
	int buf1[3][5] = { { 2, 4, 3, 5, 3 },{ 7, 2, 6, 8, 1 },{ 7, 3, 9, 0, 2 } };
	///不允许使用数组下标，只能通过指向二维数组的指针求出数组中每行和每列的平均值


	int i;
	int j;
	for (i = 0; i < 3; i++)
	{
		int sum = 0;
		for (j = 0; j < 5; j++)
		{
			sum += (*(*(buf1 + i) + j));
			//sum += buf1[i][j];
		}
		printf("%d\n", sum / 5);
	}

	printf("-------------------\n");

	for (i = 0; i < 5; i++)
	{
		int sum = 0;
		for (j = 0; j < 3; j++)
		{
			sum += (*(*(buf1 + j) + i));
			//sum += buf1[j][i];
		}
		printf("%d\n", sum / 3);
	}

	return 0;
}