/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:07:50 by pli               #+#    #+#             */
/*   Updated: 2022/03/17 14:42:56 by pli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include "../../includes/ft_printf.h"

int	ft_print_nbr(int num)
{
	int		len_str;
	char	*str;

	len_str = 0;
	str = ft_itoa(num);
	len_str += ft_print_str(str);
	free(str);
	return (len_str);
}
