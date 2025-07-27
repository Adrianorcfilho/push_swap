/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha <adrocha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 21:19:08 by adrocha           #+#    #+#             */
/*   Updated: 2025/07/27 21:20:16 by adrocha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

char	**join_and_split(char **argv, int count)
{
	char	*joined;
	char	*tmp;
	char	**result;
	int		i;

	joined = ft_strdup("");
	i = 0;
	while (i < count)
	{
		tmp = ft_strjoin(joined, " ");
		free(joined);
		joined = ft_strjoin(tmp, argv[i]);
		free(tmp);
		i++;
	}
	result = ft_split(joined, ' ');
	free(joined);
	return (result);
}

void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args && args[i])
		free(args[i++]);
	free(args);
}

int	parse_arguments(t_node **stack, int argc, char **argv)
{
	char	**args;
	int		i;

	args = join_and_split(argv + 1, argc - 1);
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
