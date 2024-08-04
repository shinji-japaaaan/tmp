/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 08:26:26 by root              #+#    #+#             */
/*   Updated: 2024/08/04 11:00:01 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int getcost_ba(t_stack *a, t_stack *b, int nbr, int *operation)
{
    int costs[4];

    costs[0] = case_rarb_ba(a, b, nbr);
    costs[1] = case_rrarrb_ba(a, b, nbr);
    costs[2] = case_rarrb_ba(a, b, nbr);
    costs[3] = case_rrarb_ba(a, b, nbr);

    int min_cost = costs[0];
    *operation = 0;

  int i = 1; // ループ変数の初期化
    while (i < 4)
    {
        if (costs[i] < min_cost)
        {
            min_cost = costs[i];
            *operation = i;
        }
        i++; // ループ変数の更新
    }
    return min_cost;
}

t_rotate_info get_rotateinfo_ba(t_stack *a, t_stack *b)
{
    t_rotate_info result;
    t_stack *tmp;
    int operation;

    tmp = b;
    result.cost = getcost_ba(a, b, b->nbr, &result.operation);
    result.nbr = b->nbr;

    while (tmp)
    {
        int cost = getcost_ba(a, b, tmp->nbr, &operation);
        if (result.cost > cost)
        {
            result.cost = cost;
            result.nbr = tmp->nbr;
            result.operation = operation;
        }
        tmp = tmp->next;
    }
    return result;
}

int getcost_ab(t_stack *a, t_stack *b, int nbr, int *operation)
{
    int costs[4];

    costs[0] = case_rarb(a, b, nbr);
    costs[1] = case_rrarrb(a, b, nbr);
    costs[2] = case_rarrb(a, b, nbr);
    costs[3] = case_rrarb(a, b, nbr);

    int min_cost = costs[0];
    *operation = 0;

    for (int i = 1; i < 4; i++)
    {
        if (costs[i] < min_cost)
        {
            min_cost = costs[i];
            *operation = i;
        }
    }
    return min_cost;
}


t_rotate_info get_rotateinfo_ab(t_stack *a, t_stack *b)
{
    t_rotate_info result;
    t_stack *tmp;
    int operation;

    tmp = a;
    result.cost = getcost_ab(a, b, a->nbr, &result.operation);
    result.nbr = a->nbr;

    while (tmp)
    {
        int cost = getcost_ab(a, b, tmp->nbr, &operation);
        if (result.cost > cost)
        {
            result.cost = cost;
            result.nbr = tmp->nbr;
            result.operation = operation;
        }
        tmp = tmp->next;
    }
    return result;
}

