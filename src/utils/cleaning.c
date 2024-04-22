/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legrandc <legrandc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:07:22 by eghaffar          #+#    #+#             */
/*   Updated: 2024/04/21 05:55:55 by legrandc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	error_exit(t_cub *cub, char *message)
{
	if (message)
		ft_putendl_fd_cub(message, 2);
	free_cub(cub);
	if (cub->mlx && cub->doors)
		free_tab((void **)cub->doors);
	if (cub->mlx && cub->main.image)
		mlx_destroy_image(cub->mlx, cub->main.image);
	if (cub->mlx && cub->north.image)
		mlx_destroy_image(cub->mlx, cub->north.image);
	if (cub->mlx && cub->south.image)
		mlx_destroy_image(cub->mlx, cub->south.image);
	if (cub->mlx && cub->west.image)
		mlx_destroy_image(cub->mlx, cub->west.image);
	if (cub->mlx && cub->east.image)
		mlx_destroy_image(cub->mlx, cub->east.image);
	if (cub->mlx && cub->door.image)
		mlx_destroy_image(cub->mlx, cub->door.image);
	if (cub->mlx && cub->win)
		mlx_destroy_window(cub->mlx, cub->win);
	if (cub->mlx)
		mlx_destroy_display(cub->mlx);
	free(cub->mlx);
	free(cub);
	exit(message != NULL);
}

void	free_strs(char **map)
{
	int	i;

	i = 0;
	if (map == NULL)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_map_data(t_map *map_data)
{
	int	i;

	if (map_data)
	{
		if (map_data->map)
		{
			i = 0;
			while (map_data->map[i])
			{
				free(map_data->map[i]);
				i++;
			}
			free(map_data->map);
		}
		free(map_data);
		map_data = NULL;
	}
}

void	free_tab(void **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}

void	free_cub(t_cub *cub)
{
	if (!cub)
		return ;
	if (cub->north_texture)
		free(cub->north_texture);
	if (cub->south_texture)
		free(cub->south_texture);
	if (cub->west_texture)
		free(cub->west_texture);
	if (cub->east_texture)
		free(cub->east_texture);
	if (cub->map_data)
	{
		free_map_data(cub->map_data);
	}
}
