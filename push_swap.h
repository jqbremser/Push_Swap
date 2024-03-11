/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:24:34 by jbremser          #+#    #+#             */
/*   Updated: 2024/03/07 17:51:00 by jbremser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "LibFT/libft.h"
# include <stdbool.h>

typedef struct s_node 
{
	int val;
	int index;
	int median; // 1 = above 0 = below
	int push_cost;
	bool cheapest; // 1 = cheapest 0 = not cheapest
	struct s_node *target;
	struct s_node	*next;
	struct s_node *prev;
} t_node;

//void    print_stack(t_node 	*stack); //delete me
/* ************************************************************************** */
/*							Error_Handling									  */
/* ************************************************************************** */
int		error_syntax(char	*str);
void	free_stack(t_node	**stack);
void 	free_error(t_node	**stack);
int		error_dup(t_node *stack, int n);
/* ************************************************************************** */
/*							Push_Swap_Utils									  */
/* ************************************************************************** */
long	ft_atol(const char	*s);
int		stack_len(t_node *stack);
int		check_sort(t_node	*stack);
t_node	*goto_last(t_node *stack);

/* ************************************************************************** */
/*									Swap									  */
/* ************************************************************************** */
void	swap(t_node	**stack);
void	sa(t_node	**a, bool print);
void	sb(t_node	**b, bool print);
void	ss(t_node	**a, t_node	**b, bool print);
/* ************************************************************************** */
/*									Rotate									  */
/* ************************************************************************** */
void 	rotate(t_node	**stack);
void	ra(t_node	**a, bool print);
void	rb(t_node	**b, bool print);
void	rr(t_node	**a, t_node	**b, bool print);
/* ************************************************************************** */
/*									Reverse_Rotate							  */
/* ************************************************************************** */
void rev_rotate(t_node	**stack);
void	rra(t_node	**a, bool print);
void	rrb(t_node	**b, bool print);
void	rrr(t_node	**a, t_node	**b, bool print);
/* ************************************************************************** */
/*									sort									  */
/* ************************************************************************** */
void	sort_three(t_node	**stack);	
t_node	*max_node(t_node	*stack);
t_node	*min_node(t_node	*stack);
void	main_sort(t_node	**a, t_node	**b);
void	push_a_b(t_node **a, t_node **b);
void	rotate_a_b(t_node	**a, t_node	**b, t_node	*cheap_node);
void	revrotate_b_a(t_node	**a, t_node	**b, t_node	*cheap_node);
void	prep_push(t_node **stack, t_node *top, char a_b);
t_node	*get_cheap(t_node *stack);
void	push_b_a(t_node **a, t_node **b);
/* ************************************************************************** */
/*									push									  */
/* ************************************************************************** */
void	push(t_node	**src, t_node	**dst);
void	pa(t_node	**a, t_node		**b, bool print);
void	pb(t_node	**a, t_node		**b, bool print);
/* ************************************************************************** */
/*									init_a									  */
/* ************************************************************************** */
void	init_a(t_node *a, t_node *b);
void	set_index(t_node *stack);
void	set_target(t_node *a, t_node *b);
void	push_price(t_node *a, t_node *b);
void	set_cheapest(t_node *stack);
void	cheap_pick(t_node *a);
/* ************************************************************************** */
/*									init_b									  */
/* ************************************************************************** */
void	init_b(t_node *a, t_node *b);
void	set_target_b(t_node *a, t_node *b);
void	check_top_min(t_node **stack);

#endif // pushswap_h
