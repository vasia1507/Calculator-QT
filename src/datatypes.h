#ifndef SRC_DATATYPES_H_
#define SRC_DATATYPES_H_

typedef struct t_data {
    int type;
    double num;
} data;

typedef struct t_node {
    struct t_data data;
    struct t_node *next;
} node;

typedef struct t_stack {
    struct t_node *head;
} stack;

stack* s_init();
void s_push(stack *s, struct t_data);
struct t_data s_pop(stack *s);
void s_destroy(stack *s);
stack *s_copy(stack *s);

#endif
