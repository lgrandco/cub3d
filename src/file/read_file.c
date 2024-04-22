/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghaffar <eghaffar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 09:40:55 by eghaffar          #+#    #+#             */
/*   Updated: 2024/04/22 01:05:47 by eghaffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	open_for_the_xpm(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY | __O_DIRECTORY);
	if (fd > 0)
	{
		close(fd);
		return (EXIT_FAILURE);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (EXIT_FAILURE);
	close(fd);
	return (EXIT_SUCCESS);
}

int	open_for_the_map(t_map *map_data)
{
	map_data->fd = open(map_data->map_name, O_RDONLY | __O_DIRECTORY);
	if (map_data->fd > 0)
	{
		close(map_data->fd);
		return (EXIT_FAILURE);
	}
	map_data->fd = open(map_data->map_name, O_RDONLY);
	if (map_data->fd == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	alloc_and_stock_lines(t_map *map_data)
{
	if (open_for_the_map(map_data) == -1)
		return (EXIT_FAILURE);
	map_data->map = ft_calloc(map_data->y + 1, sizeof(char *));
	if (!map_data->map)
	{
		close(map_data->fd);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
