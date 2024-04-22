/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_the_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legrandc <legrandc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:31:00 by eghaffar          #+#    #+#             */
/*   Updated: 2024/04/21 23:12:50 by legrandc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_cursor(t_cub *cub)
{
	int	x;
	int	y;

	x = SCREEN_W / 2 - 10;
	y = SCREEN_H / 2 - 10;
	while (y < SCREEN_H / 2 + 10)
	{
		img_pixel_put(&cub->main, SCREEN_W / 2, y, 0x0000FF00);
		if (y == SCREEN_H / 2)
		{
			while (x < SCREEN_W / 2 + 10)
			{
				img_pixel_put(&cub->main, x, y, 0x0000FF00);
				x++;
			}
		}
		y++;
	}
}

void	draw_dot(t_cub *cub, int size)
{
	int	x;
	int	y;

	y = abs(SCREEN_H / 2 - size);
	while (y < SCREEN_H / 2 + size + size)
	{
		x = abs(SCREEN_W / 2 - size);
		while (x < SCREEN_W / 2 + size)
		{
			img_pixel_put(&cub->main, x, y, 0x00FFFFFF);
			x++;
		}
		y++;
	}
}

int	render_frame(void *poly_param)
{
	t_cub	*cub;

	cub = poly_param;
	hook(cub);
	raycasting(cub, false);
	if (BONUS)
	{
		raycasting(cub, true);
		if (cub->keys.ctrl)
			draw_cursor(cub);
		else
			draw_dot(cub, 2);
		minimapping(cub);
	}
	cub->door_hit = false;
	mlx_put_image_to_window(cub->mlx, cub->win, cub->main.image, 0, 0);
	return (0);
}

int	exit_game(void *poly_param)
{
	t_cub	*cub;

	cub = poly_param;
	error_exit(cub, NULL);
	return (0);
}

void	let_the_game_begin(t_cub *cub)
{
	init_mlx(cub);
	init_doors(cub);
	init_imgs(cub);
	init_orientation(cub);
	mlx_hook(cub->win, KeyPress, KeyPressMask, &key_press, cub);
	mlx_hook(cub->win, KeyRelease, KeyReleaseMask, &key_release, cub);
	mlx_hook(cub->win, DestroyNotify, StructureNotifyMask, &exit_game, cub);
	mlx_hook(cub->win, MotionNotify, PointerMotionMask, &mouse_move, cub);
	mlx_loop_hook(cub->mlx, &render_frame, cub);
	mlx_loop(cub->mlx);
}
