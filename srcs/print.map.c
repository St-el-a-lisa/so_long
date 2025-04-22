/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecid <ecid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:40:56 by ecid              #+#    #+#             */
/*   Updated: 2025/04/22 18:18:11 by ecid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	if (fd < 0)
	{
		perror("open");
		return ;
	}
	while (line != NULL)
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
	imgs->player = mlx_xpm_file_to_image(mlx, "./assets/player1.xpm", &w, &h);
	imgs->player_left = mlx_xpm_file_to_image(mlx, "./assets/player1_left.xpm",
			&w, &h);
	imgs->exit = mlx_xpm_file_to_image(mlx, "./assets/exit.xpm", &w, &h);
	imgs->collectible = mlx_xpm_file_to_image(mlx, "./assets/collectible.xpm",
			&w, &h);
	if (!imgs->wall || !imgs->floor || !imgs->player || !imgs->exit
		|| !imgs->collectible)
	{
		error_and_exit("!!! FAAILLLLEEDDD IMG!!! Bisous!!");
	}
}

static void	*get_tile_image(char tile, t_imgs *imgs)
{
	if (tile == '1')
		return (imgs->wall);
	if (tile == '0')
		return (imgs->floor);
	if (tile == 'P')
		return (imgs->player);
	if (tile == 'E')
		return (imgs->exit);
	if (tile == 'C')
		return (imgs->collectible);
	return (NULL);
}

void	print_map_graphics(t_game *game)
{
	int		x;
	int		y;
	void	*img;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			img = get_tile_image(game->map[y][x], &game->imgs);
			if (img)
				mlx_put_image_to_window(game->mlx, game->win, img, x
					* game->tile_size, y * game->tile_size);
			x++;
		}
		y++;
	}
}
