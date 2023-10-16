/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:28:03 by pli               #+#    #+#             */
/*   Updated: 2022/03/17 14:43:12 by pli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include "../../includes/ft_printf.h"

int	ft_ptr_len(unsigned long long ptr)
{
	int	len_ptr;

	len_ptr = 0;
	while (ptr != 0)
	{
		len_ptr++;
		ptr = ptr / 16;
	}
	return (len_ptr);
}

void	ft_putptr_base(unsigned long long ptr)
{
	char	*base;

	base = "0123456789abcdef";
	if (ptr >= 16)
		ft_putptr_base(ptr / 16);
	ft_putchar_fd(base[ptr % 16], 1);
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	len_str;

	len_str = 0;
	len_str += write(1, "0x", 2);
	if (ptr == 0)
		len_str += write(1, "0", 1);
	else
	{
		ft_putptr_base(ptr);
		len_str += ft_ptr_len(ptr);
	}
	return (len_str);
}
