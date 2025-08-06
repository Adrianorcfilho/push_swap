/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha- <adrocha-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:53:35 by adrocha-          #+#    #+#             */
/*   Updated: 2025/08/06 19:09:54 by adrocha-         ###   ########.fr       */
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

void				free_error_exit(t_node **stack, char **args);
void				free_stack(t_node **stack);
void				free_args(char **args);
int					is_valid_number(char *str);
int					is_int_range(char *str);
int					has_duplicates(t_node *stack);
int					add_to_stack(t_node **stack, int value);
void				parse_arguments(t_node **stack, int argc, char **av);
long				ft_atol(const char *str);
void				free_split(char **res, size_t i);
char				**ft_split(char const *s, char c);

#endif