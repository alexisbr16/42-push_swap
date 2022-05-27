/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 12:57:30 by abrisse           #+#    #+#             */
/*   Updated: 2022/05/27 14:38:49 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac <= 1)
		return (0);
	if (!ft_get_args(ac, av, &a))
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	if (!ft_is_sort(a))
		ft_sort(&a, &b);
	ft_free_stack(&a);
	ft_free_stack(&b);
	return (0);
}
