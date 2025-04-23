/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecid <ecid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:40:56 by ecid              #+#    #+#             */
/*   Updated: 2025/04/23 19:33:29 by ecid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	game.tile_size = 32;
	game.map = load_map("maps/map1_sujet.ber", &game);
	if (!game.map)
		error_and_exit("Échec du chargement de la map", &game);
	game.map_height = get_map_height(game.map);
	game.map_width = get_map_width(game.map);
	validate_map(&game);
	game.mlx = mlx_init();
	if (!game.mlx)
		error_and_exit("Échec de l'initialisation de mlx", &game);
	game.win = mlx_new_window(game.mlx, game.map_width * game.tile_size,
			game.map_height * game.tile_size,
			"~ ^_^ Marshmallow Barista ^_^ ~");
	game.img.img = mlx_new_image(game.mlx, game.map_width * game.tile_size,
			game.map_height * game.tile_size);
	game.img.addr = mlx_get_data_addr(game.img.img, &game.img.bits_per_pixel,
			&game.img.line_length, &game.img.endian);
	load_images(game.mlx, &game.imgs, &game);
	find_player_position(&game);
	print_map_graphics(&game);
	mlx_key_hook(game.win, handle_keypress, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop(game.mlx);
	return (0);
}
