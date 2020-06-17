#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<math.h>
#define SIZE 100
typedef struct
{
	long no;            /*每一组输入的编号*/
	long Number;        /*家庭成员编号*/
	char Name[20];      /*家庭成员姓名*/
	float in;           /*家庭成员收入*/
	char intime[10];    /*收入时间*/
	float out;          /*家庭成员支出*/
	char outtime[10];   /*支出时间*/
	float sum;          /*总计*/
}money;
//--------------------------------------------------------------

void flush()
{
	char c;
	while ((c = getchar()) != '\n' && c != EOF); {
	}
}
void dayinshou()
{
	FILE* fp;
	money Tm;
	char Da[40], next;
	printf("请输入你要查询的文件名\n");
	flush();
	gets_s(Da, sizeof(Da));
	fp = fopen(Da, "rb");     /*只读方式打开二进制文件*/
	if (fp == NULL)
	{
		printf("\n打开文件%s失败！按任意键结束！\n", Da);
		exit(0);
	}
	printf("文件全部内容如下：\n\n");
	while (fread(&Tm, sizeof(money), 1, fp) != (int)NULL)  /*读取文件内容，并判断是否成功*/
	{
		printf("###############################################\n");
		printf("\n成员编号：%ld\n", Tm.Number);
		printf("成员姓名：%s\n", Tm.Name);
		printf("成员收入：%f元\n", Tm.in);
		printf("收入时间：%s\n", Tm.intime);
		printf("###############################################\n");
		printf("\n\n");
	}
	fclose(fp);
	next = getche();
}
//--------------------------------------------------------------------------
void dayinzhi()
{
	FILE* fp;
	money Tm;
	char Da[40] = "a.txt", next;
	printf("请输入你要查询的文件名\n");
	flush();
	gets_s(Da, sizeof(Da));
	fp = fopen(Da, "rb");     /*只读方式打开二进制文件*/
	if (fp == NULL)
	{
		printf("\n打开文件%s失败！按任意键结束！\n", Da);
		exit(0);
	}
	printf("文件全部内容如下：\n\n");
	while (fread(&Tm, sizeof(money), 1, fp) != (int)NULL)  /*读取文件内容，并判断是否成功*/
	{
		printf("###############################################\n");
		printf("\n成员编号：%ld\n", Tm.Number);
		printf("成员姓名：%s\n", Tm.Name);
		printf("成员支出：%f元\n", Tm.out);
		printf("支出时间：%s\n", Tm.outtime);
		printf("###############################################\n");
		printf("\n\n");
	}
	fclose(fp);
	next = getche();
}

