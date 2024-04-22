/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghaffar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:53:57 by eghaffar          #+#    #+#             */
/*   Updated: 2022/12/07 18:19:59 by eghaffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_getlen(long int n)
{
	size_t	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n / 10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long int	nbr;
	int			len;
	int			istop;	
	char		*str;

	istop = 0;
	nbr = n;
	str = (char *)ft_calloc(ft_getlen(nbr) + 1, sizeof(char));
	if (!str)
		return (NULL);
	len = ft_getlen(nbr) - 1;
	if (nbr < 0)
	{
		str [0] = '-';
		nbr = -nbr;
		istop = 1;
	}
	while (len >= istop)
	{
		str[len] = (nbr % 10) + '0';
		nbr = nbr / 10;
		len--;
	}
	return (str);
}
/*int main ()  
{
  printf("%s\n", ft_itoa(0));
  printf("%s\n", ft_itoa(987));
  printf("%s\n", ft_itoa(-123));
  }*/
