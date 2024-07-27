#include "stack.h"

void sort_stack(t_stack *a, t_stack *b)
{
    while (a->top > 0)
    {
        int max_index = 0;
        for (int i = 1; i <= a->top; i++)
        {
            if (a->data[i] > a->data[max_index])
                max_index = i;
        }
        while (a->top != max_index)
        {
            if (a->top > max_index)
            {
                rotate(a);
                write(1, "ra\n", 3);
                max_index = (max_index + 1) % (a->top + 1);
            }
            else
            {
                reverse_rotate(a);
                write(1, "rra\n", 4);
                max_index = (max_index - 1 + (a->top + 1)) % (a->top + 1);
            }
        }
        push(b, pop(a));
        write(1, "pb\n", 3);
    }
    while (b->top >= 0)
    {
        push(a, pop(b));
        write(1, "pa\n", 3);
    }
}