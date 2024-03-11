/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:05:58 by jbremser          #+#    #+#             */
/*   Updated: 2024/03/04 18:06:32 by jbremser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_syntax(char	*str) //handle syntax errors, returns 1 for error
{
	if (!(str[0] == '+' || str[0] == '-' || (str[0] >= '0' && str[0] <= '9')))
		return (1); //first char in str is not a num, +, -
	if ((str[0] == '+' || str[0] == '-') && (!(str[1] >= '0' && str[1] <= '9')))
		return (1); //first char is +,-; but not a number after
	while (*++str)
	{
		if (!(*str >= '0' && *str <= '9')) //prev conditions met: if !digit, error;
			return (1);
	}
	return (0);
}

void free_stack(t_node	**stack)
{
	t_node	*temp; //temp parking node to access next pointer after free 
	t_node	*curr;
	
	if (!stack)
		return ;
	curr = *stack; //temp parking ala GNL
	while (curr)
	{
		temp = curr->next; //assign ptr to next node to temp
		curr->val = 0; //extra protection against leaks
		free(curr);
		curr = temp; //assign temp as the current node
	}
	*stack = NULL;
}

void free_error(t_node	**stack) // error message and free the stack
{
	free_stack(stack);
	ft_printf("Error\n");
	exit(1);
}

int error_dup(t_node *stack, int n) //why only a single *, because we are dealing with the data specifically in one struct
{
	if(!stack)
		return (0);
	while (stack) //loop until end of stack
		{
			if (stack->val == n) //check if val in stack has already been checked
				return (1);
			stack = stack->next; //move to next node and check for duplicates
		}
	return (0);	
}