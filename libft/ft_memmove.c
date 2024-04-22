/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghaffar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:51:47 by eghaffar          #+#    #+#             */
/*   Updated: 2022/12/07 14:59:49 by eghaffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*dst;

	s = (unsigned char *) src;
	dst = (unsigned char *) dest;
	if (!dest && !src)
		return (NULL);
	if (src < dest)
	{
		while (n)
		{
			dst[n - 1] = s[n - 1];
			n--;
		}
	}	
	else
		ft_memcpy(dest, src, n);
	return (dest);
}

/*int main ()
{	
char lol[] = "abcdefghij";

ft_memmove(lol + 1, lol, 2); // devrait donner "1212345890"
printf("%s\n", lol);
memmove(lol + 1, lol, 2);
printf("%s\n", lol);
}*/
