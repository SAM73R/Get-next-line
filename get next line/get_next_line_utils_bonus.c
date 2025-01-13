/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbouka <selbouka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:08:28 by selbouka          #+#    #+#             */
/*   Updated: 2024/12/17 16:42:53 by selbouka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*duplicate_b(const char *src)
{
	char	*p;
	int		i;

	i = len_b(src);
	p = malloc(i + 1);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		p[i] = src[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

static void	*join(char const *s1, char const *s2, int len)
{
	char	*p;
	int		i;
	int		n;

	p = malloc(len + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	n = 0;
	while (s2[n])
	{
		p[i++] = s2[n];
		n++;
	}
	return (p[i] = '\0', p);
}

char	*joining_b(char const *s1, char const *s2)
{
	int	len;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 || !s2)
	{
		if (!s1)
			return (duplicate_b(s2));
		else if (!s2)
			return (duplicate_b(s1));
		else
			return (NULL);
	}
	len = len_b(s1) + len_b(s2);
	return (join(s1, s2, len));
}

char	*search_b(const char *str, int c)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (NULL);
}

int	len_b(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}
