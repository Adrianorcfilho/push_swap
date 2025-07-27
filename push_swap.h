/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha <adrocha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:53:35 by adrocha-          #+#    #+#             */
/*   Updated: 2025/07/26 18:22:34 by adrocha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

// ===== PARSING =====
int					parse_arguments(t_node **stack, int argc, char **argv);
int					is_valid_number(char *str);
int					is_int_range(char *str);
int					add_to_stack(t_node **stack, int value);
int					has_duplicates(t_node *stack);
char				**join_and_split(char **argv, int count);
void				free_args(char **args);
// ===== UTILS =====
int					ft_isdigit(int c);
long				ft_atol(const char *str);
int					ft_atoi(const char *str);
char				*ft_strdup(const char *s);
char				*ft_strjoin(const char *s1, const char *s2);
char				**ft_split(const char *s, char c);
int					ft_word_count(const char *s, char c);
char				*ft_substr(const char *s, int start, int len);

#endif