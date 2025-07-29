/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha <adrocha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:53:35 by adrocha-          #+#    #+#             */
/*   Updated: 2025/07/29 19:30:01 by adrocha          ###   ########.fr       */
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
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

int					parse_arguments(t_node **stack, int argc, char **argv);
int					is_valid_number(char *str);
int					is_int_range(char *str);
int					add_to_stack(t_node **stack, int value);
int					has_duplicates(t_node *stack);
void				free_args(char **args);
int					ft_isdigit(int c);
long				ft_atol(const char *str);
char				**ft_split(const char *s, char c);
void				print_stack(t_node *stack);
void				free_stack(t_node *stack);

#endif