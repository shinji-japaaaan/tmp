#include "push_swap.h"

int main(int argc, char **argv) {
    if (argc < 2)
        return 0;

    if (!validate_input(argc, argv)) {
        display_error();
        return 1;
    }

    t_stack *a = init_stack();
    t_stack *b = init_stack();

    for (int i = 1; i < argc; i++) {
        long value = atoi(argv[i]);
        if (value > INT_MAX || value < INT_MIN) {
            display_error();
            free_stack(a);
            free_stack(b);
            return 1;
        }
        push(a, (int)value);
    }

    // スタックの内容を出力
    print_stack(a, "a");
    print_stack(b, "b");

    // スタックをソート
    sort_stack(a, b);

   // スタックの内容を出力
    print_stack(a, "a");
    print_stack(b, "b");

    free_stack(a);
    free_stack(b);
    return 0;
}
