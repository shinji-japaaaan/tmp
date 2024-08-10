/* ********************************************************************************** */
/*                                                                                    */
/*                                                                :::      ::::::::   */
/*   utils_input.c                                              :+:      :+:    :+:   */
/*                                                            +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>                  +#+  +:+       +#+        */
/*                                                        +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 10:20:17 by sishizaw                  #+#    #+#             */
/*   Updated: 2024/08/08 08:10:08 by sishizaw                 ###   ########.fr       */
/*                                                                                    */
/* ********************************************************************************** */

#include "../push_swap.h"

void	all_free2(char **lst)
{
	char	**tmp;
	char	*n1;

	tmp = lst;
	if (!lst)
		return ;
	while (*lst)
	{
		n1 = *lst;
		lst++;
		free(n1);
	}
	free(tmp);
}

t_stack	*argc_2(char **argv)
{
	t_stack	*a;
	char	**tmp;
	int		i;
	int		j;

	a = NULL;
	i = 0;
	tmp = ft_split(argv[1], ' ');
	while (tmp[i])
	{
		j = ft_atoi2(tmp[i]);
		ft_add_back(&a, ft_stack_new(j));
		i++;
	}
	all_free2(tmp);
	return (a);
}

t_stack	*input(int argc, char **argv)
{
	t_stack	*a;
	int		i;
	int		j;

	i = 1;
	a = NULL;
	if (argc < 2)
		display_error();
	if (argc == 2)
		a = argc_2(argv);
	else
	{
		while (i < argc)
		{
			j = ft_atoi2(argv[i]);
			ft_add_back(&a, ft_stack_new(j));
			i++;
		}
	}
	return (a);
}
