/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:41:54 by jbremser          #+#    #+#             */
/*   Updated: 2024/03/19 12:37:00 by jbremser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_node	*stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->median = 1;
		else
			stack->median = 0;
		stack = stack->next;
		i++;
	}
}

void	set_target(t_node *a, t_node *b)
{
	t_node	*curr_a;
	t_node	*curr_b;
	t_node	*target;
	long	match;

	curr_a = a;
	while (curr_a)
	{
		match = LONG_MIN;
		curr_b = b;
		while (curr_b)
		{
			if (curr_b->val > match && (curr_b->val < curr_a->val))
			{
				match = curr_b->val;
				target = curr_b;
			}
			curr_b = curr_b->next;
		}
		if (match == LONG_MIN)
			curr_a->target = find_max(b);
		else
			curr_a->target = target;
		curr_a = curr_a->next;
	}
}

void	push_price(t_node *a, t_node *b)
{
	int		len_a;
	int		len_b;
	int		diff;
	t_node	*curr_a;

	len_a = stack_len(a);
	len_b = stack_len(b);
	diff = 0;
	curr_a = a;
	while (curr_a)
	{
		if (curr_a->median)
			curr_a->push = curr_a->index;
		if (curr_a->median == 0)
			curr_a->push = len_a - curr_a->index;
		if (curr_a->target->median)
			curr_a->push += curr_a->target->index;
		else
		{
			diff = len_b - curr_a->target->index;
			curr_a->push += diff;
		}
		curr_a = curr_a->next;
	}
}

void	cheap_pick(t_node *a)
{
	long	cheap_val;
	t_node	*cheap_node;

	if (!a)
		return ;
	cheap_val = LONG_MAX;
	while (a)
	{
		if (a->push < cheap_val)
		{
			cheap_val = a->push;
			cheap_node = a;
		}
		a = a->next;
	}
	cheap_node->cheapest = true;
}

t_node	*get_cheap(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
