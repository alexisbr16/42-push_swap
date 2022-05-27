/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 09:18:40 by abrisse           #+#    #+#             */
/*   Updated: 2022/05/27 13:02:19 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
void	ft_sort(t_stack **a, t_stack **b)
{
	ft_sort_to_b(a, b);

	ft_printf("STACK A\n=======\n");
	ft_print_stack(*a);

	ft_printf("STACK B\n=======\n");
	ft_print_stack(*b);

	ft_sort_five(a, b);
//	ft_sort_to_a(a, b);
}

void	ft_sort_to_b(t_stack **a, t_stack **b)
{
	(void)b;

//	ft_printf("=== %d\n", (*a)->value);
//	ft_printf("=== %d\n", (*a)->next->value);
//	ft_printf("=== %d\n", (ft_stacklast(*a))->value);
	while (ft_count_args(*a) > 5)
	{
		if (!(ft_count_below(*a) < ft_count_args(*a) * 0.3))
			ft_ra(a);
		else
			ft_pb(a, b);
	}
//	ft_printf("=== %d\n", (*a)->value);
}

void	ft_sort_five(t_stack **a, t_stack **b)
{
	while (!ft_is_sort(*a) || ft_count_args(*b))
	{
		if ((*a)->value > (ft_stacklast(*a))->value)
			ft_ra(a);
		else if ((*a)->value > (*a)->next->value)
			ft_sa(a);
		else if (!ft_is_sort(*a))
			ft_pb(a, b);
		else if (ft_count_args(*a) + ft_count_args(*b) <= 5)
			ft_pa(a, b);
		else
			break ;
	}
}
