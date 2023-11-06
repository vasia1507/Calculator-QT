#include "calculator.h"
#include <stdio.h>

int main(int argc, char **argv) {
  double result = start(argv[1]);
  printf("Result = %.10lf\n", result);
  return 0;
}