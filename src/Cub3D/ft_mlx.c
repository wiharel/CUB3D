/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:24:25 by pli               #+#    #+#             */
/*   Updated: 2023/04/04 14:24:27 by pli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3D.h"

void	ft_player_movement(int keycode, t_program *program)
{
	if (keycode == KEY_W)
		ft_player_up(program);
	if (keycode == KEY_S)
		ft_player_down(program);
	if (keycode == KEY_A)
		ft_player_left(program);
	if (keycode == KEY_D)
		ft_player_right(program);
	if (keycode == KEY_LEFT)
		ft_look_left(program);
	if (keycode == KEY_RIGHT)
		ft_look_right(program);
}

int	ft_keys(int keycode, t_program *program)
{
	if (keycode == KEY_ESC)
		ft_key_exit(program);
	ft_player_movement(keycode, program);
	ft_draw_ray(program, 0, 0);
	mlx_put_image_to_window(program->mlx_ptr, program->mlx_win,
		program->map.image, 0, 0);
	return (0);
}

void	ft_mlx(t_program program)
{
	ft_draw_ray(&program, 0, 0);
	mlx_put_image_to_window(program.mlx_ptr,
		program.mlx_win, program.map.image, 0, 0);
	mlx_hook(program.mlx_win, 17, 2, ft_mouse_exit, &program);
	mlx_key_hook(program.mlx_win, ft_keys, &program);
	mlx_loop(program.mlx_ptr);
}
