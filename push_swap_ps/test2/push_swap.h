#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

// ノードの構造体
typedef struct s_node {
    int value;
    struct s_node *prev;
    struct s_node *next;
} t_node;

// スタックの構造体
typedef struct s_stack {
    t_node *top;
    t_node *bottom;
    int size;
} t_stack;

// スタックの初期化
t_stack *init_stack();

// スタックが空かどうかを確認
int is_empty(t_stack *stack);

// 新しいノードを作成
t_node *new_node(int value);

// スタックにプッシュ
void push(t_stack *stack, int value);

// スタックからポップ
int pop(t_stack *stack);

// 操作関数のプロトタイプ
void sa(t_stack *a);
void sb(t_stack *b);
void ss(t_stack *a, t_stack *b);
void pa(t_stack *a, t_stack *b);
void pb(t_stack *a, t_stack *b);
void ra(t_stack *a);
void rb(t_stack *b);
void rr(t_stack *a, t_stack *b);
void rra(t_stack *a);
void rrb(t_stack *b);
void rrr(t_stack *a, t_stack *b);

// スタックの内容を出力する関数のプロトタイプ
void print_stack(t_stack *stack, const char *stack_name);

// スタックを解放する関数のプロトタイプ
void free_stack(t_stack *stack);

// ソートアルゴリズムのプロトタイプ
void sort_stack(t_stack *a, t_stack *b);

// 要素数3個以下のソート関数
void sort_three_or_less(t_stack *a);

// 要素数6個以下のソート関数
void sort_six_or_less(t_stack *a, t_stack *b);

// 要素数7個以上のソート関数
void sort_seven_or_more(t_stack *a, t_stack *b);

// 入力のバリデーション関数のプロトタイプ
int validate_input(int argc, char **argv);

// エラーメッセージを表示する関数
void display_error();

#endif
