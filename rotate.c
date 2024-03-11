/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:47:38 by jbremser          #+#    #+#             */
/*   Updated: 2024/03/05 10:43:01 by jbremser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate(t_node	**stack)
{
	t_node	*temp;
	t_node	*last_node;
	
	if (!*stack || (*stack)->next == NULL)
		return ;
	last_node = goto_last(*stack);
	temp = (*stack)->next;
	temp->prev = NULL;
	(*stack)->next = NULL;
	(*stack)->prev = last_node;
	last_node->next = *stack;
	(*stack)= temp;
}	

	// last_node->next = *temp;
	// *temp = (*temp)->next;
	// (*temp)->prev = NULL;
	// last_node->next->prev = last_node;
	// //last_node->next = NULL;
	// *stack = last_node;
// void	rotate(t_node **stack) //Define a function that rotates the stack's top node to the bottom of the stack
// {
// 	t_node	*last_node; //To store a pointer to the last node of a stack

// 	if (!*stack || !(*stack)->next) //Check if the stack is empty, or if there's one node
// 		return ;
// 	last_node = goto_last(*stack); 
// 	last_node->next = *stack; //Assign to the last node, its `next` attribute as the top node, effectively setting the current top node as the last node
// 	*stack = (*stack)->next; //Assign to the pointer of the top node, the node after it (second from the top)
// 	(*stack)->prev = NULL; //Complete setting the current top node by detaching it from its previous top node
// 	last_node->next->prev = last_node; //Reconnect the second node's prev pointer to point to what was previously the last node in the stack
// 	last_node->next->next = NULL; //Assign to the `next` attribute of the current last node, `NULL` effectively setting it as the current last node, and properly null terminating the stack
// }	

void	ra(t_node	**a, bool print)
{
	rotate(a);
	if (!print)
		ft_printf("ra\n");
}

void	rb(t_node	**b, bool print)
{
	rotate(b);
	if (!print)
		ft_printf("rb\n");
}

void	rr(t_node	**a, t_node	**b, bool print)
{
	rotate(a);
	rotate(b);
	if (!print)
		ft_printf("rr\n");
}