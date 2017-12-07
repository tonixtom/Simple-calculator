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
	int coef;    //ϵ��  
	int exp;   //ָ��  
	struct node * next;//ָ����
}chainLink;//����chainLink��node������
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
	
    printf("�������������������#���ű�ʾ������\n");
    scanf("%c", &c);
    while( c != '#' )
    {
        Push(&s, c);
        scanf("%c", &c);
    }
	
    getchar();  // ��'\n'�ӻ�����ȥ��
	
    len = StackLen(s);
    printf("ջ�ĵ�ǰ������: %d\n", len);
	
    for( i=0; i < len-1; i++ )
    {
        Pop(&s, &c);
        sum = sum + (c-48) * pow(2, i);
    }
	
    printf("ת��Ϊʮ��������: %d\n", sum);
	
    return 0;
}


void DtoB()
{
	int  c,d;
    SqStack s;
    int len, i;
	
    InitStack(&s);
	
	printf("������ʮ������: ");
    scanf("%d", &c);
	printf("ת��Ϊ����������: "); 
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
	printf("\nջ�ĵ�ǰ������: %d\n", len);
	
    return 0;
}


void OtoH()
{  
	
	int i,j,k,s=0; 
	int a;
	char p[30];  
	int result=0;  
	printf("��������Ҫת���İ˽�����: \n");
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
		printf("����������������������\n");  
	else   
	{  
		printf("\nת�������Ϊ��");  
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
		printf("����������������������\n");  
	else   
	{  
		printf("\nת�������Ϊ��");  
		for(k=j-1;k>=0;k--)  
		{  
			printf("%d",p[k]);  
		}  
		printf("\n");  
	}  
} 


struct node *create()                    //���彨������ʽ����������������ͷָ��
{
	struct node *h = NULL, *q, *p;//����ṹ��ͷָ��h�����ָ��p��q��p�Ǵ����½ڵ�ı��ָ�룬q�����������ָ�룻
	int i = 1, N;                             //�������ʽ������N�������i
	printf("���������ʽ������: ");
	scanf("%d",&N);
	p = 0;//ָ���ʼ����
	q = 0;//����ָ���ʼ����
	for (; i <= N; i++)
	{
		p = (struct node *)malloc(sizeof(chainLink));            //Ϊһ���½ڵ����ռ�
		printf("������� %i ���ϵ����\t",i);
		scanf("%d",&(*p).coef);
		printf("������� %i ���ָ��: \t",i);
		scanf("%d",&(*p).exp);
		if (i == 1) { h = p; q = p; }                           //����ͷ�ڵ�
		else
		{
			q->next = p;
			q = p;
		}
	}
	q->next = NULL;//p,q����Ϊ�������βָ�룻
	p->next = NULL;
	return h;
}
void display(struct node  *h)
{
	struct node *p;                 //������ָ�룬�������
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
			p = p->next;//ɾȥϵ��Ϊ0�Ľڵ㣻
		}
		else
		{
			if (p->coef<0)                 //ϵ��Ϊ��ʱӦ��������,��ʽ�����׿��壻
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
struct node *order(struct node *h)     //�����������������������������ͷָ��
{
	struct node *p, *q, *t, *h1, *h2;       //���������ṹ����ָ�������ͷָ��
	h1 = h;              //����һ���µ�����ͷָ��Ϊh��ָ��ԭ����ĵ�һ���ڵ㣬֮��ԭ�����еĽڵ�һ��һ���Ĳ����������������
	h2 = h1->next;                      //��ԭ�����������ɴ���������
	h1->next = NULL;                    //�ضϵ�һ��ԭ�����еĽڵ�
	while (h2 != NULL)
	{
		q = h1;
		p = q->next;
		t = h2;                  //�Ӵ�����������ѡ��һ���ڵ�׼�����뵽��������
		h2 = h2->next;           //�ƶ������������ͷָ�룬���ڽ�����һ����ѡ
		t->next = NULL;
		if (t->exp>q->exp)            //Ӧ����ͷָ��֮ǰ�����
		{
			t->next = q;
			h1 = t;
			continue;
		}
		if (p == NULL&&t->exp <= q->exp) q->next = t;     //Ӧ�����β�����
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
	return h1;                //������Ϊ������˳���źõ�����������ͷָ��
}
struct node *add(struct node *h1, struct node *h2)   //����ӷ������������ؽ���������ͷָ��
{
	struct node *p, *q, *head, *r;          //����ṹ��ͷָ��head�ͱ��ָ��p,q,r
	p = h1;
	q = h2;
	head = (struct node *)malloc(sizeof(chainLink));    //Ϊ�������ʽ����ͷָ��
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
	struct node *h1, *h2, *h3;//����3��ͷָ�룻
	printf("�������һ������ʽ��\n");
	h1 = create();//�����һ����������
	printf("\n������ĵ�һ������ʽΪ��\n");
	display(h1);//�Ѷ���ʽ��ʾ������
	h1 = order(h1);
	printf("\n�������к�ĵ�һ������ʽΪ��\n");
	display(h1);
	printf("\n");
	printf("\n������ڶ�������ʽ��\n");
	h2 = create();//����ڶ�����������
	printf("\n������ĵڶ�������ʽΪ��\n");
	display(h2);//�Ѷ���ʽ��ʾ������
	h2 = order(h2);
	printf("\n�������к�ĵڶ�������ʽΪ��\n");
	display(h2);
	printf("\n");
	h3 = add(h1, h2);//���üӺ���������ʽ��ӣ�
	printf("\n��һ������ʽ�͵ڶ�������ʽ��Ӻ�\n");
	display(h3);
	system("pause");
	return 0;
}

void phead(void)
{
	printf("*******************************************************\n");
	printf("********************Tom's calclater********************\n");
	printf("*******************************************************\n");
	printf("\n***************  ��ѡ����Ҫ�ļ������:*****************\n");
}
void thead(void)
{
	printf("*******************************************************\n");
	printf("��������Ӧ������,������һ������: ");
}

void main()  
{  
	int i,j,q=0; 
	int tom;
	phead();
	
	do  
	{   
		
		printf("0���˳�\n1������ת��\n2��������\n3��һԪ����ʽ�ӷ�\n");  
		thead();
		scanf("%d",&i);  
		switch (i)  
		{  
		case 1:  thead(); 
			printf("\n��Ҫת���ĵĽ���:\n0���˳�\n1�������Ƶ�ʮ����\n2��ʮ���Ƶ�������\n3���˽��Ƶ�ʮ������\n4��ʮ�����Ƶ��˽���\n");  
			scanf("%d",&j);  
			switch(j)  
			{  
			case 1: printf("\n����������Ҫת��������");  
				BtoD(); 
				break;  
			case 2: printf("\n����������Ҫת��������");  
				DtoB(); 
				break;  
			case 3: printf("\n����������Ҫת��������");  
				OtoH(); 
				break;  
			case 4: printf("\n����������Ҫת��������");  
				HtoO();
				break;  
			case 0:   
				
				printf("ллʹ�ã���");  
				
			}  
			break;  
			case 2: printf("\n����������Ҫ����ı��ʽ�����Կո����ÿ�����룡����\n");
				tom = EvaluateEcpression();
				printf("���ʽ�ļ������� %d\n",tom);
				break;
			case 3: 
				polynomail();
				break;
			case 0: printf("\nллʹ�ã�\n");  
				break;
				
		}  
	}while(q==1);  
}  


