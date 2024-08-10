/* ********************************************************************************** */
/*                                                                                    */
/*                                                                :::      ::::::::   */
/*   utils_libft1.c                                             :+:      :+:    :+:   */
/*                                                            +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>                  +#+  +:+       +#+        */
/*                                                        +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 10:20:17 by sishizaw                  #+#    #+#             */
/*   Updated: 2024/08/08 08:10:08 by sishizaw                 ###   ########.fr       */
/*                                                                                    */
/* ********************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	ft_lstsize(t_stack *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
