/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nograu <nograu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 18:05:33 by nograu            #+#    #+#             */
/*   Updated: 2025/11/27 16:26:58 by nograu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*check_stash(char *stash, char **line)
{
	int				i;
	unsigned int	new_stash_size;
	char			*new_stash;
	
	i = 0;
	new_stash_size = 0;
	while (stash[i])
	{
		if (stash[i] == '\n')
		{
			*line = ft_substr(stash, 0, i + 1);
			new_stash_size = ft_strlen(stash) - ft_strlen(*line);
			new_stash = ft_substr(stash, i + 1, new_stash_size);
			free(stash);
			return (new_stash);
		}
		i++;
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*stash;
	size_t			bytes_read;

	line = NULL;
	if (stash == NULL)
	 	stash = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!stash)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1)); // change n
	if (!buffer)
			return (NULL);
	while (!line)
	{
		
		bytes_read = read(fd, buffer, BUFFER_SIZE); // replace by nbytes ?
		if (bytes_read <= 0)
			return (stash);
		buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, buffer);
		stash = check_stash(stash, &line);
	}
	return(line); //replace by line
}

#include <stdio.h>
#include <fcntl.h>

int	main(void) // change n
{
	int	fd; // should work also when reading from the standard input -> write(1, "", 1); ??
	int count;
	char *next_line;

	count = 0;
	fd = open("example.txt", O_RDONLY);
	while (count <=16)
	{
		next_line = get_next_line(fd);
		count++;
		printf("[%d]:%s", count, next_line);
	}
	close(fd);
	return (0);
}