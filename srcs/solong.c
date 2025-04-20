/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecid <ecid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:40:56 by ecid              #+#    #+#             */
/*   Updated: 2025/04/20 18:37:15 by ecid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_game	game;
	int		height;
	int		width;
	int		tile_size;

	tile_size = 32;
	game.map = load_map("maps/map2_sujet.ber");
	height = get_map_height(game.map);
	width = get_map_width(game.map);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, width * tile_size, height * tile_size,
			"Window");
	game.img.img = mlx_new_image(game.mlx, width * tile_size, height
			* tile_size);
	game.img.addr = mlx_get_data_addr(game.img.img, &game.img.bits_per_pixel,
			&game.img.line_length, &game.img.endian);
	load_images(game.mlx, &game.imgs);
	validate_map(game.map, height);
	find_player_position(&game);
	print_map_graphics(game.mlx, game.win, &game.imgs, game.map);
	mlx_key_hook(game.win, handle_keypress, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop(game.mlx);
	return (0);
}
