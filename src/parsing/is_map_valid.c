/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghaffar <eghaffar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 22:57:11 by eghaffar          #+#    #+#             */
/*   Updated: 2024/04/22 01:46:51 by eghaffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	validate_map_characters_and_pos(t_map *map_data, t_cub *cub)
{
	int	i;
	int	j;

	i = map_data->i_begin_the_map;
	while (map_data->map[i])
	{
		j = 0;
		while (map_data->map[i][j])
		{
			if (is_valid_scene_character(map_data->map[i][j], map_data))
				error_exit(cub, INVALID_CHAR_MSG);
			j++;
		}
		i++;
	}
	if (map_data->flag_pos != 1)
		error_exit(cub, INVALID_POSITION);
}

void	find_map_boundaries(t_map *map_data, t_cub *cub)
{
	int	j;
	int	i;

	i = map_data->i_end_of_tc;
	while (map_data->map[i])
	{
		j = 0;
		while (map_data->map[i][j] && (iss_space_cub(map_data->map[i][j])))
			j++;
		if (map_data->map[i][j] && (map_data->map[i][j] != '\n'
				|| iss_space_cub(map_data->map[i][j])))
			break ;
		i++;
	}
	if (!map_data->map[i])
		error_exit(cub, ERROR_MAP_EMPTY);
	map_data->i_begin_the_map = i;
}

void	validate_texture_files(t_cub *cub)
{
	if (check_if_xpm(cub->north_texture) || check_if_xpm(cub->south_texture)
		|| check_if_xpm(cub->east_texture) || check_if_xpm(cub->west_texture))
		error_exit(cub, INV_EXT_XPM);
	if (open_for_the_xpm(cub->north_texture)
		|| open_for_the_xpm(cub->south_texture)
		|| open_for_the_xpm(cub->east_texture)
		|| open_for_the_xpm(cub->west_texture))
		error_exit(cub, "Error\nProblem with path to texture.");
}

void	validate_texture_and_color(t_map *map_data, t_cub *cub)
{
	int	i;

	i = 0;
	while (map_data->map[i])
	{
		if (!check_texture_and_color(map_data->map[i], cub))
			error_exit(cub, "Error\nWith map mandatory elements.");
		if (cub->flag == 6)
		{
			map_data->i_end_of_tc = i + 1;
			break ;
		}
		else
			i++;
	}
	if (cub->flag != 6)
		error_exit(cub, "Error\nWrong number of element's map.");
}
