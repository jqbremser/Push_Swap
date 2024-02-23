/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:17:13 by jbremser          #+#    #+#             */
/*   Updated: 2024/02/23 16:25:21 by jbremser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *find_end(t_node *stack)
{
	t_node *temp;
	
	temp = stack;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

void add_end(t_node **stack, int node_val)
{
	t_node *pre_node;
	t_node *last_node;

	if (!stack)
		return ;
	last_node = (t_node *)malloc(sizeof(t_node));
	if (!last_node)
		return ;
	last_node->next = NULL;
	last_node->val = node_val;
	if (!(*stack)) //in the case of empty stack, we need to find/create the first node
		{
		*stack = last_node;
		last_node->prev = NULL; //set head node to NULL as its first node (and last)
		}
	else //stack is not empty, so we need to add to existing node in LL
	{
		pre_node = find_end(*stack); //Find last node
		pre_node->next = last_node; //append new node(last) to previously last node
		last_node->prev = pre_node; // now last node is sitting under pre_node at the end, and prev backwards through pre_node
	}
	// ft_printf("%d\n", last_node->val);
}

void	add_stack(char	**av, t_node	**stack)
{
	int	i;
	long n;

	i = 0;
	while (av[i])
	{
		if (error_syntax(av[i]) == 1) //check for basic errors
			free_error(stack);			
		n = ft_atol(av[i]); //change to Long int then check below if it is
		if (n < INT_MIN || n > INT_MAX)
			free_error(stack); //free the stack if it is a long and exit
		if (error_dup(*stack, (int)n))
			free_error(stack); //free the stack if there are duplicate args
		add_end(stack, (int)n);
		i++;
	}
}

int    main(int argc, char **argv)
{
    t_node    *a;
    t_node    *b;

    a = NULL;
    b = NULL;
    if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))  
        return (1);
    else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	add_stack(argv + 1, &a);
	if (check_sort(a) = 0
	{
		
	}
	print_stack(a);
    free_stack(&a); //clean up your mess
	return (0);
}

#include <stdio.h>

void    print_stack(t_node *stack)  //DELETE BEFORE SUBMIT
{
    t_node    *ptr;

    ptr = stack;
    
    while (ptr)
    {
        ft_printf("%d\n", ptr->val);
        ptr = ptr->next;
    }
}
			//stack->val = atoi(argv[i]);  unnecessary because of next line
// convert nb to integer with atoi and then put through add_end
		//add_end(stack, ft_atoi(ft_split(argv))); // write this correctly