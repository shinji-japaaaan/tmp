// input.c
#include "stack.h"
#include <limits.h>
#include <ctype.h>

int is_integer(const char *str)
{
    if (*str == '-' || *str == '+')
        str++;
    if (!*str)
        return 0;
    while (*str)
    {
        if (!isdigit(*str))
            return 0;
        str++;
    }
    return 1;
}

int parse_input(int argc, char **argv, t_stack *a)
{
    for (int i = 1; i < argc; i++)
    {
        if (!is_integer(argv[i]))
            return 0;
        long num = atol(argv[i]);
        if (num < INT_MIN || num > INT_MAX)
            return 0;
        for (int j = 0; j < a->top + 1; j++)
        {
            if (a->data[j] == (int)num)
                return 0;
        }
        push(a, (int)num);
    }
    return 1;
}