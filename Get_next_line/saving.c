#include <libc.h>
#include "get_next_line.h"

char *reading(int fd, char *buffer, ssize_t *counter)
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

char *outline(char *saveline)
{
	char *str;
	int i = 0;
	int j  = 0;
	
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

char *cleaning(char *saveline)
{
	int i = 0;
	int j = 0;
	char *str;
	
	// if (!saveline)
	//     return (free(saveline),NULL);
	//int f = ft_strlen(saveline);
	while (saveline[j] && saveline[j]!= '\n' )
		j++;
	if (saveline[j] == '\0')
		return (free(saveline),NULL);
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


char *get_next_line(int fd)
{
	static char *saveline;                                                                                     // data segment // Initialized data segment (data segment) | unintialized data segemnt (BSS) 
	char *buffer;
	char *output;
	char *tmp;
	ssize_t stop;
	ssize_t counter = 0;
	
	if (fd < 0 || read(fd,0,0) < 0 || BUFFER_SIZE >= INT_MAX || BUFFER_SIZE <= 0)
		return (free(saveline), saveline = NULL, NULL);

	
	buffer = malloc ((unsigned int)BUFFER_SIZE + 1);                                                             // because if the Buffersize = MAXint and you add 1 it will overflow 
	if (!buffer)
		return (free (saveline),saveline = NULL, NULL);
	stop = 0;
	while (stop == 0)
	{
		buffer = reading(fd, buffer, &counter);
		if (counter == -1)
			return (free(buffer),buffer = NULL,free(saveline),saveline =NULL,NULL);
		tmp = saveline;
		saveline = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (!saveline)
			return (NULL);
		if (ft_strchr(saveline, '\n') || counter == 0)
		{
			output = outline(saveline);
			saveline = cleaning(saveline);
			stop = 1;
		}

	}
	return (free(buffer),buffer = NULL,output);
}




=====




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

int	looping(char *buffer, char *saveline, char *output, int fd)
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
			return (NULL);
		if (ft_strchr(saveline, '\n') || counter == 0)
		{
			output = outline(saveline);
			saveline = cleaning(saveline);
			break ;
		}
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char		*saveline;
	char			*buffer;
	char			*output;
	char			*tmp;
	ssize_t			counter;

	counter = 0;
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE >= INT_MAX || BUFFER_SIZE <= 0)
		return (free(saveline), saveline = NULL, NULL);
	buffer = malloc ((unsigned int)BUFFER_SIZE + 1);
	if (!buffer)
		return (free (saveline), saveline = NULL, NULL);
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
			return (NULL);
		if (ft_strchr(saveline, '\n') || counter == 0)
		{
			output = outline(saveline);
			saveline = cleaning(saveline);
			break ;
		}
	}
	return (free(buffer), buffer = NULL, output);
}
