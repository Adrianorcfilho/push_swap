/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha <adrocha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 18:17:13 by adrocha           #+#    #+#             */
/*   Updated: 2025/07/26 19:58:28 by adrocha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

long	ft_atol(const char *str)
{
	long	long_str;
	int		sign;

	long_str = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	while (*str && ft_isdigit(*str))
		long_str = long_str * 10 + (*str++ - '0');
	return (long_str * sign);
}

int	ft_atoi(const char *str)
{
	return ((int)ft_atol(str));
}
