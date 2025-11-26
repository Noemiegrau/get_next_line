/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nograu <nograu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 18:05:21 by nograu            #+#    #+#             */
/*   Updated: 2025/11/26 18:28:36 by nograu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE = 5 // ????

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
// void	*ft_calloc(size_t nmemb, size_t size);
#endif