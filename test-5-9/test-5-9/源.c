#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <ctype.h>
//ţ�����������Ŀ��ʵ�ִ�Сд��ĸ��ת��
//int main()
//{
//	int ch = 0;
//	ch = getchar();
//	ch += 32;
//	putchar(ch);
//	return 0;
//}
//�ش����ʾ��
//int main()
//{
//	int ch = 0;
//	//EOF=-1  �����ļ������ı�־
//	while ((ch = getchar()) != EOF)
//	{
//		//putchar(ch+32);
//		//printf("\n");
//		printf("%c\n", ch + 32);
//		getchar();
//	}
//	return 0;
//}
//�ش���ȷ
//ţ������������Ŀ��С�ɻ�
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
//�ش���ȷ
//ţ�������ߵ���Ŀ��ʮ������ת���ʮ����
//int main()
//{
//	printf("%15d\n", 0xABCDEF);
//	return 0;
//}
//�ش���ȷ
//ţ�����ڰ˵���Ŀ��printf�����ķ���ֵ
//int main()
//{
//	int a=printf("hallo world");
//	printf("\n");
//	printf("%d\n", a);
//	return 0;
//}
//�ⷨһ
//int main()
//{
//	int a = printf("hallo world");
//	printf("\n%d\n", a);
//	return 0;
//}
//�ⷨ��
//int main()
//{
//	printf("\n%d\n", printf("hallo world"));
//	return 0;
//}
//�ⷨ��
//˼����
//int main()
//{
//	printf("%d\n", printf("%d", printf("%d", 43)));
//	return 0;
//}
//��ӡ4321
//ţ�����ھŵ���Ŀ��ѧ��������Ϣ���������
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
//�ش���ȷ
//ţ������ʮ����Ŀ���ж���ĸ
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
//		getchar();//����\n
//	}
//	return 0;
//}
//�ⷨһ
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
//		getchar();//����\n
//	}
//	return 0;
//}
//�ⷨ��
//ţ������ʮһ����Ŀ���ַ�������
//int main()
//{
//	char n = 0;
//	n=getchar();
//	int i = 0;
//	for (i = 0; i < 5; i++)//���еĴ�ӡ
//	{
//		int j = 0;
//		for (j = 0; j < 4 - i; j++)//��ӡ�ո�
//		{
//			printf(" ");
//		}
//		for (j = 0; j <= i; j++)//��ӡ��Ҫ���ַ�
//		{
//			printf("%c ", n);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//�ش���ȷ
//ţ������ʮ������Ŀ��ASCII��ֵ
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
//�ش���ȷ
//ţ������ʮ������Ŀ���������ڵ��������
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
//�ش���ȷ
//ţ������ʮ�ĵ���Ŀ��2��n�η�����
//int main()
//{
//	int n = 0;
//	while ((scanf("%d", &n)) != EOF)
//	{
//		printf("%d\n", 1 << n);
//	}
//	return 0;
//}
//�ش���ȷ
//ţ������ʮ�����Ŀ�����ո�ʽ���벢�������
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
//�ⷨһ
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
//ʹ�ú���ʵ�ֵĴ������
//ţ������ʮ������Ŀ���ַ�תASCII��
//int main()
//{
//	char a = getchar();
//	printf("%d\n", a);
//	return 0;
//}
//�ش���ȷ
//ţ������ʮ�ߵ���Ŀ����������ʽ��ֵ
//����(-8+22)*a-10+c/2
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
//�ش���ȷ
//ţ������ʮ�˵���Ŀ������������
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d%d", &a, &b);
//	printf("%d\n", a / b);
//	printf("%d\n", a%b);
//	return 0;
//}
//�ش���ȷ