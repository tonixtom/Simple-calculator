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
                        break;
                    default:
                        return 0;
                }
                break;
            case 2: printf("\n����������Ҫ����ı��ʽ�����Կո����ÿ�����룡����\n");
                result = EvaluateEcpression();
                printf("���ʽ�ļ������� %d\n",result);
                break;
            case 3:
                polynomail();
                break;
            case 0: printf("\nллʹ�ã�\n");
                break;
            default:
                return 0;
        }
    }while( 1 == q );
    return 0;
}