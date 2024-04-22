/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghaffar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:07:11 by eghaffar          #+#    #+#             */
/*   Updated: 2022/12/05 17:49:03 by eghaffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srci;
	size_t	i;

	srci = 0;
	i = 0;
	while (src[srci] != '\0')
		srci++;
	if (size == 0)
		return (srci);
	while (src[i] != '\0' && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srci);
}
/*int main() 
{
    char s[]= "chaton";
    char d[]= "lapin";
    ft_strlcpy(d, s, 4);
    printf("%s", d);
    char s1[]= "chaton";
    char d1[]= "lapin";
    strlcpy(d1, s1, 4);

    printf("%s", d);
    return 0;
}*/
