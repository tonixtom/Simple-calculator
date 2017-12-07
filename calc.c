i love tom
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define STACK_INIT_SIZE 20
#define STACKINCREMENT  10
char OP[]={'+','-','*','/','(',')','='};
typedef char ElemType;
struct node
{
	int coef;    //系数  
	int exp;   //指数  
	struct node * next;//指针域
}chainLink;//创建chainLink的node结点对象
typedef struct
{
    ElemType *base;
    ElemType *top;
    int stackSize;
}sqStack;
typedef struct
{
    int *base;
    int *top;
    int stackSize;
}SqStack;

void InitStack(sqStack *s)
{
    s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if( !s->base )
    {
        exit(0);
    }
	
    s->top = s->base;
    s->stackSize = STACK_INIT_SIZE;
}

void initStack(SqStack *s)
{
    s->base = (int *)malloc(STACK_INIT_SIZE * sizeof(int));
    if( !s->base )
    {
        exit(0);
    }
	
    s->top = s->base;
    s->stackSize = STACK_INIT_SIZE;
}

void Push(sqStack *s, ElemType e)
{
    if( s->top - s->base >= s->stackSize )
    {
        s->base = (ElemType *)realloc(s->base, (s->stackSize + STACKINCREMENT) * sizeof(ElemType));
        if( !s->base )
        {
            exit(0);
        }
    }
	
    *(s->top) = e;
    s->top++;
}

void Pop(sqStack *s, ElemType *e)
{
    if( s->top == s->base )
    {
        return;
    }
    *e = *--(s->top);
}

void push(SqStack *s, int e)
{
    if( s->top - s->base >= s->stackSize )
    {
        s->base = (int *)realloc(s->base, (s->stackSize + STACKINCREMENT) * sizeof(int));
        if( !s->base )
        {
            exit(0);
        }
    }
	
    *(s->top) = e;
    s->top++;
}

void pop(SqStack *s, int *e)
{
    if( s->top == s->base )
    {
        return;
    }
    *e = *--(s->top);
}

int StackLen(sqStack s)
{
    return (s.top - s.base);
}

int stackLen(SqStack s)
{
    return (s.top - s.base);
}

char  GetTop(sqStack *s)
{
	char e;
	if(s->top == s->base)   
		return -1;
	e = *(s->top-1);
	return e;
}

int  getTop(SqStack *s)
{
	int e;
	if(s->top == s->base)   
		return -1;
	e = *(s->top-1);
	return e;
}
int judge(char theta)
{	
	int i;
	if(theta == '+')
		i=0;
	else if(theta == '-')
		i=1;
	else if(theta == '*')
		i=2;
	else if(theta == '/')
		i=3;
	else if(theta == '(')
		i=4;
	else if(theta == ')')
		i=5;
	else
		i=6;
	return i;
}
int precede(char theta1,char theta2)
{
	int  std_cherry[7][7]=
	{
		
		1, 1,-1,-1,-1, 1, 1,
			1, 1,-1,-1,-1, 1, 1,
			1, 1, 1, 1,-1, 1, 1,
			1, 1, 1, 1,-1, 1, 1,
			-1,-1,-1,-1,-1, 0,-2,
			1, 1, 1, 1,-2, 1, 1,
			-1,-1,-1,-1,-1,-2, 0,
	};
	int i,j;
	i = judge(theta1);
	j = judge(theta2);
	return std_cherry[i][j];
}
int OPerate(int a,char theta,int b)
{
	int result;
	switch(theta)
	{
	case '+':
		result = a+b;
		break;
	case '-':
		result = a-b;
		break;
	case '*':
		result = a*b;
		break;
	case '/':
		result = a/b;
		break;
	}
	return result;
}
int In(char *c,char *OP)
{
	int i,comp = 0;
	for(i = 0; i < 7; i++)
	{
		if( c[0] == OP[i])
			comp = 1;
	}
	return comp;
}

