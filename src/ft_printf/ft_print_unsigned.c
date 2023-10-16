/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 19:22:37 by pli               #+#    #+#             */
/*   Updated: 2022/03/17 14:43:45 by pli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include "../../includes/ft_printf.h"

int	ft_len_unsigned(unsigned int num)
{
	int	len_num;

	len_num = 0;
	while (num != 0)
	{
		num = num / 10;
		len_num++;
	}
	return (len_num);
}

char	*ft_itoa_unsigned(unsigned int num)
{
	char	*dst;
	int		len;

	len = ft_len_unsigned(num);
	dst = malloc(sizeof(char) * (len + 1));
	dst[len--] = '\0';
	while (num != 0)
	{
		dst[len] = num % 10 + '0';
		num = num / 10;
		len--;
	}
	return (dst);
}

int	ft_print_unsigned(unsigned int num)
{
	int		len_str;
	char	*nbr;

	len_str = 0;
	if (num == 0)
		len_str += write(1, "0", 1);
	else
	{
		nbr = ft_itoa_unsigned(num);
		len_str += ft_print_str(nbr);
		free(nbr);
	}
	return (len_str);
}
