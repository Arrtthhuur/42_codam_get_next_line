/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/08 18:17:34 by abeznik       #+#    #+#                 */
/*   Updated: 2021/11/16 16:36:00 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h> //printf
#include <unistd.h> //read
#include <stdlib.h> //free

#define MAX_FD 1024

static char	*get_line(char *line)
{
	size_t	len;
	char	*save;

	len = 0;
	while (line[len] != '\n' && line[len] != '\0')
		len++;
	if (line[len] == '\0' || line[0] == '\0')
		return (NULL);
	save = ft_substr(line, len + 1, ft_strlen(line) - len);
	if (!save)
		return (NULL);
	if (*save == '\0')
	{
		free(save);
		save = NULL;
	}
	line[len + 1] = '\0';
	return (save);
}

static char	*read_line(int fd, char *buffer, char *save)
{
	int		nbytes;
	char	*tmp_save;

	nbytes = 1;
	while (nbytes != 0)
	{
		nbytes = read(fd, buffer, BUFFER_SIZE);
		if (nbytes == -1)
			return (NULL);
		else if (nbytes == 0)
			break ;
		buffer[nbytes] = '\0';
		if (!save)
			save = ft_strdup("");
		if (!save)
			return (NULL);
		tmp_save = save;
		save = ft_strjoin(tmp_save, buffer);
		if (!save)
			return (NULL);
		free(tmp_save);
		tmp_save = NULL;
		if (ft_strchr (buffer, '\n'))
			break ;
	}
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*save;

	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = read_line(fd, buffer, save);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	save = get_line(line);
	return (line);
}
