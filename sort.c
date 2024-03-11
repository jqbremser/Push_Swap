/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:25:02 by jbremser          #+#    #+#             */
/*   Updated: 2024/03/11 13:04:39 by jbremser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*min_node(t_node	*stack)
{
	int n;
	t_node *curr;
	t_node *min;

	n = INT_MAX;
	if (!stack)
		return (NULL);
	curr = stack;
	while (curr)
	{
		if (curr->val <= n)
		{
			n = curr->val;
			min = curr;
			curr = curr->next;
		}
		else
			curr = curr->next;
	}
	return (min);
}

t_node	*max_node(t_node	*stack)
{
	int n;
	t_node *curr;
	t_node *max;

	n = INT_MIN;
	if (!stack)
		return (NULL);
	curr = stack;
	while (curr)
	{
		if (curr->val >= n)
		{
			n = curr->val;
			max = curr;
			// ft_printf("%d\n", n);
			curr = curr->next;
		}
		else
			curr = curr->next;
	}
	return (max);
}

// void	sort_three(t_node **stack) //Define a function that handles when stack `a` has three nodes, and sorts it
// {
// 	t_node	*biggest_node; //To store a pointer to the biggest node in stack `a`

// 	biggest_node = find_max(*stack);
// 	if (biggest_node == *stack) //Check if the current node is the biggest
// 		ra(stack, false); //If so, rotate the top node to the bottom of the stack
// 	else if ((*stack)->next == biggest_node) //Check if the second node is the biggest
// 		rra(stack, false); //If so, reverse rotate the bottom node, to the top of the stack
// 	if ((*stack)->nbr > (*stack)->next->nbr) //Check if the bottom node is the biggest, but the top node is higher than the second node
// 		sa(stack, false); //If so, simply swap the top and second nodes
// }
void	sort_three(t_node	**stack)
{
	t_node	*max;

	max = max_node(*stack);
	if (max == goto_last(*stack))
	{
		if ((*stack)->val > (*stack)->next->val) // 2 1 3
			sa(stack, false);
	}
	else if (max == (*stack))
	{
		if ((*stack)->next->val > (*stack)->next->next->val) // 3 2 1
		{
			sa(stack, false);
			rra(stack, false);
		}
		else // 3 1 2
			ra(stack, false);
	}
	else 
	{
		if ((*stack)->val < (*stack)->next->next->val) // 1 3 2
		{
			rra(stack, false);
			sa(stack, false);
		}
		else // 2 3 1
			rra(stack, false);
	}
}
void	push_a_b(t_node **a, t_node **b)
{
	t_node	*cheap_node;
	
	cheap_node = get_cheap(*a);
	if ((cheap_node->median == 1) && (cheap_node->target->median = 1)) // cheap 'a' node and its target are both above median:
		rotate_a_b(a, b, cheap_node);
	else if ((cheap_node->median == 0) && (cheap_node->target->median = 0)) 
		revrotate_b_a(a, b, cheap_node); //executes when neither node is at the top
	prep_push(a, cheap_node, 'a');
	prep_push(b, cheap_node->target, 'b');
	pb(a, b, false);
}
void	rotate_a_b(t_node	**a, t_node	**b, t_node	*cheap_node)
{
	while ((*b != cheap_node->target) && (*a != cheap_node))
		rr(a, b, false); // rotate until cheap node is at top of a, and its target is at top of b
	set_index(*a); //reset node positions
	set_index(*b);
}
void	revrotate_b_a(t_node	**a, t_node	**b, t_node	*cheap_node)
{
	while ((*b != cheap_node->target) && (*a != cheap_node))
		rrr(a, b, false); 
	set_index(*a); 
	set_index(*b);
}

void	push_b_a(t_node **a, t_node **b)
{
	prep_push(a, (*b)->target, 'a');
	pa(a, b, false);
}

void	prep_push(t_node **stack, t_node *top, char a_b)
{
	if (*stack != top)
	{
		if (a_b == 'a')
			{
				if (top->median == 1)
					ra(stack, false);
				else
					rra(stack, false);	
			}
		else if (a_b == 'b')
		{
				if (top->median == 1)
					rb(stack, false);
				else
					rrb(stack, false);	
		}	
	}
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


void	main_sort(t_node	**a, t_node	**b)
{
	int	a_len;

	a_len = stack_len(*a);
	if (a_len-- > 3 && !check_sort(*a)) //'a' has more than three nodes and aren't stored
		pb(a, b, false);
	if (a_len-- > 3 && !check_sort(*a)) //'a' still has more than three nodes and aren't stored
		pb(a, b, false);
	while (a_len-- > 3 && !check_sort(*a))
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
	check_top_min(a);
}