int EvaluateEcpression()
{
	sqStack OPTR;
	SqStack OPND;
	char c[10],theta,x;
	int a,b,put;
	InitStack(&OPTR);	
	Push(&OPTR,'=');
	initStack(&OPND);	
	scanf("%s",c);	
	while(c[0] != '=' || GetTop(&OPTR) != '=')
	{
		if(!In(c,OP))	
		{
			put = atoi(c);
			//	printf("%d\n",put);
			push(&OPND,put);
			scanf("%s",c);
		}
		else 
			switch(precede(GetTop(&OPTR),c[0]))
		{
				case -1:
					Push(&OPTR,c[0]); 
					scanf("%s",c);
					break;
				case 0:
					Pop(&OPTR,&x); 
					scanf("%s",c);
					break;
				case 1: 
					Pop(&OPTR,&theta);
					pop(&OPND,&b); 
					pop(&OPND,&a);
					push(&OPND,OPerate(a,theta,b));
					//				printf("%d\n",OPerate(a,theta,b));
					
					break;
		} 
		
	}
    return getTop(&OPND);	
}


void BtoD()
{
    ElemType c;
    sqStack s;
    int len, i, sum = 0;
	
    InitStack(&s);
	
    printf("请输入二进制数，输入#符号表示结束！\n");
    scanf("%c", &c);
    while( c != '#' )
    {
        Push(&s, c);
        scanf("%c", &c);
    }
	
    getchar();  // 把'\n'从缓冲区去掉
	
    len = StackLen(s);
    printf("栈的当前容量是: %d\n", len);
	
    for( i=0; i < len-1; i++ )
    {
        Pop(&s, &c);
        sum = sum + (c-48) * pow(2, i);
    }
	
    printf("转化为十进制数是: %d\n", sum);
	
    return 0;
}


void DtoB()
{
	int  c,d;
    SqStack s;
    int len, i;
	
    InitStack(&s);
	
	printf("请输入十进制数: ");
    scanf("%d", &c);
	printf("转化为二进制数是: "); 
	while(c > 0)
    {
		//	printf("%d",c%2);
        push(&s, c%2);
		c = c - c%2;
		c = c/2;
    }
	
	len = stackLen(s);
	for(i = 0; i < len; i++)
	{
		pop(&s,&d);
		printf("%d",d);
	}
	printf("\n栈的当前容量是: %d\n", len);
	
    return 0;
}


void OtoH()
{  
	
	int i,j,k,s=0; 
	int a;
	char p[30];  
	int result=0;  
	printf("输入你想要转化的八进制数: \n");
	scanf("%d",&a);
	for(i=1;a!=0;i*=8)  
	{  
		if(a%10>7)  
		{   
			s=1;  
			break;  
		}  
		else  
		{  
			result+=(a%10)*i;  
			a=a/10;  
		}  
	}  
	for(j=0;result!=0;j++)  
	{  
		p[j]=result%16;  
		result=result/16;  
		if(p[j]<10)  
			p[j]+=48;  
		else  
		{  
			switch(p[j])  
			{  
			case 10: p[j]='A';  
				break;  
			case 11: p[j]='B';  
				break;  
			case 12:    p[j]='C';  
				break;  
			case 13:    p[j]='D';  
				break;  
			case 14:    p[j]='E';  
				break;  
			case 15:    p[j]='F';  
				break;  
			}  
		}  
	}  
	if(s==1)  
		printf("您的输入有误！请重新输入\n");  
	else   
	{  
		printf("\n转换后的数为：");  
		for(k=j-1;k>=0;k--)  
		{  
			printf("%c",p[k]);  
		}  
		printf("\n");  
	}  
}  

