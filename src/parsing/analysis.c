/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghaffar <eghaffar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:53:27 by eghaffar          #+#    #+#             */
/*   Updated: 2024/04/21 21:45:41 by eghaffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_map_integrity(t_map *map_data, t_cub *cub)
{
	if (is_map_border_closed(map_data, cub, map_data->map))
		error_exit(cub, NULL);
	if (under_the_map(cub) == 1)
		error_exit(cub, NULL);
}

int	is_map_valid(t_map *map_data, t_cub *cub)
{
	setup_initial_cub(cub);
	validate_texture_and_color(map_data, cub);
	validate_texture_files(cub);
	find_map_boundaries(map_data, cub);
	check_map_integrity(map_data, cub);
	validate_map_characters_and_pos(map_data, cub);
	return (EXIT_SUCCESS);
}

int	parsing(t_map *map_data, t_cub *cub)
{
	if (map_empty(map_data, cub))
		return (EXIT_FAILURE);
	else if (is_map_valid(map_data, cub))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	parsing_part(t_cub *cub, char *argv)
{
	cub->map_data = init_the_map_data(argv);
	if (!cub->map_data)
		error_exit(cub, FAIL_INIT_STRUCT);
	if (check_if_dotcub(argv))
		error_exit(cub, INV_EXT);
	if (count_and_read(cub->map_data))
		error_exit(cub, NULL);
	if (parsing(cub->map_data, cub))
		error_exit(cub, NULL);
	retrieve_the_final_map(cub->map_data, cub);
	init_pos_and_dim(cub->map_data);
	close(cub->map_data->fd);
}
