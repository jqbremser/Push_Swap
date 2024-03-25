/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:37:20 by jbremser          #+#    #+#             */
/*   Updated: 2024/03/21 16:42:06 by jbremser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;

	a = NULL;
	if (argc == 1)
		return (1);
	if (argc == 2 && argv[1][0] == '\0')
	{
		write(2, "Error\n", 6);
		return (1);
	}
	wack_into_a(argc, argv, &a);
	sort_time(&a);
	free_stack(&a);
}
