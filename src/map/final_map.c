/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghaffar <eghaffar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 09:49:21 by eghaffar          #+#    #+#             */
/*   Updated: 2024/04/21 14:44:02 by eghaffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	**malloc_the_map(t_cub *cub, int i)
{
	int		j;
	char	**map_cpy;

	i = cub->map_data->end_i - cub->map_data->i_begin_the_map;
	map_cpy = ft_calloc((i + 2), sizeof(char *));
	if (map_cpy == NULL)
		error_exit(cub, "Error\nMemory allocation failed.\n");
	j = 0;
	while (j <= cub->map_data->end_i - cub->map_data->i_begin_the_map)
	{
		map_cpy[j] = ft_calloc((cub->map_data->x + 1), sizeof(char));
		if (map_cpy[j] == NULL)
		{
			free_tab((void **)map_cpy);
			error_exit(cub, "Error\nMemory allocation failed.\n");
		}
		j++;
	}
	return (map_cpy);
}

void	retrieve_the_final_map(t_map *map_data, t_cub *cub)
{
	int		i;
	int		j;
	char	**map_final;
	int		i_final;

	i = 0;
	i_final = 0;
	map_final = malloc_the_map(cub, i);
	i = map_data->i_begin_the_map;
	while (i <= map_data->end_i)
	{
		j = 0;
		while (map_data->map[i][j])
		{
			if (map_data->map[i][j] == ' ')
				map_final[i_final][j] = '1';
			else
				map_final[i_final][j] = map_data->map[i][j];
			j++;
		}
		i++;
		i_final++;
	}
	free_tab((void **)map_data->map);
	map_data->map = map_final;
}
