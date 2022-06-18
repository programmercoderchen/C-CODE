/******************************************************
��Ŀ����ѧ���ɼ�����ϵͳ
רҵ           ѧ��             ����            �ɼ�

Ҫ�����ɲ˵����˵��е�ÿ�����һ���������
ע�⣺��۲캯�����β����������Ķ��巽ʽ�Լ��ڵ��ú���ʱ��������ĸ�ʽ

1.ͳ��ѧ����countStuNum()
2.ͳ�Ʒ���������countScoreSegment()������״ͼ��ʽ��ʾ�����������
3.ͳ����߷�countMaxScore()
4.��ͷ�countMinScore()
5.ƽ����countAverageScore()
6.�ɼ���ֵcountMedian()
7.���Բ���linerSearchScore()
8.������binSearchScore()
9.��ӳɼ�appendScore()������Ч�����������ӳɼ�,����Ԫ��-1��ʾ�����������һ������Ϊ��Ч����
10.����ɼ�insertScore()����ָ��λ�ò���ɼ���
11.ɾ��ĳ��ָ��λ�õĳɼ�deleteScore()
12.ð������bubbleSort()
13.�����㷨swap()
14.�Գɼ���������reverseSort()
15.��ʾ������Ч�ɼ�displayArray()
**********************************************************/
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#define SIZE 30  //�ɼ������ܳ���
#define SEGMENTSIZE 11  //�������ܹ���0-10���ܼ�11����
#define FAILURE -1  //����ʧ�ܽ��
#define SUCCESS 1   //���سɹ����
#define ASCEND 1    //����
#define DECEND -1   //����
//#define _CRT_SECURE_NO_WARNINGS 1

//��������
int countStuNum(int array[], int length); //ͳ��ѧ��������countStuNum
void countScoreSegment(int array[], int Len, int segment[], int segmentLen);//ͳ�Ʒ���������
int countMaxScore(int array[], int len);//ͳ����߷�
int countMinScore(int array[], int len);//ͳ����ͷ�
float countAverageScore(int array[], int len);//ͳ��ƽ����
float countMedian(int array[], int len);//ͳ�Ƴɼ���ֵ
int linerSearchScore(int array[], int len, int searchNum);//���Բ���
int binSearchScore(int array[], int len, int searchNum);//������
int appendScore(int array[], int length, int appendScore);//��ӳɼ�
int insertScore(int array[], int length, int insertScore, int insertPossition);//����ɼ�
int deleteScore(int array[], int length, int deletePossition);//ɾ���ɼ�
void bubbleSort(int array[], int length, int sortOrder);//ð������
void reverseSort(int array[], int length); //��������
void displayArray(int array[]);  //��ʾ����������Ч����
int checkBoundary(int inputValue, int min, int max); //��������������Ч�߽���
void swap(int* a, int* b);//�����㷨
void versionAbout();//����汾˵��

