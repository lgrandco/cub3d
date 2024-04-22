/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghaffar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:23:53 by eghaffar          #+#    #+#             */
/*   Updated: 2022/12/06 15:56:13 by eghaffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	left;
	size_t	right;
	char	*str;

	str = 0;
	if (s1 != 0 && set != 0)
	{
		left = 0;
		right = ft_strlen(s1);
		while (s1[left] && ft_strchr(set, s1[left]))
			left++;
		while (s1[right - 1] && ft_strchr(set, s1[right - 1]) && right > left)
			right--;
		str = (char *)malloc(sizeof(char) * (right - left + 1));
		if (str)
			ft_strlcpy(str, &s1[left], right - left + 1);
	}
	return (str);
}

/*int main ()
{
  char s[] = "./;/Bonj/our..;";
  char set[] = "/;.";
  printf("%s", ft_strtrim(s, set));
 }*/
