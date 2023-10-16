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

t_program	*ft_put_sky(t_program *program, int i, t_wall wall)
{
	while (++(wall.h) < wall.offset)
		program->map.data[i + wall.h * SCREEN_WIDTH]
			= program->map.ceiling_color;
	return (program);
}

t_program	*ft_put_floor(t_program *program, int i, t_wall wall)
{
	while ((wall.y)++ < SCREEN_HEIGHT)
		program->map.data[i + wall.y * SCREEN_WIDTH] = program->map.floor_color;
	return (program);
}

void	ft_put_wall(t_program *program, int i, float wall_height, float ra)
{
	t_wall	wall;

	wall.h = -1;
	wall.y = 0;
	wall.ty_offset = 0;
	wall.ty_step = RES / wall_height;
	program->s = program->player.ray_y - sin(ra);
	program->c = program->player.ray_x - cos(ra);
	if (wall_height > SCREEN_HEIGHT)
	{
		wall.ty_offset = (wall_height - SCREEN_HEIGHT) / 2;
		wall_height = SCREEN_HEIGHT;
	}
	wall.ty = wall.ty_offset * wall.ty_step;
	wall.offset = (SCREEN_HEIGHT - wall_height) / 2;
	program = ft_put_sky(program, i, wall);
	while ((wall.y)++ <= wall_height)
	{
		program->map.data[i + (wall.y + wall.offset) * SCREEN_WIDTH]
			= ft_get_direction(program, ra, wall.ty);
		wall.ty += wall.ty_step;
	}
	wall.y += wall.offset;
	program = ft_put_floor(program, i, wall);
}

int	ft_cast_ray(t_program *program, float ra)
{
	float	distance;
	float	cosra;
	float	sinra;

	distance = 0;
	cosra = cos(ra) / (TILE_SIZE);
	sinra = sin(ra) / (TILE_SIZE);
	program->player.ray_x = program->player.player_x;
	program->player.ray_y = program->player.player_y;
	while (program->map.mini_map[(int)
			program->player.ray_y][(int)program->player.ray_x] != '1'
			&& program->map.mini_map[(int)program->player.ray_y]
			[(int)program->player.ray_x] != ' '
			&& program->map.mini_map[(int)program->player.ray_y]
			[(int)program->player.ray_x] != '\0'
			&& program->map.mini_map[(int)program->player.ray_y]
			[(int)program->player.ray_x] != '\n')
	{
		program->player.ray_x += cosra;
		program->player.ray_y += sinra;
		distance++;
	}
	return (distance);
}

void	ft_draw_ray(t_program *program, int i, float distance)
{
	float	ra;
	float	wall_height;
	float	ca;

	program->ray_step = RADIAN * FOV / SCREEN_WIDTH;
	ra = program->player.player_angle - ((FOV / 2) * RADIAN);
	if (ra < 0)
		ra += PI * 2;
	while (i < SCREEN_WIDTH)
	{
		distance = ft_cast_ray(program, ra);
		ca = program->player.player_angle - ra;
		if (ca < 0)
			ca += 2 * PI;
		if (ca > 2 * PI)
			ca -= 2 * PI;
		distance *= cos(ca);
		wall_height = ((TILE_SIZE) * SCREEN_HEIGHT / distance);
		ft_put_wall(program, i, wall_height, ra);
		ra += program->ray_step;
		if (ra > 2 * PI)
			ra -= 2 * PI;
		i++;
	}
}