//-------------------------------------------------------------------------------
void chaxunzhi()    /*按编号查询家庭成员财务支信息记录*/
{
	int result;/* "result=1"说明查询成功，反之查找失败  */
	money Tm;   /*定义进行操作时的临时结构体变量*/
	long bianhao, before = 0;
	char   Da[40], next;
	/*Da存储家庭成员财务信息的文件名，next为是否进行下一次操作的选项*/
	FILE* fp = NULL;
	/*提示用户输入要查询的文件名*/
	printf("\n 请输入存储数据的文件名，按回车键结束。\n");
	flush();
	gets_s(Da, sizeof(Da));
	/*提示用户输入要查询的家庭成员编号*/
begin:
	result = 0; system("cls");
	printf("请输入要查询的家庭成员编号，按回车键结束。\n");
	scanf("%ld", &bianhao);
	getchar();
	fp = fopen(Da, "rb");        /*只读方式打开文件*/
	if (fp == NULL)
	{
		printf("\n打开文件 %s 失败！按任意键结束！\n", Da);
		exit(0);
	}
	/*循环查找和输入编号相匹配的家庭成员财务收支信息记录，如果查找到，则输出结果*/
	while (feof(fp) == 0)          /*没有读到文件的结尾*/
	{
		if (fread(&Tm, sizeof(money), 1, fp) != (int)NULL)      /*判断是否从文件中成功读取数据*/
		{
			if (Tm.Number == bianhao)                 /*文件内容编号和输入编号一致*/
			{
				if (before != Tm.Number)
				{
					system("cls"); printf("\n查找成功！\n\n您要查找的家庭成员的信息如下：\n");
				}
				printf("######################################\n");
				printf("\n成员编号：%ld\n", Tm.Number);
				printf("成员姓名：%s\n", Tm.Name);
				printf("成员支出：%f 元\n", Tm.out);
				printf("支出时间：%s\n", Tm.outtime);
				printf("######################################\n");    result = 1;/*" result=1"说明找到了该家庭成员的对应信息.*/
				before = Tm.Number;
			}
		}
	}
	fclose(fp);
	if (result == 0)
	{
		system("cls");
		printf("对不起！\n文件中没有该家庭成员所对应的信息。\n");
	}
	printf("\n继续？（是： y/Y，否：n/N）\n");
	next = getche();
	putchar('\n'); system("cls");
	if (next == 'y' || next == 'Y') goto begin;
}
//--------------------------------------------------------------------------------
void chaxunshou()    /*按编号查询家庭成员财务收支信息记录*/
{
	int result;/* "result=1"说明查询成功，反之查找失败  */
	money Tm;   /*定义进行操作时的临时结构体变量*/
	long bianhao, before = 0;
	char   Da[40], next;
	/*Da存储家庭成员财务信息的文件名，next为是否进行下一次操作的选项*/
	FILE* fp = NULL;
	/*提示用户输入要查询的文件名*/
	printf("\n 请输入存储数据的文件名，按回车键结束。\n");
	flush();
	gets_s(Da, sizeof(Da));


	/*提示用户输入要查询的家庭成员编号*/
begin:
	result = 0; system("cls");
	printf("请输入要查询的家庭成员编号，按回车键结束。\n");
	scanf("%ld", &bianhao);
	getchar();
	fp = fopen(Da, "rb");        /*只读方式打开文件*/
	if (fp == NULL)
	{
		printf("\n打开文件 %s 失败！按任意键结束！\n", Da);
		exit(0);
	}
	/*循环查找和输入编号相匹配的家庭成员财务收支信息记录，如果查找到，则输出结果*/
	while (feof(fp) == 0)          /*没有读到文件的结尾*/
	{
		if (fread(&Tm, sizeof(money), 1, fp) != (int)NULL)      /*判断是否从文件中成功读取数据*/
		{
			if (Tm.Number == bianhao)                 /*文件内容编号和输入编号一致*/
			{
				if (before != Tm.Number)
				{
					system("cls"); printf("\n查找成功！\n\n您要查找的家庭成员的信息如下：\n");
				}
				printf("######################################\n");
				printf("\n成员编号：%ld\n", Tm.Number);
				printf("成员姓名：%s\n", Tm.Name);
				printf("成员收入：%f 元\n", Tm.in);
				printf("收入时间：%s\n", Tm.intime);

				printf("######################################\n");    result = 1;/*" result=1"说明找到了该家庭成员的对应信息.*/
				before = Tm.Number;
			}
		}
	}
	fclose(fp);
	if (result == 0)
	{
		system("cls");
		printf("对不起！\n文件中没有该家庭成员所对应的信息。\n");
	}
	printf("\n继续？（是： y/Y，否：n/N）\n");
	next = getche();
	putchar('\n'); system("cls");
	if (next == 'y' || next == 'Y') goto begin;
}
//----------------------------------------------------------------------------------
void xiugaizhi()     /*修改家庭成员收支信息记录*/
{
	int i, result = 0;
	long modnum;/*存储要修改的家庭成员序号*/
	/*输入各项修改后信息*/
	long no, Number;
	char Name[20];
	float in;
	char intime[10];
	float out;
	char outtime[10];
	float sum;
	money Tm;      /*定义进行操作时的临时结构体变量*/
	money s[SIZE];   /*SIZE，在shead.h头文件中定义的常量，值为100  */
	int recNumber;
	char Da[40], next;
	/*Da存储家庭成员收支信息信息的文件名，next为是否进行下一次操作的选项*/
	FILE* fp;   /*fp指针指向存储数据的文件名*/
	/*输入要进行修改记录的文件名*/
	printf("\n请输入存储数据的文件名，按回车键结束！\n");
	flush();
	gets_s(Da, sizeof(Da));

begin:
	fp = fopen(Da, "rb"); /*只读方式打开文件*/
	if (fp == NULL)
	{
		printf("\n打开文件 %s 失败！按任意键结束！\n", Da);
		exit(0);
	}
	printf("请输入您要修改的家庭成员的成员编号：");
	scanf("%ld", &modnum);
	printf("您要修改的成员编号是：%ld\n\n", modnum);
	while (fread(&Tm, sizeof(money), 1, fp) != (int)NULL)    /*读取文件内容，判断是否读取成功*/
	{
		if (Tm.Number == modnum)                           /*输入的编号和文件内容的编号一致*/
		{
			printf("############################\n");
			printf("\n该项内容编号：%ld\n", Tm.no);
			printf("\n    成员编号：%ld\n", Tm.Number);
			printf("\n    成员姓名：%s\n", Tm.Name);
			printf("\n    成员支出：%f元\n", Tm.out);
			printf("\n    支出时间：%s\n", Tm.outtime);
			printf("############################\n");
			result = 1;
		}
	}
	rewind(fp); /*把文件指针指向文件的开头*/
	if (result == 0)
	{
		printf("你输入的编号不存在，请确认后重新输入：\n");
		printf("\n是否继续？(是：y/Y，否：n/N)");
		next = getche(); system("cls");
		putchar('\n');
		if (next == 'y' || next == 'Y') goto begin;
		else exit(0);
	}
	result = 0;
	printf("请输入你要修改的该项内容编号：\n");
	scanf("%ld", &no);

	/*输入要修改记录的各项内容值*/
	Number = modnum;
	printf("输入姓名，支出，支出时间，输入编号为0时结束！\n");
	printf("成员姓名：");
	scanf("%s", Name);
	printf("成员支出：");
	scanf("%f", &out);
	printf("支出时间：");
	scanf("%s", outtime);
	sum = in - out;
	/*将文件中要修改的信息存入结构体数组*/
	recNumber = 0;
	/*循环将文件数据读入结构体数组，
	如文件中的数据家庭成员内容编号和要修改的家庭成员内容编号不符，则原样写入数组，
	如文件中数据的家庭成员内容编号和要修改家庭成员内容编号匹配，
	则根据输入的各项修改内容重新赋值，即修改，并写入数组*/
	while ((fread(&Tm, sizeof(money), 1, fp)) != (int)NULL)     /*读取文件内容。是否成功*/
	{
		if (Tm.no != no)                                    /*输入的内容编号和文件内容编号不一致*/
		{
			s[recNumber].no = Tm.no;
			s[recNumber].Number = Tm.Number;
			strcpy(s[recNumber].Name, Tm.Name);
			s[recNumber].in = Tm.in;
			strcpy(s[recNumber].intime, Tm.intime);
			s[recNumber].out = Tm.out;
			strcpy(s[recNumber].outtime, Tm.outtime);
			s[recNumber].sum = Tm.sum;
		}
		if (Tm.no == no)                                   /*输入的内容编号和文件内容编号一致*/
		{
			s[recNumber].no = no;
			s[recNumber].Number = Number;
			strcpy(s[recNumber].Name, Name);
			s[recNumber].in = in;
			strcpy(s[recNumber].intime, intime);
			s[recNumber].out = out;
			strcpy(s[recNumber].outtime, outtime);
			s[recNumber].sum = sum;
			result = 1;
		}
		recNumber++;
	}
	fclose(fp);
	/*将修改后的结构体数组记录写入文件*/
	fp = fopen(Da, "wb+");      /*打开文件，原文件内容清空*/
	if (fp == NULL)
	{
		printf("\n打开文件%s失败！按任意键结束！\n", Da);
		exit(0);
	}
	for (i = 0; i < recNumber; i++)     /*采用循环将数据写入文件*/
	{
		if (fwrite(&s[i], sizeof(money), 1, fp) != 1)
		{
			printf("\n写入文件 %s 失败！按任意键结束！\n", Da);
			exit(0);
		}
	}
	fclose(fp);
	if (result == 1)
	{
		printf("文件修改成功，已成功保存在用户文件夹\n");
		/*询问是否查看修改后的文件*/
		printf("\n是否查看修改后的文件？(是：y/Y，否：n/N)");
		next = getche(); system("cls");
		putchar('\n');
		if (next == 'y' || next == 'Y')
		{/*显示修改后的文件*/
			fp = fopen(Da, "rb");            /*只读方式打开文件*/
			if (fp == NULL)
			{
				printf("\n打开文件%s失败！按任意键结束！\n", Da);
				exit(0);
			}
			system("cls");
			printf("\n修改后的文件全部内容是：\n");
			while (fread(&Tm, sizeof(money), 1, fp) != (int)NULL)
			{
				printf("############################\n\n");
				printf(" 成员编号：%ld\n", Tm.Number);
				printf(" 成员姓名：%s\n", Tm.Name);
				printf(" 成员支出：%f元\n", Tm.out);
				printf(" 支出时间：%s\n", Tm.outtime);
				printf("############################\n");
				printf("\n");
			}
			fclose(fp);
		}
	}
	if (result == 0)
		printf("\n你输入的内容编号不存在。文件修改失败。。\n\n");

	/*提示是否进行下一次修改*/
	printf("\n是否继续？(是：y/Y，否：n/N)");
	next = getche(); system("cls");
	putchar('\n');
	if (next == 'y' || next == 'Y') goto begin;
}
//------------------------------------------------------------------------------
void xiugaishou()     /*修改家庭成员收信息记录*/
{
	int i, result = 0;
	long modnum;/*存储要修改的家庭成员序号*/
	/*输入各项修改后信息*/
	long no, Number;
	char Name[20];
	float in;
	char intime[10];
	float out=0;
	char outtime[10];
	float sum;
	money Tm;      /*定义进行操作时的临时结构体变量*/
	money s[SIZE];   /*SIZE，在shead.h头文件中定义的常量，值为100  */
	int recNumber;
	char Da[40], next;
	/*Da存储家庭成员收支信息信息的文件名，next为是否进行下一次操作的选项*/
	FILE* fp;   /*fp指针指向存储数据的文件名*/
	/*输入要进行修改记录的文件名*/
	printf("\n请输入存储数据的文件名，按回车键结束！\n");
	flush();
	gets_s(Da, sizeof(Da));

begin:
	fp = fopen(Da, "rb"); /*只读方式打开文件*/
	if (fp == NULL)
	{
		printf("\n打开文件 %s 失败！按任意键结束！\n", Da);
		exit(0);
	}
	printf("请输入您要修改的家庭成员的成员编号：");
	scanf("%ld", &modnum);
	printf("您要修改的成员编号是：%ld\n\n", modnum);
	while (fread(&Tm, sizeof(money), 1, fp) != (int)NULL)    /*读取文件内容，判断是否读取成功*/
	{
		if (Tm.Number == modnum)                           /*输入的编号和文件内容的编号一致*/
		{
			printf("############################\n");
			printf("\n该项内容编号：%ld\n", Tm.no);
			printf("\n    成员编号：%ld\n", Tm.Number);
			printf("\n    成员姓名：%s\n", Tm.Name);
			printf("\n    成员收入：%f元\n", Tm.in);
			printf("\n    收入时间：%s\n", Tm.intime);
			printf("############################\n");
			result = 1;
		}
	}
	rewind(fp); /*把文件指针指向文件的开头*/
	if (result == 0)
	{
		printf("你输入的编号不存在，请确认后重新输入：\n");
		printf("\n是否继续？(是：y/Y，否：n/N)");
		next = getche(); system("cls");
		putchar('\n');
		if (next == 'y' || next == 'Y') goto begin;
		else exit(0);
	}
	result = 0;
	printf("请输入你要修改的该项内容编号：\n");
	scanf("%ld", &no);

	/*输入要修改记录的各项内容值*/
	Number = modnum;
	printf("输入姓名，收入，收入时间，输入编号为0时结束！\n");
	printf("成员姓名：");
	scanf("%s", Name);
	printf("成员收入：");
	scanf("%f", &in);
	printf("收入时间：");
	scanf("%s", intime);

	sum = in - out;
	/*将文件中要修改的信息存入结构体数组*/
	recNumber = 0;
	/*循环将文件数据读入结构体数组，
	如文件中的数据家庭成员内容编号和要修改的家庭成员内容编号不符，则原样写入数组，
	如文件中数据的家庭成员内容编号和要修改家庭成员内容编号匹配，
	则根据输入的各项修改内容重新赋值，即修改，并写入数组*/
	while ((fread(&Tm, sizeof(money), 1, fp)) != (int)NULL)     /*读取文件内容。是否成功*/
	{
		if (Tm.no != no)                                    /*输入的内容编号和文件内容编号不一致*/
		{
			s[recNumber].no = Tm.no;
			s[recNumber].Number = Tm.Number;
			strcpy(s[recNumber].Name, Tm.Name);
			s[recNumber].in = Tm.in;
			strcpy(s[recNumber].intime, Tm.intime);
			s[recNumber].out = Tm.out;
			strcpy(s[recNumber].outtime, Tm.outtime);
			s[recNumber].sum = Tm.sum;
		}
		if (Tm.no == no)                                   /*输入的内容编号和文件内容编号一致*/
		{
			s[recNumber].no = no;
			s[recNumber].Number = Number;
			strcpy(s[recNumber].Name, Name);
			s[recNumber].in = in;
			strcpy(s[recNumber].intime, intime);
			s[recNumber].out = out;
			strcpy(s[recNumber].outtime, outtime);
			s[recNumber].sum = sum;
			result = 1;
		}
		recNumber++;
	}
	fclose(fp);
	/*将修改后的结构体数组记录写入文件*/
	fp = fopen(Da, "wb+");      /*打开文件，原文件内容清空*/
	if (fp == NULL)
	{
		printf("\n打开文件%s失败！按任意键结束！\n", Da);
		exit(0);
	}
	for (i = 0; i < recNumber; i++)     /*采用循环将数据写入文件*/
	{
		if (fwrite(&s[i], sizeof(money), 1, fp) != 1)
		{
			printf("\n写入文件 %s 失败！按任意键结束！\n", Da);
			exit(0);
		}
	}
	fclose(fp);
	if (result == 1)
	{
		printf("文件修改成功，已成功保存在用户文件夹\n");
		/*询问是否查看修改后的文件*/
		printf("\n是否查看修改后的文件？(是：y/Y，否：n/N)");
		next = getche(); system("cls");
		putchar('\n');
		if (next == 'y' || next == 'Y')
		{/*显示修改后的文件*/
			fp = fopen(Da, "rb");            /*只读方式打开文件*/
			if (fp == NULL)
			{
				printf("\n打开文件%s失败！按任意键结束！\n", Da);
				exit(0);
			}
			system("cls");
			printf("\n修改后的文件全部内容是：\n");
			while (fread(&Tm, sizeof(money), 1, fp) != (int)NULL)
			{
				printf("############################\n\n");
				printf(" 成员编号：%ld\n", Tm.Number);
				printf(" 成员姓名：%s\n", Tm.Name);
				printf(" 成员收入：%f元\n", Tm.in);
				printf(" 收入时间：%s\n", Tm.intime);
				printf("############################\n");
				printf("\n");
			}
			fclose(fp);
		}
	}
	if (result == 0)
		printf("\n你输入的内容编号不存在。文件修改失败。。\n\n");

	/*提示是否进行下一次修改*/
	printf("\n是否继续？(是：y/Y，否：n/N)");
	next = getche(); system("cls");
	putchar('\n');
	if (next == 'y' || next == 'Y') goto begin;
}
//--------------------------------------------------------------------------------------------

