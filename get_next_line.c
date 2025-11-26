/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nograu <nograu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 18:05:33 by nograu            #+#    #+#             */
/*   Updated: 2025/11/26 18:31:51 by nograu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	//char		*line;
	char		*buffer;
//	static char	*stash;
	size_t			bytes_read;

	buffer = malloc(sizeof(char) * (3 + 1)); // change n
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, 3); // replace by nbytes ?
	if (bytes_read <= 0)
		return (NULL);
//	stash = calloc(sizeof(char) * bytes_read + 1);

	// while (fd) // != '\0' ?
	// {
	// buffer = ;
	// stash = ;
	// free(buf);
	// }

	return(buffer); //replace by line
}

#include <stdio.h>
#include <fcntl.h>

int	main(void) // change n
{
	int	fd;
	int count;
	char *next_line = get_next_line(fd);

	count = 0;
	fd = open("example.txt", O_RDONLY);
	
	next_line = get_next_line(fd);
	count++;
	printf("[%d]:%s\n", count, next_line);
	next_line = NULL;
	
	close(fd);
	return (0);
}