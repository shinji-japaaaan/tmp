/* ********************************************************************************** */
/*                                                                                    */
/*                                                                :::      ::::::::   */
/*   operations_3.c                                             :+:      :+:    :+:   */
/*                                                            +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>                  +#+  +:+       +#+        */
/*                                                        +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 10:20:17 by sishizaw                  #+#    #+#             */
/*   Updated: 2024/08/08 08:10:08 by sishizaw                 ###   ########.fr       */
/*                                                                                    */
/* ********************************************************************************** */

#include "../push_swap.h"

void	rb(t_stack **b)
{
	t_stack	*tmp;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	*b = ft_lstlast(*b);
	(*b)->next = tmp;
	*b = tmp->next;
	tmp->next = NULL;
	write(1, "rb\n", 3);
}

void	ft_sb(t_stack **b)
{
	t_stack	*tmp;

	if (!*b || !((*b)->next))
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	write(1, "sb\n", 3);
}
