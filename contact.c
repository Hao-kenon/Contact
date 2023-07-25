#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

void InitContact(Contact *ps)
{
	ps->data = (PeoInfo*)malloc(DEFAULT_SZ * sizeof(PeoInfo));
	if (ps->data == NULL)
	{
		return;
	}
	ps->size = 0;//����ͨѶ¼���ֻ��0��Ԫ��
	ps->capacity = DEFAULT_SZ;
	LoadContact(ps);
}

void LoadContact(Contact* ps)
{
	struct PeoInfo tmp = { 0 };
	FILE* pfRead = fopen("contact.dat", "rb");
	if (pfRead == NULL)
	{
		printf("LoadContact::%s\n", strerror(errno));
		return;
	}
	while (fread(&tmp, sizeof(PeoInfo), 1, pfRead))
	{

		ps->data[ps->size] = tmp;
		ps->size++;
	}
	fclose(pfRead);
	pfRead = NULL;
}

void ChectCapacity(Contact* ps)
{
	if (ps->size == ps->capacity)
	{
		//����
		PeoInfo* ptr = realloc(ps->data, (ps->capacity + 2) * sizeof(PeoInfo));
		if (ptr != NULL)
		{
			ps->data = ptr;
			ps->capacity += 2;
			printf("���ݳɹ�\n");
		}
	}
}


void AddContact(Contact* ps)
{
	//��⵱ǰͨѶ¼������
	//1.�������ӿռ�
	//2.����
	ChectCapacity(ps);
	printf("���������֣�> ");
	scanf("%s", ps->data[ps->size].name);
	printf("���������䣺> ");
	scanf("%d", &(ps->data[ps->size].age));
	printf("�������Ա�> ");
	scanf("%s", ps->data[ps->size].sex);
	printf("������绰��> ");
	scanf("%s", ps->data[ps->size].tele);
	printf("�������ַ��> ");
	scanf("%s", ps->data[ps->size].addr);

	ps->size++;
	Space();
	printf("��ӳɹ�\n");
	Space();

}


void ShowContact(const Contact* ps)
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
		Space();
	}
	else
	{
		int i = 0;
		printf("%-5s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		Space();
		for (i = 0; i < ps->size; i++)
		{
			printf("%-5s\t%-4d\t%-5s\t%-12s\t%-20s\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].addr);
		} 
	}
}

void DelContact(Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫɾ���˵�����: > ");
	scanf("%s", &name);
	//1.����ɾ����λ��
	int pos= FindbyName( ps,name); 
	//2.ɾ��
	if(pos == -1)
	{
		printf("ͨѶ¼�����ڴ���\n");
		Space();
	}
	else
	{
		//ɾ������
		int j = 0;
		for (j = pos; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		Space();
		printf("ɾ���ɹ�\n");
		Space();
	}
}

void SearchContact(const Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫ�����˵�����: > ");
	scanf("%s", name);
	int pos = FindbyName(ps, name);
	if (pos == -1)
	{
		printf("ͨѶ¼�����ڴ���\n");
		Space();
	}
	else
	{
		printf("%-5s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		Space();
		printf("%-5s\t%-4d\t%-5s\t%-12s\t%-20s\n",
			ps->data[pos].name,
			ps->data[pos].age,
			ps->data[pos].sex,
			ps->data[pos].tele,
			ps->data[pos].addr);
		Space();
	}
}

void ModifyContact(Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫ�޸��˵�����: > ");
	scanf("%s", &name);
	Space();
	int pos = FindbyName(ps, name);
	if (pos == -1)
	{
		printf("���˲�����\n");
		Space();
	}
	else
	{
		printf("���������֣�> ");
		scanf("%s", ps->data[pos].name);
		printf("���������䣺> ");
		scanf("%d", &(ps->data[pos].age));
		printf("�������Ա�> ");
		scanf("%s", ps->data[pos].sex);
		printf("������绰��> ");
		scanf("%s", ps->data[pos].tele);
		printf("�������ַ��> ");
		scanf("%s", ps->data[pos].addr);
		Space();
		printf("�޸ĳɹ�\n");
		Space();
	}
}

void SortContact(Contact* ps)
{
	qsort(ps->data, ps->size, sizeof(ps->data[0]), cmp_data_age);
	int i = 0;
	printf("%-5s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	Space();
	for (i = 0; i < ps->size; i++)
	{
		printf("%-5s\t%-4d\t%-5s\t%-12s\t%-20s\n",
			ps->data[i].name,
			ps->data[i].age,
			ps->data[i].sex,
			ps->data[i].tele,
			ps->data[i].addr);
		Space();
	}
}

void SaveContact(Contact* ps)
{
	FILE* pfWrite = fopen("contact.dat", "wb");
	if (pfWrite == NULL)
	{
		printf("SaveContact::%s\n", strerror(errno));
		return;
	}
	//��ͨѶ¼��д���ļ�
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		fwrite(&(ps->data[i]), sizeof(PeoInfo), 1, pfWrite);
	}
	fclose(pfWrite);
	pfWrite = NULL;
}

static int FindbyName(const Contact* ps,char name[MAX_NAME]) 
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, name))
		{
			return i;
		}
	}
	//�Ҳ���
	return -1;
}


void DestoryContact(Contact* ps)
{
	free(ps->data);
	ps->data = NULL;
}


void Space()
{
	printf("\n");
}

int cmp_data_age(const* e1, const* e2)
{
	return (( Contact*)e1)->data->age - ((Contact*)e2)->data->age;
}