/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_map_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghaffar <eghaffar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 21:17:30 by eghaffar          #+#    #+#             */
/*   Updated: 2024/04/21 22:56:39 by eghaffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	map_empty(t_map *map_data, t_cub *cub)
{
	if (map_data->y == 0 || map_data->x == 0)
		error_exit(cub, ERROR_FILE_EMPTY);
	return (EXIT_SUCCESS);
}

void	is_valid(int i, int j, t_cub *cub)
{
	char	c;

	c = cub->map_data->map[i][j];
	if ((c != WALL && c != FREE_WAY && c != PLAYER_NORTH && c != PLAYER_SOUTH
			&& c != PLAYER_EAST && c != PLAYER_WEST && c != 'D') || (c == 'D'
			&& !BONUS))
		error_exit(cub, "Error\n'0' or 'player' not well guarded.");
}

int	is_player_or_free_way(char c)
{
	return ((c == FREE_WAY || c == PLAYER_NORTH || c == PLAYER_SOUTH
			|| c == PLAYER_EAST || c == PLAYER_WEST) || (BONUS && c == 'D'));
}
