/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:24:41 by mohel-mo          #+#    #+#             */
/*   Updated: 2025/03/27 04:55:29 by mohel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack **head, int is_rrr)
{
	t_stack	*last;
	t_stack	*second_last;

	if (*head && (*head)->next)
	{
		last = *head;
		while (last->next)
		{
			second_last = last;
			last = last->next;
		}
		second_last->next = NULL;
		last->next = *head;
		*head = last;
		if (!is_rrr)
			ft_printf("rra\n");
	}
}

void	ft_rrb(t_stack **head, int is_rrr)
{
	t_stack	*last;
	t_stack	*second_last;

	if (*head && (*head)->next)
	{
		last = (*head)->next;
		while (last->next)
		{
			second_last = last;
			last = last->next;
		}
		second_last->next = NULL;
		last->next = *head;
		*head = last;
		if (!is_rrr)
			ft_printf("rrb\n");
	}
}

void	ft_rrr(t_stack **a_head, t_stack **b_head)
{
	ft_rra(a_head, 1);
	ft_rrb(b_head, 1);
	ft_printf("rrr\n");
}
