/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:38:04 by pli               #+#    #+#             */
/*   Updated: 2022/03/17 14:50:08 by pli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	unsigned char	tmp;
	unsigned int	i;

	i = 0;
	tmp = c;
	str = b;
	while (i < len)
	{
		str[i] = tmp;
		i++;
	}
	return (b);
}
