/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecid <ecid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:40:56 by ecid              #+#    #+#             */
/*   Updated: 2025/04/19 21:40:50 by ecid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_printf/ft_printf.h"
#include "so_long.h"

int	get_map_height(char **map)
{
	int	height;

	height = 0;
	while (map[height])
		height++;
	return (height);
}
int	check_rectangular(char **map, int height)
{
	int	i;
	int	width;
	int	len;

	width = ft_strlen(map[0]);
	if (map[0][width - 1] == '\n')
		width--;
	i = 0;
	while (i < height)
	{
		len = ft_strlen(map[i]);
		if (map[i][len - 1] == '\n')
			len--;
		if (len != width)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_walls(char **map, int height)
{
	int	x;
	int	y;
	int	width;

	width = ft_strlen(map[0]);
	x = 0;
	while (x < width)
	{
		if (map[0][x] == '\n' || map[height - 1][x] == '\n')
			break ;
		if (map[0][x] != '1' || map[height - 1][x] != '1')
			return (0);
		x++;
	}
	y = 1;
	while (y < height - 1)
	{
		if (map[y][0] == '\n' || map[y][width - 1] == '\n')
			break ;
		if (map[y][0] != '1' || map[y][width - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}
int	check_chars(char **map, int height)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	while (y < height)
	{
		x = 0;
		while ((c = map[y][x]))
		{
			if (c == '\n')
			{
				x++;
				continue ;
			}
			if (c != '0' && c != '1' && c != 'P' && c != 'C' && c != 'E')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	check_elements(char **map, int height)
{
	int	y;
	int	x;
	int	p_count;
	int	e_count;
	int	c_count;

	p_count = 0;
	e_count = 0;
	c_count = 0;
	y = 0;
	while (y < height)
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				p_count++;
			else if (map[y][x] == 'E')
				e_count++;
			else if (map[y][x] == 'C')
				c_count++;
			x++;
		}
		y++;
	}
	if (p_count != 1 || e_count != 1 || c_count < 1)
		return (0);
	return (1);
}

void	error_and_exit(const char *message)
{
	ft_printf("Error\n%s\n", message);
	exit(EXIT_FAILURE);
}

void	validate_map(char **map, int height)
{
	if (!check_rectangular(map, height))
		error_and_exit("Map is not rectangular");
	if (!check_walls(map, height))
		error_and_exit("Map is not surrounded by walls (1)");
	if (!check_chars(map, height))
		error_and_exit("Map contains invalid characters");
	if (!check_elements(map, height))
		error_and_exit("Error\nInvalid number of P, E, or C\n");
}

// char	**copy_map(char **map, int height)
// {
// 	char	**new_map;
// 	int		i;

// 	new_map = malloc(sizeof(char *) * (height + 1));
// 	if (!new_map)
// 		return (NULL);
// 	i = 0;
// 	while (i < height)
// 	{
// 		new_map[i] = ft_strdup(map[i]);
// 		if (!new_map[i])
// 		{
// 			while (--i >= 0)
// 				free(new_map[i]);
// 			free(new_map);
// 			return (NULL);
// 		}
// 		i++;
// 	}
// 	new_map[i] = NULL;
// 	return (new_map);
// }
// void	free_map(char **map)
// {
// 	int	i;

// 	i = 0;
// 	while (map[i])
// 	{
// 		free(map[i]);
// 		i++;
// 	}
// 	free(map);
// }
