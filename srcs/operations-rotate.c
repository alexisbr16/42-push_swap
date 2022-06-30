/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations-rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:52:26 by abrisse           #+#    #+#             */
/*   Updated: 2022/06/30 14:16:58 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*move;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	move = *stack;
	while (move->next)
		move = move->next;
	move->next = first;
	first->next = NULL;
}

void	ft_ra(t_stack **a)
{
	ft_rotate(a);
	ft_putendl_fd("ra", 1);
}

void	ft_rb(t_stack **b)
{
	ft_rotate(b);
	ft_putendl_fd("rb", 1);
}

void	ft_rr(t_stack **a, t_stack **b)
{
	ft_rotate(a);
	ft_rotate(b);
	ft_putendl_fd("rr", 1);
}
