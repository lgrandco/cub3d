/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghaffar <eghaffar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:42:42 by eghaffar          #+#    #+#             */
/*   Updated: 2024/04/21 20:29:09 by eghaffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check(char *stash)
{
	int	i;

	i = 0;
	if (!stash)
		return (0);
	while (stash[i])
	{
		if (stash[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_extract(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_remaining(char *stash)
{
	char	*stock;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen(stash);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	stock = (char *)malloc((len - i + 1) * sizeof(char));
	if (!stock)
		return (0);
	while (stash[j] && stash[j] != '\n')
		j++;
	i = 0;
	while (stash[j] != '\0')
		stock[i++] = stash[j++ + 1];
	free(stash);
	stock[i] = '\0';
	return (stock);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*stash;
	char		*line;
	int			i;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	i = 1;
	while (i > 0 && ft_check(stash) == 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i < 0)
			return (free(buffer), NULL);
		buffer[i] = '\0';
		stash = ft_strjoint(stash, buffer);
	}
	free(buffer);
	if (!stash)
		return (NULL);
	line = ft_extract(stash);
	stash = ft_remaining(stash);
	return (line);
}
