/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha- <adrocha-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 17:50:43 by adrocha-          #+#    #+#             */
/*   Updated: 2025/08/07 17:59:39 by adrocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack stack)
{
	int	tmp;

	if (!stack || !stack->head || !stack->head->next)
		free_stack(stack);
	tmp = first->value;
	first->value = last->value;
	last->value = tmp;
}