void shanchushou()    /*删除家庭成员收信息记录*/
{
	int i, result = 0;
	long delnum;      /*存放要输入的要删除家庭成员序号*/
	money Tm;         /*定义进行操作时的临时结构体变量*/
	money s[SIZE];
	int recNumber;    /*原文件中的记录数*/
	char Da[40], next;
	FILE* fp;      /*fp指针指向存储数据的文件名*/
	printf("\n请输入存储数据的文件名，按回车键结束！\n");
	flush();
	gets_s(Da, sizeof(Da));

begin:
	/*以二进制读的方式打开文件*/
	fp = fopen(Da, "rb");
	if (fp == NULL)
	{
		printf("\n打开文件 %s 失败！按任意键结束！\n", Da);
		exit(0);
	}
	/*输入要删除的家庭成员序号*/
	printf("请输入要删除的家庭成员编号：");
	scanf("%ld", &delnum);
	printf("您要删除的编号是：%ld\n", delnum);

	while (fread(&Tm, sizeof(money), 1, fp) != (int)NULL)  /*从文件中读取数据，是否读取成功*/
	{
		if (Tm.Number == delnum)
		{
			printf("该项收支记录如下：\n");
			printf("############################\n");
			printf("该项内容编号：%ld\n", Tm.no);
			printf("成员编号：%ld\n", Tm.Number);
			printf("成员姓名：%s\n", Tm.Name);
			printf("成员收入：%f元\n", Tm.in);
			printf("收入时间：%s\n", Tm.intime);
			printf("############################\n");
			result = 1;
		}
	}
	rewind(fp);     /*把文件指针重新指向文件的开头*/
	if (result == 0)
	{
		printf("\n你输入的编号不存在，请确认后重新输入\n");
		printf("\n是否继续删除？(是：y/Y;否：n/N)");
		next = getche();
		system("cls");
		putchar('\n');
		if (next == 'y' || next == 'Y') goto begin;
	}
	/*询问是否删除*/
	printf("\n你确定要删除该记录吗？删除后不可恢复！！(是：y/Y;否：n/N)");
	next = getche();
	putchar('\n');
	if (next == 'y' || next == 'Y')
	{
		system("cls");
		printf("恭喜！该项纪录已成功删除。。\n");
		/*将文件中信息存入结构体数组*/
		/*与要删除的家庭成员序号相匹配的项不写入数组，
		循环后数组中即为去掉了要删除记录后的剩余记录*/
		recNumber = 0;
		while ((fread(&Tm, sizeof(money), 1, fp)) != (int)NULL)/*从文件中读取数据，是否读取成功*/
		{
			if (Tm.Number != delnum)
			{
				s[recNumber].no = Tm.no;
				s[recNumber].Number = Tm.Number;
				strcpy(s[recNumber].Name, Tm.Name);
				s[recNumber].in = Tm.in;
				strcpy(s[recNumber].intime, Tm.intime);
				s[recNumber].out = Tm.out;
				strcpy(s[recNumber].outtime, Tm.outtime);
				s[recNumber].sum = Tm.sum;
				recNumber++;
			}
		}
		fclose(fp);
		/*将删除后的剩余结构体记录写入文件*/
		fp = fopen(Da, "wb+");       /*读写方式打开文件，原文件内容清空*/
		if (fp == NULL)
		{
			printf("\n记录文件 %s失败！按任意键结束！\n", Da);
			exit(0);
		}
		for (i = 0; i < recNumber; i++)    /*用循环将数据写入文件*/
		{
			if (fwrite(&s[i], sizeof(money), 1, fp) != 1)
			{
				printf("\n记录文件 %s 失败！按任意键结束！\n", Da);
				exit(0);
			}
		}
		fclose(fp);
		/*显示删除财务信息记录后的文件*/
		printf("是否查看删除后剩下的内容、\n");
		printf("\n是否？(是：y/Y;否：n/N)");
		next = getche(); system("cls");
		putchar('\n');
		if (next == 'y' || next == 'Y')

		{
			fp = fopen(Da, "rb"); /*只读方式打开文件*/
			if (fp == NULL)
			{
				printf("\n打开文件%s失败！按任意键结束！ \n", Da);
				exit(0);
			}
			printf("################################################################################\n");
			printf("删除后剩余全部内容是：\n");
			while (fread(&Tm, sizeof(money), 1, fp) != (int)NULL)
			{
				printf("############################\n");
				printf("成员编号：%ld\n", Tm.Number);
				printf("成员姓名：%s\n", Tm.Name);
				printf("成员收入：%f元\n", Tm.in);
				printf("收入时间：%s\n", Tm.intime);

				printf("############################\n");
			}
		}
	}
	else
	{
		system("cls");
		printf("\n删除失败，原因：用户取消操作\n\n");
	}fclose(fp);
	/*询问是否继续*/
	printf("\n是否继续删除？(是：y/Y;否：n/N)");
	next = getche(); system("cls");
	putchar('\n');
	if (next == 'y' || next == 'Y') goto begin;
}

