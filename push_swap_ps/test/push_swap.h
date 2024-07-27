#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <unistd.h>

// ノードの構造体
typedef struct s_node {
    int value;
    struct s_node *next;
} t_node;

// スタックの構造体
typedef struct s_stack {
    t_node *top;
} t_stack;

// スタックが空かどうかを確認
int is_empty(t_stack *stack);

t_node *new_node(int value);

// スタックの初期化
t_stack *init_stack();

// スタックを解放する関数のプロトタイプ
void free_stack(t_stack *stack);

// スタックにプッシュ
void push(t_stack *stack, int value);

// スタックからポップ
int pop(t_stack *stack);

void sort_stack(t_stack *a, t_stack *b);

int validate_input(int argc, char **argv);

void display_error();


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

void print_stack(t_stack *stack, const char *stack_name);

#endif
