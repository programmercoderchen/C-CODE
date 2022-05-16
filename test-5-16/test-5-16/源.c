#include <stdio.h>
#include <stdlib.h>
//计算柔性数组的大小
//深入了解柔性数组
//struct s
//{
//	int a;
//	int arr[0];
//};
//int main()
//{
//	//struct s a;
//	//printf("%d\n", sizeof(a));
//	struct s* ps = (struct s*)malloc(sizeof(struct s) + 5 * sizeof(int));
//	ps->a = 100;
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		ps->arr[i] = i;
//	}
//	struct s*ptr = realloc(ps, 44);
//	if (ptr != NULL)
//	{
//		ps = ptr;
//	}
//	for (i = 5; i < 10; i++)
//	{
//		ps->arr[i] = i;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", ps->arr[i]);
//	}
//	printf("\n");
//	free(ps);
//	ps = NULL;
//	return 0;
//}
//struct s
//{
//	int a;
//	int* arr;
//};
//
//int main()
//{
//	struct s*ps = (struct s*)malloc(sizeof(struct s));
//	ps->arr = malloc(5 * sizeof(int));
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		ps->arr[i] = i;
//	}
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", ps->arr[i]);
//	}
//	printf("\n");
//	return 0;
//}
//方便内存释放
//有利于访问速度

//写法一：
struct s
{
	int a;
	char b;
	int arr[];
};
//写法二：
struct s
{
	int a;
	char b;
	int arr[0];
};