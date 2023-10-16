/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 22:12:04 by pli               #+#    #+#             */
/*   Updated: 2022/03/17 14:55:29 by pli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*tab;
	unsigned int		i;
	unsigned int		len_s;

	i = 0;
	if (!s)
		return (NULL);
	len_s = ft_strlen(s + start);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (len_s < len)
		len = len_s;
	tab = malloc(sizeof(char) * (len + 1));
	if (!tab)
		return (NULL);
	len_s = ft_strlen(s);
	while (i < len && start < len_s)
	{
		tab[i] = s[start];
		i++;
		start++;
	}
	tab[i] = '\0';
	return (tab);
}
