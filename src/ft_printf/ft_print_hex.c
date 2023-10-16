/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 22:35:42 by pli               #+#    #+#             */
/*   Updated: 2022/03/17 14:42:41 by pli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include "../../includes/ft_printf.h"

int	ft_len_hex(unsigned int num)
{
	int	len_num;

	len_num = 0;
	while (num != 0)
	{
		num = num / 16;
		len_num++;
	}
	return (len_num);
}

void	ft_hex_base(unsigned int num, const char format)
{
	char	*base_min;
	char	*base_maj;

	base_min = "0123456789abcdef";
	base_maj = "0123456789ABCDEF";
	if (num >= 16)
		ft_hex_base(num / 16, format);
	if (format == 'x')
		ft_putchar_fd(base_min[num % 16], 1);
	if (format == 'X')
		ft_putchar_fd(base_maj[num % 16], 1);
}

int	ft_print_hex(unsigned int num, const char format)
{
	int	len_str;

	len_str = 0;
	if (num == 0)
	{
		len_str += write(1, "0", 1);
		return (len_str);
	}
	else
	{
		ft_hex_base(num, format);
		len_str += ft_len_hex(num);
	}
	return (len_str);
}
