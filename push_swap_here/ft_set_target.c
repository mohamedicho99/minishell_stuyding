/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_target.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 09:02:15 by mohel-mo          #+#    #+#             */
/*   Updated: 2025/04/04 02:48:18 by mohel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_t_node(t_stack **a, t_stack **b_curr, t_stack *t, long b_mark)
{
	if (b_mark == LONG_MAX)
		(*b_curr)->t_node = ft_find_min(a);
	else
		(*b_curr)->t_node = t;
}

void	ft_set_target(t_stack **a_head, t_stack **b_head)
{
	long	b_mark;
	t_stack	*t_node;
	t_stack	*a_curr;
	t_stack	*b_curr;

	b_mark = LONG_MAX;
	a_curr = *a_head;
	b_curr = *b_head;
	while (b_curr)
	{
		a_curr = *a_head;
		b_mark = LONG_MAX;
		while (a_curr)
		{
			if (a_curr->nbr > b_curr->nbr && a_curr->nbr < b_mark)
			{
				b_mark = a_curr->nbr;
				t_node = a_curr;
			}
			a_curr = a_curr->next;
		}
		ft_set_t_node(a_head, &b_curr, t_node, b_mark);
		b_curr = b_curr->next;
	}
}
