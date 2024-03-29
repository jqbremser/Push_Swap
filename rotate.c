/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:24:12 by jbremser          #+#    #+#             */
/*   Updated: 2024/03/19 12:35:13 by jbremser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_node	**stack)
{
	t_node	*temp;
	t_node	*last;

	if (!*stack || (*stack)->next == (NULL))
		return ;
	last = find_last(*stack);
	temp = (*stack)->next;
	temp->prev = (NULL);
	(*stack)->next = (NULL);
	(*stack)->prev = last;
	last->next = (*stack);
	(*stack) = temp;
}

void	ra(t_node	**a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_node	**b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_node	**a, t_node	**b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}

void	rotate_a_b(t_node	**a, t_node	**b, t_node	*cheap_node)
{
	while ((*b != cheap_node->target) && (*a != cheap_node))
		rr(a, b);
	set_index(*a);
	set_index(*b);
}
