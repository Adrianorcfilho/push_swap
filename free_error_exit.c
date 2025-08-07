/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha- <adrocha-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 19:52:13 by adrocha           #+#    #+#             */
/*   Updated: 2025/08/07 17:44:51 by adrocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_args(char **args)
{
	int	i;

	i = 0;
	if (!args)
		return ;
	while (args[i])
		free(args[i++]);
	free(args);
}

void	free_stack(t_stack *stack)
{
	t_node	*tmp;

	while (stack && stack->first)
	{
		tmp = stack->first->next;
		free(stack->first);
		stack->first = tmp;
	}
	free(stack);
}


void	free_error_exit(t_stack *stack, char **args)
{
	if (args)
		free_args(args);
	if (stack)
		free_stack(stack);
	write(2, "Error\n", 6);
	exit(1);
}
