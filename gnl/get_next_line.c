/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecid <ecid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:48:49 by ecid              #+#    #+#             */
/*   Updated: 2025/01/07 09:45:54 by ecid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_file(int fd, char *buffer)
{
	char	temp_buffer[BUFFER_SIZE + 1];
	ssize_t	bytes_read;
	char	*new_buffer;

	bytes_read = 1;
	while (!ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buffer), buffer = NULL, NULL);
		temp_buffer[bytes_read] = '\0';
		new_buffer = malloc(ft_strlen(buffer) + bytes_read + 1);
		if (!new_buffer)
			return (free(buffer), buffer = NULL, NULL);
		ft_memcpy(new_buffer, buffer, ft_strlen(buffer));
		ft_memcpy(new_buffer + ft_strlen(buffer), temp_buffer, bytes_read + 1);
		free(buffer);
		buffer = new_buffer;
		if (bytes_read < BUFFER_SIZE)
			break ;
	}
	if (bytes_read == 0 && buffer && buffer[0] == '\0')
		return (free(buffer), buffer = NULL, NULL);
	return (buffer);
}

static char	*extract_line(char **buffer)
{
	char	*line;
	char	*newline_pos;
	size_t	line_length;
	char	*new_buffer;

	newline_pos = ft_strchr(*buffer, '\n');
	if (newline_pos != NULL)
		line_length = (size_t)(newline_pos - *buffer) + 1;
	else
		line_length = ft_strlen(*buffer);
	line = malloc(line_length + 1);
	if (!line)
	{
		free(*buffer);
		*buffer = NULL;
		return (NULL);
	}
	ft_memcpy(line, *buffer, line_length);
	line[line_length] = '\0';
	new_buffer = ft_strdup(*buffer + line_length);
	free(*buffer);
	*buffer = new_buffer;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = extract_line(&buffer);
	if (!line)
	{
		return (free(buffer), buffer = NULL, NULL);
	}
	return (line);
}
