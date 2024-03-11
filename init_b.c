/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:40:03 by jbremser          #+#    #+#             */
/*   Updated: 2024/03/07 17:49:01 by jbremser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_b(t_node *a, t_node *b)
{
	set_index(a);
	set_index(b);
	set_target_b(a, b);
}

void	set_target_b(t_node *a, t_node *b) //basically oppo of set_target
{
	t_node *curr_a;
	t_node *target;
	long	best_match;
	
	while (b)
	{
		best_match = LONG_MAX;
		curr_a = a;
		while (curr_a)
		{
			if (curr_a->val > a->val && curr_a->val < best_match)
			{
				best_match = curr_a->val;
				target = curr_a;
			}
			curr_a = curr_a->next; // move to next node for comp
		}
		if (best_match == LONG_MAX)
			b->target = min_node(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	check_top_min(t_node **stack) 
{
	while ((*stack)->val != min_node(*stack)->val)
	{
		if (min_node(*stack)->median == 1)
			ra(stack, false);
		else
			rra(stack, false);	
	}
}