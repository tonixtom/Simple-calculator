//
// Created by tom-zlw on 2021/4/24.
//
#include "calculate.h"

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

int EvaluateEcpression()
{
    CharStack OPTR;
    NumStack OPND;
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
