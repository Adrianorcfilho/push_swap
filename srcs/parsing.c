/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha- <adrocha-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 19:47:13 by adrocha           #+#    #+#             */
/*   Updated: 2025/08/17 17:22:35 by adrocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_valid_number(char *str)
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

static int	is_int_range(char *str)
{
	long	c;

	c = ft_atol(str);
	return (c >= INT_MIN && c <= INT_MAX);
}

static void	has_duplicates(t_stack *stack)
{
	t_node	*current;
	t_node	*checker;

	current = stack->first;
	while (current)
	{
		checker = current->next;
		while (checker)
		{
			if (current->value == checker->value)
				free_error_exit(stack, NULL);
			checker = checker->next;
		}
		current = current->next;
	}
}

static void	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->first)
	{
		free_stack(stack);
		exit(0);
	}
	current = stack->first;
	while (current->next)
	{
		if (current->value > current->next->value)
			return ;
		current = current->next;
	}
	free_stack(stack);
	exit(0);
}

void	parse_arguments(t_stack *stack, int argc, char **av)
{
	char	**args;
	int		i;
	int		j;
	long	value;

	i = 1;
	while (i < argc)
	{
		args = ft_split(av[i], ' ');
		if (!args || args[0] == NULL)
			free_error_exit(stack, args);
		j = -1;
		while (args[++j])
		{
			if (!is_valid_number(args[j]) || !is_int_range(args[j]))
				free_error_exit(stack, args);
			value = ft_atol(args[j]);
			if (!add_to_stack(stack, (int)value))
				free_error_exit(stack, args);
		}
		free_args(args);
		i++;
	}
	has_duplicates(stack);
	is_sorted(stack);
}
