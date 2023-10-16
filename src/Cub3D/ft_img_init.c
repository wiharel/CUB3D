/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:33:41 by pli               #+#    #+#             */
/*   Updated: 2023/04/16 19:30:33 by pli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3D.h"

t_program	ft_img_init_ea(t_program program, int tmp,
	int img_width, int img_height)
{
	program.img_ptr->img_ea = mlx_xpm_file_to_image(program.mlx_ptr,
			program.map.path_ea, &img_width, &img_height);
	if (program.img_ptr->img_ea == NULL)
		ft_free_exit(program, "[Testure EA failed to open]\n", -1);
	program.img_ptr->ea_data = (int *)mlx_get_data_addr
		(program.img_ptr->img_ea, &tmp, &tmp, &tmp);
	return (program);
}

t_program	ft_img_init_we(t_program program, int tmp,
	int img_width, int img_height)
{
	program.img_ptr->img_we = mlx_xpm_file_to_image(program.mlx_ptr,
			program.map.path_we, &img_width, &img_height);
	if (program.img_ptr->img_we == NULL)
		ft_free_exit(program, "[Testure WE failed to open]\n", -1);
	program.img_ptr->we_data = (int *)mlx_get_data_addr
		(program.img_ptr->img_we, &tmp, &tmp, &tmp);
	return (program);
}

t_program	ft_img_init_so(t_program program, int tmp,
	int img_width, int img_height)
{
	program.img_ptr->img_so = mlx_xpm_file_to_image(program.mlx_ptr,
			program.map.path_so, &img_width, &img_height);
	if (program.img_ptr->img_so == NULL)
		ft_free_exit(program, "[Testure SO failed to open]\n", -1);
	program.img_ptr->so_data = (int *)mlx_get_data_addr
		(program.img_ptr->img_so, &tmp, &tmp, &tmp);
	return (program);
}

t_program	ft_img_init_no(t_program program, int tmp,
	int img_width, int img_height)
{
	program.img_ptr->img_no = mlx_xpm_file_to_image(program.mlx_ptr,
			program.map.path_no, &img_width, &img_height);
	if (program.img_ptr->img_no == NULL)
		ft_free_exit(program, "[Testure NO failed to open]\n", -1);
	program.img_ptr->no_data = (int *)mlx_get_data_addr
		(program.img_ptr->img_no, &tmp, &tmp, &tmp);
	return (program);
}

void	ft_img_init(t_program program)
{
	int	img_width;
	int	img_height;
	int	tmp;

	tmp = 0;
	img_width = 0;
	img_height = 0;
	program.img_ptr = malloc(sizeof(t_data));
	if (!program.img_ptr)
		ft_free_exit(program, "Failed to malloc data", -1);
	program.img_ptr->img_no = NULL;
	program.img_ptr->img_so = NULL;
	program.img_ptr->img_we = NULL;
	program.img_ptr->img_ea = NULL;
	program = ft_img_init_no(program, tmp, img_width, img_height);
	program = ft_img_init_so(program, tmp, img_width, img_height);
	program = ft_img_init_we(program, tmp, img_width, img_height);
	program = ft_img_init_ea(program, tmp, img_width, img_height);
	ft_mlx(program);
}
