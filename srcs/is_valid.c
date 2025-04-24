/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecid <ecid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:40:56 by ecid              #+#    #+#             */
/*   Updated: 2025/04/24 17:17:43 by ecid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_and_exit(const char *message, t_game *game)
{
	if (game)
		free_all_resources(game);
	ft_printf("Error\n%s\n", message);
	exit(EXIT_FAILURE);
}

void	validate_map(t_game *game)
{
	if (!check_rectangular(game->map, game->map_height))
		error_and_exit("Map is not rectangular!", game);
	if (!check_walls(game->map, game->map_height))
		error_and_exit("Missing one or more walls!", game);
	if (!check_chars(game->map, game->map_height))
		error_and_exit("Map contains one or more invalid characters!", game);
	if (!check_elements(game))
		error_and_exit("Check the number of P, E, and C ;)", game);
	find_player_position(game);
	if (!validate_path(game))
		error_and_exit("Collectibles or exit unreachable!", game);
}
