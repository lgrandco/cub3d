/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghaffar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:10:11 by eghaffar          #+#    #+#             */
/*   Updated: 2022/12/13 17:58:25 by eghaffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*occu;

	occu = (char *)s;
	i = 0;
	if (c == 0)
		return (occu + ft_strlen(occu));
	while (occu[i])
	{
		if (occu[i] == (char)c)
		{
			return (&occu[i]);
		}
		i++;
	}
	return (NULL);
}

/*int main(void)
{
	char a[] = "comm";
	printf("%s \n", ft_strchr(a, 'e'));


	char b[] = "comment";
	printf("%s", strchr(b, 'e'));
}*/
