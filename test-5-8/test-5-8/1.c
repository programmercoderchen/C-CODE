#define _CRT_SECURE_NO_WARNINGS 0
#include <stdio.h>
#include <string.h>
//ţ������һ���⣺ʵ�����֪��
//int main()
//{
//	printf("ʵ�����֪��\n");
//	printf("ʵ�����֪��\n");
//	printf("ʵ�����֪��\n");
//	printf("ʵ�����֪��\n");
//	return 0;
//}
//�ش���ȷ
//ţ�����ڶ�����Ŀ�����Ǵ�V
//int main()
//{
//	//��ӡ���vʵ��һ����V
//	printf("v   v\n v v \n  v  \n");
//	//printf(" v v \n");
//	//printf("  v  \n");
//	return 0;
//}
//�ش���ȷ
//ţ������������Ŀ�������˴�
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
	//���Խ����ڴ洦��ĸĽ�
//}
//�ش���ȷ
//ţ�������ĵ���Ŀ�����̶���������
//int main()
//{
//	printf("0%o 0X%X\n", 1234,1234);
//	printf("%#o %#X\n", 1234, 1234);
//	return 0;
//}
//ע��ʮ�����ƺͰ˽��ƶ�Ӧ��ת���ַ�
//ţ�����������Ŀ�����������λ��
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
//�ش���ȷ