/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 12:44:03 by abrisse           #+#    #+#             */
/*   Updated: 2022/06/30 14:18:10 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_to_a;
	int				moves_in_a;
	int				moves_in_b;
	struct s_stack	*next;
}	t_stack;

/* parsing.c */
int		ft_get_args(int ac, char **av, t_stack **stack);

/* utils-stack.c */
t_stack	*ft_stacknew(int value);
int		ft_stackfree(t_stack *stack);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
t_stack	*ft_stacklast(t_stack *stack);

/* utils-stack2.c */
int		ft_stack_len(t_stack *stack);
t_stack	*ft_stack_max(t_stack *stack);
t_stack	*ft_stack_min(t_stack *stack);

/* check_and_fix.c */
int		ft_is_sort_not_align(t_stack *stack);
int		ft_is_sort(t_stack *stack);
void	ft_align(t_stack **stack, t_stack *el);

/* sorting.c */
void	ft_sort_three(t_stack **stack);
void	ft_sort(t_stack **stack_a, t_stack **stack_b);
void	ft_push_first_half(t_stack **stack_a, t_stack **stack_b);
void	ft_do_sort(t_stack **a, t_stack **b);

/* sorting2.c */
void	ft_find_target(t_stack **a, t_stack **b);
int		ft_find_best_target(t_stack **a, int test, int target);
void	ft_find_moves(t_stack **a, t_stack **b); //find_labor

/* sorting3.c */
void	ft_move(t_stack **a, t_stack **b);
void	ft_best_operations(t_stack **a, t_stack **b, int moves_in_a,
			int moves_in_b);
void	ft_moves_positive(t_stack **a, t_stack **b, int *moves_in_a,
			int *moves_in_b);
void	ft_moves_negative(t_stack **a, t_stack **b, int *moves_in_a,
			int *moves_in_b);
void	ft_end_moves(t_stack **stack, int *moves, char who);

/* utils.c */
long	ft_abs(int nb);
void	ft_get_index(t_stack *stack, int ac);
void	ft_get_position(t_stack **stack);
char	**free_split(char **str);

/* operations-swap.c */
int		ft_swap(t_stack **stack);
void	ft_sa(t_stack **a);
void	ft_sb(t_stack **b);
void	ft_ss(t_stack **a, t_stack **b);

/* operations-rotate.c */
void	ft_rotate(t_stack **stack);
void	ft_ra(t_stack **a);
void	ft_rb(t_stack **b);
void	ft_rr(t_stack **a, t_stack **b);

/* operations-reverse_rotate.c */
void	ft_reverse_rotate(t_stack **stack);
void	ft_rra(t_stack **a);
void	ft_rrb(t_stack **b);
void	ft_rrr(t_stack **a, t_stack **b);

/* operations-push.c */
int		ft_push(t_stack **src, t_stack **dst);
void	ft_pa(t_stack **a, t_stack **b);
void	ft_pb(t_stack **a, t_stack **b);

/* print-tool.c */
void	ft_print_stack(t_stack *stack, char *name);
void	ft_print(t_stack *a, t_stack *b);
void	ft_print_index(t_stack *a, t_stack *b);
void	ft_print_position(t_stack *a, t_stack *b);
void	ft_print_target_a(t_stack *b);
void	ft_print_labor_in_a(t_stack *b);
void	ft_print_labor_in_b(t_stack *b);

#endif
