/* ********************************************************************************** */
/*                                                                                    */
/*                                                                :::      ::::::::   */
/*   main.c                                                     :+:      :+:    :+:   */
/*                                                            +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>                  +#+  +:+       +#+        */
/*                                                        +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 10:20:17 by sishizaw                  #+#    #+#             */
/*   Updated: 2024/08/08 08:10:08 by sishizaw                 ###   ########.fr       */
/*                                                                                    */
/* ********************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;

	a = input(argc, argv);
	if (!a || !checkup(a))
	{
		ft_free(&a);
		display_error();
	}
	if (!check_sorted(a))
		sort_stack(&a);
	ft_free(&a);
	return (0);
}
