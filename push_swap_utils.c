/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:41:16 by jbremser          #+#    #+#             */
/*   Updated: 2024/03/19 14:13:44 by jbremser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char	*s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*s == ' ' || *s == '\t' || *s == '\n' || \
	*s == '\r' || *s == '\f' || *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}

t_node	*find_min(t_node	*stack)
{
	t_node	*min;
	t_node	*curr;
	int		i;

	i = INT_MAX;
	if (!stack)
		return (NULL);
	curr = stack;
	while (curr)
	{
		if (curr->val <= i)
		{
			i = curr->val;
			min = curr;
			curr = curr->next;
		}
		else
			curr = curr->next;
	}
	return (min);
}

t_node	*find_max(t_node	*stack)
{
	t_node	*max;
	t_node	*curr;
	int		i;

	i = INT_MIN;
	if (!stack)
		return (NULL);
	curr = stack;
	while (curr)
	{
		if (curr->val >= i)
		{
			i = curr->val;
			max = curr;
			curr = curr->next;
		}
		else
			curr = curr->next;
	}
	return (max);
}

t_node	*find_last(t_node	*stack)
{
	t_node	*temp;

	if (!stack)
		return (NULL);
	temp = stack;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

int	stack_len(t_node *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
