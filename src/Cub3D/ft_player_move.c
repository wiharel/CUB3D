/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:23:39 by pli               #+#    #+#             */
/*   Updated: 2023/04/04 14:23:42 by pli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3D.h"

int	ft_valid_movement(t_program *program, float pa)
{
	int		i;
	float	cosra;
	float	sinra;

	i = 0;
	cosra = (cos(pa) / (TILE_SIZE)) * MOV_SPD;
	sinra = (sin(pa) / (TILE_SIZE)) * MOV_SPD;
	program->player.ray_x = program->player.player_x;
	program->player.ray_y = program->player.player_y;
	while (i < TILE_SIZE + 1)
	{
		program->player.ray_x += cosra;
		program->player.ray_y += sinra;
		if (program->map.mini_map[(int)program->player.ray_y]
			[(int)program->player.ray_x] == '1')
			return (1);
		i++;
	}
	return (0);
}

void	ft_player_up(t_program *program)
{
	program->player.player_x_next = program->player.player_x
		+ (program->player.player_delta_x * MOV_SPD);
	program->player.player_y_next = program->player.player_y
		+ (program->player.player_delta_y * MOV_SPD);
	if (ft_valid_movement(program, program->player.player_angle) == 1)
		return ;
	if (program->player.player_x_next >= 0
		&& program->player.player_x_next < SCREEN_WIDTH
		&& program->player.player_y_next > 0
		&& program->player.player_y_next < SCREEN_HEIGHT)
	{
		program->player.player_x_old = program->player.player_x;
		program->player.player_y_old = program->player.player_y;
		program->player.player_x = program->player.player_x_next;
		program->player.player_y = program->player.player_y_next;
	}
}

void	ft_player_down(t_program *program)
{
	program->player.player_x_next = program->player.player_x
		- (program->player.player_delta_x * MOV_SPD);
	program->player.player_y_next = program->player.player_y
		- (program->player.player_delta_y * MOV_SPD);
	if (ft_valid_movement(program,
			(program->player.player_angle + (RADIAN * 180))) == 1)
		return ;
	if (program->player.player_x_next >= 0
		&& program->player.player_x_next < SCREEN_WIDTH
		&& program->player.player_y_next > 0
		&& program->player.player_y_next < SCREEN_HEIGHT)
	{
		program->player.player_x_old = program->player.player_x;
		program->player.player_y_old = program->player.player_y;
		program->player.player_x = program->player.player_x_next;
		program->player.player_y = program->player.player_y_next;
	}
}

void	ft_player_left(t_program *program)
{
	program->player.player_x_next = program->player.player_x
		+ (program->player.player_delta_y * MOV_SPD);
	program->player.player_y_next = program->player.player_y
		- (program->player.player_delta_x * MOV_SPD);
	if (ft_valid_movement(program,
			(program->player.player_angle - (RADIAN * 90))) == 1)
		return ;
	if (program->player.player_x_next >= 0
		&& program->player.player_x_next < SCREEN_WIDTH
		&& program->player.player_y_next > 0
		&& program->player.player_y_next < SCREEN_HEIGHT)
	{
		program->player.player_x_old = program->player.player_x;
		program->player.player_y_old = program->player.player_y;
		program->player.player_x = program->player.player_x_next;
		program->player.player_y = program->player.player_y_next;
	}
}

void	ft_player_right(t_program *program)
{
	program->player.player_x_next = program->player.player_x
		- (program->player.player_delta_y * MOV_SPD);
	program->player.player_y_next = program->player.player_y
		+ (program->player.player_delta_x * MOV_SPD);
	if (ft_valid_movement(program,
			(program->player.player_angle + (RADIAN * 90))) == 1)
		return ;
	if (program->player.player_x_next >= 0
		&& program->player.player_x_next < SCREEN_WIDTH
		&& program->player.player_y_next > 0
		&& program->player.player_y_next < SCREEN_HEIGHT)
	{
		program->player.player_x_old = program->player.player_x;
		program->player.player_y_old = program->player.player_y;
		program->player.player_x = program->player.player_x_next;
		program->player.player_y = program->player.player_y_next;
	}
}
