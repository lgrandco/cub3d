/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghaffar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:53:06 by eghaffar          #+#    #+#             */
/*   Updated: 2022/12/11 18:48:06 by eghaffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		is1;
	int		is2;
	int		is1s2;
	char	*dest;

	if (s1 == NULL)
		return (NULL);
	is1 = ft_strlen(s1);
	is2 = ft_strlen(s2);
	is1s2 = is1 + is2;
	dest = (char *)malloc(sizeof(char) * is1s2 + 1);
	if (!dest)
		return (NULL);
	if (s1 || s2)
	{
		ft_memcpy(dest, s1, is1);
		ft_memcpy(dest + is1, s2, is2 + 1);
	}
	return (dest);
}

/*#include <stdio.h>
  int    main()
  {
  char a[] = "coucou";
  char b[] = "ca va comment";
  printf("%s ", ft_strjoin(a, b));
  return (0);
  }*/
