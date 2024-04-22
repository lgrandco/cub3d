/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legrandc <legrandc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:48:55 by eghaffar          #+#    #+#             */
/*   Updated: 2024/04/22 00:02:39 by legrandc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*trim_new_line(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);
}

double	get_dist(t_cub *cub)
{
	if (cub->is_side)
		return (cub->side_y - cub->delta_y);
	return (cub->side_x - cub->delta_x);
}

int	is_valid_scene_character(char c, t_map *map_data)
{
	if (c == PLAYER_NORTH || c == PLAYER_SOUTH || c == PLAYER_EAST
		|| c == PLAYER_WEST)
	{
		map_data->flag_pos += 1;
		map_data->player_start_dir = c;
		return (EXIT_SUCCESS);
	}
	else if (c == FREE_WAY || c == WALL || (iss_space_cub(c)) || c == '\n'
		|| (BONUS && c == 'D'))
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

void	actualize_nb_of_col(char *line, int *nb_of_cols)
{
	int	actual_col;

	actual_col = ft_strlen(line);
	if (actual_col >= *nb_of_cols)
		*nb_of_cols = actual_col;
}
