//
// Created by tom-zlw on 2021/4/25.
//
#include "conversion.h"




//�����Ƶ�ʮ����
void BtoD()
{
    CharElem c;
    CharStack s;
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

    len = StackLen(&s);
    printf("ջ�ĵ�ǰ������: %d\n", len);

    for( i=0; i < len-1; i++ )
    {
        Pop(&s, &c);
        sum = sum + (c-48) * pow(2, i);
    }

    printf("ת��Ϊʮ��������: %d\n", sum);
}


//ʮ���Ƶ�������
void DtoB()
{
    int  c,d;
    NumStack s;
    int len, i;

    initStack(&s);

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

    len = stackLen(&s);
    for(i = 0; i < len; i++)
    {
        pop(&s,&d);
        printf("%d",d);
    }
    printf("\nջ�ĵ�ǰ������: %d\n", len);

}


//�˽��Ƶ�ʮ������
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
//ʮ�����Ƶ��˽���
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