//------------------------------------------------------------------------------

void shanchuzhi()    /*删除家庭成员支信息记录*/
{
	int i, result = 0;
	long delnum;      /*存放要输入的要删除家庭成员序号*/
	money Tm;         /*定义进行操作时的临时结构体变量*/
	money s[SIZE];
	int recNumber;    /*原文件中的记录数*/
	char Da[40], next;
	FILE* fp;      /*fp指针指向存储数据的文件名*/
	printf("\n请输入存储数据的文件名，按回车键结束！\n");
	flush();
	gets_s(Da, sizeof(Da));

begin:
	/*以二进制读的方式打开文件*/
	fp = fopen(Da, "rb");
	if (fp == NULL)
	{
		printf("\n打开文件 %s 失败！按任意键结束！\n", Da);
		exit(0);
	}
	/*输入要删除的家庭成员序号*/
	printf("请输入要删除的家庭成员编号：");
	scanf("%ld", &delnum);
	printf("您要删除的编号是：%ld\n", delnum);

	while (fread(&Tm, sizeof(money), 1, fp) != (int)NULL)  /*从文件中读取数据，是否读取成功*/
	{
		if (Tm.Number == delnum)
		{
			printf("该项收支记录如下：\n");
			printf("############################\n");
			printf("该项内容编号：%ld\n", Tm.no);
			printf("成员编号：%ld\n", Tm.Number);
			printf("成员姓名：%s\n", Tm.Name);

			printf("成员支出：%f元\n", Tm.out);
			printf("支出时间：%s\n", Tm.outtime);

			printf("############################\n");
			result = 1;
		}
	}
	rewind(fp);     /*把文件指针重新指向文件的开头*/
	if (result == 0)
	{
		printf("\n你输入的编号不存在，请确认后重新输入\n");
		printf("\n是否继续删除？(是：y/Y;否：n/N)");
		next = getche();
		system("cls");
		putchar('\n');
		if (next == 'y' || next == 'Y') goto begin;
	}
	/*询问是否删除*/
	printf("\n你确定要删除该记录吗？删除后不可恢复！！(是：y/Y;否：n/N)");
	next = getche();
	putchar('\n');
	if (next == 'y' || next == 'Y')
	{
		system("cls");
		printf("恭喜！该项纪录已成功删除。。\n");
		/*将文件中信息存入结构体数组*/
		/*与要删除的家庭成员序号相匹配的项不写入数组，
		循环后数组中即为去掉了要删除记录后的剩余记录*/
		recNumber = 0;
		while ((fread(&Tm, sizeof(money), 1, fp)) != (int)NULL)/*从文件中读取数据，是否读取成功*/
		{
			if (Tm.Number != delnum)
			{
				s[recNumber].no = Tm.no;
				s[recNumber].Number = Tm.Number;
				strcpy(s[recNumber].Name, Tm.Name);
				s[recNumber].in = Tm.in;
				strcpy(s[recNumber].intime, Tm.intime);
				s[recNumber].out = Tm.out;
				strcpy(s[recNumber].outtime, Tm.outtime);
				s[recNumber].sum = Tm.sum;
				recNumber++;
			}
		}
		fclose(fp);
		/*将删除后的剩余结构体记录写入文件*/
		fp = fopen(Da, "wb+");       /*读写方式打开文件，原文件内容清空*/
		if (fp == NULL)
		{
			printf("\n记录文件 %s失败！按任意键结束！\n", Da);
			exit(0);
		}
		for (i = 0; i < recNumber; i++)    /*用循环将数据写入文件*/
		{
			if (fwrite(&s[i], sizeof(money), 1, fp) != 1)
			{
				printf("\n记录文件 %s 失败！按任意键结束！\n", Da);
				exit(0);
			}
		}
		fclose(fp);
		/*显示删除财务信息记录后的文件*/
		printf("是否查看删除后剩下的内容、\n");
		printf("\n是否？(是：y/Y;否：n/N)");
		next = getche(); system("cls");
		putchar('\n');
		if (next == 'y' || next == 'Y')

		{
			fp = fopen(Da, "rb"); /*只读方式打开文件*/
			if (fp == NULL)
			{
				printf("\n打开文件%s失败！按任意键结束！ \n", Da);
				exit(0);
			}
			printf("################################################################################\n");
			printf("删除后剩余全部内容是：\n");
			while (fread(&Tm, sizeof(money), 1, fp) != (int)NULL)
			{
				printf("############################\n");
				printf("成员编号：%ld\n", Tm.Number);
				printf("成员姓名：%s\n", Tm.Name);

				printf("成员支出：%f元\n", Tm.out);
				printf("支出时间：%s\n", Tm.outtime);

				printf("############################\n");
			}
		}
	}
	else
	{
		system("cls");
		printf("\n删除失败，原因：用户取消操作\n\n");
	}fclose(fp);
	/*询问是否继续*/
	printf("\n是否继续删除？(是：y/Y;否：n/N)");
	next = getche(); system("cls");
	putchar('\n');
	if (next == 'y' || next == 'Y') goto begin;
}
//---------------------------------------------------------------------------------



