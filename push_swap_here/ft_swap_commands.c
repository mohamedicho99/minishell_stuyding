/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 09:31:00 by mohel-mo          #+#    #+#             */
/*   Updated: 2025/03/25 12:35:00 by mohel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_stack *a, t_stack *b)
{
	int	tmp;

	tmp = a->nbr;
	a->nbr = b->nbr;
	b->nbr = tmp;
}

void	ft_sa(t_stack **head, int is_ss)
{
	t_stack	*current;
	t_stack	*next;

	current = *head;
	next = current->next;
	ft_swap(current, next);
	if (!is_ss)
		ft_printf("sa\n");
}

void	ft_sb(t_stack **head, int is_ss)
{
	t_stack	*current;
	t_stack	*next;

	current = *head;
	next = current->next;
	ft_swap(current, next);
	if (!is_ss)
		ft_printf("sb\n");
}

void	ft_ss(t_stack **a_head, t_stack **b_head)
{
	ft_sa(a_head, 1);
	ft_sb(b_head, 1);
	ft_printf("ss\n");
}
