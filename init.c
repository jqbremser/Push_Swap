/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:44:00 by jbremser          #+#    #+#             */
/*   Updated: 2024/03/19 12:26:16 by jbremser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_a(t_node *a, t_node *b)
{
	set_index(a);
	set_index(b);
	set_target(a, b);
	push_price(a, b);
	cheap_pick(a);
}

void	move_to_top(t_node	**stack, t_node *top, char stack_name)
{
	while (*stack != top)
	{
		if (stack_name == 'a')
		{
			if (top->median == 1)
				ra(stack);
			else
				rra(stack);
		}
		if (stack_name == 'b')
		{
			if (top->median == 1)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	push_a_b(t_node	**a, t_node	**b)
{
	t_node	*cheap_node;

	cheap_node = get_cheap(*a);
	if ((cheap_node->median == 1) && (cheap_node->target->median == 1))
		rotate_a_b(a, b, cheap_node);
	else if ((cheap_node->median == 0) && (cheap_node->target->median == 0))
		rev_rotate_a_b(a, b, cheap_node);
	move_to_top(a, cheap_node, 'a');
	move_to_top(b, cheap_node->target, 'b');
	pb(a, b);
}

void	push_b_a(t_node	**a, t_node	**b)
{
	move_to_top(a, (*b)->target, 'a');
	pa(a, b);
}