void tianjiashou()     /*添加财务收信息记录*/
{
	FILE* fp = NULL;      /*定义指向文件的指针*/
	money Tm, ch;          /*定义进行操作时的临时结构体变量*/
	char Da[40] = "a.txt", next;     /*存储财务收支信息的文件名*/
	int count = 1;          /*计算可输入数据的最大范围*/
	printf("\n 请输入要添加财务收支信息的文件名：");
	flush();
	gets_s(Da, sizeof(Da));

begin:count = 1;
	fp = fopen(Da, "ab+");
	if (fp == NULL)        /*判断文件是否成功打开*/
	{
		printf("\n 打开文件 %s 失败！按任意键结束！\n", Da);
		exit(0);
	}
	while (fread(&ch, sizeof(money), 1, fp) != (int)NULL)      /*从文件中读取数据并判断是否成功*/
	{
		count++;
	}
	fclose(fp); /*如果成功打开或创建文件，则提示输入家庭成员序号、姓名、收入、支出等相关信息*/
	fp = fopen(Da, "ab+");/*ab+:当文件存在时，追加，当文件不存在时，创建*/
	printf("输入编号，姓名，收入，收入时间，输入编号为0时结束！\n");
	printf("编号不超过九位，姓名不超过二十个字符。\n");
	while (count <= SIZE)
	{
		Tm.no = count;
		printf("\n 输入 编号为零时结束输入！\n");
		printf("成员编号：");
		scanf("%ld", &Tm.Number);
		if (Tm.Number == 0)           /*如果输入的编号为0，结束*/
			break;
		printf("输入成员姓名：");
		scanf("%s", Tm.Name);
		printf("输入成员收入：");
		scanf("%f", &Tm.in);
		printf("输入收入时间：");
		scanf("%s", Tm.intime);

		Tm.sum = Tm.in - Tm.out;
		printf("\n");
		if (fwrite(&Tm, sizeof(money), 1, fp) != 1)    /*将数据写入文件并判断是否成功*/
		{
			printf("\n写入文件 %s 失败！以任意键结束！\n", Da);
			exit(0);
		}
		count++;
	}           /*如果输入的数据量超过最大允许的范围，则提示数据不能录入*/
	if (count > SIZE)
		printf("\n对不起，输入的数据量超过最大允许的范围%d\n", SIZE);
	fclose(fp);
	system("cls");

	printf("您输入的数据已成功存储在 %s 文件中。\n", Da);
	printf("文件全部内容如下：\n");

	fp = fopen(Da, "rb");     /*只读方式打开二进制文件*/
	if (fp == NULL)          /*判断是否打开成功*/
	{
		printf("\n打开文件%s失败！按任意键结束！\n", Da);
		exit(0);
	}
	while (fread(&Tm, sizeof(money), 1, fp) != (int)NULL)   /*从文件中读取数据，是否读取成功*/
	{
		printf("###############################################\n");
		printf("成员编号：%ld\n", Tm.Number);
		printf("成员姓名：%s\n", Tm.Name);
		printf("成员收入：%f元\n", Tm.in);
		printf("收入时间：%s\n", Tm.intime);


		printf("###############################################\n");
		printf("\n\n");
	}
	fclose(fp);
	/*询问是否继续*/
	printf("\n是否继续？(是：y/Y;    否：n/N)");
	next = getche();
	system("cls");
	putchar('\n');
	if (next == 'y' || next == 'Y') goto begin;
}


