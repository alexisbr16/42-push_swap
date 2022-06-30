/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:00:15 by abrisse           #+#    #+#             */
/*   Updated: 2022/06/30 15:21:30 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_keep_do_it(t_stack **a, t_stack **b, char *input)
{
	if (ft_strncmp(input, "sa\n", 3) == 0)
		ft_swap(a);
	else if (ft_strncmp(input, "sb\n", 3) == 0)
		ft_swap(b);
	else if (ft_strncmp(input, "ss\n", 3) == 0)
	{
		ft_swap(a);
		ft_swap(b);
	}
	else
	{
		ft_stackfree(*a);
		ft_stackfree(*b);
		free(input);
		ft_putendl_fd("Error", 2);
		exit (1);
	}
}

static void	ft_do_it(t_stack **a, t_stack **b, char *input)
{
	if (ft_strncmp(input, "pa\n", 3) == 0)
		ft_push(b, a);
	else if (ft_strncmp(input, "pb\n", 3) == 0)
		ft_push(a, b);
	else if (ft_strncmp(input, "rra\n", 4) == 0)
		ft_reverse_rotate(a);
	else if (ft_strncmp(input, "rrb\n", 4) == 0)
		ft_reverse_rotate(b);
	else if (ft_strncmp(input, "rrr\n", 4) == 0)
	{
		ft_reverse_rotate(a);
		ft_reverse_rotate(b);
	}
	else if (ft_strncmp(input, "ra\n", 3) == 0)
		ft_rotate(a);
	else if (ft_strncmp(input, "rb\n", 3) == 0)
		ft_rotate(b);
	else if (ft_strncmp(input, "rr\n", 3) == 0)
	{
		ft_rotate(a);
		ft_rotate(b);
	}
	else
		ft_keep_do_it(a, b, input);
}

static void	ft_verify_and_end(t_stack **a, t_stack **b)
{
	if (ft_is_sort(*a) && ft_stack_len(*b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_stackfree(*a);
	ft_stackfree(*b);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*input;
	int		loop;

	if (ac <= 1)
		return (0);
	a = NULL;
	b = NULL;
	if (!ft_get_args(ac, av, &a))
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	loop = 1;
	while (loop)
	{
		input = get_next_line(0);
		if (input != NULL)
			ft_do_it(&a, &b, input);
		else if (input == NULL)
			loop = 0;
		free(input);
	}
	ft_verify_and_end(&a, &b);
}
