/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations-reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:20:31 by abrisse           #+#    #+#             */
/*   Updated: 2022/06/30 14:16:31 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*move;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	move = *stack;
	while (move->next->next)
		move = move->next;
	*stack = move->next;
	(*stack)->next = first;
	move->next = NULL;
}

void	ft_rra(t_stack **a)
{
	ft_reverse_rotate(a);
	ft_putendl_fd("rra", 1);
}

void	ft_rrb(t_stack **b)
{
	ft_reverse_rotate(b);
	ft_putendl_fd("rrb", 1);
}

void	ft_rrr(t_stack **a, t_stack **b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	ft_putendl_fd("rrr", 1);
}
