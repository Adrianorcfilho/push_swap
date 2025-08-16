/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha- <adrocha-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 20:23:05 by adrocha-          #+#    #+#             */
/*   Updated: 2025/08/16 21:49:24 by adrocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_size(t_stack *stack)
{
	int		count;
	t_node	*current;

	if (!stack)
		return (0);
	count = 0;
	current = stack->first;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}

static void	assign_index(t_stack *stack)
{
	int		i;
	t_node	*current;
	t_node	*check;

	current = stack->first;
	while (current)
	{
		i = 0;
		check = stack->first;
		while (check)
		{
			if (check->value < current->value)
				i++;
			check = check->next;
		}
		current->index = i;
		current = current->next;
	}
}

static int	max_num(t_stack *stack)
{
	int	max_num;
	int	max_bits;

	max_num = list_size(stack) - 1;
	max_bits = 0;
	while (max_num > 0)
	{	
		max_num = max_num / 2;
		max_bits++;
	}
	return (max_bits);
}

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	max_bits;
	int	size;
	int	i;
	int	j;

	assign_index(stack_a);
	max_bits = max_num(stack_a);
	i = 0;
	while (i < max_bits)
	{
		j = -1;
		size = list_size(stack_a);
		while (j++ < size)
		{
			if (((stack_a->first->index >> i) & 1) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
		}
		while (stack_b->first)
			pa(stack_a, stack_b);
		i++;
	}
}
