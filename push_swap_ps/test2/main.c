#include "push_swap.h"

int main(int argc, char **argv) {
    if (argc < 2) {
        return 0;
    }
    if (!validate_input(argc, argv)) {
        display_error();
        return 1;
    }

    t_stack *a = init_stack();
    t_stack *b = init_stack();
    if (!a || !b) {
        display_error();
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        push(a, atoi(argv[i]));
    }

    print_stack(a, "a");
    print_stack(b, "b");
    sort_stack(a, b);
    print_stack(a, "a");
    print_stack(b, "b");
    
    free_stack(a);
    free_stack(b);
    return 0;
}