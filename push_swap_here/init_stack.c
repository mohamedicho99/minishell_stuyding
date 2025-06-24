/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:29:43 by mohel-mo          #+#    #+#             */
/*   Updated: 2025/03/25 09:07:21 by mohel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check(char *s, t_stack **head, char **nums)
{
	if ((*s != '-' && *s != '+') && !ft_isdigit(*s))
	{
		if (nums)
			free_nums(nums);
		ft_exit(head);
	}
	s++;
	if ((s[-1] == '-' || s[-1] == '+') && !*s)
	{
		if (nums)
			free_nums(nums);
		ft_exit(head);
	}
	while (*s)
	{
		if (!ft_isdigit(*s))
		{
			if (nums)
				free_nums(nums);
			ft_exit(head);
		}
		s++;
	}
}

void	ft_is_just_spaces(char *s, t_stack **head)
{
	while (*s)
	{
		if (ft_isdigit(*s) || *s == '-' || *s == '+')
			return ;
		s++;
	}
	ft_exit(head);
}

void	ft_initializing(t_stack **h, char *s, char **m, long *nbr)
{
	ft_check(s, h, m);
	*nbr = ft_atol(s, h, m);
	ft_dup_check(h, *nbr, m);
}

void	ft_init_stack_a(char *s, t_stack **head)
{
	char	**nums;
	long	nbr;
	int		i;

	nbr = 0;
	nums = NULL;
	i = 0;
	if (ft_strchr(s, ' '))
	{
		ft_is_just_spaces(s, head);
		nums = ft_split(s, ' ');
		while (nums[i])
		{
			ft_initializing(head, nums[i++], nums, &nbr);
			ft_lstadd_back(head, ft_lstnew(nbr));
		}
	}
	else
	{
		ft_initializing(head, s, nums, &nbr);
		ft_lstadd_back(head, ft_lstnew(nbr));
	}
	if (nums)
		free_nums(nums);
}
