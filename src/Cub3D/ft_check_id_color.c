/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_id_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:07:12 by pli               #+#    #+#             */
/*   Updated: 2023/04/04 15:20:20 by pli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3D.h"

t_map	ft_check_f(t_map m, unsigned int i, unsigned int j)
{
	j += 1;
	if (m.map[i][j] == ' ')
		while (m.map[i][j] != '\n' && m.map[i][j] == ' ')
			j++;
	m.check_f += 1;
	m = ft_get_color_f(m, i, -1, 0);
	if (m.check_no > 1 || m.check_so > 1 || m.check_we > 1
		|| m.check_ea > 1 || m.check_f > 1 || m.check_c > 1)
		ft_free_identifier(m, "more than one F");
	return (m);
}

t_map	ft_check_c(t_map m, unsigned int i, unsigned int j)
{
	j += 1;
	if (m.map[i][j] == ' ')
		while (m.map[i][j] != '\n' && m.map[i][j] == ' ')
			j++;
	m.check_c += 1;
	m = ft_get_color_c(m, i, -1, 0);
	if (m.check_no > 1 || m.check_so > 1 || m.check_we > 1
		|| m.check_ea > 1 || m.check_f > 1 || m.check_c > 1)
		ft_free_identifier(m, "more than one C");
	return (m);
}
