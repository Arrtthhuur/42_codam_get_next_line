/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/08 18:18:25 by abeznik       #+#    #+#                 */
/*   Updated: 2021/11/18 13:32:10 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdlib.h> // malloc

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_len;
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	total_len = ft_strlen(s1) + ft_strlen(s2);
	// ptr = malloc(sizeof(char) * (total_len + 1));
	ptr = NULL;
	if (!ptr || !s1 || !s2)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	ptr[total_len] = '\0';
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	// return (NULL);
	while (*str != c && *str)
		str++;
	if (*str == c)
		return (str);
	else
		return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	// ptr = (void *)malloc(count * size);
	ptr = NULL;
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
