/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 08:11:00 by root              #+#    #+#             */
/*   Updated: 2024/08/04 11:00:01 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_till_3(t_stack **stack_a, t_stack **stack_b)
{
	t_rotate_info rotate_info;

    while (ft_lstsize(*stack_a) > 3 && !check_sorted(*stack_a))
    {
        rotate_info = get_rotateinfo_ab(*stack_a, *stack_b); 

        if (rotate_info.operation == 0)
            apply_rarb(stack_a, stack_b, rotate_info.nbr, 'a');
        else if (rotate_info.operation == 1)
            apply_rrarrb(stack_a, stack_b, rotate_info.nbr, 'a');
        else if (rotate_info.operation == 2)
            apply_rarrb(stack_a, stack_b, rotate_info.nbr, 'a');
        else if (rotate_info.operation == 3)
            apply_rrarb(stack_a, stack_b, rotate_info.nbr, 'a');
    }
}

t_stack	*sort_stack_ab(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (ft_lstsize(*stack_a) > 3 && !check_sorted(*stack_a))
		pb(stack_a, &stack_b, 0);
	if (ft_lstsize(*stack_a) > 3 && !check_sorted(*stack_a))
		pb(stack_a, &stack_b, 0);
	if (ft_lstsize(*stack_a) > 3 && !check_sorted(*stack_a))
		sort_till_3(stack_a, &stack_b);
	if (!check_sorted(*stack_a))
		sort_stack_three(stack_a);
	return (stack_b);
}

t_stack **sort_stack_ba(t_stack **stack_a, t_stack **stack_b)
{
    t_rotate_info rotate_info;

    while (*stack_b)
    {
        rotate_info = get_rotateinfo_ba(*stack_a, *stack_b);

        if (rotate_info.operation == 0)
            apply_rarb(stack_a, stack_b, rotate_info.nbr, 'b');
        else if (rotate_info.operation == 1)
            apply_rrarrb(stack_a, stack_b, rotate_info.nbr, 'b');
        else if (rotate_info.operation == 2)
            apply_rarrb(stack_a, stack_b, rotate_info.nbr, 'b');
        else if (rotate_info.operation == 3)
            apply_rrarb(stack_a, stack_b, rotate_info.nbr, 'b');
    }
    return (stack_a);
}


void ft_print_stack(t_stack *stack, const char *stack_name)
{
    t_stack *current = stack;
    
    printf("%s:\n", stack_name);
    while (current)
    {
        printf("%ld ", current->nbr);
        current = current->next;
    }
    printf("\n");
}

void	sort_stack(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		i;

	stack_b = NULL;
	if (ft_lstsize(*stack_a) == 2)
		sa(stack_a, 0);
	else
	{
		stack_b = sort_stack_ab(stack_a);
		ft_print_stack(*stack_a, "Stack A");
        ft_print_stack(stack_b, "Stack B"); 
		stack_a = sort_stack_ba(stack_a, &stack_b);
		ft_print_stack(*stack_a, "Stack A");
        ft_print_stack(stack_b, "Stack B");
		i = find_index(*stack_a, find_min(*stack_a));
		if (i < ft_lstsize(*stack_a) - i)
		{
			while ((*stack_a)->nbr != find_min(*stack_a))
				ra(stack_a, 0);
		}
		else
		{
			while ((*stack_a)->nbr != find_min(*stack_a))
				rra(stack_a, 0);
		}			
	}	
}
