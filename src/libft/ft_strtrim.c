/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:53:26 by pli               #+#    #+#             */
/*   Updated: 2022/03/17 14:55:18 by pli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

unsigned int	ft_checkstart(unsigned int len_set, unsigned int len_s1,
	char const *s1, char const *set)
{
	unsigned int	set_cur_pos;
	unsigned int	found;
	unsigned int	s1_cur_pos;

	s1_cur_pos = 0;
	while (s1_cur_pos < len_s1)
	{
		set_cur_pos = 0;
		found = 0;
		while (set_cur_pos < len_set && !found)
		{
			if (set[set_cur_pos] == s1[s1_cur_pos])
				found = 1;
			set_cur_pos += 1;
		}
		if (!found)
			break ;
		s1_cur_pos += 1;
	}
	return (s1_cur_pos);
}

unsigned int	ft_checkend(unsigned int len_set, unsigned int len_s1,
	char const *s1, char const *set)
{
	unsigned int	set_cur_pos;
	unsigned int	found;
	unsigned int	s1_cur_pos;

	s1_cur_pos = len_s1 - 1;
	while (s1_cur_pos)
	{
		set_cur_pos = 0;
		found = 0;
		while (set_cur_pos < len_set && !found)
		{
			if (set[set_cur_pos] == s1[s1_cur_pos])
				found = 1;
			set_cur_pos += 1;
		}
		if (!found)
			break ;
		s1_cur_pos -= 1;
	}
	return (s1_cur_pos);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	end;
	unsigned int	i;
	char			*tab;

	i = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = ft_checkstart(ft_strlen(set), ft_strlen(s1), s1, set);
	if (start == ft_strlen(s1))
		return (ft_strdup(""));
	end = ft_checkend(ft_strlen(set), ft_strlen(s1), s1, set);
	tab = malloc(sizeof(char) * (end - start + 2));
	if (!tab)
		return (NULL);
	while (start <= end)
	{
		tab[i] = s1[start];
		i++;
		start++;
	}
	tab[i] = '\0';
	return (tab);
}
