/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha- <adrocha-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 16:48:17 by adrocha-          #+#    #+#             */
/*   Updated: 2025/08/17 17:24:08 by adrocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = 0;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

int	add_to_stack(t_stack *stack, int value)
{
	t_node	*new_node;

	if (!stack)
		return (0);
	new_node = create_node(value);
	if (!new_node)
		return (0);
	if (!stack->first)
	{
		stack->first = new_node;
		stack->last = new_node;
	}
	else
	{
		stack->last->next = new_node;
		new_node->prev = stack->last;
		stack->last = new_node;
	}
	return (1);
}
