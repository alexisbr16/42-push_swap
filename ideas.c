/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ideas.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:33:37 by abrisse           #+#    #+#             */
/*   Updated: 2022/05/26 18:44:21 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ERROR_MSG "Erorr\n"
#define BONUS_OK "OK\n"
#define BONUS_KO "KO\n"

void	ft_end_program(t_data *data, int exit_number)
{
	if (data)
	{
		if (data->a)
			ft_free_stack(data->a);
		if (data->b)
			ft_free_stack(data->b);
		free(data);	
	}
	if (exit_number > 0)
		ft_putstr_fd(ERROR_MSG, 2);
	else if (exit_number == -1)
		ft_putstr_fd(BONUS_OK, 1);
	else if (exit_number == -1)
		ft_putstr_fd(BONUS_KO, 1);
	exit(exit_number);
}


void	ft_sort_stack(t_stack **a, t_stack **b)
{
	(void)b;
	int	count;

	count = ft_count_args(*a);
	if (count == 2)
		ft_ra(a);
	else if (count == 3)
		ft_sort_three(a);
	else if (count == 4);
		ft_sort_four(a, b);
	else
		ft_sort(a, b);
	return ;
}

void	ft_sort_three(t_stack **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->value;
	b = (*stack)->next->value;
	c = (*stack)->next->next->value;

	if (a > b && b < c && a < c)
		ft_sa(stack);
	else if (a > b && b > c && a > c)
	{
		ft_sa(stack);
		ft_rra(stack);
	}
	else if (a > b && b < c && a > c)
		ft_ra(stack);
	else if (a < b && b > c && a < c)
	{
		ft_sa(stack);
		ft_ra(stack);
	}
	else if (a < b && b > c && a > c)
		ft_rra(stack);
}

void	ft_sort_four(t_stack **a, t_stack **b)
{
	ft_up_smallest_a(a);
	ft_pb(a, b);
	ft_sort_three(a);
	ft_pa(a, b);
}

void	ft_up_smallest_a(t_stakc **a)
{
	int	min_value;

	min_value = ft_smallest_value(*a);
	while ((*a)->value != min_value)		// TODO: Optimize this
		ft_ra(a);
}

int	ft_smallest_value(t_stack *stack)
{
	int	min_value;

	min_value = stack->value;
	while (stack)
	{
		if (stack->value < min_value)
			min_value = stack->value;
		stack = stack->next;
	}
	return (min_value);
}
