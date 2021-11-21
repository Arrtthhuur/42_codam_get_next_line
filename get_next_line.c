/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/08 18:17:34 by abeznik       #+#    #+#                 */
/*   Updated: 2021/11/19 13:38:45 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <unistd.h> // read
#include <stdlib.h> // free

#define MAX_FD 1024

/*
** Join line and buff to tmp and free line.
*/
static char	*join_free(char *buff, char *tmp)
{
	char	*line;

	line = ft_strjoin(buff, tmp);
	free(buff);
	if (!line)
		return (NULL);
	return (line);
}

/*
** Find next line and remove it from buffer.
*/
static char	*next_line(char *buff)
{
	size_t	len;
	size_t	i;
	char	*next_line;

	len = 0;
	while (buff[len] && buff[len] != '\n')
		len++;
	if (!buff[len])
	{
		free(buff);
		return (NULL);
	}
	next_line = ft_calloc((ft_strlen(buff) - len + 1), sizeof(char));
	if (!next_line)
	{
		free(buff);
		return (NULL);
	}
	len++;
	i = 0;
	while (buff[len])
		next_line[i++] = buff[len++];
	free(buff);
	return (next_line);
}

/*
** Allocate mem for line and copy buff to line.
*/
static char	*get_line(char *buff)
{
	size_t	len;
	char	*ret_line;

	len = 0;
	if (!buff[len])
		return (NULL);
	while (buff[len] && buff[len] != '\n')
		len++;
	ret_line = ft_calloc(len + 2, sizeof(char));
	if (!ret_line)
		return (NULL);
	len = 0;
	while (buff[len] && buff[len] != '\n')
	{
		ret_line[len] = buff[len];
		len++;
	}
	if (buff[len] && buff[len] == '\n')
		ret_line[len++] = '\n';
	return (ret_line);
}

/*
** Read file and break if buffer has NL.
*/
static char	*read_file(int fd, char *buff, char *tmp)
{
	int		nbytes;

	nbytes = 1;
	while (nbytes > 0)
	{
		nbytes = read(fd, tmp, BUFFER_SIZE);
		if (nbytes == -1)
		{
			free(tmp);
			free(buff);
			return (NULL);
		}
		tmp[nbytes] = '\0';
		buff = join_free(buff, tmp);
		if (!buff)
		{
			free(tmp);
			return (NULL);
		}
		if (ft_strchr(tmp, '\n'))
			break ;
	}
	free(tmp);
	return (buff);
}

/*
** Error handling, read, get line and next line.
*/
char	*get_next_line(int fd)
{
	static char	*buff;
	char		*ret_line;
	char		*tmp;

	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!buff)
	{
		buff = ft_calloc(1, 1);
		if (!buff)
			return (NULL);
	}
	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	buff = read_file(fd, buff, tmp);
	if (!buff)
		return (NULL);
	ret_line = get_line(buff);
	buff = next_line(buff);
	return (ret_line);
}
