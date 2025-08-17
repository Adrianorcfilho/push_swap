/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_to_5_cases.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha- <adrocha-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 21:01:18 by adrocha-          #+#    #+#             */
/*   Updated: 2025/08/17 17:27:54 by adrocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	find_min_position(t_stack *stack)
{
	t_node	*current;
	int		min;
	int		pos;
	int		min_pos;

	current = stack->first;
	min = current->value;
	pos = 0;
	min_pos = 0;
	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
			min_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (min_pos);
}

static void	move_to_top(t_stack *stack, int pos, int size)
{
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(stack);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rra(stack);
	}
}

void	radix_of_3(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->first->value;
	b = stack->first->next->value;
	c = stack->first->next->next->value;
	if (a < b && b > c && a < c)
	{
		rra(stack);
		sa(stack);
	}
	else if (a > b && b < c && a < c)
		sa(stack);
	else if (a < b && b > c && a > c)
		rra(stack);
	else if (a > b && b < c && a > c)
		ra(stack);
	else if (a > b && b > c)
	{
		sa(stack);
		rra(stack);
	}
}

void	radix_of_4(t_stack *stack_a, t_stack *stack_b)
{
	int	pos_min;

	pos_min = find_min_position(stack_a);
	move_to_top(stack_a, pos_min, 4);
	pb(stack_a, stack_b);
	radix_of_3(stack_a);
	pa(stack_a, stack_b);
}

void	radix_of_5(t_stack *stack_a, t_stack *stack_b)
{
	int	pos_min;

	pos_min = find_min_position(stack_a);
	move_to_top(stack_a, pos_min, 5);
	pb(stack_a, stack_b);
	pos_min = find_min_position(stack_a);
	move_to_top(stack_a, pos_min, 4);
	pb(stack_a, stack_b);
	radix_of_3(stack_a);
	if (stack_b->first->value < stack_b->first->next->value)
		sa(stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
