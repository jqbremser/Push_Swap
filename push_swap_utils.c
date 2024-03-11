/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:20:33 by jbremser          #+#    #+#             */
/*   Updated: 2024/03/04 14:29:22 by jbremser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char	*s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*s == ' ' || *s == '\t' || *s == '\n'|| \
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
// int	stack_len(t_node *stack)
// {
// 	int n;
	
// 	if (!stack)
// 		return (0);
// 	n = 0;
	// temp = stack;
// 	while (stack)	
	// t_node *temp;
		
// }


int stack_len(t_node *stack)
{
	int n;

	if (!stack)
		return (0);
	n = 0;
	while (stack)
	{
		stack = stack->next;
		n++;
	}
	return (n);
}

int	check_sort(t_node	*stack)
{
	if (!stack)
		return (2);
	while (stack->next)
	{
		if (stack->val > stack->next->val)
			return (0);
		stack = stack->next;	
	}
	return(1);
}

t_node	*goto_last(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}
