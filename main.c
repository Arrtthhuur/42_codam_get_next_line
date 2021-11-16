/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/08 18:12:30 by abeznik       #+#    #+#                 */
/*   Updated: 2021/11/16 16:01:31 by abeznik       ########   odam.nl         */
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
	char	*file_name;
	char	*line;

	count = 10;
	file_name = "tests/test0";
	// file_name = "tests/medium_plus_file";
	// file_name = "tests/lots_of_new_line";
	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	while (count > 0)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
		count--;
	}
	free(line);
	// while (1)
	// {}
	close(fd);
	return (0);
}
