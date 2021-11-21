/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/08 18:12:30 by abeznik       #+#    #+#                 */
/*   Updated: 2021/11/20 19:33:53 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h> // printf
#include <stdlib.h> // free
#include <fcntl.h> // open
#include <unistd.h> // close

int	main(void)
{
	int		fd;
	int		count;
	char	*line;
	FILE	*fp;

	count = 10;
	fd = open("input.txt", O_RDONLY);
	fp = fopen("output.txt", "w+");
	line = get_next_line(fd);
	while (count > 0)
	{
		fputs(line, fp);
		// printf("%s", line);
		free(line);
		line = get_next_line(fd);
		count--;
	}
	free(line);
	fclose(fp);
	close(fd);
	while (1)
	{}
	return (0);
}
