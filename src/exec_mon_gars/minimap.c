/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghaffar <eghaffar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 08:31:57 by eghaffar          #+#    #+#             */
/*   Updated: 2024/04/21 20:20:05 by eghaffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	my_mlx_pixel_put(t_img *image, int x, int y, int color)
{
	*(unsigned int *)(image->data + (y * image->size_line + x * (image->bpp
					/ 8))) = color;
}

void	fill_the_cell(t_cub *cub, t_point *mini, int color, int x_map)
{
	int			i;
	int			j;
	bool static	clignote;

	i = 0;
	(void)x_map;
	while (i < 10 && mini->y + i < SCREEN_H)
	{
		j = 0;
		while ((j < 10) && mini->x + j < SCREEN_W)
		{
			if (clignote || color == PLAYER_COLOR)
				my_mlx_pixel_put(&cub->main, mini->x + j, mini->y + i, color);
			clignote = (clignote == false);
			j++;
		}
		i++;
	}
}

void	fill_the_char(t_cub *cub, t_point *mini, int i, int j)
{
	if (i == floor(cub->orient.pos_y / TILE_SIZE)
		&& j == floor(cub->orient.pos_x / TILE_SIZE))
		fill_the_cell(cub, mini, PLAYER_COLOR, j);
	else if (cub->map_data->map[i][j] == '0')
		fill_the_cell(cub, mini, WAY_COLOR, j);
	else if (cub->map_data->map[i][j] == '1')
		fill_the_cell(cub, mini, WALL_COLOR, j);
	else if (cub->map_data->map[i][j] == '2')
		fill_the_cell(cub, mini, DOOR_COLOR, j);
	mini->x += 10;
}

void	minimapping(t_cub *cub)
{
	int		i;
	int		j;
	t_point	mini;

	mini.y = 10;
	i = 0;
	i = (int)(cub->orient.pos_y / TILE_SIZE) - 10;
	if (i < 0)
		i = 0;
	while (cub->map_data->map[i] && i < (int)(cub->orient.pos_y / TILE_SIZE)
		+ 10)
	{
		j = (int)(cub->orient.pos_x / TILE_SIZE) - 10;
		if (j < 0)
			j = 0;
		mini.x = 10;
		while (cub->map_data->map[i][j] && j < (int)(cub->orient.pos_x
				/ TILE_SIZE) + 10)
		{
			fill_the_char(cub, &mini, i, j);
			j++;
		}
		i++;
		mini.y += 10;
	}
}
