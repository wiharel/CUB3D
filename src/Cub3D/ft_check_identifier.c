/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_identifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:47:44 by pli               #+#    #+#             */
/*   Updated: 2023/04/16 19:03:20 by pli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3D.h"

int	ft_skip_empty_space(t_map m, unsigned int i, unsigned int j)
{
	while (m.map[i][j] != '\n' && m.map[i][j] != '\0')
	{
		if (m.map[i][j] != ' ')
			return (j);
		j++;
	}
	while (m.map[i] != 0)
	{
		j = 0;
		while (m.map[i][j] != '\n' && m.map[i][j] != '\0')
		{
			if (m.map[i][j] != '\n' && m.map[i][j] != '\0'
	&& m.map[i][j] != ' ')
				ft_free_identifier(m, "empty line not correct");
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_skip_empty_line(t_map m, unsigned int i, unsigned int j)
{
	int	check;

	check = 0;
	while (m.map[++i] != 0 && check == 0)
	{
		j = -1;
		while (m.map[i][++j] != '\n' && check == 0)
		{
			if (m.map[i][j] != ' ')
			{
				check = 1;
				break ;
			}
		}
	}
	i--;
	if (m.map[i + 1] == 0)
		ft_free_identifier(m, "miss map");
	return (i);
}

t_map	ft_check_extra_identifier(t_map m, int i, int j)
{
	while (m.map[i] != 0)
	{
		if (m.map[i][j] == ' ' || m.map[i][j] == '\n')
			j = ft_skip_empty_space(m, i, j);
		else if (m.map[i][j] == 'N' && m.map[i][j + 1] == 'O')
			ft_free_identifier(m, "more than one NO");
		else if (m.map[i][j] == 'S' && m.map[i][j + 1] == 'O')
			ft_free_identifier(m, "more than one SO");
		else if (m.map[i][j] == 'W' && m.map[i][j + 1] == 'E')
			ft_free_identifier(m, "more than one WE");
		else if (m.map[i][j] == 'E' && m.map[i][j + 1] == 'A')
			ft_free_identifier(m, "more than one EA");
		else if (m.map[i][j] == 'F')
			ft_free_identifier(m, "more than one F");
		else if (m.map[i][j] == 'C')
			ft_free_identifier(m, "more than one C");
		i++;
		j = 0;
	}
	return (m);
}

t_map	ft_check_directions_colors(t_map m, unsigned int i, unsigned int j)
{
	if (m.map[i][j] == 'N' && m.map[i][j + 1] == 'O')
		m = ft_check_no(m, i, j);
	else if (m.map[i][j] == 'S' && m.map[i][j + 1] == 'O')
		m = ft_check_so(m, i, j);
	else if (m.map[i][j] == 'W' && m.map[i][j + 1] == 'E')
		m = ft_check_we(m, i, j);
	else if (m.map[i][j] == 'E' && m.map[i][j + 1] == 'A')
		m = ft_check_ea(m, i, j);
	else if (m.map[i][j] == 'F')
		m = ft_check_f(m, i, j);
	else if (m.map[i][j] == 'C')
		m = ft_check_c(m, i, j);
	return (m);
}

t_map	ft_check_identifier(t_map m, unsigned int i, unsigned int j)
{
	while (m.map[i] != 0)
	{
		if (m.map[i][j] == 'F' || m.map[i][j] == 'C'
	|| (m.map[i][j] == 'N' && m.map[i][j + 1] == 'O')
	|| (m.map[i][j] == 'S' && m.map[i][j + 1] == 'O')
	|| (m.map[i][j] == 'W' && m.map[i][j + 1] == 'E')
	|| (m.map[i][j] == 'E' && m.map[i][j + 1] == 'A'))
		{
			m = ft_check_directions_colors(m, i, j);
			i = ft_skip_empty_line(m, i, j);
			j = ft_skip_empty_space(m, i, 0);
		}
		else if (m.map[i][j] == ' ' || m.map[i][j] == '\n')
			j = ft_skip_empty_space(m, i, j);
		else
			ft_free_identifier(m, "wrong identifier");
		if (m.check_no && m.check_so && m.check_we
			&& m.check_ea && m.check_f && m.check_c)
			break ;
	}
	ft_check_extra_identifier(m, i, j);
	m = ft_get_map(m, i - 1, 0, 0);
	return (m);
}
