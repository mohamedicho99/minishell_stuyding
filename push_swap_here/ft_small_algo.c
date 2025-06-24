/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 07:22:58 by mohel-mo          #+#    #+#             */
/*   Updated: 2025/03/30 09:16:41 by mohel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_for_three(t_stack **head, int top, int mid, int bot)
{
	if (top > mid && top > bot && mid > bot)
	{
		ft_sa(head, 0);
		ft_rra(head, 0);
	}
	else if (top > mid && top > bot && mid < bot)
		ft_ra(head, 0);
	else if (top < mid && mid > bot && top > bot)
		ft_rra(head, 0);
	else if (top > mid && top < bot)
		ft_sa(head, 0);
	else if (top < mid && mid > bot && top < bot)
	{
		ft_sa(head, 0);
		ft_ra(head, 0);
	}
}

int	ft_get_sm_position(t_stack **head)
{
	int		sm;
	int		sm_p;
	int		cur_pos;
	t_stack	*current;

	current = *head;
	sm = current->nbr;
	sm_p = 0;
	cur_pos = 0;
	while (current)
	{
		if (current->nbr < sm)
		{
			sm = current->nbr;
			sm_p = cur_pos;
		}
		current = current->next;
		cur_pos++;
	}
	return (sm_p);
}

void	ft_for_four(t_stack **head, int sm_p, int size, t_stack **b_head)
{
	int	i;

	i = 0;
	if (sm_p <= size / 2)
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

void	ft_exec_three(t_stack **head, int *top, int *mid, int *bot)
{
	*top = (*head)->nbr;
	*mid = (*head)->next->nbr;
	*bot = (*head)->next->next->nbr;
	ft_for_three(head, *top, *mid, *bot);
}

void	ft_small_algo(t_stack **head, t_stack **b_head)
{
	int	size;
	int	top;
	int	mid;
	int	bot;
	int	sm_p;

	size = ft_lstsize(*head);
	if (size == 2)
		ft_sa(head, 0);
	else if (size == 3)
		ft_exec_three(head, &top, &mid, &bot);
	else if (size == 4)
	{
		sm_p = ft_get_sm_position(head);
		ft_for_four(head, sm_p, size, b_head);
		ft_exec_three(head, &top, &mid, &bot);
		ft_pa(head, b_head);
	}
	else if (size == 5)
		ft_sort_five(head, b_head, size);
	else
		ft_sort_rest(head, b_head);
}
