/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha <adrocha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 19:52:13 by adrocha           #+#    #+#             */
/*   Updated: 2025/08/05 21:18:12 by adrocha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args && args[i])
		free(args[i++]);
	free(args);
}

void	free_stack(t_node **stack)
{
	t_node	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

void	free_error_exit(t_node **stack, char **args)
{
	if (args)
		free_args(args);
	if (stack)
		free_stack(stack);
	write(2, "Error\n", 6);
	exit(1);
}
