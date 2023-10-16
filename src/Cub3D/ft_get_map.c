/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:25:02 by pli               #+#    #+#             */
/*   Updated: 2023/04/16 18:54:26 by pli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3D.h"

int	ft_num_lines_mini(char **map, int size)
{
	int	i;

	i = 0;
	while (map[i] != 0)
		i++;
	return (i - size);
}

int	ft_check_around(t_map m, unsigned int i, unsigned int j)
{
	m.check_map[i][j] = 'A';
	ft_check_wall_hole1(m, i, j);
	if (!ft_check_up(m, i, j))
		return (0);
	if (!ft_check_left(m, i, j))
		return (0);
	if (!ft_check_down(m, i, j))
		return (0);
	if (!ft_check_right(m, i, j))
		return (0);
	ft_check_wall_hole2(m, i, j);
	return (1);
}

int	ft_check_mini_map(t_map m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	m.player_count = 0;
	ft_check_around(m, m.player_y, m.player_x);
	while (m.check_map[i] != 0)
	{
		while (m.check_map[i][j] != '\n' && m.check_map[i][j] != '\0')
		{
			if (m.check_map[i][j] == '0')
				ft_check_around(m, i, j);
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

t_map	ft_dup_mini_map(t_map m, unsigned int i, int j, int k)
{
	int	len;

	len = ft_num_lines_mini(m.map, i + 1);
	m.mini_map = malloc(sizeof(char *) * (len + 1));
	m.check_map = malloc(sizeof(char *) * (len + 1));
	if (!m.mini_map || !m.check_map)
		ft_free_map_error(m, "mini map/check map malloc failed");
	while (m.map[++i] != 0)
	{
		m.mini_map[++j] = m.map[i];
		m.check_map[j] = malloc(sizeof(char) * (ft_strlen(m.map[i]) + 1));
		if (!m.check_map[j])
			ft_free_map_error(m, "check map malloc failed");
		while ((size_t)(++k) < ft_strlen(m.map[i]) + 1)
			m.check_map[j][k] = m.map[i][k];
		k = -1;
	}
	m.mini_map[len] = 0;
	m.check_map[len] = 0;
	m.player_x = ft_mini_player_x(m, -1, -1);
	m.player_y = ft_mini_player_y(m, -1, -1);
	ft_check_mini_map(m);
	return (m);
}

t_map	ft_get_map(t_map m, unsigned int i, unsigned int j, int check)
{
	while (m.map[i] != 0 && m.map[i + 1] != 0
		&& m.map[++i][++j] != '\0' && check == 0)
	{
		while (m.map[i][++j] != '\n' && check == 0)
		{
			if (m.map[i][j] == '\0' || m.map[i][j] == '\n')
				break ;
			if (m.map[i][j] != ' ')
				check = 1;
		}
		j = -1;
	}
	return (ft_dup_mini_map(m, i - 2, -1, -1));
}
