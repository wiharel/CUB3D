/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:22:57 by pli               #+#    #+#             */
/*   Updated: 2023/04/04 15:04:19 by pli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3D.h"

void	ft_free_exit(t_program program, char *msg, int i)
{
	printf("%s", msg);
	ft_free_path(program);
	while (program.map.map[++i] != 0)
		free(program.map.map[i]);
	free(program.map.map);
	free(program.map.mini_map);
	i = -1;
	while (program.map.check_map[++i] != 0)
		free(program.map.check_map[i]);
	free(program.map.check_map);
	if (program.img_ptr->img_no != NULL)
		mlx_destroy_image(program.mlx_ptr, program.img_ptr->img_no);
	if (program.img_ptr->img_so != NULL)
		mlx_destroy_image(program.mlx_ptr, program.img_ptr->img_so);
	if (program.img_ptr->img_we != NULL)
		mlx_destroy_image(program.mlx_ptr, program.img_ptr->img_we);
	if (program.img_ptr->img_ea != NULL)
		mlx_destroy_image(program.mlx_ptr, program.img_ptr->img_ea);
	free(program.img_ptr);
	mlx_destroy_image(program.mlx_ptr, program.map.image);
	mlx_destroy_window(program.mlx_ptr, program.mlx_win);
	mlx_destroy_display(program.mlx_ptr);
	free(program.mlx_ptr);
	exit(0);
}

int	ft_mouse_exit(t_program *program)
{
	ft_free_exit(*program, "Game exit\n", -1);
	return (0);
}

int	ft_key_exit(t_program *program)
{
	ft_free_exit(*program, "Game exit\n", -1);
	return (0);
}
