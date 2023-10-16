/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:45:00 by pli               #+#    #+#             */
/*   Updated: 2022/03/17 14:54:49 by pli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strnstr(const char *dst, const char *src, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	tmp;

	i = 0;
	j = 0;
	tmp = 0;
	if (*src == '\0' || src == NULL)
		return ((char *) dst);
	while (dst[i] != '\0' && i < len)
	{
		j = 0;
		tmp = i;
		while (dst[tmp] == src[j])
		{
			if (src[j + 1] == '\0' && i + j < len)
				return ((char *) dst + i);
			j++;
			tmp++;
		}
		i++;
	}
	return (0);
}
