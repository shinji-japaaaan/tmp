/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_utils_ab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 10:09:25 by root              #+#    #+#             */
/*   Updated: 2024/08/04 11:00:01 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	case_rarb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = find_place_b(b, c);
	if (i < find_index(a, c))
		i = find_index(a, c);
	return (i);
}

int	case_rrarrb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (find_place_b(b, c))
		i = ft_lstsize(b) - find_place_b(b, c);
	if ((i < (ft_lstsize(a) - find_index(a, c))) && find_index(a, c))
		i = ft_lstsize(a) - find_index(a, c);
	return (i);
}

int	case_rrarb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (find_index(a, c))
		i = ft_lstsize(a) - find_index(a, c);
	i = find_place_b(b, c) + i;
	return (i);
}

int	case_rarrb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (find_place_b(b, c))
		i = ft_lstsize(b) - find_place_b(b, c);
	i = find_index(a, c) + i;
	return (i);
}