void tianjiaszhi()     /*添加财务支信息记录*/
{
	FILE* fp = NULL;      /*定义指向文件的指针*/
	money Tm, ch;          /*定义进行操作时的临时结构体变量*/
	char Da[40], next;     /*存储财务收支信息的文件名*/
	int count = 1;          /*计算可输入数据的最大范围*/
	printf("\n 请输入要添加财务收支信息的文件名：");
	flush();
	gets_s(Da, sizeof(Da));


begin:count = 1;
	fp = fopen(Da, "ab+");
	if (fp == NULL)        /*判断文件是否成功打开*/
	{
		printf("\n 打开文件 %s 失败！按任意键结束！\n", Da);
		exit(0);
	}
	while (fread(&ch, sizeof(money), 1, fp) != (int)NULL)      /*从文件中读取数据并判断是否成功*/
	{
		count++;
	}
	fclose(fp); /*如果成功打开或创建文件，则提示输入家庭成员序号、姓名、支出等相关信息*/
	fp = fopen(Da, "ab+");/*ab+:当文件存在时，追加，当文件不存在时，创建*/
	printf("输入编号，姓名，支出，支出时间，输入编号为0时结束！\n");
	printf("编号不超过九位，姓名不超过二十个字符。\n");
	while (count <= SIZE)
	{
		Tm.no = count;
		printf("\n 输入 编号为零时结束输入！\n");
		printf("成员编号：");
		scanf("%ld", &Tm.Number);
		if (Tm.Number == 0)           /*如果输入的编号为0，结束*/
			break;
		printf("输入成员姓名：");
		scanf("%s", Tm.Name);

		printf("输入成员支出：");
		scanf("%f", &Tm.out);
		printf("输入支出时间：");
		scanf("%s", Tm.outtime);
		Tm.sum = Tm.in - Tm.out;
		printf("\n");
		if (fwrite(&Tm, sizeof(money), 1, fp) != 1)    /*将数据写入文件并判断是否成功*/
		{
			printf("\n写入文件 %s 失败！以任意键结束！\n", Da);
			exit(0);
		}
		count++;
	}           /*如果输入的数据量超过最大允许的范围，则提示数据不能录入*/
	if (count > SIZE)
		printf("\n对不起，输入的数据量超过最大允许的范围%d\n", SIZE);
	fclose(fp);
	system("cls");

	printf("您输入的数据已成功存储在 %s 文件中。\n", Da);
	printf("文件全部内容如下：\n");

	fp = fopen(Da, "rb");     /*只读方式打开二进制文件*/
	if (fp == NULL)          /*判断是否打开成功*/
	{
		printf("\n打开文件%s失败！按任意键结束！\n", Da);
		exit(0);
	}
	while (fread(&Tm, sizeof(money), 1, fp) != (int)NULL)   /*从文件中读取数据，是否读取成功*/
	{
		printf("###############################################\n");
		printf("成员编号：%ld\n", Tm.Number);
		printf("成员姓名：%s\n", Tm.Name);

		printf("成员支出：%f元\n", Tm.out);
		printf("支出时间：%s\n", Tm.outtime);
		printf("###############################################\n");
		printf("\n\n");
	}
	fclose(fp);
	/*询问是否继续*/
	printf("\n是否继续？(是：y/Y;    否：n/N)");
	next = getche();
	system("cls");
	putchar('\n');
	if (next == 'y' || next == 'Y') goto begin;
}





