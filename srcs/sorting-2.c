/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting-2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 09:57:35 by abrisse           #+#    #+#             */
/*   Updated: 2022/05/27 14:37:42 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_to_a(t_stack **a, t_stack **b)
{
	(void)a;

	while (ft_count_args(*b))
	{
		while(!ft_max_on_top(*b))
			ft_rb(b);
		while((*a)->value < (*b)->value )
			ft_ra(a);
		ft_pa(a, b);
		ft_align(a);
	}
}

void	ft_align(t_stack **stack)
{
	while (!ft_min_on_top(*stack))
		ft_ra(stack);
}

int	ft_max_on_top(t_stack *stack)
{
	int	first;

	first = stack->value;
	stack = stack->next;
	while (stack)
	{
		if (first < stack->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_min_on_top(t_stack *stack)
{
	int	first;

	first = stack->value;
	stack = stack->next;
	while (stack)
	{
		if (first > stack->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}	
