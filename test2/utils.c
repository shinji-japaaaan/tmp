#include "push_swap.h"

// スタックの初期化
t_stack *init_stack() {
    t_stack *stack = (t_stack *)malloc(sizeof(t_stack));
    if (!stack)
        return NULL;
    stack->top = NULL;
    stack->bottom = NULL;
    stack->size = 0;
    return stack;
}

// スタックが空かどうかを確認
int is_empty(t_stack *stack) {
    return stack->size == 0;
}

// 新しいノードを作成
t_node *new_node(int value) {
    t_node *node = (t_node *)malloc(sizeof(t_node));
    if (!node)
        return NULL;
    node->value = value;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

// スタックにプッシュ
void push(t_stack *stack, int value) {
    t_node *node = new_node(value);
    if (!node)
        return;
    if (is_empty(stack)) {
        stack->top = node;
        stack->bottom = node;
    } else {
        node->next = stack->top;
        stack->top->prev = node;
        stack->top = node;
    }
    stack->size++;
}

// スタックからポップ
int pop(t_stack *stack) {
    if (is_empty(stack))
        return 0;
    t_node *temp = stack->top;
    int value = temp->value;
    stack->top = temp->next;
    if (stack->top)
        stack->top->prev = NULL;
    else
        stack->bottom = NULL;
    free(temp);
    stack->size--;
    return value;
}

// スタックを解放する関数
void free_stack(t_stack *stack) {
    t_node *current = stack->top;
    t_node *next;
    while (current) {
        next = current->next;
        free(current);
        current = next;
    }
    free(stack);
}

// スタックの内容を出力する関数
void print_stack(t_stack *stack, const char *stack_name) {
    printf("Stack %s: ", stack_name);
    t_node *current = stack->top;
    while (current) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int validate_input(int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        for (int j = 0; argv[i][j]; j++) {
            if (!((argv[i][j] >= '0' && argv[i][j] <= '9') || argv[i][j] == '-' || argv[i][j] == '+')) {
                return 0;
            }
        }
        long value = atol(argv[i]);
        if (value > INT_MAX || value < INT_MIN) {
            return 0;
        }
    }
    return 1;
}

// エラーメッセージを表示する関数
void display_error() {
    write(2, "Error\n", 6);
}