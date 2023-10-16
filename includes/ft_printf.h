/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:50:11 by pli               #+#    #+#             */
/*   Updated: 2022/03/08 19:14:46 by pli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define RED "\e[0;31m"
# define GRN "\e[0;32m"
# define YYL "\e[0;33m"
# define RET "\033[0m"

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		ft_print_format(va_list args, const char format);
int		ft_print_char(char c);
int		ft_print_str(char *str);
int		ft_print_ptr(unsigned long long ptr);
int		ft_ptr_len(unsigned long long ptr);
int		ft_print_nbr(int num);
int		ft_print_unsigned(unsigned int num);
int		ft_print_hex(unsigned int num, const char format);
char	*ft_itoa_unsigned(unsigned int num);
void	ft_putptr_base(unsigned long long ptr);

#endif