void Menu()  //主菜单 
{

	printf("========================\n");
	printf("#欢迎使用家庭财务小管家#\n");
	printf("========================\n");
	printf("1:收入管理 \n");
	printf("2:支出管理 \n");
	printf("0:退出 \n");
}




void income_guanli()    //收入管理
{
	int choice;
	while (1)
	{
		void income_menu();
		void chaxun_income();



		income_menu();




		printf("请输入选择:");
		fflush(stdin);

		scanf("%d", &choice);
		fflush(stdin);
		printf("choice=%d\n", choice);
		if (choice == 0) {
			break;
		}
		else
			switch (choice)
			{
			case 1:tianjiashou(); break;
			case 2:chaxunshou(); break;
			case 3:shanchushou(); break;
			case 4:xiugaishou(); break;
			case 5: dayinshou(); break;

			}
	}
}



void zhichu_guanli()    //支出管理
{
	int choice;
	while (1)
	{
		void zhichu_menu();




		zhichu_menu();




		printf("请输入选择:");
		scanf("%d", &choice);
		getchar();
		fflush(stdin);
		if (choice == 0) {
			break;
		}
		else
			switch (choice)
			{
			case 1:tianjiaszhi(); break;
			case 2: chaxunzhi(); break;
			case 3:shanchuzhi(); break;
			case 4: xiugaizhi(); break;
			case 5:dayinzhi(); break;
			}
	}
}




