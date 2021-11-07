//
// Created by tom-zlw on 2021/4/24.
//

#ifndef C___LIST_POLYNOMIAL_H
#define C___LIST_POLYNOMIAL_H
#include <cstdio>
#include <cstdlib>


typedef struct node chainLink;//创建chainLink的node结点对象
struct node
{
    int coef;    //系数
    int exp;   //指数
    struct node * next;//指针域
};


struct node *order(struct node *h);    //定义排序函数，并返回整理后的链表的头指针
struct node *add(struct node *h1, struct node *h2);   //定义加法函数，并返回结果的链表的头指针
void polynomail();
void display(struct node  *h);
struct node *create();                    //定义建立多项式函数，并返回链表头指针

#endif //C___LIST_POLYNOMIAL_H
