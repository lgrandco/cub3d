/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghaffar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:40:05 by eghaffar          #+#    #+#             */
/*   Updated: 2022/12/07 17:42:51 by eghaffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (len == 0 && (big == NULL || little == NULL))
		return (0);
	str = (char *)big;
	i = 0;
	j = 0;
	if (little[0] == '\0')
		return (str);
	while (big[i] && i + j < len)
	{
		if (big[i + j] == little[j])
		{
			if (little[++j] == '\0')
				return (str + i);
		}
		else
		{
			j = 0;
			i++;
		}
	}
	return (NULL);
}

/*int	main ()
{
	const char *l = "Le zoom zoo zoom";
	const char *s = "zoom";

	const char *l1 = "Le zoom zoo zoom";
        const char *s1 = "zoom";

	printf("strnstr = %s\n", strnstr(l, s, 20));
	printf("ft_strnstr = %s\n", ft_strnstr(l1, s1, 20));
}*/
