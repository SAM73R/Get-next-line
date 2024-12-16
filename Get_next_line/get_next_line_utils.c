/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbouka <selbouka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:08:28 by selbouka          #+#    #+#             */
/*   Updated: 2024/12/15 15:43:14 by selbouka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

char	*ft_strdup(const char *src)
{
	char	*p;
	int		i;

	i = ft_strlen(src);
	p = malloc(i + 1);
	i = 0;
	if (p == NULL)
		return (NULL);
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

	p = malloc(sizeof(char) * (len + 1));
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	int	len;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 || !s2)
	{
		if (!s1)
			return (ft_strdup(s2));
		else if (!s2)
			return (ft_strdup(s1));
		else
			return (NULL);
	}
	len = ft_strlen(s1) + ft_strlen(s2);
	return (join(s1, s2, len));
}

char	*ft_strchr(const char *str, int c)
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

int	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

