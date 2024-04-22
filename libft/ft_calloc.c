/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghaffar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:25:25 by eghaffar          #+#    #+#             */
/*   Updated: 2022/12/15 16:03:11 by eghaffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	void	*ptr;

	i = 0;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (size && nmemb > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	while (i < nmemb * size)
	{
			((unsigned char *)ptr)[i] = 0;
			i++;
	}
	return (ptr);
}
/*int main(void)
  {
  long *buffer;

  buffer = (long *)ft_calloc( 40, sizeof( long ) );
  if( buffer != NULL )
  printf( "Allocated 40 long integers\n" );
  else
  printf( "Can't allocate memory\n" );
  free( buffer );
  }*/
