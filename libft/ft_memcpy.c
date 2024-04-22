/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghaffar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:06:29 by eghaffar          #+#    #+#             */
/*   Updated: 2022/12/07 17:36:41 by eghaffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*strd;
	char	*strs;

	if (!dest && !src)
		return (0);
	strd = (char *)dest;
	strs = (char *)src;
	while (n--)
			*strd++ = *strs++;
	return (dest);
}

/*int main()
  {
  char a[] = "tu vas bien";
  char b[] = "oui je vais bien";
  ft_memcpy(a, b, 4);
  printf("%s\n", a);
  memcpy(a, b, 4);
  printf("%s", a);
  return 0;
  }*/
