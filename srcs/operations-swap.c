/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations-swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:57:46 by abrisse           #+#    #+#             */
/*   Updated: 2022/06/30 14:17:28 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_swap(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	return (1);
}

void	ft_sa(t_stack **a)
{
	if (ft_swap(a))
		ft_putendl_fd("sa", 1);
}

void	ft_sb(t_stack **b)
{
	if (ft_swap(b))
		ft_putendl_fd("sb", 1);
}

void	ft_ss(t_stack **a, t_stack **b)
{
	if (ft_swap(a) || ft_swap(b))
		ft_putendl_fd("ss", 1);
}
