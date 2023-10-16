/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_hole.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:25:02 by pli               #+#    #+#             */
/*   Updated: 2023/04/16 18:57:08 by pli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3D.h"

void	ft_check_wall_hole1(t_map m, unsigned int i, unsigned int j)
{
	if (m.check_map[i + 1] != 0 && m.check_map[i + 1][j] == '1')
		return ;
	if (m.check_map[i + 1] == 0 || i == 0
		|| j == 0 || j > ft_strlen(m.check_map[i - 1]) - 2
		|| j > ft_strlen(m.check_map[i + 1]) - 2)
		ft_free_holes(m, 0);
}

void	ft_check_wall_hole2(t_map m, unsigned int i, unsigned int j)
{
	if ((m.check_map[i + 1][j] != '1'
		&& m.check_map[i + 1][j] != 'A')
		|| (m.check_map[i - 1][j] != '1'
		&& m.check_map[i - 1][j] != 'A')
		|| (m.check_map[i][j + 1] != '1'
		&& m.check_map[i][j + 1] != 'A')
		|| (m.check_map[i][j - 1] != '1'
		&& m.check_map[i][j - 1] != 'A'))
		ft_free_holes(m, 0);
}
