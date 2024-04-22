/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legrandc <legrandc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 01:30:15 by legrandc          #+#    #+#             */
/*   Updated: 2024/04/20 23:46:34 by legrandc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	hook(t_cub *cub)
{
	if (cub->keys.left)
		rotate_left(cub, cub->dir, cub->plane, CAM_SPEED);
	if (cub->keys.right)
		rotate_right(cub, cub->dir, cub->plane, CAM_SPEED);
	if (cub->keys.d)
		move_right(cub);
	if (cub->keys.a)
		move_left(cub);
	if (cub->keys.w)
		move_up(cub);
	if (cub->keys.s)
		move_down(cub);
}

int	key_press(int keycode, t_cub *cub)
{
	if (keycode == XK_w)
		cub->keys.w = true;
	else if (keycode == XK_s)
		cub->keys.s = true;
	else if (keycode == XK_a)
		cub->keys.a = true;
	else if (keycode == XK_d)
		cub->keys.d = true;
	else if (keycode == XK_Left)
		cub->keys.left = true;
	else if (keycode == XK_Right)
		cub->keys.right = true;
	else if (keycode == XK_Escape)
		error_exit(cub, NULL);
	else if (keycode == XK_f)
		cub->keys.f = true;
	else if (keycode == XK_Control_L)
		cub->keys.ctrl = cub->keys.ctrl == false;
	return (0);
}

int	key_release(int keycode, t_cub *cub)
{
	if (keycode == XK_s)
		cub->keys.s = false;
	else if (keycode == XK_a)
		cub->keys.a = false;
	else if (keycode == XK_d)
		cub->keys.d = false;
	else if (keycode == XK_w)
		cub->keys.w = false;
	else if (keycode == XK_Left)
		cub->keys.left = false;
	else if (keycode == XK_Right)
		cub->keys.right = false;
	else if (keycode == XK_f)
		cub->keys.f = cub->keys.f == false;
	return (0);
}

void	img_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->data + y * img->size_line + x * sizeof(int);
	*(unsigned int *)dst = color;
}
