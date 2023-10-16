/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pli <pli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 21:35:21 by pli               #+#    #+#             */
/*   Updated: 2023/04/04 15:05:09 by pli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3D.h"

int	ft_free_holes(t_map m, int i)
{
	printf("[Wrong map configuration:");
	printf("map should only have one player and 0 and closed wall 1]\n");
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
	free(m.mini_map);
	i = 0;
	while (m.check_map[i] != 0)
	{
		free(m.check_map[i]);
		i++;
	}
	free(m.check_map);
	exit(0);
}

void	ft_map_error(char *msg, unsigned int i, unsigned int j, char c)
{
	(void)i;
	(void)c;
	(void)j;
	printf("Error\n" YYL "%s" RET, msg);
	exit (0);
}

void	ft_error(void)
{
	printf("Error\n");
	exit (0);
}

void	ft_wrong_arg(void)
{
	printf("Error\n" YYL "[Wrong arguments]\n" RET);
	exit(0);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		ft_wrong_arg();
	ft_check_mapname(argv[1]);
	return (0);
}
