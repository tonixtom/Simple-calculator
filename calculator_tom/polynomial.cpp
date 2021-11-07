//
// Created by tom-zlw on 2021/4/24.
//
#include "polynomial.h"


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
}

