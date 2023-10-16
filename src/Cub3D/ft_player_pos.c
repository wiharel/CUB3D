/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:24:41 by pli               #+#    #+#             */
/*   Updated: 2023/04/04 15:01:19 by pli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3D.h"

void	ft_free_no_player(t_map m)
{
	int	i;

	free(m.path_no);
	free(m.path_so);
	free(m.path_we);
	free(m.path_ea);
	i = 0;
	while (m.map[i] != 0)
	{
		free(m.map[i]);
		i++;
	}
	free(m.map);
	i = 0;
	while (m.check_map[i] != 0)
	{
		free(m.check_map[i]);
		i++;
	}
	free(m.check_map);
	free(m.mini_map);
	return ;
}

void	ft_player_error(char *msg, t_map m)
{
	printf("Error\n" YYL "%s\n" RET, msg);
	ft_free_no_player(m);
	exit(0);
}

int	ft_mini_player_x(t_map m, unsigned int i, unsigned int j)
{
	while (m.mini_map[++i] != 0)
	{
		while (m.mini_map[i][++j] != '\n' && m.mini_map[i][j] != '\0')
		{
			if (m.mini_map[i][j] == 'N' || m.mini_map[i][j] == 'S'
	|| m.mini_map[i][j] == 'E' || m.mini_map[i][j] == 'W')
				return (j);
		}
		j = -1;
	}
	ft_player_error("[Player not found in the map]", m);
	return (0);
}

int	ft_mini_player_y(t_map m, unsigned int i, unsigned int j)
{
	while (m.mini_map[++i] != 0)
	{
		while (m.mini_map[i][++j] != '\n' && m.mini_map[i][j] != '\0')
		{
			if (m.mini_map[i][j] == 'N' || m.mini_map[i][j] == 'S'
	|| m.mini_map[i][j] == 'E' || m.mini_map[i][j] == 'W')
				return (i);
		}
		j = -1;
	}
	ft_player_error("[Player not found in the map]", m);
	return (0);
}
