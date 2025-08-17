/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha- <adrocha-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 18:51:06 by adrocha-          #+#    #+#             */
/*   Updated: 2025/08/17 16:54:08 by adrocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp;

	if (stack_a == NULL || stack_b == NULL || stack_a->first == NULL)
		return ;
	temp = stack_a->first;
	stack_a->first = temp->next;
	if (stack_a->first)
		stack_a->first->prev = NULL;
	else
		stack_a->last = NULL;
	temp->next = stack_b->first;
	temp->prev = NULL;
	if (stack_b->first)
		stack_b->first->prev = temp;
	else
		stack_b->last = temp;
	stack_b->first = temp;
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}
