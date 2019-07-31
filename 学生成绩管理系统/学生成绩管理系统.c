#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

# define LEN sizeof(struct Student)

//函数声明
void creat(struct Student **pHead);
void search (struct Student*head);
void cut(struct Student**pHead);
void print(struct Student*head);
void change(struct Student*head);
void order(void);
void Write(struct Student* head);  //将学生信息写入到文件里
void Read(struct Student **pHead);

struct Student
{
	long num;
	char name[20];
	float c;  //chinese
	float m;  //math
	float e;  //english
	struct Student *next;
};

int main()
{   
	printf("\n");
	printf("\n");
	printf("\t\t\t# # # # # # # # # # # # # # #\n");
	printf("\t\t\t*****************************\n");
	printf("\t\t\t欢迎进入学生管理系统\n");
	printf("\t\t\t*****************************\n");
	order();
	return 0;
}
void order (void) //界面功能选择函数
{
	struct Student* pt = NULL;
	Read(&pt); //将学生信息读入
	while(1)
	{
		int x;
		printf("\n");
		printf("\n");
		printf("\t\t\t如果你想增加学生的信息，请按1\n");
		printf("\t\t\t如果你想查找学生的信息，请按2\n");
		printf("\t\t\t如果你想修改学生的信息，请按3\n");
		printf("\t\t\t如果你想删除学生的信息，请按4\n"); 
		printf("\t\t\t如果你想输出学生的信息，请按5\n");
		printf("\t\t\t如果你想结束本次操作，  请按6\n");
		scanf("%d",&x);
		switch(x)
		{
			case 1:creat(&pt);break;
			case 2:search(pt);break;
			case 3:change(pt);break;
			case 4:cut(&pt);break;
			case 5:print(pt);break;
			case 6:
				Write(pt);
				break;
		}
		if(x==6) break;
	}
}

void creat(struct Student** pHead)  //增加学生信息的函数
{
	struct Student *head = *(pHead); 
	struct Student * p1 = (struct Student*)malloc(LEN);
	printf("please input student's 学号:");
	scanf("%ld",&p1->num);
	printf("please input student's 姓名:");
	scanf("%s",&p1->name);
	printf("please input student's 语文成绩:");
	scanf("%f",&p1->c);
	printf("please input student's 数学成绩:");
	scanf("%f",&p1->m);
	printf("please input student's 英语成绩:");
	scanf("%f",&p1->e);
	
	//链表头插
	p1->next = head;
	*pHead = p1;
	printf("插入成功\n");
}


void print(struct Student*head)  //打印所有学生的信息
{
	struct Student*p;
	p=head;
	if(head!=NULL)
	do
	{
		printf("\t\t%ld",p->num);
		printf("\t%s",p->name);
		printf("\t%5.1f",p->c);
		printf("\t%5.1f",p->m);
		printf("\t%5.1f",p->e);
		printf("\n");
		p=p->next;
	}while(p!=NULL);
}

void change(struct Student*head)   //修改学生信息
{  
	long number;
	struct Student*p;

	printf("please enter 学号:");
	scanf("%ld",&number);
	p=head;
	while(1)
	{
		if(p == NULL)
		{
			printf("未找到该学号的学生\n");
			return;
		}

		if(number == p->num)
		{ 
			printf("\t\t%ld",p->num);
			printf("\t%s",p->name);
			printf("\t%5.1f",p->c);
			printf("\t%5.1f",p->m);
			printf("\t%5.1f\n",p->e);break;
		}
		else p=p->next;
	}
	printf("请输入修改后的信息：\n");
	printf("please input student's 学号:");
	scanf("%ld",&p->num);
	printf("please input student's 姓名:");
	scanf("%s",&p->name);
	printf("please input student's 语文成绩:");
	scanf("%f",&p->c);
	printf("please input student's 数学成绩:");
	scanf("%f",&p->m);
	printf("please input student's 英语成绩:");
	scanf("%f",&p->e);
}

