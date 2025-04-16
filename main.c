/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecid <ecid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:40:56 by ecid              #+#    #+#             */
/*   Updated: 2025/04/16 21:50:12 by ecid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_square(t_data *data, int start_x, int start_y, int size, int color)
{
	int	x;
	int	y;

	y = start_y;
	while (y < start_y + size)
	{
		x = start_x;
		while (x < start_x + size)
		{
			*(unsigned int *)(data->addr + (y * data->line_length + x
						* (data->bits_per_pixel / 8))) = color;
			x++;
		}
		y++;
	}
}

int	main(void)
{
	void	*mlx;
	void	*win;
	t_data	img;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 320, 320, "Window");
	img.img = mlx_new_image(mlx, 320, 320);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	// carre rose
	// draw_square(&img, 100, 100, 100, 0xbb77cc);
	// affichage du carre rose
	// mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	print_map_graphics(mlx, win, &img, "maps/map_test.ber");
	// la boucle principale
	mlx_loop(mlx);
	return (0);
}
