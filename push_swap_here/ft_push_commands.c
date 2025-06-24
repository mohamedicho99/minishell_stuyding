/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:01:13 by mohel-mo          #+#    #+#             */
/*   Updated: 2025/03/25 15:28:07 by mohel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pb(t_stack **a_head, t_stack **b_head)
{
	t_stack	*a_current;
	t_stack	*tmp;

	if (!*a_head)
		return ;
	a_current = *a_head;
	if (a_current)
	{
		ft_lstadd_front(b_head, ft_lstnew(a_current->nbr));
		tmp = a_current;
		*a_head = a_current->next;
		free(tmp);
		ft_printf("pb\n");
	}
}

void	ft_pa(t_stack **a_head, t_stack **b_head)
{
	t_stack	*b_current;
	t_stack	*tmp;

	b_current = *b_head;
	if (b_current)
	{
		ft_lstadd_front(a_head, ft_lstnew(b_current->nbr));
		tmp = b_current;
		*b_head = b_current->next;
		free(tmp);
		ft_printf("pa\n");
	}
}
