/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:09:45 by jbremser          #+#    #+#             */
/*   Updated: 2024/03/21 11:58:17 by jbremser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	check_sort(t_node	*stack)
{
	if (!stack)
		return (false);
	while (stack->next)
	{
		if (stack->val > stack->next->val)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	sort_time(t_node **a)
{
	t_node	*b;

	b = NULL;
	if (!(check_sort(*a)))
	{
		if (stack_len(*a) == 2)
			sa(a);
		if (stack_len(*a) == 3)
			sort_three(a);
		if (stack_len(*a) == 4 || stack_len(*a) == 5)
			sort_f(a, &b);
		else if (stack_len(*a) > 5)
			main_sort(a, &b);
	}
	else
	{
		free_stack(a);
		exit(0);
	}
}

void	sort_three(t_node **stack)
{
	t_node	*max;

	max = find_max(*stack);
	if (max == *stack)
		ra(stack);
	else if (max == (*stack)->next)
		rra(stack);
	if (!(check_sort(*stack)))
		sa(stack);
}

void	sort_f(t_node	**a, t_node	**b)
{
	t_node	*min;

	while (stack_len(*a) > 3)
	{
		min = find_min(*a);
		set_index(*a);
		move_to_top(a, min, 'a');
		pb(a, b);
	}
	sort_three(a);
	while (*b)
		pa(a, b);
}

void	main_sort(t_node	**a, t_node	**b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !check_sort(*a))
		pb(a, b);
	if (len_a-- > 3 && !check_sort(*a))
		pb(a, b);
	while (len_a-- > 3 && !check_sort(*a))
	{
		init_a(*a, *b);
		push_a_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_b(*a, *b);
		push_b_a(a, b);
	}
	set_index(*a);
	min_to_top(a);
}
