#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>    /*I/O����*/
#include<stdlib.h>  /*����˵��*/
#include<string.h>  /*�ַ�������*/
#define max 100
#define LEN 15      /* �˺ź���������ַ���,ʵ�������*/
#define N 100        /* ����˻���,ʵ�������*/

int k = 1, n = 0, m = 0;/* n����ǰ��¼��ѧ������*/
//�˻���Ϣ�ṹ��
struct banker
{
	char accountNo[LEN];
	char accountName[LEN];
	char Password[LEN];
	float Balance;
	char VIPoNormal[LEN];
}bank[N];
void fileWrite();

//��Ǯ
void Save()
{
	int item, i;
	char s1[LEN + 1]; //�������˺ŵ� 
	printf("��������Ҫ��Ǯ���˺�\n");
	scanf("%s", &s1);
	for (i = 0; i<n; i++)                  //n����ǰ��¼��
	{
		if (strcmp(s1, bank[i].accountNo) == 0)
		{
			item = i;
		}
	}
	printf("��������Ҫ��Ǯ�Ľ��\n");
	float wd = 0.0;
	scanf("%f", &wd);
	bank[item].Balance += wd;
	fileWrite();
	return;
}
//��ѯ�����˻���Ϣ
void seek()
{
	//�Ȱ��˻���Ϣ������	����������˺źͶ�Ӧ�����룬���������������� 
	int j = 0;
	FILE * fp;
	if ((fp = fopen("account.txt", "r")) == NULL)
		return;
	while (fscanf(fp, "%s %s %s %f %s\n", &bank[j].accountNo, &bank[j].accountName, &bank[j].Password, &bank[j].Balance, &bank[j].VIPoNormal) == 5)
	{
		j++;
	}
	n = j;
	int i = 0, item = 0, flag = 0;
	char s1[LEN + 1]; /* ���˺ź����������+1Ϊ׼*/  //�������˺ŵ� 
	char s2[LEN + 1]; /* ���˺ź����������+1Ϊ׼*/  //����������� 
	printf("��������Ҫ��ѯ���˺�\n");
	scanf("%s", &s1);
	for (i = 0; i<n; i++)                  //n����ǰ��¼��
	{
		if (strcmp(s1, bank[i].accountNo) == 0)
		{
			flag = 1;
			item = i;
		}
	}
	if (0 == flag)         //������˺źʹ�õ��˺Ų�һ��
		printf("���˺Ų����ڣ�\n");
	else{
		int flag1 = 0;//�ж����������Ƿ���ȷ 
		printf("��������Ҫ��ѯ���˺Ŷ�Ӧ������\n");
		scanf("%s", &s2);
		if (strcmp(s2, bank[item].Password) == 0)
		{
			flag1 = 1;
		}
		if (flag1 == 0){
			printf("�����������\n");//�����Ըģ��������룬��������whileѭ�� 
			return;
		}
		else{
			printf("����������ȷ\n");
			printf("�����Ϊ��%10.1f\n", bank[item].Balance);
		}

	}
	return;

}


//ȡ��ģ��
// vipһ�����3000 ��ͨ��2000
// ��ȡ��Ǯ���������ʧ��  ���û�����ѡ����������߷������˵�
// ȡǮ�������Ӧ�ĸ���  

