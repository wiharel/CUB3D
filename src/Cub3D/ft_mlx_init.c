/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pli <pli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 01:16:20 by pli               #+#    #+#             */
/*   Updated: 2023/04/04 14:20:14 by pli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3D.h"

float	ft_get_degrees(t_program program)
{
	if (program.map.mini_map[(int)program.map.player_y]
		[(int)program.map.player_x])
	{
		if (program.map.mini_map[(int)program.map.player_y]
			[(int)program.map.player_x] == 'N')
			return (PI / 2);
		if (program.map.mini_map[(int)program.map.player_y]
			[(int)program.map.player_x] == 'S')
			return (3 * PI / 2);
		if (program.map.mini_map[(int)program.map.player_y]
			[(int)program.map.player_x] == 'E')
			return (0 - (PI * 2));
		if (program.map.mini_map[(int)program.map.player_y]
			[(int)program.map.player_x] == 'W')
			return (PI);
	}
	return (0);
}

long int	ft_convert_floor(t_program program)
{
	long int	ret;

	ret = 0;
	ret += program.map.f[0] * 65536;
	ret += program.map.f[1] * 256;
	ret += program.map.f[2];
	return (ret);
}

long int	ft_convert_ceiling(t_program program)
{
	long int	ret;

	ret = 0;
	ret += program.map.c[0] * 65536;
	ret += program.map.c[1] * 256;
	ret += program.map.c[2];
	return (ret);
}

void	ft_init_mlx(t_program program)
{
	int	tmp;

	program.mlx_ptr = mlx_init();
	if (!program.mlx_ptr)
		ft_free_env(program);
	program.mlx_win = mlx_new_window(program.mlx_ptr,
			SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3D");
	program.player.player_x = program.map.player_x + 0.5;
	program.player.player_y = program.map.player_y + 0.5;
	program.player.player_x_old = program.player.player_x;
	program.player.player_y_old = program.player.player_y;
	program.player.player_angle = ft_get_degrees(program);
	program.player.player_delta_x = cos(program.player.player_angle);
	program.player.player_delta_y = sin(program.player.player_angle);
	program.map.floor_color = ft_convert_floor(program);
	program.map.ceiling_color = ft_convert_ceiling(program);
	program.map.image = mlx_new_image(program.mlx_ptr,
			SCREEN_WIDTH, SCREEN_HEIGHT);
	program.map.data = (int *)mlx_get_data_addr(program.map.image,
			&tmp, &tmp, &tmp);
	program.map.mlx_ptr = program.mlx_ptr;
	program.map.mlx_win = program.mlx_win;
	ft_img_init(program);
}
