/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations-push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:15:09 by abrisse           #+#    #+#             */
/*   Updated: 2022/06/30 14:15:55 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (!src || !*src)
		return (0);
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	*dst = tmp;
	return (1);
}

void	ft_pa(t_stack **a, t_stack **b)
{
	if (ft_push(b, a))
		ft_putendl_fd("pa", 1);
}

void	ft_pb(t_stack **a, t_stack **b)
{
	if (ft_push(a, b))
		ft_putendl_fd("pb", 1);
}
