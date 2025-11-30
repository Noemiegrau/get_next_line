/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nograu <nograu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 12:57:06 by nograu            #+#    #+#             */
/*   Updated: 2025/11/30 18:58:45 by nograu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}

static void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	calcul;

	if (nmemb != 0 && size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	calcul = nmemb * size;
	ptr = malloc(calcul);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, calcul);
	return (ptr);
}

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

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*stash;
	int			bytes_read;

	line = NULL;
	buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		stash = ft_strjoin(stash, buffer);
		if (stash && ft_strchr(stash, '\n'))
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	if (!stash || stash[0] == '\0' || bytes_read == -1)
		return (free(stash), stash = NULL, NULL);
	stash = check_stash(stash, &line);
	if (!line && stash)
		return (line = ft_strdup(stash), free(stash), stash = NULL, line);
	return (line);
}

#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int	fd = open("example.txt", O_RDONLY);
	char	*line;
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
}

// int	main(void)
// {
// 	int	fd; // should work also when reading from the standard input??
// 	int count;
// 	char *next_line;

// 	count = 0;
// 	fd = open("example.txt", O_RDONLY);
// 	while (count <= 15)
// 	{
// 		next_line = get_next_line(fd);
// 		count++;
// 		printf("[%d]:%s", count, next_line);
// 		free(next_line);
// 	}
// 	//printf("\n%s\n", next_line);
// 	close(fd);
// 	return (0);
// }