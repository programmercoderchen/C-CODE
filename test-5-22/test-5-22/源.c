#include <stdio.h>
//ʹ�ú����ͺ궨��֮�������
#define MAX(X,Y) ((X)>(Y)?(X):(Y))

int Max(int x, int y)
{
	return (x > y ? x : y);
}
int main()
{
	int a = 10;
	int b = 12;
	int max = Max(a,b);
	printf("%d\n", max);
	max = MAX(a, b);
	printf("%d\n", max);
	return 0;
}