void search (struct Student*head)  //根据学号查找学生信息
{
	long number;
	struct Student*p;

	printf("please enter 学号:");
	scanf("%ld",&number);
	p=head;
	while(1)
	{
		if(p == NULL)
		{
			printf("未找到该学号的学生\n");
			return;
		}

		if(number==p->num)
		{ 
			printf("\t\t%ld",p->num);
			printf("\t%s",p->name);
			printf("\t%5.1f",p->c);
			printf("\t%5.1f",p->m);
			printf("\t%5.1f\n",p->e);break;
		}
		else p=p->next;
	}
}
void cut(struct Student **pHead)  //删除对应学号的学生信息
{
	long number;
	struct Student*p,*p1;

	printf("please input student's 学号:");
	scanf("%ld",&number);
	p=(*pHead);
	if(p->num == number) //删除节点为头
	{
		(*pHead) = p->next;
		free(p);
		p = NULL;
	}
	else
	{		
		while(1)
		{
			if(p->next == NULL)
			{
				printf("未找到该学号的学生\n");
				return;
			}

			if(number==p->next->num)
			{
				printf("\t\t%ld",p->next->num);
				printf("\t%s",p->next->name);
				printf("\t%5.1f",p->next->c);
				printf("\t%5.1f",p->next->m);
				printf("\t%5.1f",p->next->e);
				break;
			}
			else p=p->next;
		}
		
		p1=p->next;
		p->next=p1->next;
		free(p1);
		p1=NULL;
	}
	
}

void Write(struct Student* head)  //将学生信息写入到文件里
{
	struct Student* cur = head;
	FILE* f = fopen("学生信息.txt", "w");
	if(f == NULL)
	{
		printf("打开学生信息文件出错\n");
		return;
	}
	
	fputs("学号	姓名	语文	数学	英语\n", f);
	while(cur != NULL)
	{
		fprintf(f,"%ld	%s	%5.1f	%5.1f	%5.1f\n",
			cur->num, cur->name, cur->c, cur->m, cur->e);
		cur = cur->next;
	}
	fclose(f);
}


void Read(struct Student **pHead)
{
	char information[200];
	struct Student *p = NULL;
	char* pInfo = information;
	int i = 0;

	FILE* f = fopen("学生信息.txt", "r");
	if(f == NULL)
	{
		printf("文件打开失败\n");
		return;
	}
	fgets(information, 200, f);
	while(fgets(information, 200, f))
	{
		char _number[20];
		char _name[20];
		char _c[20];
		char _m[20];
		char _e[20];

		p = (struct Student*)malloc(LEN);
		
		i = 0;
		pInfo = information;
		//获取number
		while(*pInfo != '\t')
		{
			_number[i] = *pInfo;
			++i;
			++pInfo;
		}
		_number[i] = '\0';

		++pInfo;
		i = 0;
		//获取name
		while(*pInfo != '\t')
		{
			_name[i] = *pInfo;
			++i;
			++pInfo;
		}
		_name[i] = '\0';

		++pInfo;
		i = 0;

		//获取chinese
		while(*pInfo != '\t')
		{
			_c[i] = *pInfo;
			++i;
			++pInfo;
		}
		_c[i] = '\0';

		++pInfo;
		i = 0;
		//获取math
		while(*pInfo != '\t')
		{
			_m[i] = *pInfo;
			++i;
			++pInfo;
		}
		_m[i] = '\0';

		++pInfo;
		i = 0;
		//获取english
		while(*pInfo != '\t' && *pInfo != '\n')
		{
			_e[i] = *pInfo;
			++i;
			++pInfo;
		}
		_e[i] = '\0';

		p->num = atoi(_number);
		strcpy(p->name, _name);
		p->c = (float)atof(_c);
		p->m = (float)atof(_m);
		p->e = (float)atof(_e);

		//头插
		
		p->next = *pHead;
		*pHead = p;
	}
	fclose(f);
}