/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghaffar <eghaffar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 17:26:32 by eghaffar          #+#    #+#             */
/*   Updated: 2024/04/22 01:21:18 by eghaffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	iss_space(char c)
{
	if ((c >= 9 && c <= 13) || (c == ' '))
		return (1);
	else
		return (0);
}

int	ft_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	valeur;

	i = 0;
	valeur = 0;
	sign = 1;
	while (iss_space(nptr[i]))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_number(nptr[i]))
	{
		valeur = valeur * 10 + nptr[i] - '0';
		if (valeur > 255 || valeur < 0)
			return (-1);
		i++;
	}
	return (valeur * sign);
}

/*int main(void)
  {
  char *s = " ---+--+1234ab567";
  printf("%d", ft_atoi(s));
  }*/
