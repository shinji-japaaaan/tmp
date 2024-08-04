/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 10:58:28 by root              #+#    #+#             */
/*   Updated: 2024/08/04 11:02:09 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	long			nbr;
	long			index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_rotate_info {
    int cost;
    int nbr;
    int operation;
} t_rotate_info;

void ft_print_stack(t_stack *stack, const char *stack_name);

void		ft_add_back(t_stack **stack, t_stack *stack_new);
t_stack		*ft_stack_new(int content);
int			checkup(t_stack *a);
void 		display_error(void);
void		ft_free(t_stack **lst);
t_stack		*ft_lstlast(t_stack *lst);
void		ra(t_stack **a, int j);
void		rb(t_stack **b, int j);
void		sa(t_stack **a, int j);
void		pa(t_stack **a, t_stack **b, int j);
void		pb(t_stack **stack_a, t_stack **stack_b, int j);
void		rra(t_stack **a, int j);
void		ss(t_stack **a, t_stack **b, int j);
void		rr(t_stack **a, t_stack **b, int j);
void		rrr_sub(t_stack **b, int j);
void		rrr(t_stack **a, t_stack **b, int j);
t_stack		*ft_lstlast(t_stack *lst);
int			ft_lstsize(t_stack *lst);
int			find_min(t_stack *a);
int			find_max(t_stack *a);
int			find_index(t_stack *a, int nbr);
int			find_place_b(t_stack *stack_b, int nbr_push);
int			find_place_a(t_stack *a, int nbr);
void		sort_stack(t_stack **stack_a);
int			check_sorted(t_stack *stack_a);
void		sort_stack_abig(t_stack **stack_a);
void		sort_stack_three(t_stack **stack_a);
int			case_rarb_ba(t_stack *a, t_stack *b, int c);
int			case_rrarrb_ba(t_stack *a, t_stack *b, int c);
int			case_rarrb_ba(t_stack *a, t_stack *b, int c);
int			case_rrarb_ba(t_stack *a, t_stack *b, int c);
int			case_rarb(t_stack *a, t_stack *b, int c);
int			case_rrarrb(t_stack *a, t_stack *b, int c);
int			case_rrarb(t_stack *a, t_stack *b, int c);
int			case_rarrb(t_stack *a, t_stack *b, int c);
t_rotate_info get_rotateinfo_ab(t_stack *a, t_stack *b);
t_rotate_info get_rotateinfo_ba(t_stack *a, t_stack *b);
int			apply_rarb(t_stack **a, t_stack **b, int c, char s);
int			apply_rrarrb(t_stack **a, t_stack **b, int c, char s);
int			apply_rrarb(t_stack **a, t_stack **b, int c, char s);
int			apply_rarrb(t_stack **a, t_stack **b, int c, char s);
void		rrb(t_stack **b, int j);
t_stack		*input(int argc, char **argv);
void		sort_till_3(t_stack **stack_a, t_stack **stack_b);
t_stack		*ft_sub_process(char **argv);

#endif