#ifndef SRC_CALCULATOR_H_
#define SRC_CALCULATOR_H_

struct t_data {
  int type;
  double num;
};

struct t_node {
  struct t_data data;
  struct t_node *next;
};

typedef struct t_stack {
  struct t_node *head;
} stack;

stack *s_init();
void s_push(stack *s, struct t_data);
struct t_data s_pop(stack *s);
// struct t_data s_peek(stack *s);
void s_destroy(stack *s);
stack *s_copy(stack *s);

double start(char *argv);
stack *parse(char *exp);
void replaceUnary(char *exp);
int pushNum(stack *dst, char *num_s);
void closeBracket(stack *res, stack *op);
void processOp(stack *res, stack *op, int id);
void pushOp(stack *dst, int id);
void pushX(stack *dst);
void toString(stack *exp, char *dst);
double calcExp(stack *exp, double x);
double calc(double a, double b, int id);

#endif
