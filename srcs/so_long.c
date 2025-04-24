/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecid <ecid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:40:56 by ecid              #+#    #+#             */
/*   Updated: 2025/04/24 17:20:47 by ecid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_game(t_game *game, char *map_path)
{
	ft_bzero(game, sizeof(t_game));
	game->move_count = 0;
	game->tile_size = 32;
	game->map = load_map(map_path, game);
	if (!game->map)
		error_and_exit("Map loading failed", game);
	game->map_height = get_map_height(game->map);
	game->map_width = get_map_width(game->map);
	check_map_size(game);
	validate_map(game);
}

static void	init_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error_and_exit("Failed to initialize mlx", game);
	game->win = mlx_new_window(game->mlx, game->map_width * game->tile_size,
			game->map_height * game->tile_size,
			"~ ^_^ Marshmallow Barista ^_^ ~");
	game->img.img = mlx_new_image(game->mlx, game->map_width * game->tile_size,
			game->map_height * game->tile_size);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel,
			&game->img.line_length, &game->img.endian);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./so_long fichier.ber\n", 2);
		return (1);
	}
	init_game(&game, argv[1]);
	init_window(&game);
	load_images(game.mlx, &game.imgs, &game);
	find_player_position(&game);
	print_map_graphics(&game);
	mlx_key_hook(game.win, handle_keypress, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop(game.mlx);
	return (0);
}
