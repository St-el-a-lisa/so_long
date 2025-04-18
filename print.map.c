/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecid <ecid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:40:56 by ecid              #+#    #+#             */
/*   Updated: 2025/04/18 21:08:09 by ecid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* colors
0xffffff -> blanc -> defaut/ sol
0x000000 -> noir -> mur
0x3399ff -> bleu -> joueur
0x66ff66 -> vert -> sortie
0xbb77cc -> rose -> collectibles
*/
#include "libft/ft_printf/ft_printf.h"
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
		ft_printf("%s", line);
		free(line);
	}
	close(fd);
}

void	load_images(void *mlx, t_imgs *imgs)
{
	int	w;
	int	h;

	imgs->wall = mlx_xpm_file_to_image(mlx, "./assets/wall.xpm", &w, &h);
	imgs->floor = mlx_xpm_file_to_image(mlx, "./assets/floor.xpm", &w, &h);
	imgs->player = mlx_xpm_file_to_image(mlx, "./assets/player2.xpm", &w, &h);
	imgs->exit = mlx_xpm_file_to_image(mlx, "./assets/exit.xpm", &w, &h);
	imgs->collectible = mlx_xpm_file_to_image(mlx, "./assets/collectible.xpm",
			&w, &h);
}

void	print_map_graphics(void *mlx, void *win, t_imgs *imgs, char *file)

{
	int fd;
	int y;
	int x;
	int tile_size;
	char *line;

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
			if (line[x] == '1')
				mlx_put_image_to_window(mlx, win, imgs->wall, x * tile_size, y
					* tile_size);
			else if (line[x] == '0')
				mlx_put_image_to_window(mlx, win, imgs->floor, x * tile_size, y
					* tile_size);
			else if (line[x] == 'P')
				mlx_put_image_to_window(mlx, win, imgs->player, x * tile_size, y
					* tile_size);
			else if (line[x] == 'E')
				mlx_put_image_to_window(mlx, win, imgs->exit, x * tile_size, y
					* tile_size);
			else if (line[x] == 'C')
				mlx_put_image_to_window(mlx, win, imgs->collectible, x
					* tile_size, y * tile_size);
			x++;
		}
		free(line);
		y++;
	}

	close(fd);
}

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_image(game->mlx, game->img.img);
	// destroy img
	// destroy img
	// free game mlx
	// hand look !
	return (0);
}
