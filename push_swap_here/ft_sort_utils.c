/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:17:32 by mohel-mo          #+#    #+#             */
/*   Updated: 2025/04/03 16:17:33 by mohel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_define_costs(t_stack **a_head, t_stack **b_head)
{
	t_stack	*a_curr;
	t_stack	*b_curr;
	int		a_len;
	int		b_len;

	a_curr = *a_head;
	b_curr = *b_head;
	a_len = ft_lstsize(a_curr);
	b_len = ft_lstsize(b_curr);
	while (b_curr)
	{
		if (b_curr->is_above_m)
			b_curr->m_cost = b_curr->index;
		else
			b_curr->m_cost = b_len - b_curr->index;
		if (b_curr->t_node->is_above_m)
			b_curr->m_cost += b_curr->t_node->index;
		else
			b_curr->m_cost += a_len - b_curr->t_node->index;
		b_curr = b_curr->next;
	}
}

void	ft_define_cheapest(t_stack *head)
{
	t_stack	*curr;
	t_stack	*c_node;
	long	mark;

	curr = head;
	mark = LONG_MAX;
	while (curr)
	{
		if (curr->m_cost < mark)
		{
			mark = curr->m_cost;
			c_node = curr;
		}
		curr = curr->next;
	}
	c_node->is_cheapest = 1;
}

t_stack	*ft_ret_cheapest(t_stack **head)
{
	t_stack	*curr;
	t_stack	*c_node;

	curr = *head;
	while (curr)
	{
		if (curr->is_cheapest == 1)
			c_node = curr;
		curr = curr->next;
	}
	return (c_node);
}

void	ft_do_rotate(t_stack **head, t_stack *c_node, char sn)
{
	if (sn == 'a')
	{
		while (*head != c_node)
		{
			if (c_node->is_above_m)
				ft_ra(head, 0);
			else
				ft_rra(head, 0);
		}
	}
	else if (sn == 'b')
	{
		while (*head != c_node)
		{
			if (c_node->is_above_m)
				ft_rb(head, 0);
			else
				ft_rrb(head, 0);
		}
	}
}

void	ft_move_node(t_stack **a_head, t_stack **b_head)
{
	t_stack	*c_node;

	c_node = ft_ret_cheapest(b_head);
	if (c_node->is_above_m == 1 && c_node->t_node->is_above_m == 1)
		ft_rotate(a_head, b_head, c_node);
	else if (c_node->is_above_m == 0 && c_node->t_node->is_above_m == 0)
		ft_reverse_rotate(a_head, b_head, c_node);
	ft_do_rotate(b_head, c_node, 'b');
	ft_do_rotate(a_head, c_node->t_node, 'a');
	ft_pa(a_head, b_head);
}
