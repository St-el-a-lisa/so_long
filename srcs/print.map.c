/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecid <ecid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:40:56 by ecid              #+#    #+#             */
/*   Updated: 2025/04/20 20:56:06 by ecid             ###   ########.fr       */
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

void	print_map_graphics(t_game *game)
{
	int		x;
	int		y;
	void	*img;
	char	tile;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			img = NULL;
			tile = game->map[y][x];
			if (tile == '1')
				img = game->imgs.wall;
			else if (tile == '0')
				img = game->imgs.floor;
			else if (tile == 'P')
				img = game->imgs.player;
			else if (tile == 'E')
				img = game->imgs.exit;
			else if (tile == 'C')
				img = game->imgs.collectible;
			if (img)
				mlx_put_image_to_window(game->mlx, game->win, img, x
					* game->tile_size, y * game->tile_size);
			x++;
		}
		y++;
	}
}

char	**load_map(char *file)
{
	int		fd;
	char	*line;
	char	**map;
	int		lines;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	lines = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		lines++;
		free(line);
	}
	close(fd);
	map = malloc(sizeof(char *) * (lines + 1));
	if (!map)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		free(map);
		return (NULL);
	}
	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		map[i] = ft_strtrim(line, "\n");
		free(line);
		if (!map[i])
		{
			while (--i >= 0)
				free(map[i]);
			free(map);
			close(fd);
			return (NULL);
		}
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}
