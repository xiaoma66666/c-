  #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sqlite3.h>

struct Student
{
	int id;
	int age;
	char name[32];
	char tel[12];
	struct Student *next;
};
typedef struct Student Student;

void InitLink(Student **s)
{
	(*s) = (Student *)malloc(sizeof(Student) * 1);
	if (NULL == *s)
	{
		printf("申请头结点失败\n");
		return;
	}

	(*s)->next = NULL;
}

void welcome()
{
	system("clear");
	printf("--------------------------------------------------------\n");
	printf("\t\t欢迎使用学生管理系统\n");
	printf("--------------------------------------------------------\n");
	sleep(2);
}

void menu()
{
	system("clear");

	printf("---------------------------------------------------------\n");
	printf("\t\t1、添加信息   2、显示信息\n");
	printf("\t\t3、查找信息   4、修改信息\n");
	printf("\t\t5、删除信息   6、退出系统\n");
	printf("---------------------------------------------------------\n");
}
	
int LocateElem(Student *h, Student s)
{
	if (NULL == h)
		return -1;

	int p = 1;
	Student *n = h->next;

	while (n)
	{
		if (n->id > s.id)
		{
			return p;
		}
		n = n->next;
		p++;
	}

	return p;
}

void InsertLink(Student *h, int num, Student s)
{
	if (NULL == h)
		return;

	Student *n = h;
	int k = 1;

	while (k < num && n)
	{
		n = n->next;
		k++;
	}

	if (n == NULL || k > num)
	{
		printf("插入节点的位置有误\n");
		return;
	}

	Student *m = (Student *)malloc(sizeof(Student));
	if (NULL == m)
	{
		printf("申请节点失败\n");
		return;
	}

	m->id = s.id;
	m->age = s.age;
	strcpy(m->name, s.name);
	strcpy(m->tel, s.tel);

	m->next = n->next;
	n->next = m;
}

void add_info(Student *h)
{
	if (NULL == h)
		return;

	printf("请输入学号、年龄、姓名、电话 ...\n");
	Student s;
	int flag = 1;
	while (flag)
	{
		scanf("%d%d%s%s", &s.id, &s.age, s.name, s.tel);

		//判断电话长度
		if (strlen(s.tel) != 11)
		{
			printf("电话长度输入有误，请重新输入全部信息\n");
			continue;
		}

		flag = 0;
		//遍历链表，判断电话是否重复
		Student *p = h->next;
		while (p)
		{
			if (!strcmp(s.tel, p->tel))
			{
				printf("输入的电话重复，请重新输入 ...\n");
				flag = 1;
				break;
			}
			p = p->next;
		}
	}

	int num = LocateElem(h, s);

	InsertLink(h, num, s);
	
	printf("插入数据成功\n");
	sleep(2);
}

void show_info(Student *h)
{
	if (NULL == h)
		return;

	Student *p = h->next;
	while (p)
	{
		printf("%d %d %s %s\n", p->id, p->age, p->name, p->tel);
		p = p->next;
	}
	sleep(2);
}

void find_info(Student *h)
{
	if (NULL == h)
		return;
	
	printf("请输入要查找学生的学号\n");

	int id;
	scanf("%d", &id);

	Student *p = h->next;
	while (p)
	{
		if (p->id == id)
		{
			printf("%d %d %s %s\n", p->id, p->age, p->name, p->tel);
			sleep(2);
			return;
		}
		p = p->next;
	}
	
	printf("学号不存在\n");
	sleep(2);
}

void del_info(Student *h, int id)
{
	if (NULL == h)
		return;

	Student *n1 = h->next, *n2 = h;

	while (n1)
	{
		if (n1->id == id)
		{
			n2->next = n1->next;
			free(n1);

			printf("删除信息成功\n");
			sleep(2);
			return;
		}
		n1 = n1->next;
		n2 = n2->next;
	}

	printf("学生不存在\n");
	sleep(2);
}

void modify_info(Student *h)
{
	if (NULL == h)
		return;

	printf("请输入需要修改的学生的学号\n");
	int id;
	scanf("%d", &id);

	Student *n = h->next;
	while (n)
	{
		if (n->id == id)
		{
			del_info(h, id);
			add_info(h);
			printf("信息修改成功\n");
			sleep(2);
			return;
		}
		n = n->next;
	}

	printf("学生不存在\n");
	sleep(2);
}

void exit_system(Student *h)
{
	sqlite3 *ppdb;
	if (sqlite3_open("student.db", &ppdb) != SQLITE_OK)
	{
		printf("sqlite3_open error\n");
	}

	char sql[256] = {0};
	sprintf(sql, "create table if not exists student (id integer, age integer, name text, tel text primary key);");

	if (sqlite3_exec(ppdb, sql, NULL, NULL, NULL) != SQLITE_OK)
	{
		printf("sqlite3_exec error1\n");
	}

	Student *p = h->next;
	while (p)
	{
		memset(sql, 0, 256);
		sprintf(sql, "insert into student values (%d, %d, '%s', '%s');", 
			p->id, p->age, p->name, p->tel);
		if (sqlite3_exec(ppdb, sql, NULL, NULL, NULL) != SQLITE_OK)
		{
			//continue;
		}
		p = p->next;
	}

	sqlite3_close(ppdb);

	exit(0);
}

int createLink(void *arg, int n, char **value, char **name)
{
	Student *p = (Student *)arg;
	
	Student s;
	s.id = atoi(value[0]);
	s.age = atoi(value[1]);
	strcpy(s.name, value[2]);
	strcpy(s.tel, value[3]);

	int num = LocateElem(p, s);

	InsertLink(p, num, s);

	return 0;
}

void readData(Student *h)
{
	sqlite3 *ppdb;
	if (sqlite3_open("student.db", &ppdb) != SQLITE_OK)
	{
		return;
	}

	char sql[256] = {0};
	sprintf(sql, "select * from student;");

	if (sqlite3_exec(ppdb, sql, createLink, (void *)h, NULL) != SQLITE_OK)
	{
		printf("sqlite3_exec error2\n");
	}
}

int main()
{
	int choice;
	Student *head = NULL;

	InitLink(&head);

	readData(head);

	welcome();

	while (1)
	{
		menu();

		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				add_info(head);
				break;
			case 2:
				show_info(head);
				break;
			case 3:
				find_info(head);
				break;
			case 4:
				modify_info(head);	
				break;
			case 5:
				printf("请输入要删除的学生的学号\n");
				int id;
				scanf("%d", &id);
				del_info(head, id);
				break;
			case 6:
				//exit(1);
				exit_system(head);
				break;
		}
	}

	return 0;
}
