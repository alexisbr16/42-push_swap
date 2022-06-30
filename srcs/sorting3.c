/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:23:36 by abrisse           #+#    #+#             */
/*   Updated: 2022/06/30 10:00:29 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * do the more optimize move 
 */

void	ft_move(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	long	test;
	int		moves_in_a;
	int		moves_in_b;

	tmp = *b;
	test = INT_MAX;
	while (tmp)
	{
		if (ft_abs(tmp->moves_in_a) + ft_abs(tmp->moves_in_b) < ft_abs(test))
		{
			test = ft_abs(tmp->moves_in_a) + ft_abs(tmp->moves_in_b);
			moves_in_a = tmp->moves_in_a;
			moves_in_b = tmp->moves_in_b;
		}
		tmp = tmp->next;
	}
	ft_best_operations(a, b, moves_in_a, moves_in_b);
}

void	ft_best_operations(t_stack **a, t_stack **b, int moves_in_a,
		int moves_in_b)
{
	if (moves_in_a < 0 && moves_in_b < 0)
		ft_moves_negative(a, b, &moves_in_a, &moves_in_b);
	else if (moves_in_a > 0 && moves_in_b > 0)
		ft_moves_positive(a, b, &moves_in_a, &moves_in_b);
	ft_end_moves(a, &moves_in_a, 'a');
	ft_end_moves(b, &moves_in_b, 'b');
	ft_pa(a, b);
}

void	ft_moves_positive(t_stack **a, t_stack **b, int *moves_in_a,
		int *moves_in_b)
{
	while (*moves_in_a > 0 && *moves_in_b > 0)
	{
		ft_rr(a, b);
		(*moves_in_a)--;
		(*moves_in_b)--;
	}
}

void	ft_moves_negative(t_stack **a, t_stack **b, int *moves_in_a,
		int *moves_in_b)
{
	while (*moves_in_a < 0 && *moves_in_b < 0)
	{
		ft_rrr(a, b);
		(*moves_in_a)++;
		(*moves_in_b)++;
	}
}

void	ft_end_moves(t_stack **stack, int *moves, char who)
{
	while (*moves != 0)
	{
		if (*moves > 0)
		{
			if (who == 'a')
				ft_ra(stack);
			else
				ft_rb(stack);
			(*moves)--;
		}
		else if (*moves < 0)
		{
			if (who == 'a')
				ft_rra(stack);
			else
				ft_rrb(stack);
			(*moves)++;
		}
	}
}