void Withdraw()
{
	//���ȿ϶���Ҫ��ѯһ�� 
	//�Ȱ��˻���Ϣ������	����������˺źͶ�Ӧ�����룬���������������� 
	int j = 0;
	FILE * fp;
	if ((fp = fopen("account.txt", "r")) == NULL)
		return;
	while (fscanf(fp, "%s %s %s %f %s\n", &bank[j].accountNo, &bank[j].accountName, &bank[j].Password, &bank[j].Balance, &bank[j].VIPoNormal) == 5)
	{
		j++;
	}
	n = j;
	int i = 0, item = 0, flag = 0;
	char s1[LEN + 1]; /* ���˺ź����������+1Ϊ׼*/  //�������˺ŵ� 
	char s2[LEN + 1]; /* ���˺ź����������+1Ϊ׼*/  //����������� 
	printf("�������˺�\n");
	scanf("%s", &s1);
	for (i = 0; i<n; i++)                  //n����ǰ��¼��
	{
		if (strcmp(s1, bank[i].accountNo) == 0)
		{
			flag = 1;
			item = i;
		}
	}
	if (0 == flag)         //������˺źʹ�õ��˺Ų�һ��
		printf("���˺Ų����ڣ�\n");
	else{
		int flag1 = 0;//�ж����������Ƿ���ȷ 
		printf("��������Ҫ��ѯ���˺Ŷ�Ӧ������\n");
		scanf("%s", &s2);
		if (strcmp(s2, bank[item].Password) == 0)
		{
			flag1 = 1;
		}
		if (flag1 == 0){
			printf("�����������\n");//�����Ըģ��������룬��������whileѭ�� 
			return;
		}
		else{
			printf("����������ȷ\n");
			printf("�����Ϊ��%10.1f\n", bank[item].Balance);
			printf("��������Ҫȡ��Ľ��");
			printf("�����˻�������%s\n", bank[item].VIPoNormal);
			printf("*****ע�����*****\n");
			printf("ȡ����ܳ����޶�\n");
			printf("V�����û�����ȡ��ó���3000Ԫ\n");
			printf("N�����û�����ȡ��ó���2000Ԫ\n");
			//�ж�����
			float jud = 0.0;
			if (strcmp(bank[item].VIPoNormal, "V") == 0)
			{
				jud = 3000;
			}
			else jud = 2000;
			float wd = 0.0;
			scanf("%f", &wd);
			while (bank[item].Balance<wd || wd>jud)
			{
				printf("���벻���Ϲ淶���밴��ע�������������");
				scanf("%f", &wd);
			}
			//ȡ��֮��ĸ��²���
			bank[item].Balance -= wd;
			fileWrite();

		}

	}

	return;
}

//ת��
void Transfer()
{
	//���ȿ϶���Ҫ��ѯһ�� 
	//�Ȱ��˻���Ϣ������	����������˺źͶ�Ӧ�����룬���������������� 
	int j = 0;
	FILE * fp;
	if ((fp = fopen("account.txt", "r")) == NULL)
		return;
	while (fscanf(fp, "%s %s %s %f %s\n", &bank[j].accountNo, &bank[j].accountName, &bank[j].Password, &bank[j].Balance, &bank[j].VIPoNormal) == 5)
	{
		j++;
	}
	n = j;
	int i = 0, item = 0, flag = 0;
	char s1[LEN + 1]; /* ���˺ź����������+1Ϊ׼*/  //�������˺ŵ� 
	char s2[LEN + 1]; /* ���˺ź����������+1Ϊ׼*/  //����������� 
	printf("�������˺�\n");
	scanf("%s", &s1);
	for (i = 0; i<n; i++)                  //n����ǰ��¼��
	{
		if (strcmp(s1, bank[i].accountNo) == 0)
		{
			flag = 1;
			item = i;
		}
	}
	if (0 == flag)
		printf("���˺Ų����ڣ�\n");
	else{
		int flag1 = 0;//�ж����������Ƿ���ȷ 
		printf("�������˺Ŷ�Ӧ������\n");
		scanf("%s", &s2);
		if (strcmp(s2, bank[item].Password) == 0)
		{
			flag1 = 1;
		}
		if (flag1 == 0){
			printf("�����������\n");//�����Ըģ��������룬��������whileѭ�� 
			return;
		}
		else{
			printf("����������ȷ\n");
			printf("�����Ϊ��%10.1f\n", bank[item].Balance);
			printf("�����˻�������%s\n", bank[item].VIPoNormal);
			printf("��������Ҫת�˵��˻�");
			int flag2 = 0;
			char s3[LEN + 1];
			int item2 = 0;//���Ŀ���˻� 
			scanf("%s", &s3);
			for (i = 0; i<n; i++)
			{
				if (strcmp(s3, bank[i].accountNo) == 0)
				{
					flag2 = 1;
					item2 = i;
				}
			}
			while (flag2 == 0){
				printf("�˻�������������������");
				scanf("%s", &s3);
				for (i = 0; i<n; i++)
				{
					if (strcmp(s3, bank[i].accountNo) == 0)
					{
						flag2 = 1;
						item2 = i;
						printf("accountNo    accountName  Password   Balance  VIPoNormal  \n");
						printf("--------------------------------------------------------------------\n");
						printf("%s %16s %10s %10.1f  %s\n", bank[i].accountNo, bank[i].accountName, bank[i].Password, bank[i].Balance, bank[i].VIPoNormal);
					}
				}
			}

			printf("*****ע�����*****\n");
			printf("ת�˽��ܳ����޶�\n");
			printf("V�����û�����ת�˲��ó���20000Ԫ\n");
			printf("N�����û�����ת�˲��ó���10000Ԫ\n");
			printf("��������Ҫת�˵Ľ��\n");
			float jud = 0.0;
			if (strcmp(bank[item].VIPoNormal, "V") == 0)
			{
				jud = 20000;
			}
			else jud = 10000;
			float money;
			scanf("%f", &money);
			while (money>jud || money>bank[item].Balance)
			{
				printf("���벻���Ϲ淶���밴��ע�������������");
				scanf("%f", &money);
			}
			if (strcmp(bank[item].VIPoNormal, "V") == 0)
			{
				bank[item].Balance -= money*0.005;
			}
			else{
				bank[item].Balance -= money*0.01;
			}
			bank[item].Balance -= money;
			bank[item2].Balance += money;
			fileWrite();
			printf("ת�˳ɹ�\n");
		}

	}

	return;
}

