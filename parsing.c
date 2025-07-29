/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha <adrocha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 19:47:13 by adrocha           #+#    #+#             */
/*   Updated: 2025/07/29 21:14:11 by adrocha          ###   ########.fr       */
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
	free_error_exit(stack, args);
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
				free_error_exit(stack, args);
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
		free_error_exit();
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
	char	**args;
	int		i;

	i = 0;
	if (!args)
		return (0);
	while (args[i])
	{
		args[i] = ft_split(argv[i], argc - 1);
		if (!args[i])
			free_error_exit(stack, args);
				// corrigir e colocar variaveis corretas
		is_valid_number(args[i])
			free_error_exit(stack, args);
		is_int_range(args[i])
			free_error_exit(stack, args);
		if (!add_to_stack(stack, ft_atol(args[i])))
			;
		i++;
	}
	if (has_duplicates(*stack))
	free_args(args);
	return (1);
}
