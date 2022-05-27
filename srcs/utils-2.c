/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils-2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 20:07:28 by abrisse           #+#    #+#             */
/*   Updated: 2022/05/26 21:32:32 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_args(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

int	ft_count_below(t_stack *stack)
{
	int	count;
	int	first;

	count = 0;
	first = stack->value;
	while (stack)
	{
		if (first > stack->value)
			count++;
		stack = stack->next;
	}
	return (count);
}
