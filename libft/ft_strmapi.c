/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghaffar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:44:01 by eghaffar          #+#    #+#             */
/*   Updated: 2022/12/06 13:56:14 by eghaffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*strf;
	unsigned int	i;
	size_t			len;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	strf = (((char *)malloc(sizeof(char) * (len + 1))));
	if (!strf)
		return (NULL);
	while (i < len)
	{
		strf[i] = (*f)(i, s[i]);
		i++;
	}
	strf[i] = '\0';
	return (strf);
}

/*   char my_func(unsigned int i, char str)
   {
   printf("index = %d and %c\n", i, str);
   return str - 32;
   }

   int main()
   {
   char str[10] = "hello.";
   printf("The result is %s\n", str);
   char *result = ft_strmapi(str, my_func);
   printf("The result is %s\n", result);
   return 0;
   }*/