//����ѧ����Ϣ����
void insert()
{
	int i;
	printf("����������ӵ��˻���:");
	scanf("%d", &n);
	FILE * fp;
	if ((fp = fopen("account.txt", "at")) == NULL)
		printf("�ļ�Ϊ�գ�\n");
	for (i = 0; i<n; i++)
	{
		printf("\n�������%d���˻����˺ţ�", i + 1);
		scanf("\n%s", &bank[i].accountNo);
		printf("\n�������%d���˻���������", i + 1);
		scanf("%s", &bank[i].accountName);
		printf("\n�������%d���˻������룺", i + 1);
		scanf("%s", &bank[i].Password);
		printf("\n�������%d���˻������:", i + 1);
		scanf("%f", &bank[i].Balance);
		printf("\n�������%d���˻������:", i + 1);
		scanf("%s", &bank[i].VIPoNormal);
		//		sort();   //���ð�ѧ��������
		//д���ļ�
		fprintf(fp, "%s %16s %10s %10.1f  %s\n", &bank[i].accountNo, &bank[i].accountName, &bank[i].Password, &bank[i].Balance, &bank[i].VIPoNormal);
	}
	printf("\n��ӳɹ�!!!\n");

	fclose(fp);
}


//��ʾ��ǰ��Ϣ
void display()
{
	int i = 0;
	FILE * fp;
	if ((fp = fopen("account.txt", "r")) == NULL)
		printf("�ļ�Ϊ�գ�\n");
	while (fscanf(fp, "%s %s %s %f %s\n", &bank[i].accountNo, &bank[i].accountName, &bank[i].Password, &bank[i].Balance, &bank[i].VIPoNormal) == 5)
	{
		i++;
	}
	n = i;               //��¼�ļ������ݵ�����
	printf("accountNo    accountName  Password   Balance  VIPoNormal  \n");
	printf("--------------------------------------------------------------------\n");
	for (i = 0; i<n; i++)    //�������ѧ����Ϣ
	{
		printf("%s %16s %10s %10.1f  %s\n", bank[i].accountNo, bank[i].accountName, bank[i].Password, bank[i].Balance, bank[i].VIPoNormal);
	}
	fclose(fp);
}


//���浱ǰ�˻���Ϣ
void fileWrite()
{
	FILE *fp;
	int i;
	if ((fp = fopen("account.txt", "w")) == NULL)
		printf("�ļ�Ϊ�գ�\n");
	for (i = 0; i<n; i++)
	{
		fprintf(fp, "%s %16s %10s %10.1f  %s\n", bank[i].accountNo, bank[i].accountName, bank[i].Password, bank[i].Balance, bank[i].VIPoNormal);
	}
	fclose(fp);
	printf("����ɹ�!!!");
}


//����
void menu()
{
	int num;
	printf(" \n\n                    \n\n");
	printf(" * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf(" *                   ���й���ϵͳ                    *\n");
	printf(" *                                                       *\n");
	printf(" *       * * * * * * *ϵͳ���ܲ˵�* * * * * * *          *\n");
	printf(" *    --------------------------------------------       *\n");
	printf(" *    1. ��ѯ�˻���Ϣ   *\n");
	printf(" *    2. ��Ǯ           *\n");
	printf(" *    3. ȡ��           *\n");
	printf(" *    4. ת��           *\n");
	printf(" *    5. �˳�ϵͳ       *\n");

	printf(" * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
	printf("��ѡ��˵����:");
	scanf("%d", &num);
	switch (num) {
	case 0:
		//            help();
		break;
	case 1:
		seek();
		break;
	case 2:
		Save();
		break;
	case 3:
		Withdraw();
		break;
	case 4:
		Transfer();
		break;
	case 5:
		k = 0;
		break;
	default:
		printf("����0-8֮��ѡ��\n");
	}
}


//������    
int main()
{
	while (k)
	{
		menu();
	}
	system("pause");
	return 0;
}
