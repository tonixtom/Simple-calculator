//
// Created by tom-zlw on 2021/5/8.
//

#ifndef C___LIST_STACK_H
#define C___LIST_STACK_H
#include <stdlib.h>


#define STACK_INIT_SIZE 20
#define STACKINCREMENT  10



typedef void SqStack;
typedef char CharElem;
typedef int NumElem;


typedef struct
{
    CharElem *base;
    CharElem *top;
    int StackSize;
}CharStack;


typedef struct
{
    NumElem *base;
    NumElem *top;
    int StackSize;
}NumStack;

void InitStack(SqStack *s);
void Push(SqStack *s, CharElem e);
void Pop(SqStack *s, CharElem *e);
int StackLen(SqStack *s);
CharElem  GetTop(SqStack *s);


void initStack(SqStack *t);
void push(SqStack *s, NumElem e);
void pop(SqStack *s, NumElem *e);
int stackLen(SqStack *s);
NumElem  getTop(SqStack *s);
#endif //C___LIST_STACK_H
