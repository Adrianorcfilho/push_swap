/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha- <adrocha-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:34:51 by adrocha-          #+#    #+#             */
/*   Updated: 2025/08/14 21:46:33 by adrocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void rotate(t_stack *stack)
{
    t_node *first;
    t_node *last;

    if (!stack || !stack->first || !stack->first->next)
        return;

    first = stack->first;
    last = stack->last;

    stack->first = first->next;
    stack->first->prev = NULL;

    last->next = first;
    first->prev = last;
    first->next = NULL;

    stack->last = first;
}

// static void	rotate(t_stack *stack)
// {
// 	int		temp;
// 	t_node	*node;

// 	if (stack->first == NULL || stack->first->next == NULL)
// 		return ;
// 	temp = stack->first->value;
// 	node = stack->first;
// 	while (node->next != NULL)
// 	{
// 		node->value = node->next->value;
// 		node = node->next;
// 	}
// 	node->value = temp;
// }

void	ra(t_stack *stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_stack *stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
