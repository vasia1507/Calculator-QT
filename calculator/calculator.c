#include "calculator.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define WINDOW_H 35
#define WINDOW_W 80

void plot(stack *exp);

int main(int argc, char **argv) {
  int n = 25;
  char tmp;
  char *str = argv[1];
  if (str != NULL) {
    stack *res = parse(str);
    plot(res);
    s_destroy(res);
  }
  return 0;
}

void plot(stack *exp) {
  stack *copy = s_copy(exp);
  double real_y = calcExp(copy, 0);
  printf("%.10lf\n", real_y);
}