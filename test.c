#define _CRT_SECURE_NO_WARNINGS 1

//1.��ź�����Ϣ (���� �绰 �Ա� סַ ����)
//2.��ɾ�Ĳ�

#include "contact.h"

void menu()
{
	printf("**************************************\n");
	printf("****** 1. add         2. del    ******\n");
	printf("****** 3. search      4. modify ******\n");
	printf("****** 5. show        6. sort   ******\n");
	printf("****** 7. save        0. exit   ******\n");
	printf("**************************************\n");
}
int main()
{
	//����ͨѶ¼
	struct Contact con;//con����ͨѶ¼���������1000����Ϣ��size
	//��ʼ��ͨѶ¼
	InitContact(&con);
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��> ");
		scanf("%d", &input);
		Space();
		switch (input) 
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case SAVE:
			SaveContact(&con);
			break;
		case EXIT:
			SaveContact(&con);
			DestoryContact(&con);
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
	return 0;
}