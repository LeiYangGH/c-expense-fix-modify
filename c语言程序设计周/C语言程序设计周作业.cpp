#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<math.h>
#define SIZE 100
typedef struct
{
	long no;            /*ÿһ������ı��*/
	long Number;        /*��ͥ��Ա���*/
	char Name[20];      /*��ͥ��Ա����*/
	float in;           /*��ͥ��Ա����*/
	char intime[10];    /*����ʱ��*/
	float out;          /*��ͥ��Ա֧��*/
	char outtime[10];   /*֧��ʱ��*/
	float sum;          /*�ܼ�*/
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
	printf("��������Ҫ��ѯ���ļ���\n");
	flush();
	gets_s(Da, sizeof(Da));
	fp = fopen(Da, "rb");     /*ֻ����ʽ�򿪶������ļ�*/
	if (fp == NULL)
	{
		printf("\n���ļ�%sʧ�ܣ��������������\n", Da);
		exit(0);
	}
	printf("�ļ�ȫ���������£�\n\n");
	while (fread(&Tm, sizeof(money), 1, fp) != (int)NULL)  /*��ȡ�ļ����ݣ����ж��Ƿ�ɹ�*/
	{
		printf("###############################################\n");
		printf("\n��Ա��ţ�%ld\n", Tm.Number);
		printf("��Ա������%s\n", Tm.Name);
		printf("��Ա���룺%fԪ\n", Tm.in);
		printf("����ʱ�䣺%s\n", Tm.intime);
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
	printf("��������Ҫ��ѯ���ļ���\n");
	flush();
	gets_s(Da, sizeof(Da));
	fp = fopen(Da, "rb");     /*ֻ����ʽ�򿪶������ļ�*/
	if (fp == NULL)
	{
		printf("\n���ļ�%sʧ�ܣ��������������\n", Da);
		exit(0);
	}
	printf("�ļ�ȫ���������£�\n\n");
	while (fread(&Tm, sizeof(money), 1, fp) != (int)NULL)  /*��ȡ�ļ����ݣ����ж��Ƿ�ɹ�*/
	{
		printf("###############################################\n");
		printf("\n��Ա��ţ�%ld\n", Tm.Number);
		printf("��Ա������%s\n", Tm.Name);
		printf("��Ա֧����%fԪ\n", Tm.out);
		printf("֧��ʱ�䣺%s\n", Tm.outtime);
		printf("###############################################\n");
		printf("\n\n");
	}
	fclose(fp);
	next = getche();
}

//-------------------------------------------------------------------------------
void chaxunzhi()    /*����Ų�ѯ��ͥ��Ա����֧��Ϣ��¼*/
{
	int result;/* "result=1"˵����ѯ�ɹ�����֮����ʧ��  */
	money Tm;   /*������в���ʱ����ʱ�ṹ�����*/
	long bianhao, before = 0;
	char   Da[40], next;
	/*Da�洢��ͥ��Ա������Ϣ���ļ�����nextΪ�Ƿ������һ�β�����ѡ��*/
	FILE* fp = NULL;
	/*��ʾ�û�����Ҫ��ѯ���ļ���*/
	printf("\n ������洢���ݵ��ļ��������س���������\n");
	flush();
	gets_s(Da, sizeof(Da));
	/*��ʾ�û�����Ҫ��ѯ�ļ�ͥ��Ա���*/
begin:
	result = 0; system("cls");
	printf("������Ҫ��ѯ�ļ�ͥ��Ա��ţ����س���������\n");
	scanf("%ld", &bianhao);
	getchar();
	fp = fopen(Da, "rb");        /*ֻ����ʽ���ļ�*/
	if (fp == NULL)
	{
		printf("\n���ļ� %s ʧ�ܣ��������������\n", Da);
		exit(0);
	}
	/*ѭ�����Һ���������ƥ��ļ�ͥ��Ա������֧��Ϣ��¼��������ҵ�����������*/
	while (feof(fp) == 0)          /*û�ж����ļ��Ľ�β*/
	{
		if (fread(&Tm, sizeof(money), 1, fp) != (int)NULL)      /*�ж��Ƿ���ļ��гɹ���ȡ����*/
		{
			if (Tm.Number == bianhao)                 /*�ļ����ݱ�ź�������һ��*/
			{
				if (before != Tm.Number)
				{
					system("cls"); printf("\n���ҳɹ���\n\n��Ҫ���ҵļ�ͥ��Ա����Ϣ���£�\n");
				}
				printf("######################################\n");
				printf("\n��Ա��ţ�%ld\n", Tm.Number);
				printf("��Ա������%s\n", Tm.Name);
				printf("��Ա֧����%f Ԫ\n", Tm.out);
				printf("֧��ʱ�䣺%s\n", Tm.outtime);
				printf("######################################\n");    result = 1;/*" result=1"˵���ҵ��˸ü�ͥ��Ա�Ķ�Ӧ��Ϣ.*/
				before = Tm.Number;
			}
		}
	}
	fclose(fp);
	if (result == 0)
	{
		system("cls");
		printf("�Բ���\n�ļ���û�иü�ͥ��Ա����Ӧ����Ϣ��\n");
	}
	printf("\n���������ǣ� y/Y����n/N��\n");
	next = getche();
	putchar('\n'); system("cls");
	if (next == 'y' || next == 'Y') goto begin;
}
//--------------------------------------------------------------------------------
void chaxunshou()    /*����Ų�ѯ��ͥ��Ա������֧��Ϣ��¼*/
{
	int result;/* "result=1"˵����ѯ�ɹ�����֮����ʧ��  */
	money Tm;   /*������в���ʱ����ʱ�ṹ�����*/
	long bianhao, before = 0;
	char   Da[40], next;
	/*Da�洢��ͥ��Ա������Ϣ���ļ�����nextΪ�Ƿ������һ�β�����ѡ��*/
	FILE* fp = NULL;
	/*��ʾ�û�����Ҫ��ѯ���ļ���*/
	printf("\n ������洢���ݵ��ļ��������س���������\n");
	flush();
	gets_s(Da, sizeof(Da));


	/*��ʾ�û�����Ҫ��ѯ�ļ�ͥ��Ա���*/
begin:
	result = 0; system("cls");
	printf("������Ҫ��ѯ�ļ�ͥ��Ա��ţ����س���������\n");
	scanf("%ld", &bianhao);
	getchar();
	fp = fopen(Da, "rb");        /*ֻ����ʽ���ļ�*/
	if (fp == NULL)
	{
		printf("\n���ļ� %s ʧ�ܣ��������������\n", Da);
		exit(0);
	}
	/*ѭ�����Һ���������ƥ��ļ�ͥ��Ա������֧��Ϣ��¼��������ҵ�����������*/
	while (feof(fp) == 0)          /*û�ж����ļ��Ľ�β*/
	{
		if (fread(&Tm, sizeof(money), 1, fp) != (int)NULL)      /*�ж��Ƿ���ļ��гɹ���ȡ����*/
		{
			if (Tm.Number == bianhao)                 /*�ļ����ݱ�ź�������һ��*/
			{
				if (before != Tm.Number)
				{
					system("cls"); printf("\n���ҳɹ���\n\n��Ҫ���ҵļ�ͥ��Ա����Ϣ���£�\n");
				}
				printf("######################################\n");
				printf("\n��Ա��ţ�%ld\n", Tm.Number);
				printf("��Ա������%s\n", Tm.Name);
				printf("��Ա���룺%f Ԫ\n", Tm.in);
				printf("����ʱ�䣺%s\n", Tm.intime);

				printf("######################################\n");    result = 1;/*" result=1"˵���ҵ��˸ü�ͥ��Ա�Ķ�Ӧ��Ϣ.*/
				before = Tm.Number;
			}
		}
	}
	fclose(fp);
	if (result == 0)
	{
		system("cls");
		printf("�Բ���\n�ļ���û�иü�ͥ��Ա����Ӧ����Ϣ��\n");
	}
	printf("\n���������ǣ� y/Y����n/N��\n");
	next = getche();
	putchar('\n'); system("cls");
	if (next == 'y' || next == 'Y') goto begin;
}
//----------------------------------------------------------------------------------
void xiugaizhi()     /*�޸ļ�ͥ��Ա��֧��Ϣ��¼*/
{
	int i, result = 0;
	long modnum;/*�洢Ҫ�޸ĵļ�ͥ��Ա���*/
	/*��������޸ĺ���Ϣ*/
	long no, Number;
	char Name[20];
	float in;
	char intime[10];
	float out;
	char outtime[10];
	float sum;
	money Tm;      /*������в���ʱ����ʱ�ṹ�����*/
	money s[SIZE];   /*SIZE����shead.hͷ�ļ��ж���ĳ�����ֵΪ100  */
	int recNumber;
	char Da[40], next;
	/*Da�洢��ͥ��Ա��֧��Ϣ��Ϣ���ļ�����nextΪ�Ƿ������һ�β�����ѡ��*/
	FILE* fp;   /*fpָ��ָ��洢���ݵ��ļ���*/
	/*����Ҫ�����޸ļ�¼���ļ���*/
	printf("\n������洢���ݵ��ļ��������س���������\n");
	flush();
	gets_s(Da, sizeof(Da));

begin:
	fp = fopen(Da, "rb"); /*ֻ����ʽ���ļ�*/
	if (fp == NULL)
	{
		printf("\n���ļ� %s ʧ�ܣ��������������\n", Da);
		exit(0);
	}
	printf("��������Ҫ�޸ĵļ�ͥ��Ա�ĳ�Ա��ţ�");
	scanf("%ld", &modnum);
	printf("��Ҫ�޸ĵĳ�Ա����ǣ�%ld\n\n", modnum);
	while (fread(&Tm, sizeof(money), 1, fp) != (int)NULL)    /*��ȡ�ļ����ݣ��ж��Ƿ��ȡ�ɹ�*/
	{
		if (Tm.Number == modnum)                           /*����ı�ź��ļ����ݵı��һ��*/
		{
			printf("############################\n");
			printf("\n�������ݱ�ţ�%ld\n", Tm.no);
			printf("\n    ��Ա��ţ�%ld\n", Tm.Number);
			printf("\n    ��Ա������%s\n", Tm.Name);
			printf("\n    ��Ա֧����%fԪ\n", Tm.out);
			printf("\n    ֧��ʱ�䣺%s\n", Tm.outtime);
			printf("############################\n");
			result = 1;
		}
	}
	rewind(fp); /*���ļ�ָ��ָ���ļ��Ŀ�ͷ*/
	if (result == 0)
	{
		printf("������ı�Ų����ڣ���ȷ�Ϻ��������룺\n");
		printf("\n�Ƿ������(�ǣ�y/Y����n/N)");
		next = getche(); system("cls");
		putchar('\n');
		if (next == 'y' || next == 'Y') goto begin;
		else exit(0);
	}
	result = 0;
	printf("��������Ҫ�޸ĵĸ������ݱ�ţ�\n");
	scanf("%ld", &no);

	/*����Ҫ�޸ļ�¼�ĸ�������ֵ*/
	Number = modnum;
	printf("����������֧����֧��ʱ�䣬������Ϊ0ʱ������\n");
	printf("��Ա������");
	scanf("%s", Name);
	printf("��Ա֧����");
	scanf("%f", &out);
	printf("֧��ʱ�䣺");
	scanf("%s", outtime);
	sum = in - out;
	/*���ļ���Ҫ�޸ĵ���Ϣ����ṹ������*/
	recNumber = 0;
	/*ѭ�����ļ����ݶ���ṹ�����飬
	���ļ��е����ݼ�ͥ��Ա���ݱ�ź�Ҫ�޸ĵļ�ͥ��Ա���ݱ�Ų�������ԭ��д�����飬
	���ļ������ݵļ�ͥ��Ա���ݱ�ź�Ҫ�޸ļ�ͥ��Ա���ݱ��ƥ�䣬
	���������ĸ����޸��������¸�ֵ�����޸ģ���д������*/
	while ((fread(&Tm, sizeof(money), 1, fp)) != (int)NULL)     /*��ȡ�ļ����ݡ��Ƿ�ɹ�*/
	{
		if (Tm.no != no)                                    /*��������ݱ�ź��ļ����ݱ�Ų�һ��*/
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
		if (Tm.no == no)                                   /*��������ݱ�ź��ļ����ݱ��һ��*/
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
	/*���޸ĺ�Ľṹ�������¼д���ļ�*/
	fp = fopen(Da, "wb+");      /*���ļ���ԭ�ļ��������*/
	if (fp == NULL)
	{
		printf("\n���ļ�%sʧ�ܣ��������������\n", Da);
		exit(0);
	}
	for (i = 0; i < recNumber; i++)     /*����ѭ��������д���ļ�*/
	{
		if (fwrite(&s[i], sizeof(money), 1, fp) != 1)
		{
			printf("\nд���ļ� %s ʧ�ܣ��������������\n", Da);
			exit(0);
		}
	}
	fclose(fp);
	if (result == 1)
	{
		printf("�ļ��޸ĳɹ����ѳɹ��������û��ļ���\n");
		/*ѯ���Ƿ�鿴�޸ĺ���ļ�*/
		printf("\n�Ƿ�鿴�޸ĺ���ļ���(�ǣ�y/Y����n/N)");
		next = getche(); system("cls");
		putchar('\n');
		if (next == 'y' || next == 'Y')
		{/*��ʾ�޸ĺ���ļ�*/
			fp = fopen(Da, "rb");            /*ֻ����ʽ���ļ�*/
			if (fp == NULL)
			{
				printf("\n���ļ�%sʧ�ܣ��������������\n", Da);
				exit(0);
			}
			system("cls");
			printf("\n�޸ĺ���ļ�ȫ�������ǣ�\n");
			while (fread(&Tm, sizeof(money), 1, fp) != (int)NULL)
			{
				printf("############################\n\n");
				printf(" ��Ա��ţ�%ld\n", Tm.Number);
				printf(" ��Ա������%s\n", Tm.Name);
				printf(" ��Ա֧����%fԪ\n", Tm.out);
				printf(" ֧��ʱ�䣺%s\n", Tm.outtime);
				printf("############################\n");
				printf("\n");
			}
			fclose(fp);
		}
	}
	if (result == 0)
		printf("\n����������ݱ�Ų����ڡ��ļ��޸�ʧ�ܡ���\n\n");

	/*��ʾ�Ƿ������һ���޸�*/
	printf("\n�Ƿ������(�ǣ�y/Y����n/N)");
	next = getche(); system("cls");
	putchar('\n');
	if (next == 'y' || next == 'Y') goto begin;
}
//------------------------------------------------------------------------------
void xiugaishou()     /*�޸ļ�ͥ��Ա����Ϣ��¼*/
{
	int i, result = 0;
	long modnum;/*�洢Ҫ�޸ĵļ�ͥ��Ա���*/
	/*��������޸ĺ���Ϣ*/
	long no, Number;
	char Name[20];
	float in;
	char intime[10];
	float out=0;
	char outtime[10];
	float sum;
	money Tm;      /*������в���ʱ����ʱ�ṹ�����*/
	money s[SIZE];   /*SIZE����shead.hͷ�ļ��ж���ĳ�����ֵΪ100  */
	int recNumber;
	char Da[40], next;
	/*Da�洢��ͥ��Ա��֧��Ϣ��Ϣ���ļ�����nextΪ�Ƿ������һ�β�����ѡ��*/
	FILE* fp;   /*fpָ��ָ��洢���ݵ��ļ���*/
	/*����Ҫ�����޸ļ�¼���ļ���*/
	printf("\n������洢���ݵ��ļ��������س���������\n");
	flush();
	gets_s(Da, sizeof(Da));

begin:
	fp = fopen(Da, "rb"); /*ֻ����ʽ���ļ�*/
	if (fp == NULL)
	{
		printf("\n���ļ� %s ʧ�ܣ��������������\n", Da);
		exit(0);
	}
	printf("��������Ҫ�޸ĵļ�ͥ��Ա�ĳ�Ա��ţ�");
	scanf("%ld", &modnum);
	printf("��Ҫ�޸ĵĳ�Ա����ǣ�%ld\n\n", modnum);
	while (fread(&Tm, sizeof(money), 1, fp) != (int)NULL)    /*��ȡ�ļ����ݣ��ж��Ƿ��ȡ�ɹ�*/
	{
		if (Tm.Number == modnum)                           /*����ı�ź��ļ����ݵı��һ��*/
		{
			printf("############################\n");
			printf("\n�������ݱ�ţ�%ld\n", Tm.no);
			printf("\n    ��Ա��ţ�%ld\n", Tm.Number);
			printf("\n    ��Ա������%s\n", Tm.Name);
			printf("\n    ��Ա���룺%fԪ\n", Tm.in);
			printf("\n    ����ʱ�䣺%s\n", Tm.intime);
			printf("############################\n");
			result = 1;
		}
	}
	rewind(fp); /*���ļ�ָ��ָ���ļ��Ŀ�ͷ*/
	if (result == 0)
	{
		printf("������ı�Ų����ڣ���ȷ�Ϻ��������룺\n");
		printf("\n�Ƿ������(�ǣ�y/Y����n/N)");
		next = getche(); system("cls");
		putchar('\n');
		if (next == 'y' || next == 'Y') goto begin;
		else exit(0);
	}
	result = 0;
	printf("��������Ҫ�޸ĵĸ������ݱ�ţ�\n");
	scanf("%ld", &no);

	/*����Ҫ�޸ļ�¼�ĸ�������ֵ*/
	Number = modnum;
	printf("�������������룬����ʱ�䣬������Ϊ0ʱ������\n");
	printf("��Ա������");
	scanf("%s", Name);
	printf("��Ա���룺");
	scanf("%f", &in);
	printf("����ʱ�䣺");
	scanf("%s", intime);

	sum = in - out;
	/*���ļ���Ҫ�޸ĵ���Ϣ����ṹ������*/
	recNumber = 0;
	/*ѭ�����ļ����ݶ���ṹ�����飬
	���ļ��е����ݼ�ͥ��Ա���ݱ�ź�Ҫ�޸ĵļ�ͥ��Ա���ݱ�Ų�������ԭ��д�����飬
	���ļ������ݵļ�ͥ��Ա���ݱ�ź�Ҫ�޸ļ�ͥ��Ա���ݱ��ƥ�䣬
	���������ĸ����޸��������¸�ֵ�����޸ģ���д������*/
	while ((fread(&Tm, sizeof(money), 1, fp)) != (int)NULL)     /*��ȡ�ļ����ݡ��Ƿ�ɹ�*/
	{
		if (Tm.no != no)                                    /*��������ݱ�ź��ļ����ݱ�Ų�һ��*/
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
		if (Tm.no == no)                                   /*��������ݱ�ź��ļ����ݱ��һ��*/
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
	/*���޸ĺ�Ľṹ�������¼д���ļ�*/
	fp = fopen(Da, "wb+");      /*���ļ���ԭ�ļ��������*/
	if (fp == NULL)
	{
		printf("\n���ļ�%sʧ�ܣ��������������\n", Da);
		exit(0);
	}
	for (i = 0; i < recNumber; i++)     /*����ѭ��������д���ļ�*/
	{
		if (fwrite(&s[i], sizeof(money), 1, fp) != 1)
		{
			printf("\nд���ļ� %s ʧ�ܣ��������������\n", Da);
			exit(0);
		}
	}
	fclose(fp);
	if (result == 1)
	{
		printf("�ļ��޸ĳɹ����ѳɹ��������û��ļ���\n");
		/*ѯ���Ƿ�鿴�޸ĺ���ļ�*/
		printf("\n�Ƿ�鿴�޸ĺ���ļ���(�ǣ�y/Y����n/N)");
		next = getche(); system("cls");
		putchar('\n');
		if (next == 'y' || next == 'Y')
		{/*��ʾ�޸ĺ���ļ�*/
			fp = fopen(Da, "rb");            /*ֻ����ʽ���ļ�*/
			if (fp == NULL)
			{
				printf("\n���ļ�%sʧ�ܣ��������������\n", Da);
				exit(0);
			}
			system("cls");
			printf("\n�޸ĺ���ļ�ȫ�������ǣ�\n");
			while (fread(&Tm, sizeof(money), 1, fp) != (int)NULL)
			{
				printf("############################\n\n");
				printf(" ��Ա��ţ�%ld\n", Tm.Number);
				printf(" ��Ա������%s\n", Tm.Name);
				printf(" ��Ա���룺%fԪ\n", Tm.in);
				printf(" ����ʱ�䣺%s\n", Tm.intime);
				printf("############################\n");
				printf("\n");
			}
			fclose(fp);
		}
	}
	if (result == 0)
		printf("\n����������ݱ�Ų����ڡ��ļ��޸�ʧ�ܡ���\n\n");

	/*��ʾ�Ƿ������һ���޸�*/
	printf("\n�Ƿ������(�ǣ�y/Y����n/N)");
	next = getche(); system("cls");
	putchar('\n');
	if (next == 'y' || next == 'Y') goto begin;
}
//--------------------------------------------------------------------------------------------

void shanchushou()    /*ɾ����ͥ��Ա����Ϣ��¼*/
{
	int i, result = 0;
	long delnum;      /*���Ҫ�����Ҫɾ����ͥ��Ա���*/
	money Tm;         /*������в���ʱ����ʱ�ṹ�����*/
	money s[SIZE];
	int recNumber;    /*ԭ�ļ��еļ�¼��*/
	char Da[40], next;
	FILE* fp;      /*fpָ��ָ��洢���ݵ��ļ���*/
	printf("\n������洢���ݵ��ļ��������س���������\n");
	flush();
	gets_s(Da, sizeof(Da));

begin:
	/*�Զ����ƶ��ķ�ʽ���ļ�*/
	fp = fopen(Da, "rb");
	if (fp == NULL)
	{
		printf("\n���ļ� %s ʧ�ܣ��������������\n", Da);
		exit(0);
	}
	/*����Ҫɾ���ļ�ͥ��Ա���*/
	printf("������Ҫɾ���ļ�ͥ��Ա��ţ�");
	scanf("%ld", &delnum);
	printf("��Ҫɾ���ı���ǣ�%ld\n", delnum);

	while (fread(&Tm, sizeof(money), 1, fp) != (int)NULL)  /*���ļ��ж�ȡ���ݣ��Ƿ��ȡ�ɹ�*/
	{
		if (Tm.Number == delnum)
		{
			printf("������֧��¼���£�\n");
			printf("############################\n");
			printf("�������ݱ�ţ�%ld\n", Tm.no);
			printf("��Ա��ţ�%ld\n", Tm.Number);
			printf("��Ա������%s\n", Tm.Name);
			printf("��Ա���룺%fԪ\n", Tm.in);
			printf("����ʱ�䣺%s\n", Tm.intime);
			printf("############################\n");
			result = 1;
		}
	}
	rewind(fp);     /*���ļ�ָ������ָ���ļ��Ŀ�ͷ*/
	if (result == 0)
	{
		printf("\n������ı�Ų����ڣ���ȷ�Ϻ���������\n");
		printf("\n�Ƿ����ɾ����(�ǣ�y/Y;��n/N)");
		next = getche();
		system("cls");
		putchar('\n');
		if (next == 'y' || next == 'Y') goto begin;
	}
	/*ѯ���Ƿ�ɾ��*/
	printf("\n��ȷ��Ҫɾ���ü�¼��ɾ���󲻿ɻָ�����(�ǣ�y/Y;��n/N)");
	next = getche();
	putchar('\n');
	if (next == 'y' || next == 'Y')
	{
		system("cls");
		printf("��ϲ�������¼�ѳɹ�ɾ������\n");
		/*���ļ�����Ϣ����ṹ������*/
		/*��Ҫɾ���ļ�ͥ��Ա�����ƥ����д�����飬
		ѭ���������м�Ϊȥ����Ҫɾ����¼���ʣ���¼*/
		recNumber = 0;
		while ((fread(&Tm, sizeof(money), 1, fp)) != (int)NULL)/*���ļ��ж�ȡ���ݣ��Ƿ��ȡ�ɹ�*/
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
		/*��ɾ�����ʣ��ṹ���¼д���ļ�*/
		fp = fopen(Da, "wb+");       /*��д��ʽ���ļ���ԭ�ļ��������*/
		if (fp == NULL)
		{
			printf("\n��¼�ļ� %sʧ�ܣ��������������\n", Da);
			exit(0);
		}
		for (i = 0; i < recNumber; i++)    /*��ѭ��������д���ļ�*/
		{
			if (fwrite(&s[i], sizeof(money), 1, fp) != 1)
			{
				printf("\n��¼�ļ� %s ʧ�ܣ��������������\n", Da);
				exit(0);
			}
		}
		fclose(fp);
		/*��ʾɾ��������Ϣ��¼����ļ�*/
		printf("�Ƿ�鿴ɾ����ʣ�µ����ݡ�\n");
		printf("\n�Ƿ�(�ǣ�y/Y;��n/N)");
		next = getche(); system("cls");
		putchar('\n');
		if (next == 'y' || next == 'Y')

		{
			fp = fopen(Da, "rb"); /*ֻ����ʽ���ļ�*/
			if (fp == NULL)
			{
				printf("\n���ļ�%sʧ�ܣ�������������� \n", Da);
				exit(0);
			}
			printf("################################################################################\n");
			printf("ɾ����ʣ��ȫ�������ǣ�\n");
			while (fread(&Tm, sizeof(money), 1, fp) != (int)NULL)
			{
				printf("############################\n");
				printf("��Ա��ţ�%ld\n", Tm.Number);
				printf("��Ա������%s\n", Tm.Name);
				printf("��Ա���룺%fԪ\n", Tm.in);
				printf("����ʱ�䣺%s\n", Tm.intime);

				printf("############################\n");
			}
		}
	}
	else
	{
		system("cls");
		printf("\nɾ��ʧ�ܣ�ԭ���û�ȡ������\n\n");
	}fclose(fp);
	/*ѯ���Ƿ����*/
	printf("\n�Ƿ����ɾ����(�ǣ�y/Y;��n/N)");
	next = getche(); system("cls");
	putchar('\n');
	if (next == 'y' || next == 'Y') goto begin;
}

//------------------------------------------------------------------------------

void shanchuzhi()    /*ɾ����ͥ��Ա֧��Ϣ��¼*/
{
	int i, result = 0;
	long delnum;      /*���Ҫ�����Ҫɾ����ͥ��Ա���*/
	money Tm;         /*������в���ʱ����ʱ�ṹ�����*/
	money s[SIZE];
	int recNumber;    /*ԭ�ļ��еļ�¼��*/
	char Da[40], next;
	FILE* fp;      /*fpָ��ָ��洢���ݵ��ļ���*/
	printf("\n������洢���ݵ��ļ��������س���������\n");
	flush();
	gets_s(Da, sizeof(Da));

begin:
	/*�Զ����ƶ��ķ�ʽ���ļ�*/
	fp = fopen(Da, "rb");
	if (fp == NULL)
	{
		printf("\n���ļ� %s ʧ�ܣ��������������\n", Da);
		exit(0);
	}
	/*����Ҫɾ���ļ�ͥ��Ա���*/
	printf("������Ҫɾ���ļ�ͥ��Ա��ţ�");
	scanf("%ld", &delnum);
	printf("��Ҫɾ���ı���ǣ�%ld\n", delnum);

	while (fread(&Tm, sizeof(money), 1, fp) != (int)NULL)  /*���ļ��ж�ȡ���ݣ��Ƿ��ȡ�ɹ�*/
	{
		if (Tm.Number == delnum)
		{
			printf("������֧��¼���£�\n");
			printf("############################\n");
			printf("�������ݱ�ţ�%ld\n", Tm.no);
			printf("��Ա��ţ�%ld\n", Tm.Number);
			printf("��Ա������%s\n", Tm.Name);

			printf("��Ա֧����%fԪ\n", Tm.out);
			printf("֧��ʱ�䣺%s\n", Tm.outtime);

			printf("############################\n");
			result = 1;
		}
	}
	rewind(fp);     /*���ļ�ָ������ָ���ļ��Ŀ�ͷ*/
	if (result == 0)
	{
		printf("\n������ı�Ų����ڣ���ȷ�Ϻ���������\n");
		printf("\n�Ƿ����ɾ����(�ǣ�y/Y;��n/N)");
		next = getche();
		system("cls");
		putchar('\n');
		if (next == 'y' || next == 'Y') goto begin;
	}
	/*ѯ���Ƿ�ɾ��*/
	printf("\n��ȷ��Ҫɾ���ü�¼��ɾ���󲻿ɻָ�����(�ǣ�y/Y;��n/N)");
	next = getche();
	putchar('\n');
	if (next == 'y' || next == 'Y')
	{
		system("cls");
		printf("��ϲ�������¼�ѳɹ�ɾ������\n");
		/*���ļ�����Ϣ����ṹ������*/
		/*��Ҫɾ���ļ�ͥ��Ա�����ƥ����д�����飬
		ѭ���������м�Ϊȥ����Ҫɾ����¼���ʣ���¼*/
		recNumber = 0;
		while ((fread(&Tm, sizeof(money), 1, fp)) != (int)NULL)/*���ļ��ж�ȡ���ݣ��Ƿ��ȡ�ɹ�*/
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
		/*��ɾ�����ʣ��ṹ���¼д���ļ�*/
		fp = fopen(Da, "wb+");       /*��д��ʽ���ļ���ԭ�ļ��������*/
		if (fp == NULL)
		{
			printf("\n��¼�ļ� %sʧ�ܣ��������������\n", Da);
			exit(0);
		}
		for (i = 0; i < recNumber; i++)    /*��ѭ��������д���ļ�*/
		{
			if (fwrite(&s[i], sizeof(money), 1, fp) != 1)
			{
				printf("\n��¼�ļ� %s ʧ�ܣ��������������\n", Da);
				exit(0);
			}
		}
		fclose(fp);
		/*��ʾɾ��������Ϣ��¼����ļ�*/
		printf("�Ƿ�鿴ɾ����ʣ�µ����ݡ�\n");
		printf("\n�Ƿ�(�ǣ�y/Y;��n/N)");
		next = getche(); system("cls");
		putchar('\n');
		if (next == 'y' || next == 'Y')

		{
			fp = fopen(Da, "rb"); /*ֻ����ʽ���ļ�*/
			if (fp == NULL)
			{
				printf("\n���ļ�%sʧ�ܣ�������������� \n", Da);
				exit(0);
			}
			printf("################################################################################\n");
			printf("ɾ����ʣ��ȫ�������ǣ�\n");
			while (fread(&Tm, sizeof(money), 1, fp) != (int)NULL)
			{
				printf("############################\n");
				printf("��Ա��ţ�%ld\n", Tm.Number);
				printf("��Ա������%s\n", Tm.Name);

				printf("��Ա֧����%fԪ\n", Tm.out);
				printf("֧��ʱ�䣺%s\n", Tm.outtime);

				printf("############################\n");
			}
		}
	}
	else
	{
		system("cls");
		printf("\nɾ��ʧ�ܣ�ԭ���û�ȡ������\n\n");
	}fclose(fp);
	/*ѯ���Ƿ����*/
	printf("\n�Ƿ����ɾ����(�ǣ�y/Y;��n/N)");
	next = getche(); system("cls");
	putchar('\n');
	if (next == 'y' || next == 'Y') goto begin;
}
//---------------------------------------------------------------------------------



void tianjiashou()     /*��Ӳ�������Ϣ��¼*/
{
	FILE* fp = NULL;      /*����ָ���ļ���ָ��*/
	money Tm, ch;          /*������в���ʱ����ʱ�ṹ�����*/
	char Da[40] = "a.txt", next;     /*�洢������֧��Ϣ���ļ���*/
	int count = 1;          /*������������ݵ����Χ*/
	printf("\n ������Ҫ��Ӳ�����֧��Ϣ���ļ�����");
	flush();
	gets_s(Da, sizeof(Da));

begin:count = 1;
	fp = fopen(Da, "ab+");
	if (fp == NULL)        /*�ж��ļ��Ƿ�ɹ���*/
	{
		printf("\n ���ļ� %s ʧ�ܣ��������������\n", Da);
		exit(0);
	}
	while (fread(&ch, sizeof(money), 1, fp) != (int)NULL)      /*���ļ��ж�ȡ���ݲ��ж��Ƿ�ɹ�*/
	{
		count++;
	}
	fclose(fp); /*����ɹ��򿪻򴴽��ļ�������ʾ�����ͥ��Ա��š����������롢֧���������Ϣ*/
	fp = fopen(Da, "ab+");/*ab+:���ļ�����ʱ��׷�ӣ����ļ�������ʱ������*/
	printf("�����ţ����������룬����ʱ�䣬������Ϊ0ʱ������\n");
	printf("��Ų�������λ��������������ʮ���ַ���\n");
	while (count <= SIZE)
	{
		Tm.no = count;
		printf("\n ���� ���Ϊ��ʱ�������룡\n");
		printf("��Ա��ţ�");
		scanf("%ld", &Tm.Number);
		if (Tm.Number == 0)           /*�������ı��Ϊ0������*/
			break;
		printf("�����Ա������");
		scanf("%s", Tm.Name);
		printf("�����Ա���룺");
		scanf("%f", &Tm.in);
		printf("��������ʱ�䣺");
		scanf("%s", Tm.intime);

		Tm.sum = Tm.in - Tm.out;
		printf("\n");
		if (fwrite(&Tm, sizeof(money), 1, fp) != 1)    /*������д���ļ����ж��Ƿ�ɹ�*/
		{
			printf("\nд���ļ� %s ʧ�ܣ��������������\n", Da);
			exit(0);
		}
		count++;
	}           /*�������������������������ķ�Χ������ʾ���ݲ���¼��*/
	if (count > SIZE)
		printf("\n�Բ�������������������������ķ�Χ%d\n", SIZE);
	fclose(fp);
	system("cls");

	printf("������������ѳɹ��洢�� %s �ļ��С�\n", Da);
	printf("�ļ�ȫ���������£�\n");

	fp = fopen(Da, "rb");     /*ֻ����ʽ�򿪶������ļ�*/
	if (fp == NULL)          /*�ж��Ƿ�򿪳ɹ�*/
	{
		printf("\n���ļ�%sʧ�ܣ��������������\n", Da);
		exit(0);
	}
	while (fread(&Tm, sizeof(money), 1, fp) != (int)NULL)   /*���ļ��ж�ȡ���ݣ��Ƿ��ȡ�ɹ�*/
	{
		printf("###############################################\n");
		printf("��Ա��ţ�%ld\n", Tm.Number);
		printf("��Ա������%s\n", Tm.Name);
		printf("��Ա���룺%fԪ\n", Tm.in);
		printf("����ʱ�䣺%s\n", Tm.intime);


		printf("###############################################\n");
		printf("\n\n");
	}
	fclose(fp);
	/*ѯ���Ƿ����*/
	printf("\n�Ƿ������(�ǣ�y/Y;    ��n/N)");
	next = getche();
	system("cls");
	putchar('\n');
	if (next == 'y' || next == 'Y') goto begin;
}


void tianjiaszhi()     /*��Ӳ���֧��Ϣ��¼*/
{
	FILE* fp = NULL;      /*����ָ���ļ���ָ��*/
	money Tm, ch;          /*������в���ʱ����ʱ�ṹ�����*/
	char Da[40], next;     /*�洢������֧��Ϣ���ļ���*/
	int count = 1;          /*������������ݵ����Χ*/
	printf("\n ������Ҫ��Ӳ�����֧��Ϣ���ļ�����");
	flush();
	gets_s(Da, sizeof(Da));


begin:count = 1;
	fp = fopen(Da, "ab+");
	if (fp == NULL)        /*�ж��ļ��Ƿ�ɹ���*/
	{
		printf("\n ���ļ� %s ʧ�ܣ��������������\n", Da);
		exit(0);
	}
	while (fread(&ch, sizeof(money), 1, fp) != (int)NULL)      /*���ļ��ж�ȡ���ݲ��ж��Ƿ�ɹ�*/
	{
		count++;
	}
	fclose(fp); /*����ɹ��򿪻򴴽��ļ�������ʾ�����ͥ��Ա��š�������֧���������Ϣ*/
	fp = fopen(Da, "ab+");/*ab+:���ļ�����ʱ��׷�ӣ����ļ�������ʱ������*/
	printf("�����ţ�������֧����֧��ʱ�䣬������Ϊ0ʱ������\n");
	printf("��Ų�������λ��������������ʮ���ַ���\n");
	while (count <= SIZE)
	{
		Tm.no = count;
		printf("\n ���� ���Ϊ��ʱ�������룡\n");
		printf("��Ա��ţ�");
		scanf("%ld", &Tm.Number);
		if (Tm.Number == 0)           /*�������ı��Ϊ0������*/
			break;
		printf("�����Ա������");
		scanf("%s", Tm.Name);

		printf("�����Ա֧����");
		scanf("%f", &Tm.out);
		printf("����֧��ʱ�䣺");
		scanf("%s", Tm.outtime);
		Tm.sum = Tm.in - Tm.out;
		printf("\n");
		if (fwrite(&Tm, sizeof(money), 1, fp) != 1)    /*������д���ļ����ж��Ƿ�ɹ�*/
		{
			printf("\nд���ļ� %s ʧ�ܣ��������������\n", Da);
			exit(0);
		}
		count++;
	}           /*�������������������������ķ�Χ������ʾ���ݲ���¼��*/
	if (count > SIZE)
		printf("\n�Բ�������������������������ķ�Χ%d\n", SIZE);
	fclose(fp);
	system("cls");

	printf("������������ѳɹ��洢�� %s �ļ��С�\n", Da);
	printf("�ļ�ȫ���������£�\n");

	fp = fopen(Da, "rb");     /*ֻ����ʽ�򿪶������ļ�*/
	if (fp == NULL)          /*�ж��Ƿ�򿪳ɹ�*/
	{
		printf("\n���ļ�%sʧ�ܣ��������������\n", Da);
		exit(0);
	}
	while (fread(&Tm, sizeof(money), 1, fp) != (int)NULL)   /*���ļ��ж�ȡ���ݣ��Ƿ��ȡ�ɹ�*/
	{
		printf("###############################################\n");
		printf("��Ա��ţ�%ld\n", Tm.Number);
		printf("��Ա������%s\n", Tm.Name);

		printf("��Ա֧����%fԪ\n", Tm.out);
		printf("֧��ʱ�䣺%s\n", Tm.outtime);
		printf("###############################################\n");
		printf("\n\n");
	}
	fclose(fp);
	/*ѯ���Ƿ����*/
	printf("\n�Ƿ������(�ǣ�y/Y;    ��n/N)");
	next = getche();
	system("cls");
	putchar('\n');
	if (next == 'y' || next == 'Y') goto begin;
}





void Menu()  //���˵� 
{

	printf("========================\n");
	printf("#��ӭʹ�ü�ͥ����С�ܼ�#\n");
	printf("========================\n");
	printf("1:������� \n");
	printf("2:֧������ \n");
	printf("0:�˳� \n");
}




void income_guanli()    //�������
{
	int choice;
	while (1)
	{
		void income_menu();
		void chaxun_income();



		income_menu();




		printf("������ѡ��:");
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



void zhichu_guanli()    //֧������
{
	int choice;
	while (1)
	{
		void zhichu_menu();




		zhichu_menu();




		printf("������ѡ��:");
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




void income_menu()//����˵�
{
	system("cls");
	printf("========================\n");
	printf("#��ӭʹ�ü�ͥ����С�ܼ�#\n");
	printf("========================\n");
	printf("1.��������¼\n");
	printf("2.��ѯ�����¼\n");
	printf("3.ɾ�������¼\n");
	printf("4.�޸������¼\n");
	printf("5.��ӡ�����¼\n");
	printf("0.������һ��\n");

}
void zhichu_menu() //֧���˵� 
{
	system("cls");
	printf("========================\n");
	printf("#��ӭʹ�ü�ͥ����С�ܼ�#\n");
	printf("========================\n");
	printf("1.���֧����¼\n");
	printf("2.��ѯ֧����¼\n");
	printf("3.ɾ��֧����¼\n");
	printf("4.�޸�֧����¼\n");
	printf("5.��ӡ֧����¼\n");
	printf("0.������һ��\n");

}
void chaxun_menu()       //��ѯ�˵�
{
	system("cls");
	printf("========================\n");
	printf("#��ӭʹ�ü�ͥ����С�ܼ�#\n");
	printf("========================\n");

}




void Quit()  //�˳�
{
	char panduan;
	printf("ȷ���˳�(Y/N)");
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

		printf(">�������ѡ��");
		scanf("%d", &choice);
		fflush(stdin);
		switch (choice)
		{
		case 1: income_guanli(); break;
		case 2: zhichu_guanli(); break;
		case 0: Quit(); break;
		default: printf("�������"); break;
		}
	}
	return 0;
}
