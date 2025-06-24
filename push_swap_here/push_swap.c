/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 02:34:10 by mohel-mo          #+#    #+#             */
/*   Updated: 2025/03/27 04:55:52 by mohel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;
	int		ct;

	if (argc == 1)
		exit(1);
	i = 1;
	ct = argc;
	stack_a = NULL;
	stack_b = NULL;
	while (i < ct)
	{
		ft_init_stack_a(argv[i], &stack_a);
		i++;
	}
	if (ft_is_sorted(&stack_a))
	{
		ft_lstclear(&stack_a);
		exit(0);
	}
	ft_small_algo(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}
