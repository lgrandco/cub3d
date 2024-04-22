/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghaffar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:15:34 by eghaffar          #+#    #+#             */
/*   Updated: 2022/12/13 14:58:48 by eghaffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*occu;
	char	tofind;
	size_t	len;

	occu = (char *)s;
	len = ft_strlen(s);
	tofind = (char)c;
	while (len > 0)
	{
		if (occu[len] == tofind)
			return (occu + len);
		len--;
	}
	if (occu[len] == tofind)
		return (occu);
	return (0);
}
/*int main
  {
  char* str = "pen pineapple apple pen!";

  printf("%s\n", ft_strrchr(str, 'p'));

  return 0;
  }*/
