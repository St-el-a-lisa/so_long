/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecid <ecid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:28:11 by ecid              #+#    #+#             */
/*   Updated: 2025/04/22 19:10:04 by ecid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "gnl/get_next_line.h"
# include "libft.h"
# include "libft/ft_printf/ft_printf.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct s_imgs
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*exit;
	void	*collectible;
}			t_imgs;

typedef struct _data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_data	img;
	t_imgs	imgs;
	char	**map;
	int		map_width;
	int		map_height;
	int		tile_size;
	int		player_x;
	int		player_y;
	int		move_count;
}			t_game;

void		print_map(char *file);
void		print_map_graphics(t_game *game);
char		**load_map(char *file);

void		load_images(void *mlx, t_imgs *imgs);
void		free_map(char **map);
void		free_all_resources(t_game *game);
int			close_window(t_game *game);
void		display_victory_message(t_game *game);

/* player moves*/
void		find_player_position(t_game *game);
void		move_player(t_game *game, int dx, int dy);
int			handle_keypress(int keycode, t_game *game);
void		move_count(t_game *game);

/*verification map*/
void		validate_map(t_game *game);
void		error_and_exit(const char *message);
int			check_elements(t_game *game);
int			check_chars(char **map, int height);
int			check_walls(char **map, int height);
int			check_rectangular(char **map, int height);
char		**copy_map(char **map, int height);
void		flood_fill(char **map, int x, int y);
int			acces_valid(char **map, int width, int height);
int			validate_path(t_game *game);

/*Taille de la fenetre*/
int			get_map_height(char **map);
int			get_map_width(char **map);

#endif