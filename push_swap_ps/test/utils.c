#include "push_swap.h"

t_stack *init_stack() {
    t_stack *stack = (t_stack *)malloc(sizeof(t_stack));
    stack->top = NULL;
    return stack;
}

// スタックが空かどうかを確認する関数
int is_empty(t_stack *stack) {
    return (stack->top == NULL);
}

t_node *new_node(int value) {
    t_node *node = (t_node *)malloc(sizeof(t_node));
    node->value = value;
    node->next = NULL;
    return node;
}

// スタックにプッシュする関数
void push(t_stack *stack, int value) {
    t_node *node = new_node(value);
    node->next = stack->top;
    stack->top = node;
}

// スタックからポップする関数
int pop(t_stack *stack) {
    if (is_empty(stack)) {
        return -1; // エラー値、スタックが空の場合
    }
    t_node *temp = stack->top;
    int value = temp->value;
    stack->top = stack->top->next;
    free(temp);
    return value;
}

void print_stack(t_stack *stack, const char *stack_name) {
    printf("Stack %s: ", stack_name);
    t_node *current = stack->top;
    while (current) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
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

int validate_input(int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        for (int j = 0; argv[i][j]; j++) {
            if ((argv[i][j] == '-' && j == 0 && argv[i][j + 1]) || (argv[i][j] >= '0' && argv[i][j] <= '9'))
                continue;
            return 0;
        }
    }
    return 1;
}

// エラーメッセージを表示する関数
void display_error() {
    write(2, "Error\n", 6);
}