/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghaffar <eghaffar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 04:23:11 by legrandc          #+#    #+#             */
/*   Updated: 2024/04/21 20:04:24 by eghaffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	calculate_dist(t_cub *cub, bool s)
{
	double	x;
	double	y;

	cub->delta_x = fabs(1 / cub->ray_dir.x);
	cub->delta_y = fabs(1 / cub->ray_dir.y);
	x = cub->orient.pos_x / TILE_SIZE;
	y = cub->orient.pos_y / TILE_SIZE;
	while (cub->map_data->map[(int)y][(int)x] != '1' && !hit_door(cub, x, y, s))
	{
		if (cub->side_x < cub->side_y)
		{
			cub->side_x += cub->delta_x;
			x += cub->ray.step_x;
			cub->is_side = 0;
		}
		else
		{
			cub->side_y += cub->delta_y;
			y += cub->ray.step_y;
			cub->is_side = 1;
		}
	}
	cub->ray.dist_to_the_wall = get_dist(cub);
}

void	draw_ray(t_cub *cub, int c)
{
	int				i;
	unsigned int	color;
	double			step;

	step = 1.0 * cub->cur_img->height / cub->height;
	cub->tex_y = (cub->start - SCREEN_H / 2 + cub->height / 2) * step;
	i = 0;
	while (i < SCREEN_H)
	{
		if (i < cub->start)
			img_pixel_put(&cub->main, c, i, cub->ceiling_color);
		else if (i >= cub->start && i < cub->end)
		{
			color = *(unsigned int *)(cub->cur_img->data + (int)cub->tex_y
					* cub->cur_img->size_line + (int)cub->tex_x * sizeof(int));
			img_pixel_put(&cub->main, c, i, color);
			cub->tex_y += step;
		}
		else
			img_pixel_put(&cub->main, c, i, cub->floor_color);
		i++;
	}
}

void	get_wall_infos(t_cub *cub)
{
	if (cub->door_hit)
		cub->cur_img = &cub->door;
	else if (!cub->door_hit && cub->is_side && cub->ray_dir.y < 0)
		cub->cur_img = &cub->south;
	else if (!cub->door_hit && cub->is_side)
		cub->cur_img = &cub->north;
	else if (!cub->door_hit && cub->ray_dir.x < 0)
		cub->cur_img = &cub->east;
	else if (!cub->door_hit)
		cub->cur_img = &cub->west;
	if (!cub->is_side)
		cub->tex_x = cub->orient.pos_y / TILE_SIZE + cub->ray.dist_to_the_wall
			* cub->ray_dir.y;
	else
		cub->tex_x = cub->orient.pos_x / TILE_SIZE + cub->ray.dist_to_the_wall
			* cub->ray_dir.x;
	cub->tex_x = (cub->tex_x - (int)cub->tex_x) * cub->cur_img->width;
	if ((!cub->is_side && cub->ray_dir.x < 0) || (cub->is_side
			&& cub->ray_dir.y > 0))
		cub->tex_x = cub->cur_img->width - cub->tex_x - 1;
	if (cub->tex_x < 0)
		cub->tex_x = 0;
	cub->height = SCREEN_H / cub->ray.dist_to_the_wall;
	cub->start = (SCREEN_H - cub->height) / 2;
}

void	start_data(t_cub *cub)
{
	if (cub->ray_dir.x < 0)
	{
		cub->ray.step_x = -1;
		cub->side_x = ((double)cub->orient.pos_x / TILE_SIZE
				- (int)cub->orient.pos_x / TILE_SIZE) * cub->delta_x;
	}
	else
	{
		cub->ray.step_x = 1;
		cub->side_x = ((int)cub->orient.pos_x / TILE_SIZE + 1.0
				- (double)cub->orient.pos_x / TILE_SIZE) * cub->delta_x;
	}
	if (cub->ray_dir.y < 0)
	{
		cub->ray.step_y = -1;
		cub->side_y = ((double)cub->orient.pos_y / TILE_SIZE
				- (int)cub->orient.pos_y / TILE_SIZE) * cub->delta_y;
	}
	else
	{
		cub->ray.step_y = 1;
		cub->side_y = ((int)cub->orient.pos_y / TILE_SIZE + 1.0
				- (double)cub->orient.pos_y / TILE_SIZE) * cub->delta_y;
	}
}

void	raycasting(t_cub *cub, bool sprites)
{
	double	camera_x;

	cub->last.x = -1;
	cub->last.y = -1;
	cub->cur_pix_x = 0;
	while (cub->cur_pix_x < SCREEN_W)
	{
		camera_x = 2 * cub->cur_pix_x / (double)SCREEN_W - 1;
		cub->ray_dir.x = cub->dir.x + cub->plane.x * camera_x;
		cub->ray_dir.y = cub->dir.y + cub->plane.y * camera_x;
		start_data(cub);
		cub->door_hit = false;
		calculate_dist(cub, sprites);
		get_wall_infos(cub);
		if (cub->start < 0)
			cub->start = 0;
		cub->end = cub->start + cub->height;
		if (!sprites)
			draw_ray(cub, cub->cur_pix_x);
		if (sprites && cub->door_hit == 1)
			draw_door(cub, cub->cur_pix_x);
		cub->cur_pix_x++;
	}
}
