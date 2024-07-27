#include "stack.h"

t_stack *init_stack(int size)
{
    t_stack *stack = (t_stack *)malloc(sizeof(t_stack));
    stack->data = (int *)malloc(sizeof(int) * size);
    stack->top = -1;
    stack->size = size;
    return stack;
}

void push(t_stack *stack, int value)
{
    if (stack->top < stack->size - 1)
        stack->data[++stack->top] = value;
}

int pop(t_stack *stack)
{
    if (stack->top >= 0)
        return stack->data[stack->top--];
    return -1; // Error value
}

void swap(t_stack *stack)
{
    if (stack->top > 0)
    {
        int temp = stack->data[stack->top];
        stack->data[stack->top] = stack->data[stack->top - 1];
        stack->data[stack->top - 1] = temp;
    }
}

void rotate(t_stack *stack)
{
    if (stack->top > 0)
    {
        int temp = stack->data[stack->top];
        for (int i = stack->top; i > 0; i--)
            stack->data[i] = stack->data[i - 1];
        stack->data[0] = temp;
    }
}

void reverse_rotate(t_stack *stack)
{
    if (stack->top > 0)
    {
        int temp = stack->data[0];
        for (int i = 0; i < stack->top; i++)
            stack->data[i] = stack->data[i + 1];
        stack->data[stack->top] = temp;
    }
}

void free_stack(t_stack *stack)
{
    free(stack->data);
    free(stack);
}

void print_stack(t_stack *stack)
{
    for (int i = 0; i <= stack->top; i++)
    {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}