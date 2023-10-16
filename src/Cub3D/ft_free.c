/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:22:57 by pli               #+#    #+#             */
/*   Updated: 2023/04/04 15:04:19 by pli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3D.h"

void	ft_free_path(t_program program)
{
	if (program.map.path_no != NULL)
		free(program.map.path_no);
	if (program.map.path_so != NULL)
		free(program.map.path_so);
	if (program.map.path_we != NULL)
		free(program.map.path_we);
	if (program.map.path_ea != NULL)
		free(program.map.path_ea);
}

int	ft_free_env(t_program program)
{
	int	i;

	free(program.map.path_no);
	free(program.map.path_so);
	free(program.map.path_we);
	free(program.map.path_ea);
	i = 0;
	while (program.map.map[i] != 0)
	{
		free(program.map.map[i]);
		i++;
	}
	free(program.map.map);
	i = 0;
	while (program.map.check_map[i] != 0)
	{
		free(program.map.check_map[i]);
		i++;
	}
	free(program.map.check_map);
	free(program.map.mini_map);
	exit(0);
}

int	ft_free_identifier(t_map m, char *msg)
{
	int	i;

	i = 0;
	printf("[Wrong map configuration:%s]\n", msg);
	if (m.path_no != NULL)
		free(m.path_no);
	if (m.path_so != NULL)
		free(m.path_so);
	if (m.path_we != NULL)
		free(m.path_we);
	if (m.path_ea != NULL)
		free(m.path_ea);
	while (m.map[i] != 0)
	{
		free(m.map[i]);
		i++;
	}
	free(m.map);
	exit(0);
}
