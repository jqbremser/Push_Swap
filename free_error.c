/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:02:28 by jbremser          #+#    #+#             */
/*   Updated: 2024/03/19 12:19:01 by jbremser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_args(char **av, int split)
{
	int	i;

	i = 0;
	if (split == 1)
	{
		while (av[i])
			free(av[i++]);
		free(av);
	}
	write(2, "Error\n", 6);
	exit(1);
}

void	free_stack(t_node	**stack)
{
	t_node	*temp;
	t_node	*curr;

	if (!stack)
		return ;
	curr = *stack;
	temp = NULL;
	while (curr)
	{
		temp = curr->next;
		curr->val = 0;
		free(curr);
		curr = temp;
	}
	*stack = NULL;
}

bool	error_syntax(char	*str)
{
	if (!(str[0] == '+' || str[0] == '-' || (str[0] >= '0' && str[0] <= '9')))
		return (true);
	if ((str[0] == '+' || str[0] == '-') && (!(str[1] >= '0' && str[1] <= '9')))
		return (true);
	while (*++str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (true);
	}
	return (false);
}

bool	error_dup(char **av, int n)
{
	int	i;
	int	dup;

	i = 0;
	dup = 0;
	if (!av)
		return (true);
	while (av[i])
	{
		if (ft_atol(av[i]) == n)
		{
			dup++;
			if (dup != 1)
				return (true);
		}
		i++;
	}
	return (0);
}

// void	error_n_exit(char **arguments, int split_flag)
// {
// 	if (split_flag)
// 		free_split(arguments);
// 	write(2, "Error\n", 6);
// 	exit (1);
// }