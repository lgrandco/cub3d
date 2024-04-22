/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghaffar <eghaffar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:57:25 by eghaffar          #+#    #+#             */
/*   Updated: 2024/04/21 20:29:45 by eghaffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_gnl(const char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		return (0);
	}
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoint(char const *s1, char const *s2)
{
	char	*dest;
	int		i;
	int		j;

	i = -1;
	j = -1;
	dest = malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	if (!dest)
		return (NULL);
	while (s1 != NULL && s1[++j] != '\0')
		dest[++i] = s1[j];
	j = -1;
	while (s2 != NULL && s2[++j] != '\0')
		dest[++i] = s2[j];
	dest[++i] = '\0';
	free((char *)s1);
	return (dest);
}
