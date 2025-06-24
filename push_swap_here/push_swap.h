/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:31:37 by mohel-mo          #+#    #+#             */
/*   Updated: 2025/04/04 15:31:39 by mohel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

int		ft_isspace(char c);
long	ft_atol(char *s, t_stack **head, char **nums);
void	ft_dup_check(t_stack **head, int nbr, char **nums);
void	ft_exit(t_stack **head);
void	free_nums(char **nums);
void	ft_init_stack_a(char *s, t_stack **head);
int		ft_is_sorted(t_stack **head);
void	ft_sa(t_stack **head, int is_ss);
void	ft_sb(t_stack **head, int is_ss);
void	ft_ss(t_stack **a_head, t_stack **b_head);
void	ft_pb(t_stack **a_head, t_stack **b_head);
void	ft_pa(t_stack **a_head, t_stack **b_head);
void	ft_ra(t_stack **head, int is_rr);
void	ft_rb(t_stack **head, int is_rr);
void	ft_rr(t_stack **a_head, t_stack **b_head);
void	ft_rra(t_stack **a_head, int is_rrr);
void	ft_rrb(t_stack **a_head, int is_rrr);
void	ft_rrr(t_stack **a_head, t_stack **b_head);
void	ft_small_algo(t_stack **head, t_stack **b_head);
int		ft_get_sm_position(t_stack **head);
void	ft_for_four(t_stack **head, int sm_p, int size, t_stack **b_head);
void	ft_exec_three(t_stack **head, int *top, int *mid, int *bot);
void	ft_sort_five(t_stack **head, t_stack **b_head, int size);
void	ft_for_three(t_stack **head, int top, int mid, int bot);
void	ft_sort_rest(t_stack **a_head, t_stack **b_head);
void	ft_print_indexes(t_stack **head);
void	ft_define_costs(t_stack **a_head, t_stack **b_head);
void	ft_define_cheapest(t_stack *head);
void	ft_move_node(t_stack **a_head, t_stack **b_head);
void	ft_update_index(t_stack **head);
void	ft_sort_smallest(t_stack **head);
void	ft_rotate(t_stack **a_head, t_stack **b_head, t_stack *c_node);
void	ft_reverse_rotate(t_stack **a_head, t_stack **b_head, t_stack *c_node);
void	ft_set_target(t_stack **a_head, t_stack **b_head);
t_stack	*ft_find_min(t_stack **head);

#endif
