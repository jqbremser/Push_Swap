/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:17:13 by jbremser          #+#    #+#             */
/*   Updated: 2024/02/12 12:59:47 by jbremser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *find_end(t_node *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_node *add_end(t_node *stack, int par)
{
	t_node *last_node;
	t_node *pre_node;

	last_node = NULL;
	last_node = (t_node *)malloc(sizeof(t_node));
	if (last_node == NULL)
		return (NULL);
	last_node->val = par;
	last_node->next = NULL;
	if (!stack)
		stack = last_node;
	else
	{
		pre_node = find_end(stack);
		pre_node->next = last_node;
	}
	return (stack);
}

void	*pull_stack(int argc, char	**argv, t_node	*stack)
{
	if (argc > 2)
	{
		int i;

		i = 1;
		while (argv[i])
		{
			//stack->val = atoi(argv[i]);  unnecessary because of next line
			add_end(stack, atoi(argv[i])); //add argv info to val in the stack structure
			i++;
		}
	}
	else
	{
		add_end(stack, atoi(split(argv))); // write this correctly
	}
}