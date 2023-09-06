#ifndef SRC_RPN_H_
#define SRC_RPN_H_

#include "datatypes.h"

stack* parse(char *exp);
void replaceUnary(char *exp);
int pushNum(stack *dst, char *num_s);
void closeBracket(stack *res, stack *op);
void processOp(stack *res, stack *op, int id);
void pushOp(stack *dst, int id);
void pushX(stack *dst);
void toString(stack *exp, char *dst);
double calcExp(stack *exp, double x);
double calc(double a, double b, int id);

#endif  // SRC_RPN_H_
