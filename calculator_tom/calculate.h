//
// Created by tom-zlw on 2021/4/24.
//

#ifndef C___LIST_CALCULATE_H
#define C___LIST_CALCULATE_H
#include <stdio.h>
#include <math.h>
#include "stack.h"


static char OP[]={'+','-','*','/','(',')','='};
int judge(char theta);
int precede(char theta1,char theta2);
int OPerate(int a,char theta,int b);
int In(char *c,char *OP);
int EvaluateEcpression();

// output headline
void phead(void);
void thead(void);

#endif //C___LIST_CALCULATE_H
