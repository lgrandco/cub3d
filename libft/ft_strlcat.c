/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghaffar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:21:09 by eghaffar          #+#    #+#             */
/*   Updated: 2022/12/15 16:03:25 by eghaffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dsti;
	size_t	srci;
	size_t	i;

	if (size == 0 && (dst == NULL || src == NULL))
		return (0);
	dsti = ft_strlen(dst);
	srci = ft_strlen(src);
	i = 0;
	if (size < dsti + 1)
		return (size + srci);
	if (size > dsti + 1)
	{
		while (src[i] != '\0' && dsti + 1 + i < size)
		{
			dst[dsti + i] = src[i];
			i++;
		}
	}
	dst[dsti + i] = '\0';
	return (dsti + srci);
}
/*int main()
{
    char s[]= "chaton";
    char d[]= "coucoucavacomment";

    ft_strlcat(s, d, 7);
    printf("%s", d);
    return 0;
}*/
