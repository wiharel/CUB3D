/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 22:23:57 by pli               #+#    #+#             */
/*   Updated: 2022/03/17 14:53:38 by pli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ps;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	ps = ft_strdup(s);
	if (!f || !ps)
		return (NULL);
	while (ps[i])
	{
		ps[i] = f(i, ps[i]);
		i++;
	}
	return (ps);
}
