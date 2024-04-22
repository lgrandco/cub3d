/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legrandc <legrandc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 02:36:20 by legrandc          #+#    #+#             */
/*   Updated: 2024/04/21 10:11:04 by legrandc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_down(t_cub *cub)
{
	double	new_x;
	double	new_y;

	new_y = cub->orient.pos_y - cub->dir.y * MOVE_SPEED;
	new_x = cub->orient.pos_x - cub->dir.x * MOVE_SPEED;
	move_player(cub, new_x, new_y);
}

void	move_up(t_cub *cub)
{
	double	new_x;
	double	new_y;

	new_y = cub->orient.pos_y + cub->dir.y * MOVE_SPEED;
	new_x = cub->orient.pos_x + cub->dir.x * MOVE_SPEED;
	move_player(cub, new_x, new_y);
}

void	move_left(t_cub *cub)
{
	double	new_x;
	double	new_y;

	new_y = cub->orient.pos_y - cub->dir.x * MOVE_SPEED;
	new_x = cub->orient.pos_x + cub->dir.y * MOVE_SPEED;
	move_player(cub, new_x, new_y);
}

void	move_right(t_cub *cub)
{
	double	new_x;
	double	new_y;

	new_y = cub->orient.pos_y + cub->dir.x * MOVE_SPEED;
	new_x = cub->orient.pos_x - cub->dir.y * MOVE_SPEED;
	move_player(cub, new_x, new_y);
}

void	move_player(t_cub *cub, double new_x, double new_y)
{
	if (!BONUS && cub->map_data->map[(int)new_y
			/ TILE_SIZE][(int)cub->orient.pos_x / TILE_SIZE] != '1'
		&& cub->map_data->map[(int)cub->orient.pos_y / TILE_SIZE][(int)new_x
		/ TILE_SIZE] != '1' && cub->map_data->map[(int)new_y
		/ TILE_SIZE][(int)new_x / TILE_SIZE] != '1')
	{
		cub->orient.pos_x = new_x;
		cub->orient.pos_y = new_y;
	}
	if (!BONUS)
		return ;
	if (cub->map_data->map[(int)new_y / TILE_SIZE][(int)cub->orient.pos_x
		/ TILE_SIZE] != '1' && (cub->doors[(int)new_y
			/ TILE_SIZE][(int)cub->orient.pos_x / TILE_SIZE].state == OPENED
			|| cub->doors[(int)new_y / TILE_SIZE][(int)cub->orient.pos_x
			/ TILE_SIZE].state == OPENING))
		cub->orient.pos_y = new_y;
	if (cub->map_data->map[(int)cub->orient.pos_y / TILE_SIZE][(int)new_x
		/ TILE_SIZE] != '1' && (cub->doors[(int)cub->orient.pos_y
			/ TILE_SIZE][(int)new_x / TILE_SIZE].state == OPENED
			|| cub->doors[(int)cub->orient.pos_y / TILE_SIZE][(int)new_x
			/ TILE_SIZE].state == OPENING))
		cub->orient.pos_x = new_x;
	minimapping(cub);
}
