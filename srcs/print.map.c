/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecid <ecid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:40:56 by ecid              #+#    #+#             */
/*   Updated: 2025/04/19 19:02:36 by ecid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	print_map_graphics(void *mlx, void *win, t_imgs *imgs, char **map)
{
	int	tile_size;
	int	x;
	int	y;

	tile_size = 32;
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == '1')
				mlx_put_image_to_window(mlx, win, imgs->wall, x * tile_size, y
					* tile_size);
			else if (map[y][x] == '0')
				mlx_put_image_to_window(mlx, win, imgs->floor, x * tile_size, y
					* tile_size);
			else if (map[y][x] == 'P')
				mlx_put_image_to_window(mlx, win, imgs->player, x * tile_size, y
					* tile_size);
			else if (map[y][x] == 'E')
				mlx_put_image_to_window(mlx, win, imgs->exit, x * tile_size, y
					* tile_size);
			else if (map[y][x] == 'C')
				mlx_put_image_to_window(mlx, win, imgs->collectible, x
					* tile_size, y * tile_size);
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
		return (NULL);
	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		map[i++] = line;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}
