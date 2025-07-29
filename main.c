/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha <adrocha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:54:59 by adrocha-          #+#    #+#             */
/*   Updated: 2025/07/29 20:11:48 by adrocha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_node *stack)
{
	while (stack)
	{
		printf("%d\n", stack->value);
		stack = stack->next;
	}
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;

	stack_a = NULL;
	if (argc < 2)
		return (0);
	if (!parse_arguments(&stack_a, argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	print_stack(stack_a);
	free_stack(stack_a);
	return (0);
}
