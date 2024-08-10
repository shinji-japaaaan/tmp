/* ********************************************************************************** */
/*                                                                                    */
/*                                                                :::      ::::::::   */
/*   utils_get_costinfo.c                                       :+:      :+:    :+:   */
/*                                                            +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>                  +#+  +:+       +#+        */
/*                                                        +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 10:20:17 by sishizaw                  #+#    #+#             */
/*   Updated: 2024/08/08 08:10:08 by sishizaw                 ###   ########.fr       */
/*                                                                                    */
/* ********************************************************************************** */

#include "../push_swap.h"

int get_costinfo2_ba(t_stack *a, t_stack *b, int nbr, int *operation)
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

t_cost_info get_costinfo_ba(t_stack *a, t_stack *b)
{
    t_cost_info result;
    t_stack *tmp;
    int operation;

    tmp = b;
    result.cost = get_costinfo2_ba(a, b, b->nbr, &result.operation);
    result.nbr = b->nbr;

    while (tmp)
    {
        int cost = get_costinfo2_ba(a, b, tmp->nbr, &operation);
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

int get_costinfo2_ab(t_stack *a, t_stack *b, int nbr, int *operation)
{
    int costs[4];
    int min_cost;
    int i;

    costs[0] = case_rarb(a, b, nbr);
    costs[1] = case_rrarrb(a, b, nbr);
    costs[2] = case_rarrb(a, b, nbr);
    costs[3] = case_rrarb(a, b, nbr);

    min_cost = costs[0];
    *operation = 0;

    i = 1;
    while (i < 4)
    {
        if (costs[i] < min_cost)
        {
            min_cost = costs[i];
            *operation = i;
        }
        i++;
    }
    return min_cost;
}

t_cost_info get_costinfo_ab(t_stack *a, t_stack *b)
{
    t_cost_info result;
    t_stack *tmp;
    int operation;

    tmp = a;
    result.cost = get_costinfo2_ab(a, b, a->nbr, &result.operation);
    result.nbr = a->nbr;

    while (tmp)
    {
        int cost = get_costinfo2_ab(a, b, tmp->nbr, &operation);
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

