#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "datatypes.h"
#include "rpn.h"

#define WINDOW_H 35
#define WINDOW_W 80

void plot(stack *exp);

int main() {
  int n = 25;
  printf("Enter example:");
  char *str = malloc(n * sizeof *str), tmp;
  for (int i = 0; (tmp = getchar()) != '\n'; ++i) {
    if (i == n) {
      char *tmp_p;
      n += 25;
      str = realloc(tmp_p = str, n * sizeof *str);
      if (str == NULL) free(tmp_p);
    }
    if (str != NULL) {
      str[i] = tmp;
    }
  }
  if (str != NULL) {
    stack *res = parse(str);
    plot(res);
    s_destroy(res);
  }
  free(str);
  return 0;
}

void plot(stack *exp) {
  stack *copy = s_copy(exp);
  double real_y = calcExp(copy, 0);
  printf("%.10lf\n", real_y);
}

/*void plot(stack *exp) {
    char plot[WINDOW_H][WINDOW_W];
    for (int i = 0; i < WINDOW_H; ++i)
        for (int j = 0; j < WINDOW_W; ++j)
            plot[i][j] = '.';

    for (int x = 0; x < WINDOW_W; ++x) {
        stack *copy = s_copy(exp);
        double real_x = (4 * M_PI / (WINDOW_W-1)) * x;
        double real_y = calcExp(copy, real_x);
        int y = round((real_y + 1) * (WINDOW_H/2));
        if (y >= 0 && y < WINDOW_H)
            plot[y][x] = '*';
        s_destroy(copy);
    }

    for (int i = 0; i < WINDOW_H; ++i) {
        for (int j = 0; j < WINDOW_W; ++j)
            putchar(plot[i][j]);
        if (i+1 != WINDOW_H)
            putchar('\n');
    }
}*/
