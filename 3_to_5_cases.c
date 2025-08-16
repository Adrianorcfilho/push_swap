/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_to_5_cases.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha- <adrocha-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 21:01:18 by adrocha-          #+#    #+#             */
/*   Updated: 2025/08/16 21:32:38 by adrocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (pos <= size / 2) // mais perto do topo
	{
		while (pos-- > 0)
			ra(stack);
	}
	else // mais perto do fundo
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
	if (a < b && b > c && a < c) // 1 3 2
	{
		rra(stack);
		sa(stack);
	}
	else if (a > b && b < c && a < c) // 2 1 3
		sa(stack);
	else if (a < b && b > c && a > c) // 2 3 1
		rra(stack);
	else if (a > b && b < c && a > c) // 3 1 2
		ra(stack);
	else if (a > b && b > c) // 3 2 1
	{
		sa(stack);
		rra(stack);
	}
}

void	radix_of_4(t_stack *stack_a, t_stack *stack_b)
{
	int	pos_min;

	pos_min = find_min_position(stack_a);  // posição do menor valor (0-index)
	move_to_top(stack_a, pos_min, 4); // leva menor para o topo
	pb(stack_a, stack_b);             // joga menor para B
	radix_of_3(stack_a);              // ordena os 3 restantes
	pa(stack_a, stack_b);             // devolve o menor
}

void	radix_of_5(t_stack *stack_a, t_stack *stack_b)
{
	int	pos_min;

	pos_min = find_min_position(stack_a);
	move_to_top(stack_a, pos_min, 5);
	pb(stack_a, stack_b); // menor vai para B
	pos_min = find_min_position(stack_a);
	move_to_top(stack_a, pos_min, 4);
	pb(stack_a, stack_b); // segundo menor vai para B
	radix_of_3(stack_a); // ordena os 3 restantes
	if (stack_b->first->value < stack_b->first->next->value)
		sa(stack_b); // coloca maior em cima
	pa(stack_a, stack_b); // devolve maior
	pa(stack_a, stack_b); // devolve menor
}
