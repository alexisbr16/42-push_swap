/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:26:53 by abrisse           #+#    #+#             */
/*   Updated: 2022/06/13 19:36:07 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacknew(int number)
{
	t_stack *element;

	element = malloc(sizeof(t_stack));
	if (!element)
		return (NULL);
	element->value = number;
	element->next = NULL;
	element->prev = NULL;
	return (element);
}

int	ft_free_stack(t_stack **stack)
{
	if (!*stack)
		return (0);
	while ((*stack)->next)
	{
		*stack = (*stack)->next;
		free((*stack)->prev);
	}
	free(*stack);
	return (0);
}

t_stack	*ft_stackfirst(t_stack *stack)
{
	while (stack->prev)
		stack = stack->prev;
	return (stack);
}

t_stack	*ft_stacklast(t_stack *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (*stack == NULL)
		*stack = new;
	else
	{
		last = ft_stacklast(*stack);
		last->next = new;
		new->prev = last;
	}
}

/* ************************************************************************** */

int	ft_stack_len(t_stack *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

t_stack	*ft_stack_max(t_stack *stack)
{
	t_stack	*max;

	if (!stack)
		return (NULL);
	max = stack;
	while (stack)
	{
		if (stack->value > max->value)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

t_stack	*ft_stack_min(t_stack *stack)
{
	t_stack	*min;

	if (!stack)
		return (NULL);
	min = stack;
	while (stack)
	{
		if (stack->value < min->value)
			min = stack;
		stack = stack->next;
	}
	return (min);
}


int	ft_stack_index(t_stack *stack, t_stack *element)
{
	int	i;

	if (!stack || !element)
		return (-1);
	i = 0;
	while (stack && stack->value != element->value)
	{
		stack = stack->next;
		i++;
	}
	if (!stack)
		i = -1;
	return (i);
}

t_stack	*ft_stack_greater(t_stack *stack, t_stack *el)
{
	t_stack	*greater;

	if (!stack || !el)
		return (NULL);
	greater = ft_stack_max(stack);
	while (stack)
	{
		if (stack->value > el->value && stack->value < greater->value)
			greater = stack;
		stack = stack->next;
	}
	return (greater);
}

/* ************************************************************************** */

int	ft_are_same_sign(int a, int b)
{
	if ((a > 0 && b > 0) || (a < 0 && b < 0))
		return (1);
	return (0);
}


/* ************************************************************************** */

void	ft_print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_printf("= %d\n", stack->value);
		stack = stack->next;
	}
	ft_printf("\n");
	return ;
}

void	ft_print_twostack(t_stack *a, t_stack *b)
{
	ft_printf(" a\t b\n-----\t-----\n");
	while (a || b)
	{
		if (a)
		{
			ft_printf(" %d\t", a->value);
			a = a->next;
		}
		else
			ft_printf(" \t");
		if (b)
		{
			ft_printf(" %d", b->value);
			b = b->next;
		}
		ft_printf("\n");
	}
	ft_printf("\n");
	return ;
}








void	ft_align(t_stack **stack, t_stack *el, char c)
{
	int		i;
	int		index;
	void	(*rotate_me)(t_stack **);
	void	(*reverse_me)(t_stack **);

	if (c == 'a')
	{
		rotate_me = ft_ra;
		reverse_me = ft_rra;
	}
	else
	{
		rotate_me = ft_rb;
		reverse_me = ft_rrb;
	}
	i = -1;
	index = ft_stack_index(*stack, el);
	if (index <= ft_stack_len(*stack) / 2)
		while (++i < index)
			rotate_me(stack);
	else
		while (++i < ft_stack_len(*stack) - index)
			reverse_me(stack);
}
