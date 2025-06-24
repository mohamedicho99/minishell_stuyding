/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 09:03:11 by mohel-mo          #+#    #+#             */
/*   Updated: 2025/03/25 09:24:09 by mohel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sign(char c, int *i)
{
	int	sign;

	sign = 1;
	if (c == '+' || c == '-')
	{
		if (c == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

static void	ft_calc_re(char *s, int *i, long *re, t_stack **head)
{
	int	j;

	j = 0;
	while (s[*i])
	{
		while (s[*i] >= '0' && s[*i] <= '9')
		{
			*re = (*re * 10) + (s[*i] - '0');
			(*i)++;
			j++;
			if (j > 11 && *re > 2147483647)
				ft_exit(head);
		}
	}
}

long	ft_atol(char *s, t_stack **head, char **nums)
{
	int		i;
	long	re;
	int		sign;

	i = 0;
	re = 0;
	while (s[i] && ft_isspace(s[i]))
		i++;
	sign = ft_sign(s[i], &i);
	ft_calc_re(s, &i, &re, head);
	re = re * sign;
	if (re > 2147483647 || re < -2147483648)
	{
		if (nums)
			free_nums(nums);
		ft_exit(head);
	}
	return (re);
}
// 