void main()
{
	//ע����������25��ѧ��������������һ��-1��ʾ��Ԫ��֮ǰ������Ԫ��ֵΪ��Ч������
	int i=0;
	int scoreSegment[SEGMENTSIZE] = { 0 };//���������ڴ��ͳ�Ƹ������ε�������������Ϊ0-10
	int stuNumber=0, maxScore=0, minScore=0, searchArrayPosition=0;
	int searchScore=0, appendScoreNum=0, insertScoreNum=0, result=0, arrayPossition=0;
	int order=0;//������
	float averageScore=0, medianScore=0;
	int choiceNum=0;
	FILE*fp = NULL;//�ļ�ָ�����ڶ�ȡ�ļ��е�����
	int score[30];
	int x = 0;
	fp = fopen("data.txt", "r");
	while (fscanf(fp, "%d", &score[x]) != EOF)
	{
		x++;
	}
	enum Status { GAMEOVER, CONTINUE };
	enum Status gameStatus;

	do
	{
		gameStatus = CONTINUE;
		printf("\n\t\tѧ  ��  ��  ��  ��  ��  ϵ  ͳ  1.3 \n\t\t\tDesigned by HuangX\n");
		printf("\n\t1.ͳ��ѧ����\t\t\t2.ͳ�Ʒ���������\n\n");
		printf("\t3.ͳ����߷�\t\t\t4.ͳ����ͷ�\n\n");
		printf("\t5.ͳ��ƽ����\t\t\t6.ͳ����ֵ\n\n");
		printf("\t7.���Բ���\t\t\t8.������\n\n");
		printf("\t9.��ӳɼ�\t\t\t10.����ɼ�\n\n");
		printf("\t11.ɾ��ĳ��ָ��λ�õĳɼ�\t12.ð������\n\n");
		printf("\t13.��������\t\t\t14.��ʾ������Ч�ɼ�\n\n");
		printf("\t15.�汾����˵��\n\n");
		printf("\t0.�˳�\n\n\t��ѡ���ܣ�");
		scanf_s("%d", &choiceNum);
		fflush(stdin);//������̻��������������������ַ�ʱ�������ѭ��
		switch (choiceNum)
		{
		case 0:
			gameStatus = GAMEOVER;
			break;
		case 1:
			//ͳ��ѧ����
			stuNumber = countStuNum(score, SIZE); //��ϸ��ͳ�Ƽ�����ź���
												  //���ú���ͳ����Ч������ѧ��������
												  //�ѷ�����������score���������е��������array��
												  //��ע�⣬����ֻ����������,��score����Ĵ�СSIZE���������е��������length
												  //countStuNum(score,SIZE)����󷵻ص�ֵ�ŵ�stuNumber��

			printf("\n\t1.��Чѧ�������ĸ����ǣ�%d\n\n", stuNumber);
			displayArray(score);//��ʾ������Ч�ķ���
			system("pause"); //������ͣ
			break;
		case 2:
			//ͳ�Ʒ���������
			printf("���������д�ֶ�ͳ�Ƶĳ������ú���\n");
			countScoreSegment(score, SIZE, scoreSegment, SEGMENTSIZE);
			system("pause"); //������ͣ
			break;
		case 3:
			//ͳ����߷�
			printf("���������дͳ����߷ֵĳ������ú���\n");
			maxScore = countMaxScore(score, SIZE);
			printf("%d", maxScore);
			system("pause"); //������ͣ
			break;
		case 4:
			//ͳ����ͷ�
			printf("���������дͳ����ͷֵĳ������ú���\n");
			minScore = countMinScore(score, SIZE);
			printf("%d", minScore);
			system("pause"); //������ͣ
			break;
		case 5:
			//ͳ��ƽ����
			//float averageScore;
			//��дһ������ƽ���ֺ��������ú���ͳ��ƽ����,��ֵ��averageScore��
			averageScore = countAverageScore(score, SIZE);
			printf("\n\t5.ƽ�����ǣ�%.1f\n\n", averageScore);
			system("pause"); //������ͣ
			break;
		case 6:
			//��дͳ����ֵ����
			medianScore = countMedian(score, SIZE);
			printf("��ֵ��:%f", medianScore);
			system("pause"); //������ͣ
			break;
		case 7:
			//���Բ���
			printf("���Բ��ҵ�����:\n");
			scanf("%d", &searchScore);
			arrayPossition = linerSearchScore(score, SIZE, searchScore);
			printf("%d\n", arrayPossition+1);
			system("pause"); //������ͣ
			break;
		case 8:
			//��д�����ҳ���
			printf("�����ҵķ���:\n");
			scanf("%d", &searchScore);
			arrayPossition = binSearchScore(score, SIZE, searchScore);
			printf("���ڵ�λ���ǣ�%d", arrayPossition);
			system("pause"); //������ͣ
			break;
		case 9:
			//��ӳɼ�
			printf("Ҫ��ӵĳɼ�:\n");
			scanf("%d", &appendScoreNum);
			appendScore(score, SIZE, appendScoreNum);
			displayArray(score);
			system("pause"); //������ͣ
			break;
		case 10:
			//����ɼ�
			printf("Ҫ�������ֵ��±�:\n");
			scanf("%d", &arrayPossition);
			printf("Ҫ��������֣�\n");
			scanf("%d", &insertScoreNum);
			insertScore(score, SIZE, insertScoreNum, arrayPossition);
			system("pause"); //������ͣ
			break;
		case 11:
			//ɾ���ɼ�
			printf("Ҫɾ�����ֵ��±�:\n");
			scanf("%d", &arrayPossition);
			deleteScore(score, SIZE, arrayPossition);
			system("pause"); //������ͣ
			break;

		case 12:
			//�Գɼ�ð������
			while (1)
			{
				printf("��ѡ��˳��1����   -1���򣩣�");
				scanf("%d",&order);
				if (order == 1 || order == -1)
					break;
				else
					printf("�����������������");
			}
			bubbleSort(score, SIZE, order);
			system("pause"); //������ͣ
			break;

		case 13:
			//�Գɼ���������
			reverseSort(score, SIZE);
			system("pause"); //������ͣ
			break;
		case 14:
			//��ʾ������Ч�ɼ�
			displayArray(score);
			system("pause"); //������ͣ
			break;
		case 15:
			//�汾˵��
			versionAbout();
			break;
		default:
			printf("\n\tѡ�����������ʾ��Ŀ��Ӧ������������ѡ��!\n");
			system("pause"); //������ͣ
		}
		system("cls");//����
		choiceNum = -1;  //����ڶ��ֽ���˵�ѡ��ʱ�������ַ�������ŵȷ�����ʱ���ֵĴ���
	} while (gameStatus != GAMEOVER);

}  //end main()

   /**********************************************
   1.��������˵����ͳ����Ч������ѧ������
   �β�˵���� array[]  Ҫ����ͳ�Ƶ���������
   length   ��������ܳ���
   ����ֵ��   ������Чѧ������
   **********************************************/
   //ע���β�������Ķ����ʽ��ͨ���β���������飬
   //����˶����������⣬���ö�������ĳ��ȣ��Է�ֹԽ��
