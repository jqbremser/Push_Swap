/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:46:25 by jbremser          #+#    #+#             */
/*   Updated: 2024/03/19 12:34:07 by jbremser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_node	**stack)
{
	t_node	*last;
	t_node	*bottom;

	if (!*stack || !(*stack)->next)
		return ;
	last = find_last(*stack);
	bottom = last->prev;
	bottom->next = (NULL);
	last->next = *stack;
	last->prev = (NULL);
	(*stack)->prev = last;
	*stack = last;
}

void	rra(t_node	**a)
{
	rev_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_node	**b)
{
	rev_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_node	**a, t_node	**b)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_printf("rrr\n");
}

void	rev_rotate_a_b(t_node	**a, t_node	**b, t_node	*cheap_node)
{
	while ((*b != cheap_node->target) && (*a != cheap_node))
		rrr(a, b);
	set_index(*a);
	set_index(*b);
}
