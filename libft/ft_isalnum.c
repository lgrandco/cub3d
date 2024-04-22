/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghaffar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:47:47 by eghaffar          #+#    #+#             */
/*   Updated: 2022/11/16 18:17:10 by eghaffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c);

int	ft_isalnum(int c)
{
	if ((c > '@' && c < '[') || (c > '`' && c < '{')
		|| (c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}

/*int main()
  {
  printf("%d", ft_isalnum('8'));
  printf("%d", ft_isalnum('D'));
  printf("%d", ft_isalnum('}'));
  }*/
