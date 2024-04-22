/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghaffar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:58:10 by eghaffar          #+#    #+#             */
/*   Updated: 2022/11/16 17:31:37 by eghaffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	str = s;
	i = 0;
	while (i < n)
	{
		*str = c;
		str++;
		i++;
	}
	return (s);
}

/*int	main()
  {

  char s[20] = "Trottinette";
  ft_memset(s + 1, '!', 5);
  printf("%s", s);
  }*/