void income_menu()//收入菜单
{
	system("cls");
	printf("========================\n");
	printf("#欢迎使用家庭财务小管家#\n");
	printf("========================\n");
	printf("1.添加收入记录\n");
	printf("2.查询收入记录\n");
	printf("3.删除收入记录\n");
	printf("4.修改收入记录\n");
	printf("5.打印收入记录\n");
	printf("0.返回上一级\n");

}
void zhichu_menu() //支出菜单 
{
	system("cls");
	printf("========================\n");
	printf("#欢迎使用家庭财务小管家#\n");
	printf("========================\n");
	printf("1.添加支出记录\n");
	printf("2.查询支出记录\n");
	printf("3.删除支出记录\n");
	printf("4.修改支出记录\n");
	printf("5.打印支出记录\n");
	printf("0.返回上一级\n");

}
void chaxun_menu()       //查询菜单
{
	system("cls");
	printf("========================\n");
	printf("#欢迎使用家庭财务小管家#\n");
	printf("========================\n");

}




void Quit()  //退出
{
	char panduan;
	printf("确认退出(Y/N)");
	panduan = getchar();
	fflush(stdin);
	if (panduan == 'Y' || panduan == 'y')
	{
		exit(0);
	}
}



int main()
{



	void Menu();


	while (1)
	{
		void income_guanli();
		void zhichu_guanli();
		void Quit();

		int choice;
		system("cls");
		Menu();

		printf(">输入你的选择：");
		scanf("%d", &choice);
		fflush(stdin);
		switch (choice)
		{
		case 1: income_guanli(); break;
		case 2: zhichu_guanli(); break;
		case 0: Quit(); break;
		default: printf("输入错误"); break;
		}
	}
	return 0;
}
