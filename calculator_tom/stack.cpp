//
// Created by tom-zlw on 2021/5/8.
//
#include "stack.h"


//char stack

void InitStack(SqStack *t)
{
    CharStack *s = (CharStack *)t;

    s->base = (CharElem *)malloc(STACK_INIT_SIZE * sizeof(CharElem));
    if( !s->base )
    {
        exit(0);
    }

    s->top = s->base;
    s->StackSize = STACK_INIT_SIZE;
}

void Push(SqStack *t, char e)
{
    CharStack *s = (CharStack *)t;
    if( s->top - s->base >= s->StackSize )
    {
        s->base = (CharElem *)realloc(s->base, (s->StackSize + STACKINCREMENT) * sizeof(CharElem));
        if( !s->base )
        {
            exit(0);
        }
    }

    *(s->top) = e;
    s->top++;
}

void Pop(SqStack *t, CharElem *e)
{
    CharStack *s = (CharStack *)t;
    if( s->top == s->base )
    {
        return;
    }
    *e = *--(s->top);
}


int StackLen(SqStack *t)
{
    CharStack *s = (CharStack *)t;
    return (s->top - s->base);
}



char  GetTop(SqStack *t)
{
    CharStack *s = (CharStack *)t;
    char e;
    if(s->top == s->base)
        return -1;
    e = *(s->top-1);
    return e;
}

//int stack


void initStack(SqStack *t)
{
    NumStack *s = (NumStack *)t;
    s->base = (int *)malloc(STACK_INIT_SIZE * sizeof(int));
    if( !s->base )
    {
        exit(0);
    }

    s->top = s->base;
    s->StackSize = STACK_INIT_SIZE;
}

void push(SqStack *t, int e)
{
    NumStack *s = (NumStack *)t;
    if( s->top - s->base >= s->StackSize )
    {
        s->base = (int *)realloc(s->base, (s->StackSize + STACKINCREMENT) * sizeof(int));
        if( !s->base )
        {
            exit(0);
        }
    }

    *(s->top) = e;
    s->top++;
}

void pop(SqStack *t, int *e)
{
    NumStack *s = (NumStack *)t;
    if( s->top == s->base )
    {
        return;
    }
    *e = *--(s->top);
}



int stackLen(SqStack *t)
{
    NumStack *s = (NumStack *)t;
    return (s->top - s->base);
}


int  getTop(SqStack *t)
{
    NumStack *s = (NumStack *)t;
    int e;
    if(s->top == s->base)
        return -1;
    e = *(s->top-1);
    return e;
}
