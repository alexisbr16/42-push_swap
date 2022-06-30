/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:13:26 by abrisse           #+#    #+#             */
/*   Updated: 2022/06/30 09:07:39 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_get_index(t_stack *stack, int len)
{
	t_stack	*max;
	t_stack	*save;
	int		move;

	save = stack;
	while (len > 0)
	{
		stack = save;
		move = INT_MIN;
		while (stack)
		{
			if (stack->value == INT_MIN && stack->index == 0)
				stack->index = 1;
			if (stack->value > move && stack->index == 0)
			{
				move = stack->value;
				max = stack;
				stack = save;
			}
			else
				stack = stack->next;
		}
		max->index = len;
		len--;
	}
}

void	ft_get_position(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

long	ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

char	**free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}
