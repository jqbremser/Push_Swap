/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:12:18 by jbremser          #+#    #+#             */
/*   Updated: 2024/02/27 10:24:30 by jbremser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node	**stack)
{
	if (!*stack || !(*stack)->next)
		return ;
	*stack = (*stack)->next; //#1
	(*stack)->prev->prev = *stack; //#2
	(*stack)->prev->next = (*stack)->next; //*3
	if ((*stack)->next)
		(*stack)->next->prev = (*stack)->prev; //#3a
	(*stack)->next = (*stack)->prev; //#4
	(*stack)->prev = NULL; //#5
}	

void	sa(t_node	**a, bool print)
{
	swap(a);
	if(!print)
		ft_printf("sa\n");
}

void	sb(t_node	**b, bool print)
{
	swap(b);
	if(!print)
		ft_printf("sb\n");
}
void	ss(t_node	**a, t_node	**b, bool print)
{
	swap(a);
	swap(b);
	if (!print)
		ft_printf("ss\n");
	
}


// void	swap(t_node	**stack)
// {
// 	t_node	*temp;

// 	if (!*stack || !(*stack)->next)
// 		return ;
// 	temp = *stack;
// 	*temp = *temp->next; //#1
// 	*temp->prev->prev = *temp; //#2
// 	*temp->prev->next = *temp->next; //*3
// 	if ((*temp).next)
// 		*temp->next->prev = *temp->prev; //#3a
// 	*temp->next = *temp->prev; //#4
// 	temp->prev = NULL; //#5
// }	



	
// 	temp2 = temp1->next;
// 	temp2->next->prev = temp1;
// 	temp2->next = temp1;
// 	temp2->prev = NULL;
// 	temp1->next = temp2->next->next;
// 	temp1->prev = temp2;
// 	return ;
	

	
// }