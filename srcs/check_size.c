/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecid <ecid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:40:56 by ecid              #+#    #+#             */
/*   Updated: 2025/04/24 17:12:01 by ecid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map_height(char **map)
{
	int	height;

	height = 0;
	while (map[height])
		height++;
	return (height);
}

int	get_map_width(char **map)
{
	return (ft_strlen(map[0]));
}

int	check_map_size(t_game *game)
{
	int	max_width;
	int	max_height;
	int	window_width;
	int	window_height;

	max_width = 1920;
	max_height = 1080;
	window_width = game->map_width * game->tile_size;
	window_height = game->map_height * game->tile_size;
	if (window_width > max_width || window_height > max_height)
	{
		error_and_exit("Map exceeds screen size!", game);
	}
	return (1);
}
