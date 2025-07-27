/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha <adrocha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 19:55:35 by adrocha           #+#    #+#             */
/*   Updated: 2025/07/27 21:13:13 by adrocha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_words(const char *s, char c)
{
	int	count;
	int	nw;

	count = 0;
	nw = 0;
	while (*s)
	{
		if (*s != c && nw == 0)
		{
			count++;
			nw = 1;
		}
		else if (*s == c)
		{
			nw = 0;
		}
		s++;
	}
	return (count);
}

char	*new_string(const char *s, char c)
{
	char	*new;
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	new = (char *)malloc((len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	ft_strlcpy(new, s, len + 1);
	return (new);
}

void	free_split(char **res, size_t i)
{
	while (i > 0)
	{
		i--;
		free(res[i]);
	}
	free(res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	res = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			res[i] = new_string(s, c);
			if (!res[i])
				return (free_split(res, i), NULL);
			i++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	res[i] = NULL;
	return (res);
}
