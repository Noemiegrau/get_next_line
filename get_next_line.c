/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nograu <nograu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 12:57:06 by nograu            #+#    #+#             */
/*   Updated: 2025/11/29 14:25:27 by nograu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

static char	*check_stash(char *stash, char **line)
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

int	read_and_stash(int fd, char **stash)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL); // -1 ?

}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*stash;
	int			bytes_read;

	line = NULL;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	buffer[bytes_read] = '\0';
	while (bytes_read > 0)
	{
		stash = ft_strjoin(stash, buffer);
		if (stash && ft_strchr(stash, '\n'))
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = '\0';
	}
	free(buffer);
	if (!stash || stash[0] == '\0' || bytes_read == -1)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = check_stash(stash, &line);
	if (!line && stash)
	{ 
		line = ft_strdup(stash);
		free(stash);
		stash = NULL;
	}
	return (line);
}


// char	*get_next_line(int fd)
// {
// 	char		*line;
// 	char		*buffer;
// 	static char	*stash;
// 	int			bytes_read;

// 	line = NULL;
// 	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	if (!buffer)
// 		return (NULL);
// 	bytes_read = read(fd, buffer, BUFFER_SIZE);
// 	buffer[bytes_read] = '\0';
// 	while (bytes_read > 0)
// 	{
// 		stash = ft_strjoin(stash, buffer);
// 		if (stash && ft_strchr(stash, '\n'))
// 			break ;
// 		bytes_read = read(fd, buffer, BUFFER_SIZE);
// 		buffer[bytes_read] = '\0';
// 	}
// 	free(buffer);
// 	if (!stash || stash[0] == '\0' || bytes_read == -1)
// 	{
// 		free(stash);
// 		stash = NULL;
// 		return (NULL);
// 	}
// 	stash = check_stash(stash, &line);
// 	if (!line && stash)
// 	{ 
// 		line = ft_strdup(stash);
// 		free(stash);
// 		stash = NULL;
// 	}
// 	return (line);
// }

#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int	fd; // should work also when reading from the standard input??
	int count;
	char *next_line;

	count = 0;
	fd = open("example.txt", O_RDONLY);
	while (count <= 15)
	{
		next_line = get_next_line(fd);
		count++;
		printf("[%d]:%s", count, next_line);
		free(next_line);
	}
	//printf("\n%s\n", next_line);
	close(fd);
	return (0);
}

// int	main(void)
// {
// 	int	fd;
// 	int count;
// 	char *next_line;

// 	count = 0;
// 	fd = open("example.txt", O_RDONLY);
// 	next_line = get_next_line(fd);
// 	while (next_line == get_next_line(fd))
// 	{
// 		count++;
// 		printf("[%d]:%s", count, next_line);
// 		free(next_line);
// 	}
// 	//printf("\n%s\n", next_line);
// 	close(fd);
// 	return (0);
// }
