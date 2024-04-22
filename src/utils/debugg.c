/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:06:38 by eghaffar          #+#    #+#             */
/*   Updated: 2024/04/06 14:39:25 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_the_map(char **map)
{
	int	i;

	i = 0;
	printf("BEGINING OF THE MAP \n");
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
	printf("END OF THE MAP \n\n");
}

int	ft_strslen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
