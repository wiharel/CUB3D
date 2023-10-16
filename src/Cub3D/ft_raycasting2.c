/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiharel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:25:27 by wiharel           #+#    #+#             */
/*   Updated: 2023/04/04 15:35:36 by pli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3D.h"

int	get_x_offset(float ray)
{
	int		counter;
	float	decimal;
	float	step;

	decimal = ray - (int)ray;
	counter = 63;
	step = STEP;
	while (step < decimal)
	{
		step += STEP;
		counter--;
	}
	return (counter);
}

int	get_x_offset2(float ray)
{
	int		counter;
	float	decimal;
	float	step;

	decimal = ray - (int)ray;
	counter = 0;
	step = STEP;
	while (step < decimal)
	{
		step += STEP;
		counter++;
	}
	return (counter);
}

int	ft_get_direction2(t_program *program, float ra, float ty)
{
	if (program->map.mini_map[(int)(program->player.ray_y)]
		[(int)((program->player.ray_x + STEP))] != '1'
		&& (int)((program->player.ray_x + STEP))
		== (int)((program->c)))
		return (program->img_ptr->we_data[(int)
				(get_x_offset(program->player.ray_y)) + (int)ty * RES]);
	else if (program->map.mini_map[(int)(program->player.ray_y)]
		[(int)((program->player.ray_x - STEP))] != '1'
		&& (int)((program->player.ray_x - STEP))
		== (int)((program->c)))
		return (program->img_ptr->ea_data
			[get_x_offset2(program->player.ray_y) + (int)ty * RES]);
	if ((ra <= PI / 4 && ra >= 0) || (ra >= 7 * PI / 4 && ra <= 2 * PI))
		return (program->img_ptr->ea_data
			[get_x_offset2(program->player.ray_y) + (int)ty * RES]);
	else if (ra >= 5 * PI / 4 && ra <= 7 * PI / 4)
		return (program->img_ptr->no_data
			[get_x_offset2(program->player.ray_x) + (int)ty * RES]);
	else if (ra >= 3 * PI / 4 && ra <= 5 * PI / 4)
		return (program->img_ptr->we_data[(int)
				(get_x_offset(program->player.ray_y)) + (int)ty * RES]);
	else
		return (program->img_ptr->so_data[(int)
				(get_x_offset(program->player.ray_x)) + (int)ty * RES]);
}

int	ft_get_direction(t_program *program, float ra, float ty)
{
	if (program->map.mini_map[(int)((program->player.ray_y - STEP))]
		[(int)(program->player.ray_x)] != '1'
		&& (int)((program->player.ray_y - STEP))
		== (int)((program->s)))
		return (program->img_ptr->so_data[(int)
				((get_x_offset(program->player.ray_x) + (int)ty * RES))]);
	else if (program->map.mini_map[(int)((program->player.ray_y + STEP))]
		[(int)(program->player.ray_x)] != '1'
		&& (int)((program->player.ray_y + STEP))
		== (int)(program->s))
		return (program->img_ptr->no_data
			[get_x_offset2(program->player.ray_x) + (int)ty * RES]);
	return (ft_get_direction2(program, ra, ty));
}
