/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha <adrocha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 19:47:13 by adrocha           #+#    #+#             */
/*   Updated: 2025/08/05 21:51:45 by adrocha          ###   ########.fr       */
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
	return (c >= INT_MIN && c <= INT_MAX);
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
	t_node	*head;
	t_node	*last;

	head = malloc(sizeof(t_node));
	if (!head)
		return (0);
	head->value = value;
	head->index = -1;
	head->next = NULL;
	head->prev = NULL;
	if (!*stack)
		*stack = head;
	else
	{
		last = *stack;
		while (last->next)
			last = last->next;
		last->next = head;
		head->prev = last;
	}
	return (1);
}

int	parse_arguments(t_node **stack, int argc, char **av)
{
	char	**args;
	int		i;
	int		j;
	long	value;

	i = 1;
	while (i < argc)
	{
		args = ft_split(av[i], ' ');
		if (!args)
			free_error_exit(stack, NULL);
		j = 0;
		while (args[j])
		{
			if (!is_valid_number(args[j]) || !is_int_range(args[j]))
				free_error_exit(stack, args);
			value = ft_atol(args[j]);
			if (!add_to_stack(stack, (int)value))
				free_error_exit(stack, args);
			j++;
		}
		free_args(args);
		i++;
	}
	if (has_duplicates(*stack))
		free_error_exit(stack, args);
	return (1);
}
