//
// Created by tom-zlw on 2021/4/25.
//
#include "conversion.h"




//二进制到十进制
void BtoD()
{
    CharElem c;
    CharStack s;
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

    len = StackLen(&s);
    printf("栈的当前容量是: %d\n", len);

    for( i=0; i < len-1; i++ )
    {
        Pop(&s, &c);
        sum = sum + (c-48) * pow(2, i);
    }

    printf("转化为十进制数是: %d\n", sum);
}


//十进制到二进制
void DtoB()
{
    int  c,d;
    NumStack s;
    int len, i;

    initStack(&s);

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

    len = stackLen(&s);
    for(i = 0; i < len; i++)
    {
        pop(&s,&d);
        printf("%d",d);
    }
    printf("\n栈的当前容量是: %d\n", len);

}


//八进制到十六进制
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
//十六进制到八进制
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


