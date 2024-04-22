/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghaffar <eghaffar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:52:20 by eghaffar          #+#    #+#             */
/*   Updated: 2024/04/22 01:48:20 by eghaffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	nb_lines_and_col(t_map *map_data)
{
	int	lines;
	int	nb_of_cols;

	nb_of_cols = 0;
	if (open_for_the_map(map_data) == 1)
	{
		ft_putendl_fd_cub("Error\nProblem with path to map.", 2);
		return (EXIT_FAILURE);
	}
	lines = 0;
	while (1)
	{
		map_data->line = get_next_line(map_data->fd);
		if (map_data->line == NULL)
			break ;
		actualize_nb_of_col(map_data->line, &nb_of_cols);
		free(map_data->line);
		lines++;
	}
	close(map_data->fd);
	map_data->y = lines;
	map_data->x = nb_of_cols;
	return (0);
}

char	**read_file_lines(t_map *map_data)
{
	int	i;

	if (alloc_and_stock_lines(map_data) == 1)
	{
		ft_putendl_fd_cub("Error\nAllocation new line", 2);
		return (NULL);
	}
	i = 0;
	while (i <= map_data->y)
	{
		map_data->line = get_next_line(map_data->fd);
		if (!map_data->line)
			break ;
		trim_new_line(map_data->line);
		map_data->map[i] = map_data->line;
		i++;
	}
	map_data->map[i] = NULL;
	close(map_data->fd);
	return (map_data->map);
}
