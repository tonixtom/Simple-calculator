#include <stdio.h>
#include "calculate.h"
#include "polynomial.h"
#include "conversion.h"

int main()
{
    int i,j,q=0;
    int result;
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
                        break;
                    default:
                        return 0;
                }
                break;
            case 2: printf("\n请输入你想要计算的表达式（在以空格隔开每个输入！）：\n");
                result = EvaluateEcpression();
                printf("表达式的计算结界是 %d\n",result);
                break;
            case 3:
                polynomail();
                break;
            case 0: printf("\n谢谢使用！\n");
                break;
            default:
                return 0;
        }
    }while( 1 == q );
    return 0;
}