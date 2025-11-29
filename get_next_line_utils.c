/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nograu <nograu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 18:05:40 by nograu            #+#    #+#             */
/*   Updated: 2025/11/29 13:25:10 by nograu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*result;
	unsigned int	result_size;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!s1)
		return(result = ft_strdup(s2), result);
	result_size = ft_strlen(s1) + ft_strlen(s2);
	result = malloc(sizeof(char) * (result_size + 1));
	if (!result)
		return (NULL);
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j])
		result[i++] = s2[j++];
	result[i] = '\0';
	free((void *)s1);
	return (result);
}

char	*ft_strdup(const char *s)
{
	int		i;
	int		len_s;
	char	*dest;

	i = 0;
	len_s = ft_strlen(s);
	dest = malloc(sizeof(char) * (len_s + 1));
	if (!dest)
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;
	size_t			len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= len_s)
		return (ft_strdup(""));
	if (len > len_s - start)
		len = len_s - start;
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

// static void	ft_bzero(void *s, size_t n)
// {
// 	unsigned char	*ptr;
// 	size_t			i;

// 	i = 0;
// 	ptr = (unsigned char *)s;
// 	while (i < n)
// 	{
// 		ptr[i] = '\0';
// 		i++;
// 	}
// }

// void	*ft_calloc(size_t nmemb, size_t size)
// {
// 	void	*ptr;
// 	size_t	calcul;

// 	if (nmemb != 0 && size != 0 && nmemb > SIZE_MAX / size)
// 		return (NULL);
// 	calcul = nmemb * size;
// 	ptr = malloc(calcul);
// 	if (!ptr)
// 		return (NULL);
// 	ft_bzero(ptr, calcul);
// 	return (ptr);
// }