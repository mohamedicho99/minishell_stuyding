/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 23:44:17 by mohel-mo          #+#    #+#             */
/*   Updated: 2025/04/03 23:44:18 by mohel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_ret_smallest(t_stack **head)
{
	t_stack	*curr;
	t_stack	*sm;
	long	mark;

	curr = *head;
	mark = LONG_MAX;
	sm = NULL;
	while (curr)
	{
		if (curr->nbr < mark)
		{
			mark = curr->nbr;
			sm = curr;
		}
		curr = curr->next;
	}
	return (sm);
}

void	ft_sort_smallest(t_stack **head)
{
	t_stack	*sm;

	ft_update_index(head);
	sm = ft_ret_smallest(head);
	if (sm->is_above_m == 1)
		while (sm != *head)
			ft_ra(head, 0);
	else
		while (sm != *head)
			ft_rra(head, 0);
}

void	ft_rotate(t_stack **a_head, t_stack **b_head, t_stack *c_node)
{
	while (*a_head != c_node->t_node && *b_head != c_node)
		ft_rr(a_head, b_head);
	ft_update_index(a_head);
	ft_update_index(b_head);
}

void	ft_reverse_rotate(t_stack **a_head, t_stack **b_head, t_stack *c_node)
{
	while (*a_head != c_node->t_node && *b_head != c_node)
		ft_rrr(a_head, b_head);
	ft_update_index(a_head);
	ft_update_index(b_head);
}
