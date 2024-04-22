/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghaffar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:57:42 by eghaffar          #+#    #+#             */
/*   Updated: 2022/11/15 15:14:14 by eghaffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*z;

	z = (char *)s;
	i = 0;
	while (i < n)
	{
		*z = '\0';
		i++;
		z++;
	}
}

/*int main() 
{
	char s[10] = "Bonjour";

	ft_bzero(s, 3);
	printf("str = %s", s);
	return (0);
}*/
