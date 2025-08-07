/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha- <adrocha-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:54:59 by adrocha-          #+#    #+#             */
/*   Updated: 2025/08/07 17:46:14 by adrocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_node	*current = stack->first;

	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	if (argc < 2)
	{
		printf("Usage: %s numbers...\n", argv[0]);
		return (1);
	}
	stack_a = create_stack();
	if (!stack_a)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	parse_arguments(stack_a, argc, argv);
	print_stack(stack_a);
	free_stack(stack_a);
	return (0);
}
