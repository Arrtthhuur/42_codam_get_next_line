/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/08 18:12:41 by abeznik       #+#    #+#                 */
/*   Updated: 2021/11/17 13:53:13 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h> // size_t

char	*get_next_line(int fd);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strchr(const char *s, int c);

void	ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t count, size_t size);

size_t	ft_strlen(const char *s);

#endif