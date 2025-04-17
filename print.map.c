/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecid <ecid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:40:56 by ecid              #+#    #+#             */
/*   Updated: 2025/04/17 16:27:52 by ecid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* colors
0xffffff -> blanc -> defaut/ sol
0x000000 -> noir -> mur
0x3399ff -> bleu -> joueur
0x66ff66 -> vert -> sortie
0xbb77cc -> rose -> collectibles
*/
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
	int		color;

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
			color = 0xffffff;
			if (line[x] == '1')
				color = 0x000000;
			else if (line[x] == '0')
				color = 0xffffff;
			else if (line[x] == 'P')
				color = 0x3399ff;
			else if (line[x] == 'E')
				color = 0x66ff66;
			else if (line[x] == 'C')
				color = 0xbb77cc;
			draw_square(img, x * tile_size, y * tile_size, tile_size, color);
			x++;
		}
		free(line);
		y++;
	}
	close(fd);
	mlx_put_image_to_window(mlx, win, img->img, 0, 0);
}
