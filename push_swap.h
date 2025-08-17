/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha- <adrocha-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:53:35 by adrocha-          #+#    #+#             */
/*   Updated: 2025/08/17 16:49:33 by adrocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	struct s_node	*prev;
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	struct s_node	*first;
	struct s_node	*last;
}					t_stack;

void				free_error_exit(t_stack *stack, char **args);
void				free_stack(t_stack *stack);
void				free_args(char **args);
int					add_to_stack(t_stack *stack, int value);
t_stack				*create_stack(void);
void				parse_arguments(t_stack *stack, int argc, char **av);
long				ft_atol(const char *str);
void				free_split(char **res, size_t i);
char				**ft_split(char const *s, char c);
void				sa(t_stack *stack_a);
void				sb(t_stack *stack_b);
void				ss(t_stack *stack_a, t_stack *stack_b);
void				pa(t_stack *stack_a, t_stack *stack_b);
void				pb(t_stack *stack_a, t_stack *stack_b);
void				ra(t_stack *stack_a);
void				rb(t_stack *stack_b);
void				rr(t_stack *stack_a, t_stack *stack_b);
void				rra(t_stack *stack_a);
void				rrb(t_stack *stack_b);
void				rrr(t_stack *stack_a, t_stack *stack_b);
int					list_size(t_stack *stack);
void				radix_sort(t_stack *stack_a, t_stack *stack_b);
void				radix_of_3(t_stack *stack);
void				radix_of_4(t_stack *stack_a, t_stack *stack_b);
void				radix_of_5(t_stack *stack_a, t_stack *stack_b);
void				radix_cases(t_stack *stack_a, t_stack *stack_b);

#endif