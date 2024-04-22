/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_around.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghaffar <eghaffar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:51:20 by eghaffar          #+#    #+#             */
/*   Updated: 2024/04/21 22:51:53 by eghaffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	**find_the_end_of_the_map(t_cub *cub, char **map)
{
	char	c;
	int		j;

	c = 'a';
	cub->map_data->beg_index = cub->map_data->i_begin_the_map + 1;
	while (map[cub->map_data->beg_index + 1])
	{
		j = 0;
		while (map[cub->map_data->beg_index + 1][j])
		{
			if ((map[cub->map_data->beg_index + 1][j] == '\n'
				|| map[cub->map_data->beg_index + 1][j] == '\0')
				&& c == '\n')
				cub->map_data->j_end_of_map = j;
			c = map[cub->map_data->beg_index + 1][j];
			j++;
		}
		if (cub->map_data->j_end_of_map == j)
			break ;
		cub->map_data->beg_index++;
	}
	return (map);
}

int	under_the_map(t_cub *cub)
{
	char	**map;
	int		j;

	j = 0;
	map = cub->map_data->map;
	map = find_the_end_of_the_map(cub, map);
	cub->map_data->end_i = cub->map_data->beg_index;
	cub->map_data->end_j = cub->map_data->j_end_of_map;
	while (map[cub->map_data->beg_index + 1])
	{
		j = 0;
		while (map[cub->map_data->beg_index + 1][j] != '\0')
		{
			if (map[cub->map_data->beg_index + 1][j] != SPACES)
				error_exit(cub, INV_UNDER_THE_MAP);
			j++;
		}
		cub->map_data->beg_index++;
	}
	return (0);
}
