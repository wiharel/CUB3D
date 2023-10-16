/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:23:56 by pli               #+#    #+#             */
/*   Updated: 2023/04/04 14:23:59 by pli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3D.h"

int	ft_value_len(t_map m, unsigned int i, unsigned int jo)
{
	int	len;

	len = 0;
	while (m.map[i][jo] != ',' && m.map[i][jo] != '\n')
	{
		jo++;
		len++;
	}
	return (len + 1);
}

int	ft_free_map_error(t_map m, char *msg)
{
	int	i;

	printf("%s\n", msg);
	if (m.path_no != NULL)
		free(m.path_no);
	if (m.path_so != NULL)
		free(m.path_so);
	if (m.path_we != NULL)
		free(m.path_we);
	if (m.path_ea != NULL)
		free(m.path_ea);
	i = 0;
	while (m.map[i] != 0)
	{
		free(m.map[i]);
		i++;
	}
	free(m.map);
	exit(0);
}

void	ft_check_pos_val(t_map m, int pos_val, char c)
{
	if (pos_val != 2)
	{
		printf("[Wrong %c configuration: Invalid number of values]\n", c);
		ft_free_map_error(m, "");
	}
}

void	ft_free_color(t_map m, char *value, char c, char *msg)
{
	free(value);
	printf("[Wrong color %c configuration: %s\n", c, msg);
	ft_free_map_error(m, "");
}

int	ft_get_val(t_map m, char *value, char c)
{
	int	val;

	val = ft_atoi(value);
	if (val < 0 || val > 255)
		ft_free_color(m, value, c, "RGB Value range should be 0 to 255");
	return (val);
}
