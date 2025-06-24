/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shift.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:55:32 by mohel-mo          #+#    #+#             */
/*   Updated: 2025/03/25 12:27:29 by mohel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack **head, int is_rr)
{
	t_stack	*current;
	t_stack	*tmp_p;
	int		tmp_i;

	current = *head;
	if (current)
	{
		tmp_p = current;
		tmp_i = current->nbr;
		*head = current->next;
		free(tmp_p);
		ft_lstadd_back(head, ft_lstnew(tmp_i));
		if (!is_rr)
			ft_printf("ra\n");
	}
}

void	ft_rb(t_stack **head, int is_rr)
{
	t_stack	*current;
	t_stack	*tmp_p;
	int		tmp_i;

	current = *head;
	if (current)
	{
		tmp_p = current;
		tmp_i = current->nbr;
		*head = current->next;
		free(tmp_p);
		ft_lstadd_back(head, ft_lstnew(tmp_i));
		if (!is_rr)
			ft_printf("rb\n");
	}
}

void	ft_rr(t_stack **a_head, t_stack **b_head)
{
	ft_ra(a_head, 1);
	ft_rb(b_head, 1);
	ft_printf("rr\n");
}
