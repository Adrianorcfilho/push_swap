/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha <adrocha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 19:47:13 by adrocha           #+#    #+#             */
/*   Updated: 2025/07/29 20:09:31 by adrocha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	is_int_range(char *str)
{
	long	c;

	c = ft_atol(str);
	if (c >= INT_MIN && c <= INT_MAX)
		return (1);
	exit (free, 0); // arrumar o free;
}

int	has_duplicates(t_node *stack)
{
	t_node	*current;
	t_node	*checker;

	current = stack;
	while (current)
	{
		checker = current->next;
		while (checker)
		{
			if (current->value == checker->value)
				return (1);
			checker = checker->next;
		}
		current = current->next;
	}
	return (0);
}

int	add_to_stack(t_node **stack, int value)
{
	t_node	*new;
	t_node	*last;

	new = malloc(sizeof(t_node));
	if (!new)
		return (0);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	if (!*stack)
		*stack = new;
	else
	{
		last = *stack;
		while (last->next)
			last = last->next;
		last->next = new;
	}
	return (1);
}

int	parse_arguments(t_node **stack, int argc, char **argv)
{
	char **args;
	int i;

	while ()
	{
		args = ft_split(argv, argc - 1);
	}

	i = 0;
	if (!args)
		return (0);
	while (args[i])
	{
		if (!is_valid_number(args[i]) || !is_int_range(args[i]))
			return (free_args(args), 0);
		if (!add_to_stack(stack, ft_atoi(args[i])))
			return (free_args(args), 0);
		i++;
	}
	if (has_duplicates(*stack))
		return (free_args(args), 0);
	free_args(args);
	return (1);
}
