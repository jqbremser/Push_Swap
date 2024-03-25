/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:21:11 by jbremser          #+#    #+#             */
/*   Updated: 2024/03/25 16:21:05 by jbremser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_node	**src, t_node	**dst)
{
	t_node	*push_node;

	if (!*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (!*dst)
	{
		*dst = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dst;
		push_node->next->prev = push_node;
		*dst = push_node;
	}
}

void	pa(t_node	**a, t_node	**b)
{
	push(b, a);
	ft_printf("pa\n");
}

void	pb(t_node	**a, t_node	**b)
{
	push(a, b);
	ft_printf("pb\n");
}
