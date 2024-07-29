#include "push_swap.h"

// 3個以下の要素をソート
void sort_three_or_less(t_stack *a) {
    if (a->size == 2 && a->top->value > a->top->next->value) {
        sa(a);
    } else if (a->size == 3) {
        int top = a->top->value;
        int middle = a->top->next->value;
        int bottom = a->top->next->next->value;
        if (top > middle && middle < bottom && top < bottom) {
            sa(a);
        } else if (top > middle && middle > bottom && top > bottom) {
            sa(a);
            rra(a);
        } else if (top > middle && middle < bottom && top > bottom) {
            ra(a);
        } else if (top < middle && middle > bottom && top < bottom) {
            sa(a);
            ra(a);
        } else if (top < middle && middle > bottom && top > bottom) {
            rra(a);
        }
    }
}

// 6個以下の要素をソート
void sort_six_or_less(t_stack *a, t_stack *b) {
    // aが3個になるまで小さい数からbにpush
    while (a->size > 3) {
        int min_index = 0;
        t_node *current = a->top;
        t_node *min_node = a->top;
        for (int i = 0; i < a->size; i++) {
            if (current->value < min_node->value) {
                min_node = current;
                min_index = i;
            }
            current = current->next;
        }
        if (min_index <= a->size / 2) {
            for (int i = 0; i < min_index; i++) {
                ra(a);
            }
        } else {
            for (int i = 0; i < a->size - min_index; i++) {
                rra(a);
            }
        }
        pb(a, b);
    }
    // 残った3個の要素をソート
    sort_three_or_less(a);    

    // bからaに要素をpushし直す
    while (b->size > 0) {
        pa(a, b);
    }
}


// クイックソートを応用して7個以上の要素をソート
void sort_seven_or_more(t_stack *a, t_stack *b) {
    // クイックソートのアルゴリズムを適用
    (void)b;
    (void)a;
}

// メインのソート関数
void sort_stack(t_stack *a, t_stack *b) {
    if (a->size <= 3) {
        sort_three_or_less(a);
    } else if (a->size <= 6) {
        sort_six_or_less(a, b);
    } else {
        sort_seven_or_more(a, b);
    }
}
