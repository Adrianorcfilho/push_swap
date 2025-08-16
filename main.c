/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha- <adrocha-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:54:59 by adrocha-          #+#    #+#             */
/*   Updated: 2025/08/16 21:57:32 by adrocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_cases(t_stack *stack_a, t_stack *stack_b)
{
	int	size;

	size = list_size(stack_a);
	if (size == 2 && stack_a->first->value > stack_a->first->next->value)
		sa(stack_a);
	else if (size == 3)
		radix_of_3(stack_a);
	else if (size == 4)
		radix_of_4(stack_a, stack_b);
	else if (size == 5)
		radix_of_5(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	static t_stack	stack_a;
	static t_stack	stack_b;

	if (argc < 2)
		return (1);
	parse_arguments(&stack_a, argc, argv);
	radix_cases(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
