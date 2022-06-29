/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:23:36 by abrisse           #+#    #+#             */
/*   Updated: 2022/06/29 23:36:15 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * do the more optimize move 
 */

void	ft_move(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		test; //voir si pas long int plutot
	int		labor_in_a;
	int		labor_in_b;

	tmp = *b;
	test = INT_MAX;
	while (tmp)
	{
		if (ft_abs(tmp->labor_in_a) + ft_abs(tmp->labor_in_b) < ft_abs(test))
		{
			test = ft_abs(tmp->labor_in_a) + ft_abs(tmp->labor_in_b);
			labor_in_a = tmp->labor_in_a;
			labor_in_b = tmp->labor_in_b;
		}
		tmp = tmp->next;
	}
	ft_best_operations(a, b, labor_in_a, labor_in_b);
}

void	ft_best_operations(t_stack **a, t_stack **b, int labor_in_a, 
		int labor_in_b)
{
	if (labor_in_a > 0 && labor_in_b > 0)
		ft_labor_positive(a, b, &labor_in_a, &labor_in_b);
	else if (labor_in_a < 0 && labor_in_b < 0)
		ft_labor_negative(a, b, &labor_in_a, &labor_in_b);
	ft_end_labor(a, &labor_in_a, 'a');
	ft_end_labor(b, &labor_in_a, 'b');
	ft_pa(a, b);
}

void	ft_labor_positive(t_stack **a, t_stack **b, int *labor_in_a, int *labor_in_b)
{
	while (*labor_in_a > 0 && *labor_in_b > 0)
	{
		ft_rr(a, b);
		(*labor_in_a)--;
		(*labor_in_b)--;
	}
}

void	ft_labor_negative(t_stack **a, t_stack **b, int *labor_in_a, int *labor_in_b)
{
	while (*labor_in_a < 0 && *labor_in_b < 0)
	{
		ft_rrr(a, b);
		(*labor_in_a)++;
		(*labor_in_b)++;
	}
}

void	ft_end_labor(t_stack **stack, int *labor, char who)
{
	while (*labor != 0)
	{
		if (*labor > 0)
		{
			if (who == 'a')
				ft_ra(stack);
			else
				ft_rb(stack);
			(*labor)--;
		}
		else if (*labor < 0)
		{
			if (who == 'a')
				ft_rra(stack);
			else
				ft_rrb(stack);
			(*labor)++;
		}
	}
}
