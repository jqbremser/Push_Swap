/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wack_into_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:41:17 by jbremser          #+#    #+#             */
/*   Updated: 2024/03/21 11:56:04 by jbremser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	add_end(t_node **stack, int val)
{
	t_node	*pre;
	t_node	*last;

	last = (t_node *)malloc(sizeof(t_node));
	if (!last)
		return (0);
	last->next = NULL;
	last->val = val;
	if (!(*stack))
	{
		*stack = last;
		last->prev = NULL;
	}
	else
	{
		pre = find_last(*stack);
		pre->next = last;
		last->prev = pre;
	}
	return (1);
}

static void	add_stack(char	**av, t_node **stack, bool split)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (!add_end(stack, ft_atoi(av[i++])))
		{
			free_stack(stack);
			write(2, "Error\n", 6);
			exit(1);
		}
	}
	if (split == 1)
	{
		i = 0;
		while (av[i])
			free(av[i++]);
		free(av);
	}
}

static void	check_args(char **av, bool split)
{
	int		i;
	long	l;

	i = 0;
	while (av[i])
	{
		l = ft_atol(av[i]);
		if (error_syntax(av[i]) || ft_strlen(av[i]) > 11 || \
			(l < INT_MIN || l > INT_MAX) || error_dup(av, (int)l))
			free_args(av, split);
		i++;
	}
}

void	wack_into_a(int argc, char **argv, t_node **a)
{
	char	**args;
	bool	split;

	split = false;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
			free_args(args, split);
		split = true;
	}
	else
		args = argv + 1;
	check_args(args, split);
	add_stack(args, a, split);
}
