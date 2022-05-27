/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 12:44:03 by abrisse           #+#    #+#             */
/*   Updated: 2022/05/27 14:36:37 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

/* parsing.c */
int		ft_get_args(int ac, char **av, t_stack **stack);
int		check_number(char *str);
int		check_int(char *str);
int		check_duplicate(t_stack *stack, int value);

/* sorting.c */
int		ft_is_sort(t_stack *stack);
void	ft_sort(t_stack **a, t_stack **b);
void	ft_sort_to_b(t_stack **a, t_stack **b);
void	ft_sort_five(t_stack **a, t_stack **b);

/* sorting-2.c */
void	ft_sort_to_a(t_stack **a, t_stack **b);
int		ft_max_on_top(t_stack *stack);
int		ft_min_on_top(t_stack *stack);
void	ft_align(t_stack **stack);

/* utils.c */
int		ft_free_stack(t_stack **stack);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
t_stack	*ft_stacknew(int number);
t_stack	*ft_stacklast(t_stack *stack);
void	ft_print_stack(t_stack *stack);

/* utils-2.c */
int		ft_count_args(t_stack *stack);
int		ft_count_below(t_stack *stack);

/* operations-swap.c */
int		ft_swap(t_stack **stack);
void	ft_sa(t_stack **a);
void	ft_sb(t_stack **b);
void	ft_ss(t_stack **a, t_stack **b);

/* operations-push.c */
int		ft_push(t_stack **a, t_stack **b);
void	ft_pa(t_stack **a, t_stack **b);
void	ft_pb(t_stack **a, t_stack **b);

/* operations-rotate.c */
void	ft_rotate(t_stack **stack);
void	ft_ra(t_stack **a);
void	ft_rb(t_stack **b);
void	ft_rr(t_stack **a, t_stack **b);

/* operations-reverse.c */
void	ft_reverse_rotate(t_stack **stack);
void	ft_rra(t_stack **a);
void	ft_rrb(t_stack **b);
void	ft_rrr(t_stack **a, t_stack **b);

#endif
