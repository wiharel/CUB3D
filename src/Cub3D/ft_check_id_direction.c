/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_id_direction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:08:27 by pli               #+#    #+#             */
/*   Updated: 2023/04/04 15:18:18 by pli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3D.h"

t_map	ft_check_no(t_map m, unsigned int i, unsigned int j)
{
	j += 2;
	if (m.map[i][j] == ' ')
		while (m.map[i][j] != '\n' && m.map[i][j] != '\0' && m.map[i][j] == ' ')
			j++;
	else
		ft_free_identifier(m, "path of NO");
	m.check_no += 1;
	m = ft_get_texture_no(m, i, j);
	if (m.check_no > 1 || m.check_so > 1
		|| m.check_we > 1 || m.check_ea > 1 || m.check_f > 1 || m.check_c > 1)
		ft_free_identifier(m, "more than one NO");
	return (m);
}

t_map	ft_check_so(t_map m, unsigned int i, unsigned int j)
{
	j += 2;
	if (m.map[i][j] == ' ')
		while (m.map[i][j] != '\n' && m.map[i][j] != '\0' && m.map[i][j] == ' ')
			j++;
	m.check_so += 1;
	m = ft_get_texture_so(m, i, j);
	if (m.check_no > 1 || m.check_so > 1
		|| m.check_we > 1 || m.check_ea > 1 || m.check_f > 1 || m.check_c > 1)
		ft_free_identifier(m, "more than one SO");
	return (m);
}

t_map	ft_check_we(t_map m, unsigned int i, unsigned int j)
{
	j += 2;
	if (m.map[i][j] == ' ')
		while (m.map[i][j] != '\n' && m.map[i][j] != '\0' && m.map[i][j] == ' ')
			j++;
	m.check_we += 1;
	m = ft_get_texture_we(m, i, j);
	if (m.check_no > 1 || m.check_so > 1
		|| m.check_we > 1 || m.check_ea > 1 || m.check_f > 1 || m.check_c > 1)
		ft_free_identifier(m, "more than one WE");
	return (m);
}

t_map	ft_check_ea(t_map m, unsigned int i, unsigned int j)
{
	j += 2;
	if (m.map[i][j] == ' ')
		while (m.map[i][j] != '\n' && m.map[i][j] != '\0' && m.map[i][j] == ' ')
			j++;
	m.check_ea += 1;
	m = ft_get_texture_ea(m, i, j);
	if (m.check_no > 1 || m.check_so > 1
		|| m.check_we > 1 || m.check_ea > 1 || m.check_f > 1 || m.check_c > 1)
		ft_free_identifier(m, "more than one EA");
	return (m);
}