int countStuNum(int array[], int length)
{
	int i, stuNumber = 0;
	for (i = 0; i < length; i++)
		if (array[i] != -1) stuNumber++; //��Ϊ����Ľ�β��-1��ͳ�Ʒ�-1�ĸ���
		else break;
	return stuNumber;

} //countStuNum(int array[],int length)


  /**********************************************
  2.��������˵����ͳ�Ƹ�����������
  �β�˵���� array[]   Ҫ����ͳ�Ƶ���������
  len       ��������Чѧ����
  segment[] ���ڴ�ŷ���������
  ����ֵ��   ��
  **********************************************/
void countScoreSegment(int array[], int Len, int segment[], int segmentLen)
{

	//��״��ʾ������ε�����
	printf("\n\t2. ͳ����ʾ������ε�����\n");



}//end countScoreSegment(int array[],int len)


 /**********************************************
 3.��������˵����ͳ����߷�
 �β�˵���� array[] Ҫ����ͳ�Ƶ���������
 len     ��������Чѧ����
 ����ֵ��   ������߷�
 **********************************************/
int countMaxScore(int array[], int len)
{
	int max = 0;
	for (int i = 0; i < len; i++)
	{
		if (max <= array[i])
			max = array[i];
	}
	return max;

}  //countMaxScore(int array[],int len)


   /**********************************************
   4.��������˵����ͳ����ͷ�
   �β�˵���� array[]  Ҫ����ͳ�Ƶ���������
   len      ��������Чѧ����
   ����ֵ��   ������ͷ�
   **********************************************/
int countMinScore(int array[], int len)
{
	int min = 100;
	for (int i = 0; i < len-5; i++)
	{
		if (min >= array[i])
			min = array[i];
	}
	return min;

}//end countMinScore(int array[],int len)


 /**********************************************
 5.��������˵����ͳ��ƽ����
 �β�˵���� array[] Ҫ����ͳ�Ƶ���������
 len     ��������Чѧ����
 ����ֵ��   ����ƽ����
 **********************************************/
float countAverageScore(int array[], int len)
{
	int i=0, sum = 0;
	for (int i = 0; i < len; i++)
	{
		sum += array[i];
	}
	return (float)sum / len;

}//end countAverageScore

 /****************************************************************
 6.�������ܣ���ȫ��ѧ���ɼ�����ֵ
 (�������Ԫ�ظ���Ϊż������ֵ�������м�����Ԫ�ص�ƽ��ֵ)
 �β�˵����int array[]  ���ȫ��ɼ�������
 int len  ����ĳ���
 ����ֵ:   �ɼ�����ֵ
 *****************************************************************/
