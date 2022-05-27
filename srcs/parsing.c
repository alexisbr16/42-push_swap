/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 14:19:38 by abrisse           #+#    #+#             */
/*   Updated: 2022/03/29 16:03:48 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_args(int ac, char **av, t_stack **stack)
{
	int		i;
	int		j;
	char	*arg;
	char	**tab;
	int		number;

	i = 0;
	while (++i < ac)
	{
		tab = ft_split(av[i], ' ');
		j = 0;
		while (tab[j])
		{
			arg = tab[j];
			if (!check_number(arg) || !check_int(arg))
				return (ft_free_stack(stack));
			number = ft_atoi(arg);
			if (!check_duplicate(*stack, number))
				return (ft_free_stack(stack));
			ft_stackadd_back(stack, ft_stacknew(number));
			j++;
		}
	}
	return (1);
}

int	check_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_int(char *str)
{
	if (ft_strlen(str) > 11)
		return (0);
	if (ft_atoi(str) > 2147483647 || ft_atoi(str) < -2147483648)
		return (0);
	return (1);
}

int	check_duplicate(t_stack *stack, int value)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->value == value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
