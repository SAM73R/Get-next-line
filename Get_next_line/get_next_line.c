/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbouka <selbouka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 09:32:49 by selbouka          #+#    #+#             */
/*   Updated: 2024/12/16 21:47:29 by selbouka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include "get_next_line.h"

char	*reading(int fd, char *buffer, ssize_t *counter)
{
	*counter = read(fd, buffer, BUFFER_SIZE);
	if (*counter == -1)
	{
		free (buffer);
		buffer = NULL;
	}
	else
		buffer[*counter] = '\0';
	return (buffer);
}

char	*outline(char *saveline)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (saveline[j] == '\0' || !saveline)
		return (NULL);
	while (saveline[i] != '\0' && saveline[i] != '\n')
		i++;
	if (saveline[i] == '\n')
		i++;
	str = malloc (i + 1);
	if (!str)
		return (NULL);
	while (saveline[j] && saveline[j] != '\n')
	{
		str[j] = saveline[j];
		j++;
	}
	if (saveline[j] == '\n')
		str[j++] = '\n';
	str[j] = '\0';
	return (str);
}

char	*cleaning(char *saveline)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (saveline[j] && saveline[j]!= '\n' )
		j++;
	if (saveline[j] == '\0')
		return (free(saveline), NULL);
	if (saveline[j] == '\n')
		j++;
	str = malloc (sizeof(char) * (ft_strlen(saveline) - j + 1));
	if (!str)
		return (NULL);
	while (saveline[j])
		str[i++] = saveline[j++];
	str[i] = '\0';
	free(saveline);
	return (str);
}

char	*looping(char *buffer, char *saveline, char **output, int fd)
{
	ssize_t			counter;
	char			*tmp;

	counter = 0;
	while (1)
	{
		buffer = reading(fd, buffer, &counter);
		if (counter == -1)
			return (free(buffer), free(saveline), NULL);
		tmp = saveline;
		saveline = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (!saveline)
			return (free(saveline), saveline = NULL, NULL);
		if (ft_strchr(saveline, '\n') || counter == 0)
		{
			*output = outline(saveline);
			saveline = cleaning(saveline);
			break ;
		}
	}
	return (*output);
}

char	*get_next_line(int fd)
{
	static char		*saveline;
	char			*buffer;
	char			*output;

	if (read(fd, 0, 0) < 0 || BUFFER_SIZE >= INT_MAX || BUFFER_SIZE <= 0)
		return (free(saveline), saveline = NULL, NULL);
	buffer = malloc ((unsigned int)BUFFER_SIZE + 1);
	if (!buffer)
		return (free (saveline), saveline = NULL, NULL);
	output = looping(buffer, saveline, &output, fd);
	if (!output)
		return (free(saveline), saveline = NULL, NULL);
	return (free(buffer), buffer = NULL, output);
}
