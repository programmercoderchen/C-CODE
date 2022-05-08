#define _CRT_SECURE_NO_WARNINGS 0
#include <stdio.h>
#include <string.h>
//牛客网第一道题：实验出真知！
//int main()
//{
//	printf("实验出真知！\n");
//	printf("实验出真知！\n");
//	printf("实验出真知！\n");
//	printf("实验出真知！\n");
//	return 0;
//}
//回答正确
//牛客网第二道题目：我是大V
//int main()
//{
//	//打印五个v实现一个大V
//	printf("v   v\n v v \n  v  \n");
//	//printf(" v v \n");
//	//printf("  v  \n");
//	return 0;
//}
//回答正确
//牛客网第三道题目：有容乃大
//int main()
//{
	//int a, b, c, d;
	//a = sizeof(short);
	//b = sizeof(int);
	//c = sizeof(long);
	//d = sizeof(long long);
	//printf("The size of short is %d bytes\n", a);
	//printf("The size of int is %d bytes\n", b);
	//printf("The size of long is %d bytes\n", c);
	//printf("The size of long long is %d bytes\n", d);
	//return 0;
	//printf("The size of short is %d bytes\n", sizeof(short));
	//printf("The size of int is %d bytes\n", sizeof(int));
	//printf("The size of long is %d bytes\n", sizeof(long));
	//printf("The size of long long is %d bytes\n", sizeof(long long));
	//return 0;
	//可以进行内存处理的改进
//}
//回答正确
//牛客网第四道题目：缩短二进制数字
//int main()
//{
//	printf("0%o 0X%X\n", 1234,1234);
//	printf("%#o %#X\n", 1234, 1234);
//	return 0;
//}
//注意十六进制和八进制对应的转义字符
//牛客网第五道题目：反向输出四位数
int main()
{
	int n = 0;
	scanf("%d", &n);
	while (n)
	{
		printf("%d", n % 10);
		n /= 10;
	}
	return 0;
}
//回答正确