#define _CRT_SECURE_NO_WARNINGS 1

//1.存放好友信息 (名字 电话 性别 住址 年龄)
//2.增删改查

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
	//创建通讯录
	struct Contact con;//con就是通讯录，里面包含1000个信息和size
	//初始化通讯录
	InitContact(&con);
	int input = 0;
	do
	{
		menu();
		printf("请选择：> ");
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
			printf("退出通讯录\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	return 0;
}