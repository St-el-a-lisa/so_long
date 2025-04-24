/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecid <ecid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:40:56 by ecid              #+#    #+#             */
/*   Updated: 2025/04/24 19:45:09 by ecid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_victory_message(t_game *game)
{
	int		window_width;
	char	*message;
	int		text_x;

	window_width = game->map_width * game->tile_size;
	if (game->map_width <= 6)
	{
		message = "~ ^_^ ~";
		text_x = window_width / 2 - 30;
	}
	else
	{
		message = "Enjoy your latte!! ~ ^_^ ~";
		text_x = window_width / 2 - 100;
	}
	mlx_clear_window(game->mlx, game->win);
	mlx_string_put(game->mlx, game->win, text_x, (game->map_height
			* game->tile_size) / 2, 0xFF69B4, message);
	mlx_do_sync(game->mlx);
	sleep(2);
	close_window(game);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_all_resources(t_game *game)
{
	if (!game)
		return ;
	if (game->map)
		free_map(game->map);
	if (game->mlx)
	{
		if (game->imgs.wall)
			mlx_destroy_image(game->mlx, game->imgs.wall);
		if (game->imgs.floor)
			mlx_destroy_image(game->mlx, game->imgs.floor);
		if (game->imgs.player)
			mlx_destroy_image(game->mlx, game->imgs.player);
		if (game->imgs.exit)
			mlx_destroy_image(game->mlx, game->imgs.exit);
		if (game->imgs.collectible)
			mlx_destroy_image(game->mlx, game->imgs.collectible);
		if (game->img.img)
			mlx_destroy_image(game->mlx, game->img.img);
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

int	close_window(t_game *game)
{
	free_all_resources(game);
	exit(0);
	return (0);
}
