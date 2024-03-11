/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:41:18 by jbremser          #+#    #+#             */
/*   Updated: 2024/03/07 17:50:48 by jbremser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rev_rotate(t_node	**stack)
{
	t_node *last_node;
	
	if (!*stack || (*stack)->next == NULL)
		return ;
	last_node = goto_last(*stack);
	last_node->next = *stack;
	last_node->prev = NULL;
	(*stack)->next->next = NULL;
	(*stack)->prev = last_node;
	//print_stack(*stack);
	(*stack) = last_node;
	//ft_printf("after rotate:");
	//print_stack(*stack);

}

//  void	rev_rotate(t_node **stack) //Define a funtion that rotates a stack's bottom node, to the top
// {
// 	t_node	*last; //To store the pointer to the last node

// 	if (!*stack || !(*stack)->next) //Check if the stack is empty, or if there's one node
// 		return ;
// 	last = goto_last(*stack);
// 	last->prev->next = NULL; //Assign to the `next` attribute of the node before itself, `NULL` effectively setting it as the current last node
// 	last->next = *stack; //Assign to its own `next` attribute as the top node of the stack
// 	last->prev = NULL; //Detach itself from the node before it
// 	*stack = last;  //Complete appending itself to the top of the stack, and now holds the pointer to the top node
// 	last->next->prev = last; //Update the current last node of the stack
//  	//print_stack(*stack);
// }

void	rra(t_node	**a, bool print)
{
	rev_rotate(a);
	if (!print)
		ft_printf("rra\n");
}

void	rrb(t_node	**b, bool print)
{
	rev_rotate(b);
	if (!print)
		ft_printf("rrb\n");
}

void	rrr(t_node	**a, t_node	**b, bool print)
{
	rev_rotate(a);
	rev_rotate(b);
	if (!print)
		ft_printf("rrr\n");
}