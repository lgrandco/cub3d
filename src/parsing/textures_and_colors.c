/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_and_colors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghaffar <eghaffar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:55:51 by eghaffar          #+#    #+#             */
/*   Updated: 2024/04/19 06:41:33 by eghaffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_floor_color(char *line, t_cub *cub)
{
	cub->floor_color = rgbstr_to_int(line);
	if (cub->floor_color == -1)
		error_exit(cub, "Error\nProblem with your floor color.");
}

void	init_ceiling_color(char *line, t_cub *cub)
{
	cub->ceiling_color = rgbstr_to_int(line);
	if (cub->ceiling_color == -1)
		error_exit(cub, "Error\nProblem with your ceiling color.");
}

void	handle_floor_color(char *line, t_cub *cub)
{
	if (cub->floor_color == -1)
		cub->flag += 1;
	else
		error_exit(cub, "Error\nDuplicate Key Color.");
	line += 2;
	while (iss_space_cub(*line))
		line++;
	init_floor_color(line, cub);
	if (cub->flag == 6)
		cub->map_data->j_end_of_tc = ft_strlen(line);
}

void	handle_ceiling_color(char *line, t_cub *cub)
{
	if (cub->ceiling_color == -1)
		cub->flag += 1;
	else
		error_exit(cub, "Error\nDuplicate Key color.");
	line += 2;
	while (iss_space_cub(*line))
		line++;
	init_ceiling_color(line, cub);
	if (cub->flag == 6)
		cub->map_data->j_end_of_tc = ft_strlen(line);
}

int	check_texture_and_color(char *line, t_cub *cub)
{
	while (iss_space_cub(*line))
		line++;
	if (ft_strncmp(line, "NO ", 3) == 0)
		handle_north_texture(line, cub);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		handle_south_texture(line, cub);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		handle_west_texture(line, cub);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		handle_east_texture(line, cub);
	else if (ft_strncmp(line, "F ", 2) == 0)
		handle_floor_color(line, cub);
	else if (ft_strncmp(line, "C ", 2) == 0)
		handle_ceiling_color(line, cub);
	else if ((*line != '\0') && (*line != '\n') && (cub->flag != 6))
		return (0);
	return (1);
}
