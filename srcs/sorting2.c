/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:23:36 by abrisse           #+#    #+#             */
/*   Updated: 2022/06/30 09:40:23 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * determine the position where the value is going on the stack a
 */

void	ft_find_target(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		test;
	int		target;

	tmp_b = *b;
	ft_get_position(a);
	ft_get_position(b);
	while (tmp_b)
	{
		test = INT_MAX;
		tmp_a = *a;
		while (tmp_a)
		{
			if (tmp_a->index > tmp_b->index && tmp_a->index < test)
			{
				test = tmp_a->index;
				target = tmp_a->pos;
			}
			tmp_a = tmp_a->next;
		}
		target = ft_find_best_target(a, test, target);
		tmp_b->target_to_a = target;
		tmp_b = tmp_b->next;
	}
}

int	ft_find_best_target(t_stack **a, int test, int target)
{
	t_stack	*tmp_a;

	tmp_a = *a;
	if (test == INT_MAX)
	{
		while (tmp_a)
		{
			if (tmp_a->index < test)
			{
				test = tmp_a->index;
				target = tmp_a->pos;
			}
			tmp_a = tmp_a->next;
		}
	}
	return (target);
}

/*
 * determine the number of move to exit b and to move to the right position on a
 */

void	ft_find_moves(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *a;
	tmp_b = *b;
	size_a = ft_stack_len(tmp_a);
	size_b = ft_stack_len(tmp_b);
	while (tmp_b)
	{
		if (tmp_b->pos > (size_b / 2))
			tmp_b->moves_in_b = - (size_b - tmp_b->pos);
		else
			tmp_b->moves_in_b = tmp_b->pos;
		if (tmp_b->target_to_a > (size_a / 2))
			tmp_b->moves_in_a = - (size_a - tmp_b->target_to_a);
		else
			tmp_b->moves_in_a = tmp_b->target_to_a;
		tmp_b = tmp_b->next;
	}
}
