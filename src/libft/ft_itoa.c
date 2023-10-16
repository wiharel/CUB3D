/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 22:22:41 by pli               #+#    #+#             */
/*   Updated: 2022/03/17 14:46:44 by pli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_getlen(long nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = -nb;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*dst;
	long	nb;
	int		len;

	nb = n;
	len = ft_getlen(nb);
	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	dst[len--] = '\0';
	if (nb == 0)
		dst[0] = '0';
	if (nb < 0)
	{
		dst[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		dst[len] = nb % 10 + '0';
		nb = nb / 10;
		len--;
	}
	return (dst);
}