void HtoO()
{ 	
	int i,j,k,s=0;  
	char a[10];
	int result=0;  
	int b[30];  
	int p[30]; 
	scanf("%s",&a);
	for(k=0;;k++)  
	{  
		if(a[k]=='\0')  
			break;  
	}  
	
	for(i=0;i<k;i++)  
	{  
		if(a[i]<='9'&&a[i]>='1')  
			b[i]=a[i]-48;  
		else  
		{  
			switch(a[i])  
			{  
			case 'A': b[i]=10;  
				break;  
			case 'B': b[i]=11;  
				break;  
			case 'C':   b[i]=12;  
				break;  
			case 'D':   b[i]=13;  
				break;  
			case 'E':   b[i]=14;  
				break;  
			case 'F':   b[i]=15;  
				break;  
			case 'a': b[i]=10;  
				break;  
			case 'b': b[i]=11;  
				break;  
			case 'c':   b[i]=12;  
				break;  
			case 'd':   b[i]=13;  
				break;  
			case 'e':   b[i]=14;  
				break;  
			case 'f':   b[i]=15;  
				break;  
			default: s=1;  
			}  
		}  
	}  
	for(j=k-1,i=1;j>=0;j--,i*=16)  
	{  
		result+=b[j]*i;  
	}  
	for(j=0;result!=0;j++)  
	{  
		p[j]=result%8;  
		result=result/8;  
	}  
	if(s==1)  
		printf("您的输入有误！请重新输入\n");  
	else   
	{  
		printf("\n转换后的数为：");  
		for(k=j-1;k>=0;k--)  
		{  
			printf("%d",p[k]);  
		}  
		printf("\n");  
	}  
} 


struct node *create()                    //定义建立多项式函数，并返回链表头指针
{
	struct node *h = NULL, *q, *p;//定义结构体头指针h，标记指针p和q，p是创造新节点的标记指针，q是链接链表的指针；
	int i = 1, N;                             //定义多项式的项数N及标记数i
	printf("请输入多项式的项数: ");
	scanf("%d",&N);
	p = 0;//指针初始化；
	q = 0;//本地指针初始化；
	for (; i <= N; i++)
	{
		p = (struct node *)malloc(sizeof(chainLink));            //为一个新节点分配空间
		printf("请输入第 %i 项的系数：\t",i);
		scanf("%d",&(*p).coef);
		printf("请输入第 %i 项的指数: \t",i);
		scanf("%d",&(*p).exp);
		if (i == 1) { h = p; q = p; }                           //建立头节点
		else
		{
			q->next = p;
			q = p;
		}
	}
	q->next = NULL;//p,q都成为新链表的尾指针；
	p->next = NULL;
	return h;
}
void display(struct node  *h)
{
	struct node *p;                 //定义标记指针，输出链表
	p = h;
	while (p != NULL)
	{
		if (p->coef == 0)
		{
			struct node *d;
			d = h;
			while (d->next != p)
			{
				d = d->next;
			}
			d->next = p->next;
			p = p->next;//删去系数为0的节点；
		}
		else
		{
			if (p->coef<0)                 //系数为负时应加上括号,让式子容易看清；
			{
				if (p->exp == 0) printf("%d+",(*p).coef);
				else printf("(%d)*X^%d+",(*p).coef,(*p).exp);
			}
			else
			{
				if (p->exp == 0) printf("%d+",(*p).coef);
				else if (p->exp!=0&&p->exp!=1)
				{
					printf("%d*X^%d+",(*p).coef,(*p).exp);
				}
				else printf("%d*X+",(*p).coef);
			}
			p = p->next;
		}
	}
	printf("\b \b \n");
	
}
struct node *order(struct node *h)     //定义排序函数，并返回整理后的链表的头指针
{
	struct node *p, *q, *t, *h1, *h2;       //定义三个结构体标记指针和两个头指针
	h1 = h;              //建立一个新的链表，头指针为h，指向原链表的第一个节点，之后将原链表中的节点一个一个的插入此链表，进行排序
	h2 = h1->next;                      //将原来的链表建立成待排序链表
	h1->next = NULL;                    //截断第一个原链表中的节点
	while (h2 != NULL)
	{
		q = h1;
		p = q->next;
		t = h2;                  //从待排序链表中选出一个节点准备插入到新链表中
		h2 = h2->next;           //移动待排序链表的头指针，便于进行下一次挑选
		t->next = NULL;
		if (t->exp>q->exp)            //应插入头指针之前的情况
		{
			t->next = q;
			h1 = t;
			continue;
		}
		if (p == NULL&&t->exp <= q->exp) q->next = t;     //应插入表尾的情况
		while (p != NULL)
		{
			if (t->exp>p->exp)
			{
				q->next = t;
				t->next = p;
				break;
			}
			else
			{
				q = q->next;
				p = p->next;
			}
		}
		if (p == NULL) q->next = t;
	}
	return h1;                //新链表即为按降幂顺序排好的链表，返回其头指针
}
struct node *add(struct node *h1, struct node *h2)   //定义加法函数，并返回结果的链表的头指针
{
	struct node *p, *q, *head, *r;          //定义结构体头指针head和标记指针p,q,r
	p = h1;
	q = h2;
	head = (struct node *)malloc(sizeof(chainLink));    //为结果多项式分配头指针
	if (p->exp >= q->exp) { head = h1; p = p->next; }
	else
	{
		if (p->exp<q->exp) { head = h2; q = q->next; }
		else { p->coef = p->coef + q->coef; head = p; p = p->next; q = q->next; }
	}
	r = head;
	while (p != NULL&&q != NULL)
	{
		if (p->exp>q->exp) { r->next = p; p = p->next; }
		else
		{
			if (p->exp<q->exp) { r->next = q; q = q->next; }
			else { p->coef = p->coef + q->coef; r->next = p; p = p->next; q = q->next; }
		}
		r = r->next;
	}
	if (p == NULL&&q == NULL) r->next = NULL;
	else
	{
		if (p == NULL) r->next = q;
		if (q == NULL) r->next = p;
	}
	return head;
}


