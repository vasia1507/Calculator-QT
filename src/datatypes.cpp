#include "datatypes.h"
#include <stdlib.h>
#include <stdio.h>

stack* s_init() {
    node *new_n = (node*)malloc(sizeof *new_n);
    new_n->data.type = -1;
    new_n->next = NULL;

    stack *s = (stack*)malloc(sizeof *s);
    s->head = new_n;
    return s;
}

void s_push(stack *s, data v) {
    node *new_n = (node*)malloc(sizeof *new_n);
    new_n->data = v;
    new_n->next = s->head->next;
    s->head->next = new_n;
}

data s_pop(stack *s) {
    data v;
    v.type = -1;
    v.num = 0;
    if (s->head->next != NULL) {
        v = s->head->next->data;
        node *tmp = s->head->next->next;
        free(s->head->next);
        s->head->next = tmp;
    }
    return v;
}

void s_destroy(stack *s) {
    while (s->head->next != NULL)
        s_pop(s);
    free(s->head);
    free(s);
}

stack *s_copy(stack *s) {
    stack *new_s = s_init();
    node *new_ptr = new_s->head;
    if (s->head != NULL) {
        for (node *ptr = s->head->next; ptr != NULL; ptr = ptr->next) {
            node *new_n = (node*)malloc(sizeof *new_n);
            new_ptr->next = new_n;
            new_n->data = ptr->data;
            new_n->next = NULL;
            new_ptr = new_n;
        }
    }
    return new_s;
}

