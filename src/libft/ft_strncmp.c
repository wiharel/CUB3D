/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:44:40 by pli               #+#    #+#             */
/*   Updated: 2022/03/17 14:54:34 by pli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*ps1;
	unsigned char	*ps2;

	i = 0;
	ps1 = (unsigned char *) s1;
	ps2 = (unsigned char *) s2;
	if (n > 0)
	{
		while ((ps1[i] != '\0' || ps2[i] != '\0') && i < n)
		{
			if (ps1[i] != ps2[i])
				return (ps1[i] - ps2[i]);
			i++;
		}
	}
	return (0);
}
