/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghaffar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:38:47 by eghaffar          #+#    #+#             */
/*   Updated: 2022/12/05 16:54:46 by eghaffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*dest;
	char	*s;

	s = (char *)s1;
	i = 0;
	while (s[i])
			i++;
	dest = malloc(sizeof(char) * i + 1);
	i = 0;
	if (dest == NULL)
		return (0);
	else
	{
		while (s[i])
		{
					dest[i] = s[i];
					i++;
		}
			dest[i] = '\0';
		return (dest);
	}
}

/*  int	main(void)
  {
	char x1[100] = "Kaka Kou Rou Kou";
    ft_strdup(x1);
    printf("%s\n", x1);
 	
	 char x[100] = "Kaka Kou Rou Kou";
  	ft_strdup(x);
  	printf("%s", x);
  	return(0);
  }*/
