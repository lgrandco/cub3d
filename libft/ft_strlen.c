/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghaffar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:20:07 by eghaffar          #+#    #+#             */
/*   Updated: 2022/11/20 12:13:21 by eghaffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*int	main(void)
{
	char	*x;

	x = "Je contiens ce nombre de caracteres :";	
	printf("%d\n", ft_strlen(x));
	return(0);
}*/
