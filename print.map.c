/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecid <ecid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:40:56 by ecid              #+#    #+#             */
/*   Updated: 2025/04/16 22:23:51 by ecid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return ;
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line); // chaque ligne se termine déjà par \n
		free(line);
	}
	close(fd);
}

void	print_map_graphics(void *mlx, void *win, t_data *img, char *file)
{
	int		fd;
	char	*line;
	int		y;
	int		x;
	int		tile_size;

	tile_size = 32;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return ;
	}
	y = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		x = 0;
		while (line[x] && line[x] != '\n')
		{
			int color = 0xffffff; // blanc par défaut
			if (line[x] == '1')
				color = 0x000000; // mur = noir
			else if (line[x] == '0')
				color = 0xffffff; // sol = blanc
			else if (line[x] == 'P')
				color = 0x3399ff; // joueur = bleu
			else if (line[x] == 'E')
				color = 0x66ff66; // sortie = vert
			else if (line[x] == 'C')
				color = 0xbb77cc; // sortie = rose
			draw_square(img, x * tile_size, y * tile_size, tile_size, color);
			x++;
		}
		free(line);
		y++;
	}
	close(fd);
	mlx_put_image_to_window(mlx, win, img->img, 0, 0);
}
