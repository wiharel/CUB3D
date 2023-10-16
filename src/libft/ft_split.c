/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 22:21:41 by pli               #+#    #+#             */
/*   Updated: 2022/03/17 14:51:13 by pli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_tabcount(char const *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			n++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (n);
}

char	*ft_tab(char *tab, char const *s, int j, int tab_len)
{
	int		i;

	i = 0;
	while (tab_len > 0)
	{
		tab[i] = s[j - tab_len];
		i++;
		tab_len--;
	}
	tab[i] = '\0';
	return (tab);
}

char	**ft_split_2(char **tab, int tab_num, char const *s, char c)
{
	int		i;
	int		j;
	int		tab_len;

	i = 0;
	j = 0;
	tab_len = 0;
	while (s[j] && i < tab_num)
	{
		while (s[j] && s[j] == c)
			j++;
		while (s[j] && s[j] != c)
		{
			j++;
			tab_len++;
		}
		tab[i] = malloc(sizeof(char) * (tab_len + 1));
		if (!tab)
			return (NULL);
		ft_tab(tab[i], s, j, tab_len);
		tab_len = 0;
		i++;
	}
	tab[i] = 0;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	int		tab_num;
	char	**tab;

	if (!s)
		return (NULL);
	tab_num = ft_tabcount(s, c);
	tab = malloc(sizeof(char *) * (tab_num + 1));
	if (!tab)
		return (NULL);
	ft_split_2(tab, tab_num, s, c);
	return (tab);
}
