/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghaffar <eghaffar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:35:51 by eghaffar          #+#    #+#             */
/*   Updated: 2024/04/22 01:38:26 by eghaffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include "struct.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define SCREEN_W 1920
# define SCREEN_H 1080
# define MINI_W 1000
# define MINI_H 1000

# define FOV (double)90
# define CAM_SPEED 0.05
# define MOUSE_SPEED 0.015
# define TILE_SIZE 128
# define SPRITE_FRAMES 16
# define MOVE_SPEED 7.94238312
# define INVALID_TEXT_COL "Error\nProblem with your textures or colors."
# define INV_XPM_FILE_NOT_FOUND "Error\nXPM file not found."
# define INV_EXT_XPM "Error\nProblem with the extension's name(xpm)."
# define INV_EXT "Error\nWrong extension's name."
# define ERROR_ARGS "Error\nInvalid arguments."
# define INV_FILE_NOT_FOUND "Error\nFile not found."
# define INV_FILE_DIRECTORY "Error\nNot a file."
# define INVALID_POSITION "Error\nProblem with the player."
# define INVALID_EXIT "Error\nProblem with the exit."
# define INV_UNDER_THE_MAP "Error\nSomething left under the map."
# define MAP_NOT_CLOSED "Error\nMap border not closed."
# define ERROR_FILE_EMPTY "Error\nThe file is empty."
# define ERROR_MAP_EMPTY "Error\nThe map is empty."
# define INVALID_CHAR_MSG "Error\nInvalid character."
# define FAIL_INIT_STRUCT "Error\nInitialisation of the structure failed."
# define MALLOC_ERROR ("Error\nMalloc failed.")
# ifndef BONUS
#  define BONUS 0
# endif
# define PLAYER_COLOR 0
# define WAY_COLOR 0x90EE90
# define WALL_COLOR 0xFA8072
# define DOOR_COLOR 0x808080
// Enumération pour les caractères de scène
enum	e_scene_characters
{
	FREE_WAY = '0',
	WALL = '1',
	PLAYER_NORTH = 'N',
	PLAYER_SOUTH = 'S',
	PLAYER_EAST = 'E',
	PLAYER_WEST = 'W',
	SPACES = ' '
};

/* Init*/
t_map	*init_the_map_data(char *filename);
int		nb_lines_and_col(t_map *map_data);
char	**read_file_lines(t_map *map_data);
void	retrieve_the_final_map(t_map *map_data, t_cub *cub);
void	is_valid(int i, int j, t_cub *cub);
int		map_empty(t_map *map_data, t_cub *cub);
int		is_map_border_closed(t_map *map_data, t_cub *cub, char **map);
void	init_pos_and_dim(t_map *map_data);
void	setup_initial_cub(t_cub *cub);

// Assignation
int		count_and_read(t_map *map_data);
char	*trim_new_line(char *line);
int		is_valid_scene_character(char c, t_map *map_data);
void	actualize_nb_of_col(char *line, int *nb_of_cols);
// Parsing
int		parsing(t_map *map_data, t_cub *cub);
int		check_if_dotcub(char *filename);
int		check_if_xpm(char *filename);
int		map_empty(t_map *map_data, t_cub *cub);
int		is_map_valid(t_map *map_data, t_cub *cub);
int		is_map_border_closed(t_map *map_data, t_cub *cub, char **map);
int		is_whitespace(char c);
int		check_texture_and_color(char *line, t_cub *cub);
int		under_the_map(t_cub *cub);
void	check_extreme_line(t_map *map_data, t_cub *cub, char **map,
			int l_to_check);
int		is_player_or_free_way(char c);
void	check_particular_cases(t_cub *cub, t_map *map_data, char **map, int i);
void	validate_texture_and_color(t_map *map_data, t_cub *cub);
void	validate_texture_files(t_cub *cub);
void	check_map_integrity(t_map *map_data, t_cub *cub);
void	find_map_boundaries(t_map *map_data, t_cub *cub);
void	validate_map_characters_and_pos(t_map *map_data, t_cub *cub);
void	check_if_one(t_map *map_data, char **map);
void	is_valid(int i, int j, t_cub *cub);
int		is_player_or_free_way(char c);
void	parsing_part(t_cub *cub, char *argv);
void	check_map_integrity(t_map *map_data, t_cub *cub);

/*Files*/
int		open_for_the_xpm(char *filename);
int		alloc_and_stock_lines(t_map *map_data);
int		open_for_the_map(t_map *map_data);

void	actualize_nb_of_col(char *line, int *nb_of_cols);
char	*trim_new_line(char *line);
int		ft_putendl_fd_cub(char *str, int fd);
int		is_whitespace(char c);
int		is_valid_scene_character(char c, t_map *map_data);
/*Debugg*/
void	print_the_map(char **map);
int		ft_strslen(char **strs);
/*Textures*/
void	handle_north_texture(char *line, t_cub *cub);
void	handle_south_texture(char *line, t_cub *cub);
void	handle_east_texture(char *line, t_cub *cub);
void	handle_west_texture(char *line, t_cub *cub);
void	handle_ceiling_color(char *line, t_cub *cub);
void	handle_floor_color(char *line, t_cub *cub);
void	init_floor_color(char *line, t_cub *cub);
void	init_ceiling_color(char *line, t_cub *cub);
int		retrieve_the_int(char *line, int *i);
int		rgbstr_to_int(char *line);
int		ft_result_color(char *str, int i);
/*Clear*/
void	error_exit(t_cub *cub, char *message);
void	free_map_data(t_map *map_data);
void	free_cub(t_cub *cub);
void	free_tab(void **tab);
/*utils*/
char	*ft_strdup_cub(const char *s1);
int		ft_strlen_cub(const char *s);
int		iss_space_cub(char c);

/* FUNCTIONS */
double	get_dist(t_cub *cub);
void	get_wall_infos(t_cub *cub);
double	get_dist(t_cub *cub);
void	minimapping(t_cub *cub);
void	draw_door(t_cub *cub, int c);
bool	hit_door(t_cub *cub, int x, int y, bool sprites);
void	init_doors(t_cub *cub);
void	rotate_left(t_cub *cub, t_point old_dir, t_point old_plane,
			double speed);
void	rotate_right(t_cub *cub, t_point old_dir, t_point old_plane,
			double speed);
int		mouse_move(int x, int y, t_cub *cub);
void	init_orientation(t_cub *cub);
void	img_pixel_put(t_img *img, int x, int y, int color);
void	init_mlx(t_cub *cub);
void	init_imgs(t_cub *cub);
void	move_player(t_cub *cub, double new_x, double new_y);
void	move_right(t_cub *cub);
void	move_left(t_cub *cub);
void	move_up(t_cub *cub);
void	move_down(t_cub *cub);
void	move_player(t_cub *cub, double new_x, double new_y);
void	rotate_player(t_cub *cub);
void	hook(t_cub *cub);
int		key_press(int keycode, t_cub *cub);
int		key_release(int keycode, t_cub *cub);
void	raycasting(t_cub *cub, bool sprites);
void	let_the_game_begin(t_cub *cub);

/*Minimap*/
void	minimapping(t_cub *cub);

#endif
