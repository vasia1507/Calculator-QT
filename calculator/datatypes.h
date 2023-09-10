#ifndef SRC_DATATYPES_H_
#define SRC_DATATYPES_H_

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

#endif  // SRC_DATATYPES_H_
