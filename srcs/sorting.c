/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:23:36 by abrisse           #+#    #+#             */
/*   Updated: 2022/06/30 10:22:40 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stack **stack)
{
	int		max;
	t_stack	*tmp;

	tmp = *stack;
	max = (ft_stack_max(*stack))->value;
	if (tmp->value == max)
		ft_ra(&tmp);
	else if (tmp->next->value == max)
		ft_rra(&tmp);
	if (tmp->value > tmp->next->value)
		ft_sa(&tmp);
	*stack = tmp;
}

void	ft_sort(t_stack **a, t_stack **b)
{
	ft_push_first_half(a, b);
	ft_sort_three(a);
	ft_find_target(a, b);
	ft_find_moves(a, b);
	while (*b)
	{
		ft_find_target(a, b);
		ft_find_moves(a, b);
		ft_move(a, b);
	}
	if (!ft_is_sort(*a))
		ft_align(a, ft_stack_min(*a));
}

void	ft_push_first_half(t_stack **a, t_stack **b)
{
	int	i;
	int	count;
	int	len;

	i = 0;
	count = 0;
	len = ft_stack_len(*a);
	while (len > 6 && i < len && count < (len / 2))
	{
		if ((*a)->index <= (len / 2))
		{
			ft_pb(a, b);
			count++;
		}
		else
			ft_ra(a);
		i++;
	}
	while (len - count > 3)
	{
		ft_pb(a, b);
		count++;
	}
}

void	ft_do_sort(t_stack **a, t_stack **b)
{
	int	len;

	len = ft_stack_len(*a);
	if (len == 2)
		ft_sa(a);
	else if (len == 3)
		ft_sort_three(a);
	else
		ft_sort(a, b);
}
