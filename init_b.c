/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:36:07 by jbremser          #+#    #+#             */
/*   Updated: 2024/03/19 12:28:43 by jbremser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_b(t_node	*a, t_node	*b)
{
	t_node	*curr_a;
	t_node	*curr_b;
	t_node	*target;
	long	best_match;

	curr_b = b;
	while (curr_b)
	{
		best_match = LONG_MAX;
		curr_a = a;
		while (curr_a)
		{
			if ((curr_a->val > curr_b->val) && (curr_a->val < best_match))
			{
				best_match = curr_a->val;
				target = curr_a;
			}
			curr_a = curr_a->next;
		}
		if (best_match == LONG_MAX)
			curr_b->target = find_min(a);
		else
			curr_b->target = target;
		curr_b = curr_b->next;
	}
}

void	min_to_top(t_node **stack)
{
	t_node	*min;

	min = find_min(*stack);
	while (*stack != min)
	{
		if (min->median == 1)
			ra(stack);
		else
			rra(stack);
	}
}

void	init_b(t_node *a, t_node *b)
{
	set_index(a);
	set_index(b);
	set_target_b(a, b);
}
