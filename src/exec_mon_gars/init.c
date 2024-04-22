/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghaffar <eghaffar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 05:33:07 by legrandc          #+#    #+#             */
/*   Updated: 2024/04/21 20:01:53 by eghaffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_mlx(t_cub *cub)
{
	cub->mlx = mlx_init();
	if (!cub->mlx)
		error_exit(cub, "Error\nmlx_init() failed");
	cub->main.image = mlx_new_image(cub->mlx, SCREEN_W, SCREEN_H);
	if (!cub->main.image)
		error_exit(cub, "Error\nmlx_new_image() failed");
	cub->main.data = mlx_get_data_addr(cub->main.image, &cub->main.bpp,
			&cub->main.size_line, &cub->main.type);
	cub->door.image = mlx_xpm_file_to_image(cub->mlx, "./textures/door.xpm",
			&cub->door.width, &cub->door.height);
	if (!cub->door.image)
		error_exit(cub, "Error\nDoor texture not found\n");
	cub->door.data = mlx_get_data_addr(cub->door.image, &cub->door.bpp,
			&cub->door.size_line, &cub->door.type);
	cub->doors = NULL;
	cub->north.image = NULL;
	cub->south.image = NULL;
	cub->west.image = NULL;
	cub->east.image = NULL;
	cub->win = NULL;
	cub->orient.pos_x = cub->map_data->pos_map_x * TILE_SIZE + TILE_SIZE * .5;
	cub->orient.pos_y = cub->map_data->pos_map_y * TILE_SIZE + TILE_SIZE * .5;
	cub->keys.ctrl = 0;
}

void	init_imgs(t_cub *cub)
{
	cub->north.image = mlx_xpm_file_to_image(cub->mlx, cub->north_texture,
			&cub->north.width, &cub->north.height);
	cub->south.image = mlx_xpm_file_to_image(cub->mlx, cub->south_texture,
			&cub->south.width, &cub->south.height);
	cub->east.image = mlx_xpm_file_to_image(cub->mlx, cub->east_texture,
			&cub->east.width, &cub->east.height);
	cub->west.image = mlx_xpm_file_to_image(cub->mlx, cub->west_texture,
			&cub->west.width, &cub->west.height);
	if (!cub->north.image || !cub->south.image || !cub->east.image
		|| !cub->west.image)
		error_exit(cub, "Error\nMLX_XPM_FILE_TO_IMG.");
	cub->north.data = mlx_get_data_addr(cub->north.image, &cub->north.bpp,
			&cub->north.size_line, &cub->north.type);
	cub->south.data = mlx_get_data_addr(cub->south.image, &cub->south.bpp,
			&cub->south.size_line, &cub->south.type);
	cub->east.data = mlx_get_data_addr(cub->east.image, &cub->east.bpp,
			&cub->east.size_line, &cub->east.type);
	cub->west.data = mlx_get_data_addr(cub->west.image, &cub->west.bpp,
			&cub->west.size_line, &cub->west.type);
	cub->win = mlx_new_window(cub->mlx, SCREEN_W, SCREEN_H, "cub3D");
	if (!cub->win)
		error_exit(cub, "Error\nmlx_new_window() failed");
}

void	init_orientation(t_cub *cub)
{
	cub->dir.x = 0.00;
	cub->dir.y = 0.00;
	cub->plane.x = 0.00;
	cub->plane.y = 0.00;
	if (cub->map_data->player_start_dir == 'N')
	{
		cub->dir.y = -1;
		cub->plane.x = FOV / 100;
	}
	else if (cub->map_data->player_start_dir == 'S')
	{
		cub->dir.y = 1;
		cub->plane.x = -FOV / 100;
	}
	else if (cub->map_data->player_start_dir == 'E')
	{
		cub->dir.x = 1;
		cub->plane.y = FOV / 100;
	}
	else if (cub->map_data->player_start_dir == 'W')
	{
		cub->dir.x = -1;
		cub->plane.y = -FOV / 100;
	}
}
