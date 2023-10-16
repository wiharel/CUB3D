/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:46:54 by pli               #+#    #+#             */
/*   Updated: 2022/03/17 14:42:22 by pli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include "../../includes/ft_printf.h"

int	ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_format(va_list args, const char format)
{
	if (format == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (format == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (format == 'p')
		return (ft_print_ptr(va_arg(args, unsigned long long)));
	else if (format == 'd' || format == 'i')
		return (ft_print_nbr(va_arg(args, int)));
	else if (format == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	else if (format == 'X' || format == 'x')
		return (ft_print_hex(va_arg(args, unsigned int), format));
	else if (format == '%')
		return (ft_print_char('%'));
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	int		len_str;
	int		pos;
	va_list	args;

	len_str = 0;
	pos = 0;
	va_start(args, format);
	while (format[pos])
	{
		if (format[pos] == '%')
		{
			len_str += ft_print_format(args, format[pos + 1]);
			pos++;
		}
		else
			len_str += ft_print_char(format[pos]);
		pos++;
	}
	va_end(args);
	return (len_str);
}
