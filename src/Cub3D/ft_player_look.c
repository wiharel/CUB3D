/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_look.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:25:54 by pli               #+#    #+#             */
/*   Updated: 2023/04/04 14:25:57 by pli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3D.h"

void	ft_look_left(t_program *program)
{
	program->player.player_y_old = program->player.player_y;
	program->player.player_x_old = program->player.player_x;
	program->player.player_angle -= 0.1;
	if (program->player.player_angle < 0)
		program->player.player_angle += 2 * PI;
	program->player.player_delta_x = cos(program->player.player_angle);
	program->player.player_delta_y = sin(program->player.player_angle);
}

void	ft_look_right(t_program *program)
{
	program->player.player_y_old = program->player.player_y;
	program->player.player_x_old = program->player.player_x;
	program->player.player_angle += 0.1;
	if (program->player.player_angle > 2 * PI)
		program->player.player_angle -= 2 * PI;
	program->player.player_delta_x = cos(program->player.player_angle);
	program->player.player_delta_y = sin(program->player.player_angle);
}
