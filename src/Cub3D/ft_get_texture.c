/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pli <pli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:21:04 by pli               #+#    #+#             */
/*   Updated: 2023/03/30 15:46:31 by pli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3D.h"

t_map	ft_check_xpm(t_map m, unsigned int i, unsigned int pos, unsigned int j)
{
	if (m.map[i][pos] != 'x' || m.map[i][pos + 1] != 'p'
	|| m.map[i][pos + 2] != 'm')
		ft_free_identifier(m, "texture file not xpm");
	pos += 3;
	while (m.map[i][pos] != 0 && pos != j)
	{
		if (m.map[i][pos] != ' ')
			ft_free_identifier(m, "Wrong texture path configuration");
		pos++;
	}
	return (m);
}

t_map	ft_get_texture_ea(t_map m, unsigned int i, unsigned int j)
{
	int	jo;
	int	pos;

	jo = j;
	pos = -1;
	while (m.map[i][j] != '\n' && m.map[i][j] != '\0')
		j++;
	if (m.path_ea != NULL)
		return (m);
	m.path_ea = malloc(sizeof(char) * (j - jo + 1));
	if (!m.path_ea)
		ft_free_identifier(m, "path_ea failed to malloc");
	jo--;
	while (m.map[i][++jo] != '\n' && m.map[i][jo] != '\0'
	&& m.map[i][jo] != ' ')
		m.path_ea[++pos] = m.map[i][jo];
	m.path_ea[pos + 1] = '\0';
	m = ft_check_xpm(m, i, jo - 3, j);
	return (m);
}

t_map	ft_get_texture_we(t_map m, unsigned int i, unsigned int j)
{
	int	jo;
	int	pos;

	jo = j;
	pos = -1;
	while (m.map[i][j] != '\n' && m.map[i][j] != '\0')
		j++;
	if (m.path_we != NULL)
		return (m);
	m.path_we = malloc(sizeof(char) * (j - jo + 1));
	if (!m.path_we)
		ft_free_identifier(m, "path_we failed to malloc");
	jo--;
	while (m.map[i][++jo] != '\n' && m.map[i][jo] != '\0'
	&& m.map[i][jo] != ' ')
		m.path_we[++pos] = m.map[i][jo];
	m.path_we[pos + 1] = '\0';
	m = ft_check_xpm(m, i, jo - 3, j);
	return (m);
}

t_map	ft_get_texture_so(t_map m, unsigned int i, unsigned int j)
{
	int	jo;
	int	pos;

	jo = j;
	pos = -1;
	while (m.map[i][j] != '\n' && m.map[i][j] != '\0')
		j++;
	if (m.path_so != NULL)
		return (m);
	m.path_so = malloc(sizeof(char) * (j - jo + 1));
	if (!m.path_so)
		ft_free_identifier(m, "path_so failed to malloc");
	jo--;
	while (m.map[i][++jo] != '\n' && m.map[i][jo] != '\0')
		m.path_so[++pos] = m.map[i][jo];
	m.path_so[pos + 1] = '\0';
	m = ft_check_xpm(m, i, jo - 3, j);
	return (m);
}

t_map	ft_get_texture_no(t_map m, unsigned int i, unsigned int j)
{
	int	jo;
	int	pos;

	jo = j;
	pos = -1;
	while (m.map[i][j] != '\n' && m.map[i][j] != '\0')
		j++;
	if (m.path_no != NULL)
		return (m);
	m.path_no = malloc(sizeof(char) * (j - jo + 1));
	if (!m.path_no)
		ft_free_identifier(m, "path_no failed to malloc");
	jo--;
	while (m.map[i][++jo] != '\n' && m.map[i][jo] != '\0')
		m.path_no[++pos] = m.map[i][jo];
	m.path_no[pos + 1] = '\0';
	m = ft_check_xpm(m, i, jo - 3, j);
	return (m);
}
