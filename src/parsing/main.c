/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghaffar <eghaffar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 23:45:06 by eghaffar          #+#    #+#             */
/*   Updated: 2024/04/22 01:24:52 by eghaffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char *argv[])
{
	t_cub	*cub;

	cub = ft_calloc(1, sizeof(t_cub));
	if (!cub)
		return (1);
	if (argc != 2)
		error_exit(cub, "Error\nWrong number of arguments.");
	cub->mlx = NULL;
	parsing_part(cub, argv[1]);
	let_the_game_begin(cub);
	free_cub(cub);
	return (0);
}
