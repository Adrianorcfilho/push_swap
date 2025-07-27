/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha <adrocha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 14:28:15 by adrocha           #+#    #+#             */
/*   Updated: 2025/07/27 21:15:22 by adrocha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

char	*ft_strdup(const char *src)
{
	char	*dst;

	dst = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	ft_strcpy(dst, (char *)src);
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*c;
	size_t	i;
	size_t	j;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	c = (char *)malloc((len_s1 + len_s2 + 1) * (sizeof(char)));
	if (!c)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		c[j++] = s1[i++];
	i = 0;
	while (s2[i])
		c[j++] = s2[i++];
	c[j] = '\0';
	return (c);
}
