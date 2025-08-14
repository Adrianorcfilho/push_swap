/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha- <adrocha-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:54:59 by adrocha-          #+#    #+#             */
/*   Updated: 2025/08/14 21:41:55 by adrocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_node	*current;

	current = stack->first;
	while (current)
	{
		printf("%d\n", current->value);
		printf("%d\n", current->index);
		current = current->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
	{
		printf("Usage: %s numbers...\n", argv[0]);
		return (1);
	}
	stack_a = create_stack();
	stack_b = create_stack();
	if (!stack_a || !stack_b)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	parse_arguments(stack_a, argc, argv);
	
	printf("Stack A Original: \n");
	print_stack(stack_a);
	printf("Stack B Original: \n\n");
	print_stack(stack_b);
	
	radix_sort(stack_a, stack_b);

	printf("Stack A after radix: \n");
	print_stack(stack_a);
	printf("Stack B after radix: \n\n");
	print_stack(stack_b);
	
	
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}

// printf("Stack A SA: \n");
// sa(stack_a);
// print_stack(stack_a);

// // printf("Stack B SB: \n");
// // sb(stack_b);
// print_stack(stack_b);


// printf("Stack A SS: \n");
// ss(stack_a, stack_b);
// print_stack(stack_a);
// printf("Stack B SS: \n");
// print_stack(stack_b);

// printf("Stack A PA: \n");
// pa(stack_a, stack_b);
// print_stack(stack_a);
// printf("Stack B PA: \n");
// print_stack(stack_b);

// printf("Stack A PB: \n");
// pb(stack_a, stack_b);
// print_stack(stack_a);
// printf("Stack B PB: \n");
// print_stack(stack_b);

// printf("Stack A RA: \n");
// ra(stack_a);
// print_stack(stack_a);

// printf("Stack B RB: \n");
// rb(stack_b);
// print_stack(stack_b);

// printf("Stack A RR: \n");
// rr(stack_a, stack_b);
// print_stack(stack_a);
// printf("Stack B RR: \n");
// print_stack(stack_b);


// printf("Stack A RRA: \n");
// rra(stack_a);
// print_stack(stack_a);

// printf("Stack B RRB: \n");
// rrb(stack_b);
// print_stack(stack_b);


// printf("Stack A RRR: \n");
// rrr(stack_a, stack_b);
// print_stack(stack_a);
// printf("Stack B RRR: \n");
// print_stack(stack_b);