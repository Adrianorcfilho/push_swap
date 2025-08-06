/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha- <adrocha-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 17:50:43 by adrocha-          #+#    #+#             */
/*   Updated: 2025/08/06 20:17:34 by adrocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_node(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (0);
	new_node->value = value;
	new_node->index = -1;
	new_node->next = NULL;
	new_node->prev = NULL;
}

t_stack	create_stack(void)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		return (0);
	new_stack->first = NULL;
	new_stack->last = NULL;
	return (new_stack);
}

int	add_to_stack(t_stack *stack)
{
	if (!stack)
		return (0);
	else
	{
		
	}
	return (1);
}

void	ft_swap(t_node *stack)
{
	int	tmp;

	if (!stack || !stack->head || !stack->head->next)
		free_stack(stack);
	tmp = first->value;
	first->value = last->value;
	last->value = tmp;
}
