/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:04:30 by abrisse           #+#    #+#             */
/*   Updated: 2022/06/30 09:22:27 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		len;

	if (ac <= 1)
		return (0);
	a = NULL;
	b = NULL;
	if (!ft_get_args(ac, av, &a))
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	len = ft_stack_len(a);
	ft_get_index(a, len);
	if (ft_is_sort_not_align(a))
		ft_align(&a, ft_stack_min(a));
	else if (!ft_is_sort(a))
		ft_do_sort(&a, &b);
	ft_stackfree(a);
	return (0);
}
