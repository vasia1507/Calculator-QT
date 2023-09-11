#include "rpn.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "datatypes.h"

/*

0: (
1: - (unary)
2: *
3: /
4: -
5: +
6: ^
7: mod
8: sin
9: cos
10: tan
11: asin
12: acos
13: atan
14: sqrt
15: ln
16: log

*/

stack *parse(char *exp) {
  const char chrOps[] = "~*/-+^";
  replaceUnary(exp);
  stack *res = s_init();
  stack *op = s_init();
  int i = 0;
  while (exp[i] != '\0') {
    if ((exp[i] >= '0' && exp[i] <= '9') || exp[i] == '.') {
      i += pushNum(res, &exp[i]);
    } else if (exp[i] == '(') {
      pushOp(op, 0);
      ++i;
    } else if (exp[i] == ')') {
      closeBracket(res, op);
      ++i;
    } else if (strchr(chrOps, exp[i]) != NULL) {
      processOp(res, op, strchr(chrOps, exp[i]) - chrOps + 1);
      ++i;
    } else if (exp[i] == 'x') {
      pushX(res);
      ++i;
    } else if (strncmp(&exp[i], "mod", 3) == 0) {
      pushOp(op, 7);
      i += 3;
    } else if (strncmp(&exp[i], "sin", 3) == 0) {
      pushOp(op, 8);
      i += 3;
    } else if (strncmp(&exp[i], "cos", 3) == 0) {
      pushOp(op, 9);
      i += 3;
    } else if (strncmp(&exp[i], "tan", 3) == 0) {
      pushOp(op, 10);
      i += 3;
    } else if (strncmp(&exp[i], "asin", 4) == 0) {
      pushOp(op, 11);
      i += 4;
    } else if (strncmp(&exp[i], "acos", 4) == 0) {
      pushOp(op, 12);
      i += 4;
    } else if (strncmp(&exp[i], "atan", 4) == 0) {
      pushOp(op, 13);
      i += 4;
    } else if (strncmp(&exp[i], "sqrt", 4) == 0) {
      pushOp(op, 14);
      i += 4;
    } else if (strncmp(&exp[i], "ln", 2) == 0) {
      pushOp(op, 15);
      i += 2;
    } else if (strncmp(&exp[i], "log", 3) == 0) {
      pushOp(op, 16);
      i += 3;
    } else if (exp[i] == ' ') {
      i += 1;
    } else {
      i += 1;
    }
  }

  struct t_data tmp = s_pop(op);
  while (tmp.type != -1) {
    s_push(res, tmp);
    tmp = s_pop(op);
  }
  s_destroy(op);
  return res;
}

void replaceUnary(char *exp) {
  if (exp[0] == '-') exp[0] = '~';
  for (int i = 1; exp[i] != '\0'; ++i) {
    if (exp[i] == '-' && (exp[i - 1] < '0' || exp[i - 1] > '9') &&
        exp[i - 1] != ')') {
      exp[i] = '~';
    }
  }
}

int pushNum(stack *dst, char *num_s) {
  char *tmp;
  struct t_data new;
  new.type = 0;
  new.num = strtod(num_s, &tmp);
  s_push(dst, new);
  return tmp - num_s;
}

void closeBracket(stack *res, stack *op) {
  struct t_data dat = s_pop(op);
  while (dat.num != 0) {
    s_push(res, dat);
    dat = s_pop(op);
  }
  dat = s_pop(op);
  if (dat.num >= 6 && dat.num <= 11)
    s_push(res, dat);
  else
    s_push(op, dat);
}

void processOp(stack *res, stack *op, int id) {
  struct t_data dat = s_pop(op);
  while ((dat.type == 1 && dat.num != 0) && (dat.num < id)) {
    s_push(res, dat);
    dat = s_pop(op);
  }
  if (dat.type != -1) {
    s_push(op, dat);
  }
  pushOp(op, id);
}

void pushOp(stack *dst, int id) {
  struct t_data new;
  new.type = 1;
  new.num = id;
  s_push(dst, new);
}

void pushX(stack *dst) {
  struct t_data new;
  new.type = 2;
  new.num = 0;
  s_push(dst, new);
}

double calcExp(stack *exp, double x) {
  struct t_data dat = s_pop(exp);
  double res = dat.num;
  if (dat.type == 1) {
    double a = 0, b = 0;
    b = calcExp(exp, x);
    if (dat.num != 1 && dat.num < 7) {
      a = calcExp(exp, x);
    }
    res = calc(a, b, dat.num);
  } else if (dat.type == 2) {
    res = x;
  }
  return res;
}

double calc(double a, double b, int id) {
  double res = 0;
  switch (id) {
    case 1:
      res = -b;
      break;
    case 2:
      res = a * b;
      break;
    case 3:
      res = a / b;
      break;
    case 4:
      res = a - b;
      break;
    case 5:
      res = a + b;
      break;
    case 6:
      res = pow(a, b);
      break;
    case 7:
      res = (int)a % (int)b;
      break;
    case 8:
      res = sin(b);
      break;
    case 9:
      res = cos(b);
      break;
    case 10:
      res = tan(b);
      break;
    case 11:
      res = asin(b);
      break;
    case 12:
      res = acos(b);
      break;
    case 13:
      res = atan(b);
      break;
    case 14:
      res = sqrt(b);
      break;
    case 15:
      res = log(b);
      break;
    case 16:
      res = log10(b);
      break;
  }
  return res;
}

/*

0: (
1: - (unary)
2: *
3: /
4: -
5: +
6: ^
7: mod
8: sin
9: cos
10: tan
11: asin
12: acos
13: atan
14: sqrt
15: ln
16: log

*/