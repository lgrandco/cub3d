/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghaffar <eghaffar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:06:50 by eghaffar          #+#    #+#             */
/*   Updated: 2024/04/18 23:07:10 by eghaffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	handle_north_texture(char *line, t_cub *cub)
{
	if (cub->north_texture == NULL)
		cub->flag += 1;
	else
		error_exit(cub, "Error\nDuplicate of the Key Texture.");
	line += 2;
	while (iss_space_cub(*line))
		line++;
	free(cub->north_texture);
	cub->north_texture = ft_strdup_cub(line);
	if (cub->flag == 6)
		cub->map_data->j_end_of_tc = ft_strlen(line);
}

void	handle_south_texture(char *line, t_cub *cub)
{
	if (cub->south_texture == NULL)
		cub->flag += 1;
	else
		error_exit(cub, "Error\nDuplicate of the Key Texture.");
	line += 2;
	while (iss_space_cub(*line))
		line++;
	free(cub->south_texture);
	cub->south_texture = ft_strdup_cub(line);
	if (cub->flag == 6)
		cub->map_data->j_end_of_tc = ft_strlen(line);
}

void	handle_east_texture(char *line, t_cub *cub)
{
	if (cub->east_texture == NULL)
		cub->flag += 1;
	else
		error_exit(cub, "Error\nDuplicate of the Key Texture.");
	line += 2;
	while (iss_space_cub(*line))
		line++;
	free(cub->east_texture);
	cub->east_texture = ft_strdup_cub(line);
	if (cub->flag == 6)
		cub->map_data->j_end_of_tc = ft_strlen(line);
}

void	handle_west_texture(char *line, t_cub *cub)
{
	if (cub->west_texture == NULL)
		cub->flag += 1;
	else
		error_exit(cub, "Error\nDuplicate of the Key Texture.");
	line += 2;
	while (iss_space_cub(*line))
		line++;
	free(cub->west_texture);
	cub->west_texture = ft_strdup_cub(line);
	if (cub->flag == 6)
		cub->map_data->j_end_of_tc = ft_strlen(line);
}
