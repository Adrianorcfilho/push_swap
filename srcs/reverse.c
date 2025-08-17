/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha- <adrocha-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:35:30 by adrocha-          #+#    #+#             */
/*   Updated: 2025/08/17 16:54:16 by adrocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	reverse(t_stack *stack)
{
	t_node	*last;

	if (!stack || !stack->first || !stack->first->next)
		return ;
	last = stack->last;
	stack->last = last->prev;
	stack->last->next = NULL;
	last->prev = NULL;
	last->next = stack->first;
	stack->first->prev = last;
	stack->first = last;
}

void	rra(t_stack *stack_a)
{
	reverse(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack_b)
{
	reverse(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse(stack_a);
	reverse(stack_b);
	write(1, "rrr\n", 4);
}
