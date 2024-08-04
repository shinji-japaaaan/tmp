/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 10:20:17 by root              #+#    #+#             */
/*   Updated: 2024/08/04 11:00:01 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;

	a = input(argc, argv);
	ft_print_stack(a, "Stack A");
	if (!a || checkup(a))
	{
		ft_free(&a);
		display_error();
	}
	if (!check_sorted(a))
		sort_stack(&a);
	ft_free(&a);
	return (0);
}
