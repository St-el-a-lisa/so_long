/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecid <ecid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:40:56 by ecid              #+#    #+#             */
/*   Updated: 2025/04/21 21:54:31 by ecid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_lines(char *file)
{
	int		fd;
	char	*line;
	int		lines;

	lines = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (lines);
}

static char	**allocate_map(int lines)
{
	char	**map;

	map = malloc(sizeof(char *) * (lines + 1));
	if (!map)
		return (NULL);
	return (map);
}

static int	load_lines(int fd, char **map)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		map[i] = ft_strtrim(line, "\n");
		free(line);
		if (!map[i])
			return (0);
		i++;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	return (1);
}

int	check_file_extension(const char *filename)
{
	int	len;

	len = strlen(filename);
	if (len < 4 || strcmp(filename + len - 4, ".ber") != 0)
	{
		return (0);
	}
	return (1);
}

char	**load_map(char *file)
{
	int		lines;
	char	**map;
	int		fd;

	if (!check_file_extension(file))
	{
		error_and_exit("Le fichier doit avoir l'extension .ber");
	}
	lines = count_lines(file);
	if (lines < 0)
		return (NULL);
	map = allocate_map(lines);
	if (!map)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0 || !load_lines(fd, map))
	{
		free(map);
		close(fd);
		return (NULL);
	}
	close(fd);
	return (map);
}
