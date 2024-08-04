// main.c
#include "stack.h"

int main(int argc, char **argv)
{
    if (argc < 2)
        return 0;

    t_stack *a = init_stack(argc - 1);
    t_stack *b = init_stack(argc - 1);

    if (!parse_input(argc, argv, a))
    {
        write(2, "Error\n", 6);
        free_stack(a);
        free_stack(b);
        return 1;
    }
    printf("Input:\n");
    print_stack(a);
    sort_stack(a, b);
    printf("Output:\n");
    print_stack(a);
    free_stack(a);
    free_stack(b);
    return 0;
}