/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:23:49 by jbremser          #+#    #+#             */
/*   Updated: 2024/03/21 11:32:27 by jbremser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_node	**stack)
{
	if (!*stack || !(*stack)->next)
		return ;
	*stack = (*stack)->next;
	(*stack)->prev->prev = *stack;
	(*stack)->prev->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = (NULL);
}

void	sa(t_node	**a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_node	**b)
{
	swap(b);
	ft_printf("sa\n");
}

void	ss(t_node	**a, t_node	**b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
