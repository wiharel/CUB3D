/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:16:34 by pli               #+#    #+#             */
/*   Updated: 2022/03/17 14:53:10 by pli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_strlen(const char *str)
{
	unsigned int	i;
	char			*pstr;

	i = 0;
	pstr = (char *) str;
	while (pstr[i])
		i++;
	return (i);
}