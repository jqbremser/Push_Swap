/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:37:37 by jbremser          #+#    #+#             */
/*   Updated: 2024/03/25 15:50:37 by jbremser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_node
{
	int				val;
	int				index;
	int				median;
	int				push;
	bool			cheapest;
	struct s_node	*next;
	struct s_node	*prev;
	struct s_node	*target;
}	t_node;

/* ************************************************************************** */
/*								wack_into_a									  */
/* ************************************************************************** */
void	wack_into_a(int argc, char **argv, t_node **a);

/* ************************************************************************** */
/*								free_error									  */
/* ************************************************************************** */
bool	error_syntax(char	*str);
bool	error_dup(char **av, int n);
void	free_args(char **av, int split);
void	free_stack(t_node	**stack);

/* ************************************************************************** */
/*									sort									  */
/* ************************************************************************** */
void	sort_time(t_node **a);
void	sort_three(t_node **stack);
void	sort_f(t_node	**a, t_node	**b);
void	main_sort(t_node	**a, t_node	**b);

/* ************************************************************************** */
/*								push_swap_utils								  */
/* ************************************************************************** */
long	ft_atol(const char	*s);
t_node	*find_last(t_node *stack);
int		stack_len(t_node *stack);
t_node	*find_max(t_node *stack);
t_node	*find_min(t_node *stack);

/* ************************************************************************** */
/*									push									  */
/* ************************************************************************** */
void	pa(t_node	**a, t_node	**b);
void	pb(t_node	**a, t_node	**b);

/* ************************************************************************** */
/*									swap									  */
/* ************************************************************************** */
void	sa(t_node	**a);
void	sb(t_node	**b);
void	ss(t_node	**a, t_node	**b);

/* ************************************************************************** */
/*									rotate									  */
/* ************************************************************************** */
void	ra(t_node	**a);
void	rb(t_node	**b);
void	rr(t_node	**a, t_node	**b);
void	rotate_a_b(t_node	**a, t_node	**b, t_node	*cheap_node);

/* ************************************************************************** */
/*									rev_rotate								  */
/* ************************************************************************** */
void	rra(t_node	**a);
void	rrb(t_node	**b);
void	rrr(t_node	**a, t_node	**b);
void	rev_rotate_a_b(t_node	**a, t_node	**b, t_node	*cheap_node);

/* ************************************************************************** */
/*									set_move								  */
/* ************************************************************************** */
void	set_index(t_node	*stack);
void	set_target(t_node	*a, t_node	*b);
void	push_price(t_node *a, t_node *b);
void	cheap_pick(t_node *a);
t_node	*get_cheap(t_node *stack);

/* ************************************************************************** */
/*									init									  */
/* ************************************************************************** */
void	init_a(t_node *a, t_node *b);
void	move_to_top(t_node	**stack, t_node *top, char stack_name);
void	push_a_b(t_node	**a, t_node	**b);
void	push_b_a(t_node	**a, t_node	**b);
/* ************************************************************************** */
/*									init_b			 						  */
/* ************************************************************************** */
void	init_b(t_node *a, t_node *b);
void	min_to_top(t_node **stack);

#endif // pushswap_h
