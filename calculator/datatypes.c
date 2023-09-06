#include "datatypes.h"
#include <stdlib.h>
#include <stdio.h>

stack* s_init() {
    struct t_node *new_n = malloc(sizeof *new_n);
    new_n->data.type = -1;
    new_n->next = NULL;

    stack *s = malloc(sizeof *s);
    s->head = new_n;
    return s;
}

void s_push(stack *s, struct t_data v) {
    struct t_node *new_n = malloc(sizeof *new_n);
    new_n->data = v;
    new_n->next = s->head->next;
    s->head->next = new_n;
}

struct t_data s_pop(stack *s) {
    struct t_data v;
    v.type = -1;
    v.num = 0;
    if (s->head->next != NULL) {
        v = s->head->next->data;
        struct t_node *tmp = s->head->next->next;
        free(s->head->next);
        s->head->next = tmp;
    }
    return v;
}

/*  struct t_data s_peek(stack *s) {
    struct t_data v;
    v.type = -1;
    v.num = 0;
    if (s->head->next != NULL)
        v = s->head->next->data;
    return v;
}*/

void s_destroy(stack *s) {
    while (s->head->next != NULL)
        s_pop(s);
    free(s->head);
    free(s);
}

stack *s_copy(stack *s) {
    stack *new = s_init();
    struct t_node *new_ptr = new->head;
    if (s->head != NULL) {
        for (struct t_node *ptr = s->head->next; ptr != NULL; ptr = ptr->next) {
            struct t_node *new_n = malloc(sizeof *new_n);
            new_ptr->next = new_n;
            new_n->data = ptr->data;
            new_n->next = NULL;
            new_ptr = new_n;
        }
    }
    return new;
}

