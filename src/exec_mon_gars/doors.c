/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legrandc <legrandc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 22:55:59 by legrandc          #+#    #+#             */
/*   Updated: 2024/04/22 00:42:50 by legrandc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_doors(t_cub *cub)
{
	t_point	p;

	cub->doors = ft_calloc((cub->map_data->map_height + 1), sizeof(t_door *));
	if (!cub->doors)
		error_exit(cub, MALLOC_ERROR);
	p.y = 0;
	while (p.y < cub->map_data->map_height)
	{
		cub->doors[(int)p.y] = ft_calloc(cub->map_data->map_w + 1,
				sizeof(t_door));
		if (!cub->doors[(int)p.y])
			error_exit(cub, MALLOC_ERROR);
		p.x = -1;
		while (++p.x < cub->map_data->map_w)
		{
			if (cub->map_data->map[(int)p.y][(int)p.x] == 'D')
			{
				cub->doors[(int)p.y][(int)p.x].seen = false;
				cub->doors[(int)p.y][(int)p.x].state = CLOSED;
			}
			else
				cub->doors[(int)p.y][(int)p.x].state = OPENED;
		}
		p.y++;
	}
}

void	slide_door(t_cub *cub, int x, int y)
{
	if (cub->doors[y][x].state == OPENING && x != (int)cub->last.x
		&& y != (int)cub->last.y)
	{
		cub->doors[y][x].seg_len -= (double)1 / SPRITE_FRAMES;
		if (cub->doors[y][x].seg_len <= 0)
		{
			cub->doors[y][x].state = OPENED;
			cub->doors[y][x].seg_len = 0;
		}
	}
	else if (cub->doors[y][x].state == CLOSING && x != (int)cub->last.x
		&& y != (int)cub->last.y)
	{
		cub->doors[y][x].seg_len += (double)1 / SPRITE_FRAMES;
		if (cub->doors[y][x].seg_len >= 0.98)
		{
			cub->doors[y][x].state = CLOSED;
			cub->doors[y][x].seg_len = 0.98;
		}
	}
	if (cub->tex_x / cub->door.width < cub->doors[y][x].seg_len)
		cub->doors[y][x].seen = false;
	else
		cub->doors[y][x].seen = true;
}

bool	hit_door(t_cub *cub, int x, int y, bool sprites)
{
	if (!sprites || cub->map_data->map[y][x] != 'D'
		|| (cub->doors[y][x].seen == true && x == (int)cub->last.x
			&& y == (int)cub->last.y))
		return (cub->door_hit = 0, 0);
	cub->door_hit = true;
	get_wall_infos(cub);
	if (cub->doors[y][x].state == OPENED && cub->keys.f && get_dist(cub) <= 1.5
		&& !((int)cub->orient.pos_x / TILE_SIZE == x && (int)cub->orient.pos_y
			/ TILE_SIZE == y) && cub->cur_pix_x == SCREEN_W / 2)
		cub->doors[y][x].state = CLOSING;
	else if (cub->doors[y][x].state == CLOSED && cub->keys.f
		&& get_dist(cub) <= 1.5 && cub->cur_pix_x == SCREEN_W / 2)
	{
		cub->doors[y][x].state = OPENING;
		cub->doors[y][x].seg_len = 0.98;
	}
	else if (cub->doors[y][x].state == OPENED)
		return (cub->door_hit = 0, false);
	else if (cub->doors[y][x].state == CLOSED)
		return (true);
	slide_door(cub, x, y);
	cub->last.x = x;
	cub->last.y = y;
	return (cub->doors[y][x].seen == false);
}

void	draw_door(t_cub *cub, int c)
{
	double			i;
	unsigned int	color;
	double			step;

	step = 1.0 * cub->cur_img->height / cub->height;
	cub->tex_y = (cub->start - SCREEN_H / 2 + cub->height / 2) * step;
	i = cub->start;
	while (i >= cub->start && i < cub->end && i < SCREEN_H)
	{
		color = *(unsigned int *)(cub->cur_img->data + (int)cub->tex_y
				* cub->cur_img->size_line + (int)cub->tex_x * sizeof(int));
		img_pixel_put(&cub->main, c, i, color);
		cub->tex_y += step;
		i++;
	}
}
