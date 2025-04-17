/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecid <ecid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:28:11 by ecid              #+#    #+#             */
/*   Updated: 2025/04/17 19:25:33 by ecid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "gnl/get_next_line.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>

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
}			t_game;

void		print_map(char *file);
void		print_map_graphics(void *mlx, void *win, t_data *img, char *file);
void		draw_square(t_data *data, int start_x, int start_y, int size,
				int color);
int			close_window(t_game *game);

#endif