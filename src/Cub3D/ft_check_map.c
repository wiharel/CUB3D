/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:25:02 by pli               #+#    #+#             */
/*   Updated: 2023/04/04 14:25:05 by pli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3D.h"

int	ft_check_left(t_map m, unsigned int i, unsigned int j)
{
	if (j > 0 && m.check_map[i][j - 1] == '0')
	{
		m.check_map[i][j - 1] = 'A';
		if (!ft_check_around(m, i, j - 1))
			return (0);
	}
	return (1);
}

int	ft_check_right(t_map m, unsigned int i, unsigned int j)
{
	if (m.check_map[i][j + 1] != '\n' && m.check_map[i][j + 1]
	&& (m.check_map[i][j + 1] == '0'))
	{
		m.check_map[i][j + 1] = 'A';
		if (!ft_check_around(m, i, j + 1))
			return (0);
	}
	return (1);
}

int	ft_check_down(t_map m, unsigned int i, unsigned int j)
{
	if (j < ft_strlen(m.check_map[i + 1]) && m.check_map[i + 1]
		&& (m.check_map[i + 1][j] == '0'))
	{
		m.check_map[i + 1][j] = 'A';
		if (!ft_check_around(m, i + 1, j))
			return (0);
	}
	return (1);
}

int	ft_check_up(t_map m, unsigned int i, unsigned int j)
{
	if (i > 0 && j < ft_strlen(m.check_map[i - 1])
		&& m.check_map[i - 1][j] == '0')
	{
		m.check_map[i - 1][j] = 'A';
		if (!ft_check_around(m, i - 1, j))
			return (0);
	}
	return (1);
}
