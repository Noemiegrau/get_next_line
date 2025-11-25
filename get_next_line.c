#include "get_next_line.h"

char	*get_next_line(int fd)
{
	//char		*line;
	char		*buffer;
//	static char	*stash;
	size_t			bytes_read;

	buffer = malloc(sizeof(char) * (5 + 1));
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, 5); // replace by nbytes ?
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

int	main(void)
{
	int	fd = open("example.txt", O_RDONLY);
	int count = 0;
	char *result = get_next_line(fd);

	count++;
	printf("[%d]:%s\n", count, result);
	result = NULL;
	close(fd);
	return (0);
}