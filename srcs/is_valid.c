/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecid <ecid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:40:56 by ecid              #+#    #+#             */
/*   Updated: 2025/04/22 16:07:42 by ecid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_and_exit(const char *message)
{
	ft_printf("Error\n%s\n", message);
	exit(EXIT_FAILURE);
}

void	validate_map(t_game *game)
{
	if (!check_rectangular(game->map, game->map_height))
		error_and_exit("La map n est pas rectangulaire!");
	if (!check_walls(game->map, game->map_height))
		error_and_exit("Il manque un ou des mur(s)!");
	if (!check_chars(game->map, game->map_height))
		error_and_exit("La carte contient un ou des caractères non valides!");
	if (!check_elements(game->map, game->map_height))
		error_and_exit("Vérifiez le nombre de P, E et C ;)");
	find_player_position(game);
	if (!validate_path(game->map, game->map_width, game->map_height,
			game->player_x, game->player_y))
		error_and_exit("Collectibles ou sortie inaccessibles !");
}
