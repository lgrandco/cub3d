/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghaffar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:00:09 by eghaffar          #+#    #+#             */
/*   Updated: 2022/12/11 18:49:43 by eghaffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_lensplit(char const *str, char sep)
{
	int	i;

	i = 0;
	while (str[i] != sep && str[i])
				i++;
	return (i);
}

static	int	ft_tablen(char const *str, char sep)
{
	int		itab;
	int		countsep;

	itab = 0;
	countsep = 0;
	if (str[0] != sep && str[0] != '\0')
			countsep++;
	while (str[itab])
	{
		if (str[itab] == sep && str[itab + 1] != sep && str[itab + 1] != '\0')
		{
					countsep++;
		}
			itab++;
	}
	return (countsep);
}

static	void	free_all(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
			i++;
	}
	free(tab);
}

static	char	**ft_split_division(char const *s, char sep, char **tab)
{
	int		itab;
	int		isep;

	itab = 0;
	isep = 0;
	while (s[itab])
	{
		if (s[itab] != sep)
		{
				tab[isep] = ft_substr(s, itab, ft_lensplit(&s[itab], sep));
			if (!tab[isep])
			{
				free_all(tab);
				return (NULL);
			}
					itab = itab + ft_lensplit(&s[itab], sep);
					isep++;
		}
		else
					itab++;
	}
	tab[isep] = 0;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (s == NULL)
		return (NULL);
	tab = malloc(sizeof(char *) * (ft_tablen(s, c) + 1));
	if (!tab)
		return (NULL);
	tab = ft_split_division(s, c, tab);
	return (tab);
}

/*int    main(void)
  {
  char const *s4 = "lorem ipsum dolor sit amet, consectetur adipi";
  char	c4 = ' ';
  int	r;
  char	**tib;

  r = 0;
  tib = ft_split(s4, c4);	
  while (r < ft_tablen(s4, c4))
  {
  printf("%s\n", tib[r]);
  r++;
  }
  return (0);
  }*/
