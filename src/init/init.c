/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghaffar <eghaffar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 20:26:59 by eghaffar          #+#    #+#             */
/*   Updated: 2024/04/22 01:37:54 by eghaffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "struct.h"

void	setup_initial_cub(t_cub *cub)
{
	cub->ceiling_color = -1;
	cub->floor_color = -1;
}

t_map	*init_the_map_data(char *filename)
{
	t_map	*map_data;

	map_data = ft_calloc(1, sizeof(t_map));
	if (!map_data)
		return (NULL);
	map_data->map_name = filename;
	return (map_data);
}

int	count_and_read(t_map *map_data)
{
	if (nb_lines_and_col(map_data))
		return (EXIT_FAILURE);
	if (!read_file_lines(map_data))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	init_pos_and_dim(t_map *map_data)
{
	int	i;
	int	j;

	i = 0;
	while (map_data->map[i])
	{
		j = 0;
		while (map_data->map[i][j])
		{
			if (map_data->map[i][j] == PLAYER_EAST
				|| map_data->map[i][j] == PLAYER_WEST
				|| map_data->map[i][j] == PLAYER_NORTH
				|| map_data->map[i][j] == PLAYER_SOUTH)
			{
				map_data->pos_map_x = j;
				map_data->pos_map_y = i;
				map_data->map[i][j] = '0';
			}
			j++;
		}
		if (map_data->map_w < j)
			map_data->map_w = j;
		i++;
	}
	map_data->map_height = i;
}
