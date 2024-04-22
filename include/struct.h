/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghaffar <eghaffar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 02:05:10 by eghaffar          #+#    #+#             */
/*   Updated: 2024/04/21 20:04:24 by eghaffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "cub3D.h"
# include <stdbool.h>

enum				e_door_state
{
	CLOSED,
	OPENING,
	OPENED,
	CLOSING,
};

typedef struct s_point
{
	double			x;
	double			y;
}					t_point;

/*About the map and the player*/
typedef struct s_map
{
	char			**map;
	char			*map_name;
	char			*col;
	char			*line;
	char			player_start_dir;
	int				y;
	int				x;
	int				fd;
	int				i_end_of_tc;
	int				j_end_of_tc;
	int				i_begin_the_map;
	int				j_end_of_map;
	int				beg_index;
	int				end_i;
	int				end_j;
	int				flag_pos;
	int				pos_map_x;
	int				pos_map_y;
	int				map_w;
	int				map_height;
}					t_map;

/**/
typedef struct s_orientation
{
	double			screen_dist;
	double			pos_pix_x;
	double			pos_pix_y;
	double			pos_x;
	double			pos_y;
	double			angle;
	double			fov;
	int				rot;
	int				left;
	int				right;
}					t_orientation;

typedef struct s_ray
{
	double			step_x;
	double			step_y;
	t_point			start_point;
	double			ray_angle;
	double			dist_to_the_wall;
	int				flag_wall_color;
}					t_ray;

typedef struct keys
{
	bool			a;
	bool			s;
	bool			d;
	bool			w;
	bool			left;
	bool			right;
	bool			ctrl;
	bool			f;
}					t_keys;
/*About the description*/
typedef struct s_door
{
	int				state;
	double			x;
	double			seg_len;
	double			start_time;
	double			delta;
	bool			seen;
}					t_door;

typedef struct s_cub
{
	char			*north_texture;
	char			*south_texture;
	char			*west_texture;
	char			*east_texture;
	int				floor_color;
	int				ceiling_color;
	int				flag;
	t_map			*map_data;
	void			*mlx;
	void			*win;
	t_ray			ray;
	t_orientation	orient;
	double			height;
	double			start;
	double			end;
	int				mini_h;
	t_point			dir;
	t_point			plane;
	t_point			player;
	t_img			main;
	t_img			minimap;
	t_img			north;
	t_img			south;
	t_img			east;
	t_img			west;
	t_keys			keys;
	double			side_x;
	double			side_y;
	double			delta_x;
	double			delta_y;
	bool			is_side;
	t_img			*cur_img;
	double			tex_x;
	double			tex_y;
	t_point			mouse;
	t_door			**doors;
	t_img			door;
	bool			door_hit;
	t_point			last;
	t_point			ray_dir;
	int				cur_pix_x;
}					t_cub;

#endif
