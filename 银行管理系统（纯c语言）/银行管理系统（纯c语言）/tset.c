#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>    /*I/O函数*/
#include<stdlib.h>  /*其它说明*/
#include<string.h>  /*字符串函数*/
#define max 100
#define LEN 15      /* 账号和密码最大字符数,实际请更改*/
#define N 100        /* 最大账户数,实际请更改*/

int k = 1, n = 0, m = 0;/* n代表当前记录的学生人数*/
//账户信息结构体
struct banker
{
	char accountNo[LEN];
	char accountName[LEN];
	char Password[LEN];
	float Balance;
	char VIPoNormal[LEN];
}bank[N];
void fileWrite();

//存钱
void Save()
{
	int item, i;
	char s1[LEN + 1]; //用来输账号的 
	printf("请输入需要存钱的账号\n");
	scanf("%s", &s1);
	for (i = 0; i<n; i++)                  //n代表当前记录数
	{
		if (strcmp(s1, bank[i].accountNo) == 0)
		{
			item = i;
		}
	}
	printf("请输入需要存钱的金额\n");
	float wd = 0.0;
	scanf("%f", &wd);
	bank[item].Balance += wd;
	fileWrite();
	return;
}
//查询银行账户信息
void seek()
{
	//先把账户信息读进来	必须输入该账号和对应的密码，输入错误则给出警告 
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
	char s1[LEN + 1]; /* 以账号和密码最长长度+1为准*/  //用来输账号的 
	char s2[LEN + 1]; /* 以账号和密码最长长度+1为准*/  //用来输密码的 
	printf("请输入需要查询的账号\n");
	scanf("%s", &s1);
	for (i = 0; i<n; i++)                  //n代表当前记录数
	{
		if (strcmp(s1, bank[i].accountNo) == 0)
		{
			flag = 1;
			item = i;
		}
	}
	if (0 == flag)         //输入的账号和存好的账号不一致
		printf("该账号不存在！\n");
	else{
		int flag1 = 0;//判断密码输入是否正确 
		printf("请输入需要查询的账号对应的密码\n");
		scanf("%s", &s2);
		if (strcmp(s2, bank[item].Password) == 0)
		{
			flag1 = 1;
		}
		if (flag1 == 0){
			printf("密码输入错误\n");//这块可以改，重新输入，初步打算while循环 
			return;
		}
		else{
			printf("密码输入正确\n");
			printf("您余额为：%10.1f\n", bank[item].Balance);
		}

	}
	return;

}


//取款模块
// vip一次最多3000 普通的2000
// 提取的钱超过余额则失败  ，用户可以选择重新输或者返回主菜单
// 取钱后进行相应的更新  

void Withdraw()
{
	//首先肯定需要查询一下 
	//先把账户信息读进来	必须输入该账号和对应的密码，输入错误则给出警告 
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
	char s1[LEN + 1]; /* 以账号和密码最长长度+1为准*/  //用来输账号的 
	char s2[LEN + 1]; /* 以账号和密码最长长度+1为准*/  //用来输密码的 
	printf("请输入账号\n");
	scanf("%s", &s1);
	for (i = 0; i<n; i++)                  //n代表当前记录数
	{
		if (strcmp(s1, bank[i].accountNo) == 0)
		{
			flag = 1;
			item = i;
		}
	}
	if (0 == flag)         //输入的账号和存好的账号不一致
		printf("该账号不存在！\n");
	else{
		int flag1 = 0;//判断密码输入是否正确 
		printf("请输入需要查询的账号对应的密码\n");
		scanf("%s", &s2);
		if (strcmp(s2, bank[item].Password) == 0)
		{
			flag1 = 1;
		}
		if (flag1 == 0){
			printf("密码输入错误\n");//这块可以改，重新输入，初步打算while循环 
			return;
		}
		else{
			printf("密码输入正确\n");
			printf("您余额为：%10.1f\n", bank[item].Balance);
			printf("请输入需要取款的金额");
			printf("您的账户类型是%s\n", bank[item].VIPoNormal);
			printf("*****注意事项：*****\n");
			printf("取款金额不能超过限额\n");
			printf("V类型用户单次取款不得超过3000元\n");
			printf("N类型用户单次取款不得超过2000元\n");
			//判断类型
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
				printf("输入不符合规范，请按照注意事项进行输入");
				scanf("%f", &wd);
			}
			//取款之后的更新操作
			bank[item].Balance -= wd;
			fileWrite();

		}

	}

	return;
}

