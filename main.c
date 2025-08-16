/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha- <adrocha-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:54:59 by adrocha-          #+#    #+#             */
/*   Updated: 2025/08/16 18:50:20 by adrocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	print_stack(t_stack *stack)
// {
// 	t_node	*current;

// 	current = stack->first;
// 	while (current)
// 	{
// 		printf("%d\n", current->value);
// 		printf("%d\n", current->index);
// 		current = current->next;
// 	}
// }

int	main(int argc, char **argv)
{
	static t_stack	stack_a;
	static t_stack	stack_b;

	if (argc < 2)
		return (1);
	parse_arguments(&stack_a, argc, argv);
	radix_sort(&stack_a, &stack_b);	
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
