/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:24:34 by jbremser          #+#    #+#             */
/*   Updated: 2024/02/23 16:22:59 by jbremser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "LibFT/libft.h"

typedef struct node 
{
	int val;
	int index;
	struct node	*next;
	struct node *prev;
	struct node *target_node;

} t_node;

void    print_stack(t_node 	*stack);
int		error_syntax(char	*str);
void	free_stack(t_node	**stack);
void 	free_error(t_node	**stack);
int		error_dup(t_node *stack, int n);
long	ft_atol(const char	*s);
int		check_sort(t_node	**stack);






#endif // pushswap_h
