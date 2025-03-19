/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndufourn <ndufourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:46:40 by ndufourn          #+#    #+#             */
/*   Updated: 2025/03/19 15:57:06 by ndufourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

static char	*read_file(int fd, char **str);
static char	*extract_line(char *buffer);
static char	*join_n_free(char *buffer, char *new_buffer);

char	*ft_get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer || !ft_strchr(buffer, '\n'))
	{
		if (!read_file(fd, &buffer))
		{
			free(buffer);
			buffer = NULL;
			return (NULL);
		}
	}
	line = extract_line(buffer);
	if (!line)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	ft_strlcpy(buffer, buffer + ft_strlen(line),
		ft_strlen(buffer) - ft_strlen(line) + 1);
	return (line);
}

//Reads chunks of data from fd until newline (\n) is found or EOF.
static char	*read_file(int fd, char **str)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(*str, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		*str = join_n_free(*str, buffer);
		if (!*str)
		{
			free(buffer);
			return (NULL);
		}
	}
	free(buffer);
	return (*str);
}

static char	*extract_line(char *buffer)
{
	char	*line;
	size_t	i;

	if (!buffer || !*buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = (char *)malloc((i + 1 + (buffer[i] == '\n')) * sizeof(char));
	if (!line)
		return (NULL);
	ft_strlcpy(line, buffer, i + 1 + (buffer[i] == '\n'));
	return (line);
}

static char	*join_n_free(char *buffer, char *new_buffer)
{
	char	*temp;

	temp = ft_strjoin(buffer, new_buffer);
	if (!temp)
	{
		free(buffer);
		return (NULL);
	}
	free(buffer);
	return (temp);
}
