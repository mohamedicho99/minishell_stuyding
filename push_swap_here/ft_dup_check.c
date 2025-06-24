/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 00:29:56 by mohel-mo          #+#    #+#             */
/*   Updated: 2025/03/25 01:33:37 by mohel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dup_check(t_stack **head, int nbr, char **nums)
{
	t_stack	*current;

	current = *head;
	while (current)
	{
		if (nbr == current->nbr)
		{
			if (nums)
				free_nums(nums);
			ft_exit(head);
		}
		current = current->next;
	}
}
