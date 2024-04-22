/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorstr_to_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghaffar <eghaffar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:25:13 by eghaffar          #+#    #+#             */
/*   Updated: 2024/04/22 02:01:19 by eghaffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_result_color(char *str, int i)
{
	while (str[i] && iss_space_cub(str[i]))
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

int	retrieve_the_int(char *line, int *i)
{
	int	color;

	while (iss_space_cub(line[*i]))
		(*i)++;
	color = ft_atoi(line + *i);
	if (line[*i] == '\0')
		return (-1);
	while (line[*i] && ft_isdigit(line[*i]))
		(*i)++;
	while (iss_space_cub(line[*i]))
		(*i)++;
	return (color);
}

int	is_valid_color(int color, char next_char)
{
	return (color >= 0 && color <= 255 && (next_char == ','
			|| iss_space_cub(next_char) || next_char == '\0'));
}

int	rgbstr_to_int(char *line)
{
	int	i;
	int	r;
	int	g;
	int	b;

	i = 0;
	if (!line || !line[i])
		return (-1);
	r = retrieve_the_int(line, &i);
	if (!is_valid_color(r, line[i]) || line[i++] != ',')
		return (-1);
	g = retrieve_the_int(line, &i);
	if (!is_valid_color(g, line[i]) || line[i++] != ',')
		return (-1);
	b = retrieve_the_int(line, &i);
	if (!is_valid_color(b, line[i]) || !ft_result_color(line, i))
		return (-1);
	return ((r * 65536) + (g * 256) + b);
}
