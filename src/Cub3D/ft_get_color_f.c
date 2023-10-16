/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color_f.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:23:56 by pli               #+#    #+#             */
/*   Updated: 2023/04/04 14:23:59 by pli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3D.h"

t_map	ft_get_color_f2(t_map m, unsigned int i, int jo, int pos_val)
{
	int		k;
	char	*value;

	value = 0;
	while (m.map[i][++jo] != 0 && m.map[i][jo] != '\n')
	{
		k = -1;
		value = malloc(sizeof(char) * ft_value_len(m, i, jo));
		if (!value)
			ft_free_map_error(m, "F value malloc failed");
		if (m.map[i][jo] == ',')
			ft_free_color(m, value, 'F', "miss value");
		while (m.map[i][jo] != ',' && m.map[i][jo] != '\n')
		{
			if (m.map[i][jo] < '0' || m.map[i][jo] > '9')
				ft_free_color(m, value, 'F', "should only have numbers");
			value[++k] = m.map[i][jo];
			jo++;
		}
		value[++k] = '\0';
		m.f[++pos_val] = ft_get_val(m, value, 'F');
		free(value);
	}
	ft_check_pos_val(m, pos_val, 'F');
	return (m);
}

t_map	ft_get_color_f(t_map m, unsigned int i, unsigned int j, int jo)
{
	while (m.map[i][++j] != '\n')
	{
		if (m.map[i][j] == 'F')
		{
			j += 1;
			while (m.map[i][j + 1] != '\n' && m.map[i][j + 1] != '\0'
			&& m.map[i][j++] == ' ')
				jo = j;
		}
	}
	m = ft_get_color_f2(m, i, jo -1, -1);
	return (m);
}
