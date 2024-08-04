#include "push_swap.h"

void sort_stack(t_stack *a, t_stack *b) {
    int size = 0;
    t_node *current = a->top;
    
    // スタックのサイズを計算
    while (current) {
        size++;
        current = current->next;
    }

    // 簡単なソートアルゴリズム（例: バブルソート）を使用
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (a->top->value > a->top->next->value) {
                sa(a);
            }
            pb(a, b);
        }
        while (!is_empty(b)) {
            pa(a, b);
        }
    }
}