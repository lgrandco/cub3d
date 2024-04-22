/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legrandc <legrandc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:12:59 by legrandc          #+#    #+#             */
/*   Updated: 2024/04/21 09:46:46 by legrandc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	rotate_right(t_cub *cub, t_point old_dir, t_point old_plane,
		double speed)
{
	cub->dir.x = old_dir.x * cos(CAM_SPEED) - old_dir.y * sin(speed);
	cub->dir.y = old_dir.x * sin(speed) + old_dir.y * cos(speed);
	cub->plane.x = old_plane.x * cos(speed) - old_plane.y * sin(speed);
	cub->plane.y = old_plane.x * sin(speed) + old_plane.y * cos(speed);
}

void	rotate_left(t_cub *cub, t_point old_dir, t_point old_plane,
		double speed)
{
	cub->dir.x = old_dir.x * cos(-speed) - old_dir.y * sin(-speed);
	cub->dir.y = old_dir.x * sin(-speed) + old_dir.y * cos(-speed);
	cub->plane.x = old_plane.x * cos(-speed) - old_plane.y * sin(-speed);
	cub->plane.y = old_plane.x * sin(-speed) + old_plane.y * cos(-speed);
}

int	mouse_move(int x, int y, t_cub *cub)
{
	double		diff_x;
	double		diff_y;
	static int	mouse_x = SCREEN_W / 2;
	static int	mouse_y = SCREEN_H / 2;

	if (!BONUS || !cub->keys.ctrl)
		return (0);
	diff_x = x - mouse_x;
	diff_y = y - mouse_y;
	if (diff_x > 0 || (diff_x == 0 && x == SCREEN_W - 1))
		rotate_right(cub, cub->dir, cub->plane, MOUSE_SPEED);
	else if (diff_x < 0 || (diff_x == 0 && x == 0))
		rotate_left(cub, cub->dir, cub->plane, MOUSE_SPEED);
	mouse_x = x;
	mouse_y = y;
	return (0);
}
