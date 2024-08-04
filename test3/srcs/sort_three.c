/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:10:59 by yogun             #+#    #+#             */
/*   Updated: 2024/08/04 08:05:23 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// This function sort the stack if there are only 
// three elements in the stack.
void	sort_stack_three(t_stack **stack_a)
{
	if (find_min(*stack_a) == (*stack_a)->nbr)
	{
		rra(stack_a, 0);
		sa(stack_a, 0);
	}
	else if (find_max(*stack_a) == (*stack_a)->nbr)
	{
		ra(stack_a, 0);
		if (!check_sorted(*stack_a))
			sa(stack_a, 0);
	}
	else
	{
		if (find_index(*stack_a, find_max(*stack_a)) == 1)
			rra(stack_a, 0);
		else
			sa(stack_a, 0);
	}
}
