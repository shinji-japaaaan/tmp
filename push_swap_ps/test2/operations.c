#include "push_swap.h"

// swap a
void sa(t_stack *a) {
    if (a->top && a->top->next) {
        int temp = a->top->value;
        a->top->value = a->top->next->value;
        a->top->next->value = temp;
        write(1, "sa\n", 3);
    }
}

// swap b
void sb(t_stack *b) {
    if (b->top && b->top->next) {
        int temp = b->top->value;
        b->top->value = b->top->next->value;
        b->top->next->value = temp;
        write(1, "sb\n", 3);
    }
}

// swap both
void ss(t_stack *a, t_stack *b) {
    sa(a);
    sb(b);
    write(1, "ss\n", 3);
}

// push a
void pa(t_stack *a, t_stack *b) {
    if (!is_empty(b)) {
        int value = pop(b);
        push(a, value);
        write(1, "pa\n", 3);
    }
}

// push b
void pb(t_stack *a, t_stack *b) {
    if (!is_empty(a)) {
        int value = pop(a);
        push(b, value);
        write(1, "pb\n", 3);
    }
}

// rotate a
void ra(t_stack *a) {
    if (a->top && a->top->next) {
        t_node *temp = a->top;
        a->top = a->top->next;
        a->top->prev = NULL;
        temp->next = NULL;
        a->bottom->next = temp;
        temp->prev = a->bottom;
        a->bottom = temp;
        write(1, "ra\n", 3);
    }
}

// rotate b
void rb(t_stack *b) {
    if (b->top && b->top->next) {
        t_node *temp = b->top;
        b->top = b->top->next;
        b->top->prev = NULL;
        temp->next = NULL;
        b->bottom->next = temp;
        temp->prev = b->bottom;
        b->bottom = temp;
        write(1, "rb\n", 3);
    }
}

// rotate both
void rr(t_stack *a, t_stack *b) {
    ra(a);
    rb(b);
    write(1, "rr\n", 3);
}

// reverse rotate a
void rra(t_stack *a) {
    if (a->top && a->top->next) {
        t_node *temp = a->bottom;
        a->bottom = a->bottom->prev;
        a->bottom->next = NULL;
        temp->prev = NULL;
        temp->next = a->top;
        a->top->prev = temp;
        a->top = temp;
        write(1, "rra\n", 4);
    }
}

// reverse rotate b
void rrb(t_stack *b) {
    if (b->top && b->top->next) {
        t_node *temp = b->bottom;
        b->bottom = b->bottom->prev;
        b->bottom->next = NULL;
        temp->prev = NULL;
        temp->next = b->top;
        b->top->prev = temp;
        b->top = temp;
        write(1, "rrb\n", 4);
    }
}

// reverse rotate both
void rrr(t_stack *a, t_stack *b) {
    rra(a);
    rrb(b);
    write(1, "rrr\n", 4);
}
