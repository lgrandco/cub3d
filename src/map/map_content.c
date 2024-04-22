/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legrandc <legrandc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 00:20:23 by eghaffar          #+#    #+#             */
/*   Updated: 2024/04/22 00:25:10 by legrandc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_particular_cases(t_cub *cub, t_map *map_data, char **map, int i)
{
	if ((map_data->j_end_of_tc >= ft_strlen_cub(map[i + 1]))
		|| (map_data->j_end_of_tc >= ft_strlen_cub(map[i - 1])))
		error_exit(cub, MAP_NOT_CLOSED);
	else if (map_data->j_end_of_tc == 0)
		error_exit(cub, MAP_NOT_CLOSED);
	if (BONUS && map[i][map_data->j_end_of_tc] == 'D')
	{
		if (!((map[i][map_data->j_end_of_tc + 1] == '1'
				&& map[i][map_data->j_end_of_tc - 1] == '1') || (map[i
					- 1][map_data->j_end_of_tc] == '1' && map[i
					+ 1][map_data->j_end_of_tc] == '1')))
			error_exit(cub, "Error\nDoor not enclosed by walls.\n");
	}
}

int	check_player(char c)
{
	if (BONUS && c == 'D')
		return (true);
	return ((c == FREE_WAY || c == PLAYER_NORTH || c == PLAYER_SOUTH
			|| c == PLAYER_EAST || c == PLAYER_WEST));
}

void	check_if_one(t_map *map_data, char **map)
{
	int	j;
	int	i;

	j = 0;
	i = map_data->i_begin_the_map;
	while (map[i][j])
	{
		while ((map[i][j]) && (iss_space_cub(map[i][j])))
			j++;
		while ((map[i][j]) && (map[i][j] == '1'))
			j++;
		while ((map[i][j]) && (iss_space_cub(map[i][j])))
			j++;
	}
}

void	check_first_line(t_map *map_data, t_cub *cub, char **map)
{
	int	j;
	int	flag;

	flag = 0;
	j = 0;
	while (map[map_data->i_begin_the_map][j])
	{
		while ((map[map_data->i_begin_the_map][j])
			&& (iss_space_cub(map[map_data->i_begin_the_map][j])))
			j++;
		while ((map[map_data->i_begin_the_map][j])
			&& (map[map_data->i_begin_the_map][j] == '1'))
		{
			flag = 1;
			j++;
		}
		while ((map[map_data->i_begin_the_map][j])
			&& (iss_space_cub(map[map_data->i_begin_the_map][j])))
			j++;
		if ((map[map_data->i_begin_the_map][j] != '\0'
			&& map[map_data->i_begin_the_map][j] != '1') || flag != 1)
			error_exit(cub, MAP_NOT_CLOSED);
		else
			check_if_one(map_data, map);
	}
}

int	is_map_border_closed(t_map *map_data, t_cub *cub, char **map)
{
	int	i;

	i = map_data->i_begin_the_map;
	check_first_line(map_data, cub, map);
	i += 1;
	while (map[i])
	{
		map_data->j_end_of_tc = 0;
		while (map[i][map_data->j_end_of_tc])
		{
			if (check_player(map[i][map_data->j_end_of_tc]))
			{
				check_particular_cases(cub, map_data, map, i);
				is_valid(i, map_data->j_end_of_tc + 1, cub);
				is_valid(i, map_data->j_end_of_tc - 1, cub);
				is_valid(i - 1, map_data->j_end_of_tc, cub);
				is_valid(i + 1, map_data->j_end_of_tc, cub);
			}
			map_data->j_end_of_tc++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
