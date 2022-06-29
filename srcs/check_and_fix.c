/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_fix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:20:14 by abrisse           #+#    #+#             */
/*   Updated: 2022/06/29 23:18:42 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sort_not_align(t_stack *stack)
{
	int		len;
	t_stack	*next;
	t_stack	*move;

	len = ft_stack_len(stack);
	move = ft_stack_min(stack);
	while (--len)
	{
		if (!move)
			move = stack;
		next = move->next;
		if (!next)
			next = stack;
		if (move->value > next->value)
			return (0);
		move = move->next;
	}
	return (1);
}

int	ft_is_sort(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp && tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_align(t_stack **stack, t_stack *el)
{
	int	i;
	int	len;

	i = -1;
	len = ft_stack_len(*stack);
	ft_get_position(stack);
	if (el->pos <= (len / 2))
		while (++i < el->pos)
			ft_ra(stack);
	else
		while (++i < len - el->pos)
			ft_rra(stack);
}
