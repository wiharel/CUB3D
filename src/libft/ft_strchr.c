/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:43:35 by pli               #+#    #+#             */
/*   Updated: 2022/03/17 14:51:23 by pli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned int	i;
	char			*tmp;

	i = 0;
	tmp = (char *) str;
	while (tmp[i] != '\0' && tmp[i] != (unsigned char)c)
		i++;
	if (tmp[i] == (unsigned char)c)
		return (&tmp[i]);
	return (0);
}
