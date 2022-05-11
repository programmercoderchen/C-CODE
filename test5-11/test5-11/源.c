#include <stdio.h>
#include <assert.h>
//void* my_memcpy(void* dest, const void* str, size_t num)
//{
//	char* ret = dest;
//	assert(dest!=NULL);
//	assert(str != NULL);
//	while (num--)
//	{
//		*(char*)dest = *(char*)str;
//		++(char*)dest;
//		++(char*)str;
//	}
//	return ret;
//}

//int main()
//{
//	int arr1[] = { 1, 2, 3, 4, 5 };
//	int arr2[10] = { 0 };
//	int i = 0;
//	my_memcpy(arr2, arr1, sizeof(arr1));
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//	printf("\n");
//	return 0;
//}
//void* my_memcpy(void* dest, const void* str, size_t num)
//{
//	char* ret = dest;
//	assert(dest != NULL);
//	assert(str != NULL);
//	if (dest<str)//从前向后拷贝
//	{
//		while (num--)
//		{
//			*(char*)dest = *(char*)str;
//			++(char*)dest;
//			++(char*)str;
//		}
//	}
//	else//从后向前拷贝
//	{
//		*((char*)dest + num) = *((char*)str + num);
//	}
//	return ret;
//}
//int main()
//{
//	int arr1[5] = { 1, 2, 3, 4, 5 };
//	int i = 0;
//	my_memcpy(arr1+2, arr1, sizeof(arr1));
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	printf("\n");
//	return 0;
//}
