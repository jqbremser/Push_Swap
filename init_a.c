/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:32:40 by jbremser          #+#    #+#             */
/*   Updated: 2024/03/07 17:50:37 by jbremser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_a(t_node *a, t_node *b)
{
	set_index(a);
	// ft_printf("b4 index b\n");
	set_index(b);
	set_target(a, b);
	push_price(a, b);
	cheap_pick(a);
	//print_stack(a);
	
	// ft_printf("b4 set target\n");
	//ft_printf("b4 push price\n");
	// ft_printf("b4 index a\n");
//	ft_printf("b4 print a\n");
	// set_cheapest(a);
	// print_stack(a);
	// print_stack(b);

}

void	set_index(t_node *stack)
{
	int i;
	int median;

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
	t_node *curr_b;
	t_node *target;
	long	best_match;
	
	while (a)
	{
		best_match = LONG_MIN;
		curr_b = b;
		while (curr_b)
		{
			if (curr_b->val < a->val && curr_b->val > best_match)
			{
				best_match = curr_b->val; //update best match with closest smallest number
				target = curr_b;
				// ft_printf("target %d\n", a->target);
				// print_stack(b);
			}
			curr_b = curr_b->next; // move to next node for comp
		}
		if (best_match == LONG_MIN) // the val's in b are bigger than all of the A, thus the target is the last node
			a->target = max_node(b);
		else
			a->target = target;
			
		a = a->next;
		// ft_printf("target %d\n", a->val);

	}
}
void	push_price(t_node *a, t_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_cost = a->index;
		// ft_printf("index %d\n", a->index);
		// ft_printf("median %d\n", a->median);
		if (a->median == 0)
			a->push_cost = len_a - (a->index);
		// ft_printf("index %d\n", a->index);
		// ft_printf("push_cost %d\n", a->push_cost);
		if (a->target->median == 1)
			{	
			a->push_cost += (a->target->index);
			// ft_printf("index %d\n", a->index);
			// ft_printf("push_cost %d\n", a->push_cost);
			}
		else // 'a' node is above median and 'b' node is below 		
			a->push_cost += (len_b - (a->target->index));
		a = a->next;	
	}
}
void	cheap_pick(t_node *a)
{
	long	cheap_val;
	t_node *cheap_node;

	if (!a)
		return ;
	cheap_val = LONG_MAX;
	while (a)
	{
		if (a->push_cost < cheap_val)
		{
			cheap_val = a->push_cost;
			cheap_node = a;
		}
		a = a->next;
	}
	cheap_node->cheapest = true;
}

