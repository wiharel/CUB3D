/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:44:05 by pli               #+#    #+#             */
/*   Updated: 2022/03/17 14:52:24 by pli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t			i;
	size_t			len_dst;
	size_t			len_src;
	char			*psrc;

	i = 0;
	psrc = (char *) src;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(psrc);
	if (dstsize <= len_dst)
		return (len_src + dstsize);
	while (psrc[i] && i < dstsize - len_dst - 1)
	{
		dst[len_dst + i] = psrc[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_src + len_dst);
}
