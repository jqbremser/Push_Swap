/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:12:50 by jbremser          #+#    #+#             */
/*   Updated: 2024/03/07 17:22:01 by jbremser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
 void    push(t_node	**src, t_node	**dst)
{
    t_node    *push_node;

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

void	pa(t_node	**a, t_node		**b, bool print)
{
	push(b, a);
	if (!print)
		ft_printf("pa\n");
}
void	pb(t_node	**a, t_node		**b, bool print)
{
	push(a, b);
	if (!print)
		ft_printf("pb\n");
}
// void	push(t_node	**src, t_node	**dst)
// {
// 	if (!*src /*|| !(*src)->next*/)
// 		return ;
// 	if (!*dst)
// 	{
// 		(*src)->next->prev = NULL;
// 		//src->next->prev = NULL; (same in both conditions)
// 		(*dst) = (*src);
// 		(*src) = (*src)->next;
// 		(*dst)->next = NULL;	
// 	}
// 	else if (*dst)
// 	{
// 		//(*src)->next->prev = NULL;  //causes a seg fault
// 		(*dst)->prev = (*src);
// 		(*src) = (*src)->next;
// 		(*dst)->prev->next = (*dst);
// 		(*dst) = (*dst)->prev;
// 	}
// }