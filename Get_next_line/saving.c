#include <libc.h>
#include "get_next_line.h"

char *reading(int fd, char *buffer, ssize_t *counter)
{
    *counter = read(fd, buffer, BUFFER_SIZE);
    if (*counter < 1)
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
    char *str= NULL;
    int i = 0;
    int j  = 0;
    
    while (saveline[i] != '\n')
    {
        if (saveline[i] == '\0')
            return (free(str) ,saveline);
        i++;
    }
    str = malloc (sizeof(char) * (i + 2));
    if (!str)
        return (NULL);
    while (j <= i)
    {
        str[j] = saveline[j];
        j++;
    }
    str[j] = '\0';
    return (str);
}

char *cleaning(char *saveline)
{
    int i = 0;
    int j = 0;
    char *str;
    
    if (!saveline)
        return (free(saveline),NULL);
    
    while (saveline[j] != '\n' && saveline[j])
        j++;
    if (saveline[j + 1] == '\0')
        return (free(saveline),NULL);
    j++;
    str = malloc (sizeof(char) * (ft_strlen(saveline) - j + 1));
    if (!str)
        return (NULL);
    while (j < ft_strlen(saveline) - 1)
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
    int stop;
    stop = 0;
    ssize_t counter;
    
    if (fd < 0 || read(fd,0,0) < 0 || BUFFER_SIZE >= INT_MAX || BUFFER_SIZE <= 0)
        return (free(saveline), saveline = NULL, NULL);
    buffer = malloc ((unsigned int)BUFFER_SIZE + 1);                                                             // because if the Buffersize = MAXint and you add 1 it will overflow 
    if (!buffer)
        return (free (saveline),saveline = NULL, NULL);
    
    counter = 0;
    while (stop == 0)
    {
        buffer = reading (fd, buffer, &counter);
        tmp = saveline;
        saveline = ft_strjoin(tmp, buffer);
        free(tmp);
        if (!saveline)
            return (NULL);
        if (ft_strchr(saveline, '\n') || counter < 1)
        {
            output = outline(saveline);
            saveline = cleaning(saveline);
            stop = 1;
        }
    }
    free(buffer);
    buffer = NULL;
    return (output);
}
_________

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbouka <selbouka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 09:32:49 by selbouka          #+#    #+#             */
/*   Updated: 2024/12/15 18:16:03 by selbouka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include "get_next_line.h"

char *reading(int fd, char *buffer, ssize_t *counter)
{
    *counter = read(fd, buffer, BUFFER_SIZE);
    if (*counter < 1)
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
    char *str= NULL;
    int i = 0;
    int j  = 0;
    
    while (saveline[i] != '\n' && saveline[i] != '\0')
        i++;
    if (saveline[i] == '\n')
        i++;
    str = malloc (sizeof(char) * (i + 1));
    if (!str)
        return (NULL);
    while (j < i)
    {
        str[j] = saveline[j];
        j++;
    }
    str[j] = '\0';
    return (str);
}

char *cleaning(char *saveline)
{
    int i = 0;
    int j = 0;
    char *str;
    
    if (!saveline)
        return (free(saveline),NULL);
    
    while (saveline[j] != '\n' && saveline[j])
        j++;
    if (saveline[j] == '\0')
        return (free(saveline),NULL);
    j++;
    str = malloc (sizeof(char) * (ft_strlen(saveline) - j + 1));
    if (!str)
        return (NULL);
    while (j < ft_strlen(saveline) - 1)
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
    int stop;
    stop = 0;
    ssize_t counter;
    
    if (fd < 0 || read(fd,0,0) < 0 || BUFFER_SIZE >= INT_MAX || BUFFER_SIZE <= 0)
        return (free(saveline), saveline = NULL, NULL);
    buffer = malloc ((unsigned int)BUFFER_SIZE + 1);                                                             // because if the Buffersize = MAXint and you add 1 it will overflow 
    if (!buffer)
        return (free (saveline),saveline = NULL, NULL);
    
    counter = 0;
    while (stop == 0)
    {
        buffer = reading (fd, buffer, &counter);
        tmp = saveline;
        saveline = ft_strjoin(tmp, buffer);
        free(tmp);
        if (!saveline)
            return (NULL);
        if(!ft_strlen(saveline))
            return(free (saveline),saveline = NULL, NULL);
        if (ft_strchr(saveline, '\n') || counter < 1)
        {
            output = outline(saveline);
            saveline = cleaning(saveline);
            stop = 1;
        }
    }
    free(buffer);
    buffer = NULL;
    return (output);
}


