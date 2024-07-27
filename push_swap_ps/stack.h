#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_stack
{
    int *data;
    int top;
    int size;
} t_stack;

t_stack *init_stack(int size);
void push(t_stack *stack, int value);
int pop(t_stack *stack);
void swap(t_stack *stack);
void rotate(t_stack *stack);
void reverse_rotate(t_stack *stack);
void free_stack(t_stack *stack);
int parse_input(int argc, char **argv, t_stack *a);
void sort_stack(t_stack *a, t_stack *b);
void print_stack(t_stack *stack);

#endif