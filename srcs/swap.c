/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha- <adrocha-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 18:50:33 by adrocha-          #+#    #+#             */
/*   Updated: 2025/08/17 17:25:32 by adrocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !stack->first || !stack->first->next)
		return ;
	first = stack->first;
	second = first->next;
	second->prev = NULL;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	first->prev = second;
	stack->first = second;
	if (first->next == NULL)
		stack->last = first;
}

void	sa(t_stack *stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}
