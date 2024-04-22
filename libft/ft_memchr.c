/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghaffar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:36:31 by eghaffar          #+#    #+#             */
/*   Updated: 2022/12/13 18:12:00 by eghaffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	tofind;

	str = (unsigned char *)s;
	tofind = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == tofind)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
/*
   int main(void)
   {
   char a[] = "";
   ft_memchr(a, 'e', 15);
   printf("%s", a);
   char a1[] = "";
   memchr(a1, 'e', 15);
   printf("%s", a);
   return(0);
}

   int main(void)
   {
   char a[] = "coucou comment vas-tu ?";
   char *CharacterPointer = NULL;
   CharacterPointer = ft_memchr(a, 'e', 15);
   printf("%s", CharacterPointer);
   return(0);
   }
*/
