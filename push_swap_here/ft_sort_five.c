/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 09:01:16 by mohel-mo          #+#    #+#             */
/*   Updated: 2025/03/30 09:16:18 by mohel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_exec_two(t_stack **head)
{
	if (*head && (*head)->next)
	{
		if ((*head)->nbr > (*head)->next->nbr)
			ft_sa(head, 0);
	}
}

static void	ft_for_x(t_stack **head, int sm_p, int size, t_stack **b_head)
{
	int	i;

	i = 0;
	if (sm_p == 3)
		ft_rra(head, 0);
	else if (sm_p <= size / 2)
	{
		while (i < sm_p)
		{
			ft_ra(head, 0);
			i++;
		}
	}
	else
	{
		while (i < size - sm_p)
		{
			ft_rra(head, 0);
			i++;
		}
	}
	ft_pb(head, b_head);
}

void	ft_sort_five(t_stack **head, t_stack **b_head, int size)
{
	int	sm_p;
	int	top;
	int	mid;
	int	bot;

	sm_p = ft_get_sm_position(head);
	ft_for_four(head, sm_p, size, b_head);
	sm_p = ft_get_sm_position(head);
	ft_for_x(head, sm_p, size, b_head);
	top = (*head)->nbr;
	mid = (*head)->next->nbr;
	bot = (*head)->next->next->nbr;
	ft_for_three(head, top, mid, bot);
	ft_exec_two(head);
	ft_pa(head, b_head);
	ft_pa(head, b_head);
}