//转账
void Transfer()
{
	//首先肯定需要查询一下 
	//先把账户信息读进来	必须输入该账号和对应的密码，输入错误则给出警告 
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
	char s1[LEN + 1]; /* 以账号和密码最长长度+1为准*/  //用来输账号的 
	char s2[LEN + 1]; /* 以账号和密码最长长度+1为准*/  //用来输密码的 
	printf("请输入账号\n");
	scanf("%s", &s1);
	for (i = 0; i<n; i++)                  //n代表当前记录数
	{
		if (strcmp(s1, bank[i].accountNo) == 0)
		{
			flag = 1;
			item = i;
		}
	}
	if (0 == flag)
		printf("该账号不存在！\n");
	else{
		int flag1 = 0;//判断密码输入是否正确 
		printf("请输入账号对应的密码\n");
		scanf("%s", &s2);
		if (strcmp(s2, bank[item].Password) == 0)
		{
			flag1 = 1;
		}
		if (flag1 == 0){
			printf("密码输入错误\n");//这块可以改，重新输入，初步打算while循环 
			return;
		}
		else{
			printf("密码输入正确\n");
			printf("您余额为：%10.1f\n", bank[item].Balance);
			printf("您的账户类型是%s\n", bank[item].VIPoNormal);
			printf("请输入需要转账的账户");
			int flag2 = 0;
			char s3[LEN + 1];
			int item2 = 0;//标记目的账户 
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
				printf("账户输入有误请重新输入");
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

			printf("*****注意事项：*****\n");
			printf("转账金额不能超过限额\n");
			printf("V类型用户单次转账不得超过20000元\n");
			printf("N类型用户单次转账不得超过10000元\n");
			printf("请输入需要转账的金额\n");
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
				printf("输入不符合规范，请按照注意事项进行输入");
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
			printf("转账成功\n");
		}

	}

	return;
}

//插入学生信息函数
void insert()
{
	int i;
	printf("请输入待增加的账户数:");
	scanf("%d", &n);
	FILE * fp;
	if ((fp = fopen("account.txt", "at")) == NULL)
		printf("文件为空！\n");
	for (i = 0; i<n; i++)
	{
		printf("\n请输入第%d个账户的账号：", i + 1);
		scanf("\n%s", &bank[i].accountNo);
		printf("\n请输入第%d个账户的姓名：", i + 1);
		scanf("%s", &bank[i].accountName);
		printf("\n请输入第%d个账户的密码：", i + 1);
		scanf("%s", &bank[i].Password);
		printf("\n请输入第%d个账户的余额:", i + 1);
		scanf("%f", &bank[i].Balance);
		printf("\n请输入第%d个账户的类别:", i + 1);
		scanf("%s", &bank[i].VIPoNormal);
		//		sort();   //调用按学号排序函数
		//写入文件
		fprintf(fp, "%s %16s %10s %10.1f  %s\n", &bank[i].accountNo, &bank[i].accountName, &bank[i].Password, &bank[i].Balance, &bank[i].VIPoNormal);
	}
	printf("\n添加成功!!!\n");

	fclose(fp);
}


//显示当前信息
void display()
{
	int i = 0;
	FILE * fp;
	if ((fp = fopen("account.txt", "r")) == NULL)
		printf("文件为空！\n");
	while (fscanf(fp, "%s %s %s %f %s\n", &bank[i].accountNo, &bank[i].accountName, &bank[i].Password, &bank[i].Balance, &bank[i].VIPoNormal) == 5)
	{
		i++;
	}
	n = i;               //记录文件中数据的行数
	printf("accountNo    accountName  Password   Balance  VIPoNormal  \n");
	printf("--------------------------------------------------------------------\n");
	for (i = 0; i<n; i++)    //依次输出学生信息
	{
		printf("%s %16s %10s %10.1f  %s\n", bank[i].accountNo, bank[i].accountName, bank[i].Password, bank[i].Balance, bank[i].VIPoNormal);
	}
	fclose(fp);
}


//保存当前账户信息
void fileWrite()
{
	FILE *fp;
	int i;
	if ((fp = fopen("account.txt", "w")) == NULL)
		printf("文件为空！\n");
	for (i = 0; i<n; i++)
	{
		fprintf(fp, "%s %16s %10s %10.1f  %s\n", bank[i].accountNo, bank[i].accountName, bank[i].Password, bank[i].Balance, bank[i].VIPoNormal);
	}
	fclose(fp);
	printf("保存成功!!!");
}


//界面
void menu()
{
	int num;
	printf(" \n\n                    \n\n");
	printf(" * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf(" *                   银行管理系统                    *\n");
	printf(" *                                                       *\n");
	printf(" *       * * * * * * *系统功能菜单* * * * * * *          *\n");
	printf(" *    --------------------------------------------       *\n");
	printf(" *    1. 查询账户信息   *\n");
	printf(" *    2. 存钱           *\n");
	printf(" *    3. 取款           *\n");
	printf(" *    4. 转账           *\n");
	printf(" *    5. 退出系统       *\n");

	printf(" * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
	printf("请选择菜单编号:");
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
		printf("请在0-8之间选择\n");
	}
}


//主函数    
int main()
{
	while (k)
	{
		menu();
	}
	system("pause");
	return 0;
}
