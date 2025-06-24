/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 09:02:15 by mohel-mo          #+#    #+#             */
/*   Updated: 2025/04/01 09:02:18 by mohel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_find_min(t_stack **head)
{
	t_stack	*min_n;
	t_stack	*curr;
	long	min_nbr;

	if (!*head)
		return (NULL);
	curr = *head;
	min_nbr = LONG_MAX;
	while (curr)
	{
		if (curr->nbr < min_nbr)
		{
			min_nbr = curr->nbr;
			min_n = curr;
		}
		curr = curr->next;
	}
	return (min_n);
}

void	ft_update_index(t_stack **head)
{
	t_stack	*curr;
	int		s;
	int		mid;
	int		i;

	if (!*head)
		return ;
	curr = *head;
	s = ft_lstsize(curr);
	mid = s / 2;
	i = 0;
	while (curr)
	{
		curr->index = i;
		if (i <= mid)
			curr->is_above_m = 1;
		else
			curr->is_above_m = 0;
		curr = curr->next;
		i++;
	}
}

void	ft_refresh_data(t_stack **a_head, t_stack **b_head)
{
	ft_update_index(a_head);
	ft_update_index(b_head);
	ft_set_target(a_head, b_head);
	ft_define_costs(a_head, b_head);
	ft_define_cheapest(*b_head);
}

void	ft_sort_rest(t_stack **a_head, t_stack **b_head)
{
	int	a_size;

	a_size = ft_lstsize(*a_head);
	while (a_size > 3)
	{
		ft_pb(a_head, b_head);
		a_size--;
	}
	ft_small_algo(a_head, b_head);
	while (*b_head)
	{
		ft_refresh_data(a_head, b_head);
		ft_move_node(a_head, b_head);
	}
	ft_sort_smallest(a_head);
}
