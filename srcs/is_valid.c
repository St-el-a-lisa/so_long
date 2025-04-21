/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecid <ecid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:40:56 by ecid              #+#    #+#             */
/*   Updated: 2025/04/21 20:27:20 by ecid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rectangular(char **map, int height)
{
	int	i;
	int	width;
	int	len;

	width = ft_strlen(map[0]);
	i = 0;
	while (i < height)
	{
		len = ft_strlen(map[i]);
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
		if (map[0][x] != '1' || map[height - 1][x] != '1')
			return (0);
		x++;
	}
	y = 1;
	while (y < height - 1)
	{
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

void	validate_map(t_game *game)
{
	if (!check_rectangular(game->map, game->map_height))
		error_and_exit("La map n est pas rectangulaire!");
	if (!check_walls(game->map, game->map_height))
		error_and_exit("Il manque un ou des mur(s)!");
	if (!check_chars(game->map, game->map_height))
		error_and_exit("La carte contient un ou des caractères non valides!");
	if (!check_elements(game->map, game->map_height))
		error_and_exit("Vérifiez le nombre de P, E et C ;)");
	find_player_position(game);
	if (!validate_path(game->map, game->map_width, game->map_height,
			game->player_x, game->player_y))
		error_and_exit("Collectibles ou sortie inaccessibles !");
}
