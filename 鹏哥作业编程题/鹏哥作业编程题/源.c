#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
//#include <assert.h>
//
//
//void reserve(char* arr)
//{
//	assert(arr);
//	int len = strlen(arr);
//	char* left = arr;
//	char* right = arr + len - 1;
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right++;
//	}
//}
//int main()
//{
//	char arr[200] = { 0 };
//	gets(arr);
//	reserve(arr);
//	printf("%s\n", arr);
//	return 0;
//}
//int main()//喝汽水题目
//{
//	int money = 0;
//	int total = 0;
//	int empty = 0;
//	scanf("%d", &money);
//	//买回来的汽水喝掉
//	total = money;
//	empty = money;
//	//用空瓶换的汽水
//	while (empty >= 2)
//	{
//		total += empty / 2;
//		empty = empty / 2 + empty % 2;
//	}
//	printf("喝到的汽水有：%d\n", total);
//	return 0;
//}
//void print(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//void move(int arr[], int sz)
//{
//	int left = 0;
//	int right = sz-1;
//	//从左边找偶数
//	while (left < right)
//	{
//		//从左边找偶数
//		while ((left < right) && (arr[left] % 2 == 1))
//		{
//			left++;
//		}
//		//从右边找奇数
//		while ((left < right) && (arr[right] % 2 == 0))
//		{
//			right--;
//		}
//		if (left < right)
//		{
//			int tmp = arr[left];
//			arr[left] = arr[right];
//			arr[right] = tmp;
//		}
//	}
//}
//int main()
//{
//	int arr[]={ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int sz = sizeof(arr)/sizeof(arr[0]);
//	move(arr, sz);//实现交换
//	print(arr, sz);//打印数组
//	return 0;
//}
//谁是凶手？
//int main()
//{
//	int killer = 0;
//	for (killer = 'a'; killer <= 'd'; killer++)
//	{
//		if ((killer != 'a') + (killer == 'c') + (killer == 'd') + (killer != 'd') == 3)
//		{
//			printf("killer=%c\n", killer);
//		}
//	}
//	return 0;
//}