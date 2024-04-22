/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghaffar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:36:24 by eghaffar          #+#    #+#             */
/*   Updated: 2022/11/08 12:08:37 by eghaffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c);

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

/*int main()
  {
  printf("%d", ft_isascii(' '));
  printf("%d", ft_isascii('D'));
  printf("%d", ft_isascii('}'));
  printf("%d", isascii(' '));
  }*/
