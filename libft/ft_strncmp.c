/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghaffar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:02:52 by eghaffar          #+#    #+#             */
/*   Updated: 2022/12/06 17:46:32 by eghaffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (n--)
	{
		if (str1[i] != str2[i] || str1[i] == 0 || str2[i] == 0)
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

/*int    main()
{
	printf("%d", strncmp("Cava", "CavaBien", 8));
	printf("%d", ft_strncmp("Cava", "CavaBien", 8))
	printf("\n%d", strncmp("Cava", "Ca", 9));
	printf("%d", ft_strncmp("Cava", "CavaBien", 8))  
	printf("\n%d", strncmp("Cava", "Cava", 2));
	printf("%d", ft_strncmp("Cava", "CavaBien", 8))  
}*/
