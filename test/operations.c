#include "push_swap.h"


// sa: スタックaの最初の2つの要素を交換する
void sa(t_stack *a) {
    if (a->top && a->top->next) {
        t_node *first = a->top;
        t_node *second = a->top->next;
        first->next = second->next;
        second->next = first;
        a->top = second;
    }
}

// sb: スタックbの最初の2つの要素を交換する
void sb(t_stack *b) {
    sa(b); // saと同じロジックを使う
}

// ss: saとsbを同時に行う
void ss(t_stack *a, t_stack *b) {
    sa(a);
    sb(b);
}

// pa: スタックbの最初の要素をスタックaのトップに移動する
void pa(t_stack *a, t_stack *b) {
    if (!is_empty(b)) {
        int value = pop(b);
        push(a, value);
    }
}

// pb: スタックaの最初の要素をスタックbのトップに移動する
void pb(t_stack *a, t_stack *b) {
    if (!is_empty(a)) {
        int value = pop(a);
        push(b, value);
    }
}

// ra: スタックaの要素を1つ上にシフトする
void ra(t_stack *a) {
    if (a->top && a->top->next) {
        t_node *first = a->top;
        a->top = first->next;
        t_node *current = a->top;
        while (current->next) {
            current = current->next;
        }
        current->next = first;
        first->next = NULL;
    }
}

// rb: スタックbの要素を1つ上にシフトする
void rb(t_stack *b) {
    ra(b); // raと同じロジックを使う
}

// rr: raとrbを同時に行う
void rr(t_stack *a, t_stack *b) {
    ra(a);
    rb(b);
}

// rra: スタックaの要素を1つ下にシフトする
void rra(t_stack *a) {
    if (a->top && a->top->next) {
        t_node *prev = NULL;
        t_node *current = a->top;
        while (current->next) {
            prev = current;
            current = current->next;
        }
        current->next = a->top;
        a->top = current;
        prev->next = NULL;
    }
}

// rrb: スタックbの要素を1つ下にシフトする
void rrb(t_stack *b) {
    rra(b); // rraと同じロジックを使う
}

// rrr: rraとrrbを同時に行う
void rrr(t_stack *a, t_stack *b) {
    rra(a);
    rrb(b);
}
