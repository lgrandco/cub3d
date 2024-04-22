/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghaffar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:56:55 by eghaffar          #+#    #+#             */
/*   Updated: 2022/11/07 18:40:57 by eghaffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c);

int	ft_isalpha(int c)
{
	if ((c > '@' && c < '[') || (c > '`' && c < '{'))
		return (1);
	else
		return (0);
}

/*int main()
  {
  printf("%d", ft_isalpha('t'));
  printf("%d", ft_isalpha('*'));
  }*/