float countMedian(int array[], int len)
{
	float median=0;
	//ð������
	for (int i = 0; i<len; i++)
	{
		for (int j = 0; j<len - i - 1; j++)
		{
			if (array[j]>array[j + 1])
			{
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
	median = array[len / 2];
	return median;
}
/**********************************************
7.��������˵�������Բ���ĳһ�����������е�λ��
�β�˵���� array[]   Ҫ����ͳ�Ƶ���������
len       ��������Чѧ����
searchNum Ҫ���ҵ���
����ֵ��   �ҵ��˷��ط����������е�λ��(�±�)
�Ҳ���������-1
**********************************************/
int linerSearchScore(int array[], int len, int searchNum)
{
	int i, flag = 0, f_at;
	for (i = 0; i < len; i++)
	{
		if (array[i] == searchNum)
		{
			flag = 1;
			f_at = i;
		}
	}
	if (flag == 1) return f_at;
	else return FAILURE;
}//end linerSearchScore(int array[],int len,int searchNum)


 /**********************************************
 8.��������˵����������ĳһ�����������е�λ��
 �β�˵���� array[]   Ҫ����ͳ�Ƶ���������
 len       ��������Чѧ����
 searchNum Ҫ���ҵ���
 ����ֵ��   �ҵ��˷��ط����������е�λ��(�±�)
 �Ҳ���������-1
 **********************************************/
int binSearchScore(int array[], int len, int searchNum)
{
	int flag = 0, left = 0,  mid; 
	int right = (sizeof(array) / sizeof(array[0])) - 1;//Ҫע���ֹright�±�Խ��
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (searchNum == array[mid])
		{
			flag = 1;
			break;
		}
		else if (searchNum > array[mid])
			left = mid + 1;
		else right = mid - 1;
	}
	if (flag == 1) 
		return mid+1;
	else 
		return FAILURE;//�Ҳ���
}//end binSearchScore(int array[],int len,int searchNum)


 /**********************************************
 9.��������˵������ӳɼ�������Ч�����������ӳɼ���
 �β�˵���� array[]     Ҫ����ͳ�Ƶ���������
 length      �������ܳ���
 appendScore Ҫ��ӵĳɼ�
 ����ֵ��   SUCCESS  ��ʾ��ӳɹ�
 FAILURE  ��ʾ�����������޷����
 **********************************************/
int appendScore(int array[], int length, int appendScore)
{
	array[sizeof(array) / sizeof(array[0])] = appendScore;
	//return FAILURE; //������������һ��Ԫ�أ�����������
	return SUCCESS;
}//end appendScore(int array[],int len,int appendScore)


 /**********************************************
 10.��������˵��������ɼ�����ָ��λ�ò���ɼ���
 �β�˵���� array[]         Ҫ����ͳ�Ƶ���������
 length          �������ܳ���
 insertScore     Ҫ����ĳɼ�
 insertPossition Ҫ�����λ��
 ����ֵ��   SUCCESS  ��ʾ����ɹ�
 FAILURE  ��ʾ�����������޷�����
 **********************************************/
int insertScore(int array[], int length, int insertScore, int insertPossition)
{
	return SUCCESS;

}//end insertScore(int array[],int length,int insertScore)


 /**********************************************
 11.��������˵����ɾ��ĳ��ָ��λ�õĳɼ�
 �β�˵���� array[]         Ҫ����ͳ�Ƶ���������
 length          �������ܳ���
 deletePossition Ҫɾ��Ԫ�ص�λ��
 ����ֵ��   SUCCESS  ��ʾɾ���ɹ�
 **********************************************/
int deleteScore(int array[], int length, int deletePossition)
{
	if (deletePossition > 30 || deletePossition<0)
	{
		printf("Ҫɾ����λ��Խ�磬�޷�ɾ��");
	}
	else
	{
		char c;
		printf("%d\n", array[deletePossition - 1]);
		printf("�Ƿ�ȷ��Ҫɾ�����ϳɼ���Y/N����\n");
		scanf("%c", &c);
		if (c == 'Y' || c == 'y')
		{
			for (int i = deletePossition-1; i < length; i++)
				array[i] = array[i + 1];//���ݵĸ���
			length--;
		}
	}
	return SUCCESS;
}//end deleteScore(int array[],int len,int deletePossition)


 /**********************************************
 12.��������˵����ð������
 �β�˵���� array[]     Ҫ����ͳ�Ƶ���������
 length      �������ܳ���
 sortOrder   ������
 ASCEND   ����
 DECEND   ����

 ����ֵ��   ��
 **********************************************/
void bubbleSort(int array[], int length, int sortOrder)
{
	int i, j, k, stuNum;
	stuNum = countStuNum(array, length);//�õ���Ч�ɼ���ѧ������
	for (i = stuNum; i > 0; i--)   //iָ��i������
	{
		k = i;   //kָһ����Ҫ�ȽϽ�����Ԫ�ظ���
		if (sortOrder == ASCEND)  //��������
		{
			for (j = 0; j < k - 1; j++)
				if (array[j] > array[j + 1])
					swap(&array[j], &array[j + 1]);
		}
		else   //��������
		{
			for (j = 0; j < k - 1; j++)
				if (array[j] < array[j + 1])
					swap(&array[j], &array[j + 1]);
		}
	} //end for
}//end bubbleSort(int array[],int length,int sortOrder)

 /**********************************************
 16.��������˵���������㷨
 �β�˵���� *a   �����������ĵ�ַ
 *b   �����������ĵ�ַ
 ����ֵ��   ��
 **********************************************/
void swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}//swap(int *a,int *b)



 /**********************************************
 13.��������˵������������
 �β�˵���� array[]         Ҫ����ͳ�Ƶ���������
 length          �������ܳ���
 ����ֵ��   ��
 **********************************************/
void reverseSort(int array[], int length)
{
	int left, right, stuNum;
	stuNum = countStuNum(array, length);//�õ���Ч�ɼ���ѧ������
	right = stuNum - 1;//ע���ֹ�±�Խ��
	for (left = 0; left <= right; left++, right--)
		swap(&array[left], &array[right]); //�����㷨

}//end reverseSort(int array[],int length)


 /**********************************************
 14.��������˵������ʾ����������Ч����
 �β�˵���� array[]  Ҫ��ʾ����������
 ����ֵ��   ��
 **********************************************/
void displayArray(int array[])
{
	int i, len;
	len = countStuNum(array, SIZE); //���ú���countStuNum()�õ�������Ч��������
	printf("\t\t");
	for (i = 0; i < len; i++)
	{
		printf("[%2d] %-5d", i, array[i]); //���������Ч����
		if ((i + 1) % 5 == 0) printf("\n\t\t");  //ÿ�������
	}//end for
	printf("\n");
}//end displayArray(int array[],int len)

 /**********************************************
 15.��������˵��������汾����˵��
 �β�˵���� ��
 ����ֵ��   ��
 **********************************************/
void versionAbout()
{
	system("cls");//����
	printf("\n\t\tѧ  ��  ��  ��  ��  ��  ϵ  ͳ  1.3 �汾˵��\n\t\t\tDesigned by HuangX\n");
	printf("\n******************************************************************************\n");
	printf("\n# 1.1�汾�޸��˶�ε���ͳ�Ʒ����κ���ʱ�������ۼӵ����� \n");
	printf("\n\t��л2017��̨���˾�ͬѧ���ֵ�Bug! \n");

	printf("\n# 1.2�汾�޸��˵ڶ��ֽ���˵�ѡ��ʱ�������ַ�������ŵȷ�����ʱ���ֵĴ������� \n");
	printf("\n\t��л2017��̨��¿�褡�֣���ͬѧ���ֵ�Bug! \n");

	printf("\n# 1.3�汾�޸��˷�����ͳ��ʱ�������0��Ԫ��δ��ͳ�ƵĴ������� \n");
	printf("\n\t��л2017��̨��������ͬѧ���ֵ�Bug! \n");
	printf("\n# 1.3�汾����9��10��11�������������˱�Ҫ�ı߽������ʾ��Ϣ! \n");
	printf("\n******************************************************************************\n\n");
	system("pause"); //������ͣ
	system("cls");//����
}
/**********************************************
��������˵������������������Ч�߽���
�β�˵���� inputValue  ����ķ���
min         �߽����Сֵ
max         �߽�����ֵ
����ֵ��   ������Ч�����ط���
������Ч������FAILURE
**********************************************/
int checkBoundary(int inputValue, int min, int max)
{
	if (inputValue <= max && inputValue >= min)
		return inputValue;
	else return FAILURE;
}//end inputScore(int inputScore

