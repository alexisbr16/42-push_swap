/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print-tool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:04:30 by abrisse           #+#    #+#             */
/*   Updated: 2022/06/30 10:04:44 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * UTILS FOR ME
 */

void	ft_print_stack(t_stack *stack, char *name)
{
	while (stack)
	{
		ft_printf(" %d\t -> %d\n", stack->value, stack->index);
		stack = stack->next;
	}
	ft_printf(" -\n %s\n\n", name);
	return ;
}

void	ft_print(t_stack *a, t_stack *b)
{
	ft_printf("\n");
	while (a || b)
	{
		if (a)
		{
			ft_printf(" %4d\t", a->value);
			a = a->next;
		}
		else
			ft_printf(" \t");
		if (b)
		{
			ft_printf(" %4d", b->value);
			b = b->next;
		}
		ft_printf("\n");
	}
	ft_printf("-----\t-----\n  a\t  b\n");
	ft_printf("\n");
	return ;
}

void	ft_print_index(t_stack *a, t_stack *b)
{
	ft_printf("\n");
	ft_printf("index\n-------------\n");
	while (a || b)
	{
		if (a)
		{
			ft_printf(" %4d\t", a->index);
			a = a->next;
		}
		else
			ft_printf(" \t");
		if (b)
		{
			ft_printf(" %4d", b->index);
			b = b->next;
		}
		ft_printf("\n");
	}
	ft_printf("-----\t-----\n  a\t  b\n");
	ft_printf("\n");
	return ;
}

void	ft_print_position(t_stack *a, t_stack *b)
{
	ft_printf("\n");
	ft_printf("position\n-------------\n");
	while (a || b)
	{
		if (a)
		{
			ft_printf(" %4d\t", a->pos);
			a = a->next;
		}
		else
			ft_printf(" \t");
		if (b)
		{
			ft_printf(" %4d", b->pos);
			b = b->next;
		}
		ft_printf("\n");
	}
	ft_printf("-----\t-----\n  a\t  b\n");
	ft_printf("\n");
	return ;
}

void	ft_print_target_a(t_stack *b)
{
	ft_printf("\n");
	ft_printf("target_a\n-------------\n");
	while (b)
	{
		ft_printf(" %4d", b->target_to_a);
		b = b->next;
		ft_printf("\n");
	}
	ft_printf("-----\n  b\n");
	ft_printf("\n");
	return ;
}

void	ft_print_labor_in_a(t_stack *b)
{
	ft_printf("\n");
	ft_printf("moves in a\n-------------\n");
	while (b)
	{
		ft_printf(" %4d", b->moves_in_a);
		b = b->next;
		ft_printf("\n");
	}
	ft_printf("-----\n  b\n");
	ft_printf("\n");
	return ;
}

void	ft_print_labor_in_b(t_stack *b)
{
	ft_printf("\n");
	ft_printf("moves in b\n-------------\n");
	while (b)
	{
		ft_printf(" %4d", b->moves_in_b);
		b = b->next;
		ft_printf("\n");
	}
	ft_printf("-----\n  b\n");
	ft_printf("\n");
	return ;
}