void polynomail()
{
	struct node *h1, *h2, *h3;//定义3个头指针；
	printf("请输入第一个多项式：\n");
	h1 = create();//创造第一个线性链表；
	printf("\n您输入的第一个多项式为：\n");
	display(h1);//把多项式显示出来；
	h1 = order(h1);
	printf("\n降幂排列后的第一个多项式为：\n");
	display(h1);
	printf("\n");
	printf("\n请输入第二个多项式：\n");
	h2 = create();//创造第二个线性链表；
	printf("\n您输入的第二个多项式为：\n");
	display(h2);//把多项式显示出来；
	h2 = order(h2);
	printf("\n降幂排列后的第二个多项式为：\n");
	display(h2);
	printf("\n");
	h3 = add(h1, h2);//利用加函数将多项式相加；
	printf("\n第一个多项式和第二个多项式相加后：\n");
	display(h3);
	system("pause");
	return 0;
}

void phead(void)
{
	printf("*******************************************************\n");
	printf("********************Tom's calclater********************\n");
	printf("*******************************************************\n");
	printf("\n***************  请选择需要的计算操作:*****************\n");
}
void thead(void)
{
	printf("*******************************************************\n");
	printf("请输入相应的数字,并进行一步计算: ");
}

void main()  
{  
	int i,j,q=0; 
	int tom;
	phead();
	
	do  
	{   
		
		printf("0、退出\n1、进制转化\n2、计算器\n3、一元多项式加法\n");  
		thead();
		scanf("%d",&i);  
		switch (i)  
		{  
		case 1:  thead(); 
			printf("\n请要转化的的进制:\n0、退出\n1、二进制到十进制\n2、十进制到二进制\n3、八进制到十六进制\n4、十六进制到八进制\n");  
			scanf("%d",&j);  
			switch(j)  
			{  
			case 1: printf("\n请输入您想要转化的数：");  
				BtoD(); 
				break;  
			case 2: printf("\n请输入您想要转化的数：");  
				DtoB(); 
				break;  
			case 3: printf("\n请输入您想要转化的数：");  
				OtoH(); 
				break;  
			case 4: printf("\n请输入您想要转化的数：");  
				HtoO();
				break;  
			case 0:   
				
				printf("谢谢使用！！");  
				
			}  
			break;  
			case 2: printf("\n请输入你想要计算的表达式（在以空格隔开每个输入！）：\n");
				tom = EvaluateEcpression();
				printf("表达式的计算结界是 %d\n",tom);
				break;
			case 3: 
				polynomail();
				break;
			case 0: printf("\n谢谢使用！\n");  
				break;
				
		}  
	}while(q==1);  
}  


