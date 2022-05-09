#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <ctype.h>
//牛客网第五道题目：实现大小写字母的转换
//int main()
//{
//	int ch = 0;
//	ch = getchar();
//	ch += 32;
//	putchar(ch);
//	return 0;
//}
//回答错误示范
//int main()
//{
//	int ch = 0;
//	//EOF=-1  代表文件结束的标志
//	while ((ch = getchar()) != EOF)
//	{
//		//putchar(ch+32);
//		//printf("\n");
//		printf("%c\n", ch + 32);
//		getchar();
//	}
//	return 0;
//}
//回答正确
//牛客网第六道题目：小飞机
//int main()
//{
//	printf("     **\n");
//	printf("     **\n");
//	printf("************\n");
//	printf("************\n");
//	printf("    *  *\n");
//	printf("    *  *\n");
//	return 0;
//}
//回答正确
//牛客网第七道题目：十六进制转变成十进制
//int main()
//{
//	printf("%15d\n", 0xABCDEF);
//	return 0;
//}
//回答正确
//牛客网第八道题目：printf函数的返回值
//int main()
//{
//	int a=printf("hallo world");
//	printf("\n");
//	printf("%d\n", a);
//	return 0;
//}
//解法一
//int main()
//{
//	int a = printf("hallo world");
//	printf("\n%d\n", a);
//	return 0;
//}
//解法二
//int main()
//{
//	printf("\n%d\n", printf("hallo world"));
//	return 0;
//}
//解法三
//思考：
//int main()
//{
//	printf("%d\n", printf("%d", printf("%d", 43)));
//	return 0;
//}
//打印4321
//牛客网第九道题目：学生基础信息的输入输出
//int main()
//{
//	int id = 0;
//	float C_score = 0;
//	float math_score = 0;
//	float eng_score = 0;
//	scanf("%d;%f,%f,%f", id, C_score, math_score, eng_score);
//	printf("The each subject score of number %d is %.2f,%.2f,%.2f", id, C_score, math_score, eng_score);
//	return 0;
//}
//回答正确
//牛客网第十道题目：判断字母
//int main()
//{
//	int ch = 0;
//	while ((ch=getchar()) != EOF)
//	{
//		if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z'))
//		{
//			printf("yes\n");
//		}
//		else
//		{
//			printf("no\n");
//		}
//		getchar();//处理\n
//	}
//	return 0;
//}
//解法一
//int main()
//{
//	int ch = 0;
//	while ((ch = getchar()) != EOF)
//	{
//		if (isalpha(ch))
//		{
//			printf("yes\n");
//		}
//		else
//		{
//			printf("no\n");
//		}
//		getchar();//处理\n
//	}
//	return 0;
//}
//解法二
//牛客网第十一道题目：字符金字塔
//int main()
//{
//	char n = 0;
//	n=getchar();
//	int i = 0;
//	for (i = 0; i < 5; i++)//五行的打印
//	{
//		int j = 0;
//		for (j = 0; j < 4 - i; j++)//打印空格
//		{
//			printf(" ");
//		}
//		for (j = 0; j <= i; j++)//打印想要的字符
//		{
//			printf("%c ", n);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//回答正确
//牛客网第十二道题目：ASCII码值
//int main()
//{
//	char arr[] = { 73, 32, 99, 97, 110, 32, 100, 111, 32, 105, 116, 33 };
//	int i = 0;
//	int sz = sizeof(arr)/sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%c ", arr[i]);
//	}
//	return 0;
//}
//I can do it!
//回答正确
//牛客网第十三道题目：出生日期的输入输出
//int main()
//{
//	int year = 0;
//	int mouth = 0;
//	int day = 0;
//	scanf("%4d%2d%2d", &year, &mouth, &day);
//	printf("%4d\n", year);
//	printf("%02d\n", mouth);
//	printf("%02d\n", day);
//	return 0;
//}
//回答正确
//牛客网第十四道题目：2的n次方计算
//int main()
//{
//	int n = 0;
//	while ((scanf("%d", &n)) != EOF)
//	{
//		printf("%d\n", 1 << n);
//	}
//	return 0;
//}
//回答正确
//牛客网第十五道题目：按照格式输入并交换输出
//int main()
//{
//	int x = 0;
//	int y = 0;
//	int tmp = 0;
//	scanf("%d%d", &x, &y);
//	tmp = x;
//	x = y; 
//	y = tmp;
//	printf("%d,%d", x, y);
//	return 0;
//}
//解法一
//void swap(int a, int b)
//{
//	int tmp = 0;
//	tmp = a;
//	a = b; 
//	b = tmp;
//	return 0;
//}
//int main()
//{
//	int x = 0;
//	int y = 0;
//	scanf("%d%d", &x, &y);
//	swap(x, y);
//	printf("%d,%d", x, y);
//	return 0;
//}
//使用函数实现的错误代码
//牛客网第十六道题目：字符转ASCII码
//int main()
//{
//	char a = getchar();
//	printf("%d\n", a);
//	return 0;
//}
//回答正确
//牛客网第十七道题目：计算机表达式的值
//计算(-8+22)*a-10+c/2
//int main()
//{
//	int a = 40;
//	int c = 212;
//	int b = 0;
//	b = (-8 + 22)*a - 10 + c / 2;
//	printf("%d", b);
//	return 0;
//}
//int main()
//{
//	int a = 40;
//	int c = 212;
//	int b = 0;
//	printf("%d\n", (- 8 + 22)*a - 10 + c / 2);
//	return 0;
//}
//回答正确
//牛客网第十八道题目：计算带余除法
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d%d", &a, &b);
//	printf("%d\n", a / b);
//	printf("%d\n", a%b);
//	return 0;
//}
//回答正确