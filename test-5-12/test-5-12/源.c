#include <stdio.h>
#include <math.h>
//ţ������ʮ�ŵ���Ŀ�����������ε��ܳ������
//int main()
//{
//	float a, b, c, d, s;
//	scanf_s("%f %f %f", &a, &b, &c);
//	if (a + b > c || a + c > b || b + c > a)
//	{
//		float p = 0;
//		printf("����һ��������������\n");
//		d = a + b + c;
//		p = (a + b + c) / 2.0;
//		s = sqrt(p*(p - a)*(p - b)*(p - c));
//		printf("%f %f", d, s);
//	}
//	else
//	{
//		printf("�޷�����һ��������������\n");
//	}
//	return 0;
//}
//�ش���ȷ
//ţ�����ڶ�ʮ����Ŀ��������������
//int main()
//{
//	double r = 0;
//	double v = 0;
//	double pai = 3.1415926;
//	scanf_s("%lf", &r);
//	v = 4 / 3 * pai*r*r*r;
//	printf("%.3lf\n", v);
//	return 0;
//}
//�ش���ȷ
//ţ�����ڶ�ʮһ����Ŀ��������Ƴɼ�
//int main()
//{
//	int a, b, c;
//	scanf_s("%d %d %d", &a, &b, &c);
//	printf("%d %d %d", a, b, c);
//	return 0;
//}
//ţ�����ڶ�ʮ������Ŀ������ˮ�ɻ���
//int main()
//{
//	int i = 0;
//	for (i = 10000; i <= 99999; i++)
//	{
//		int j = 0;
//		int sum = 0;
//		for (j = 10; j <= 10000; j *= 10)
//		{
//			sum += ((i / j)*(i%j));
//		}
//		if (sum == i)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}
//ע�⸳ֵ���͵��ڵ�����Ҫ�������
//ţ�����ڶ�ʮ�����⣺kiki����
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf_s("%d %d", &a, &b);
//	//int ret = ((a % 100) + (b % 100)) % 100;
//	int ret = (a + b) % 100;
//	printf("%d\n", ret);
//	return 0;
//}
//ţ�����ڶ�ʮ�ĵ��⣺�������ĸ�λ����
//int main()
//{
//	float s = 0;
//	int ret = 0;
//	scanf_s("%f", &s);
//	ret = (int)s % 10;
//	printf("%d", ret);
//	return 0;
//}
//ţ�����ڶ�ʮ����⣺�ܻ������
//int main()
//{
//	int age = 0;
//	scanf_s("%d", &age);
//	//sec = age * 31560000;
//	long sec = age*3.156e7;
//	printf("%lld", sec);
//	return 0;
//}