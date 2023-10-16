/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pli <pli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:30:38 by pli               #+#    #+#             */
/*   Updated: 2023/04/03 14:39:55 by pli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define KEY_LEFT   65361
# define KEY_RIGHT  65363
# define KEY_ESC    65307
# define KEY_W  119
# define KEY_S  115
# define KEY_A  97
# define KEY_D  100
# define PI 3.1415926535
# define FOV   60
# define RADIAN 0.0174533
# define SCREEN_WIDTH   1040
# define SCREEN_HEIGHT  540
# define TILE_SIZE  64
# define MOV_SPD 0.15
# define RES 64
# define STEP 0.015625

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "../mlx/mlx.h"

# include <unistd.h>
# include <math.h>
# include <X11/Xlib.h>
# include <X11/Xutil.h> 

typedef struct s_player
{
	float	player_x;
	float	player_y;
	float	player_x_old;
	float	player_y_old;
	float	player_x_next;
	float	player_y_next;
	float	ray_x;
	float	ray_y;
	float	dis_to_wall;
	float	player_angle;
	float	player_speed;
	float	player_delta_x;
	float	player_delta_y;
	char	**map;
}		t_player;

typedef struct s_wall
{
	int		h;
	int		y;
	int		offset;
	float	ty_offset;
	float	ty_step;
	float	ty;
}		t_wall;

typedef struct s_data
{
	int		*no_data;
	int		*so_data;
	int		*we_data;
	int		*ea_data;
	void	*img_no;
	void	*img_so;
	void	*img_we;
	void	*img_ea;
}		t_data;

typedef struct s_map
{
	long int	floor_color;
	long int	ceiling_color;
	int			check_no;
	int			check_so;
	int			check_we;
	int			check_ea;
	int			check_f;
	int			check_c;
	int			f[3];
	int			c[3];
	int			player_count;
	int			check;
	int			*data;
	float		player_x;
	float		player_y;
	void		*mlx_ptr;
	void		*mlx_win;
	void		*image;
	char		*path_no;
	char		*path_so;
	char		*path_we;
	char		*path_ea;
	char		**map;
	char		**mini_map;
	char		**check_map;

}		t_map;

typedef struct s_program
{
	t_player	player;
	int			img_width;
	int			img_height;
	float		s;
	float		c;
	float		ray_step;
	t_map		map;
	void		*mlx_ptr;
	void		*mlx_win;
	char		*path_player;
	char		*path_floor;
	t_data		*img_ptr;
}		t_program;

t_program	*ft_put_sky(t_program *program, int i, t_wall wall);
t_program	*ft_put_floor(t_program *program, int i, t_wall wall);
int			ft_num_lines(int fd);
int			ft_keys(int keycode, t_program *program);
int			ft_mouse_exit(t_program *program);
int			ft_key_exit(t_program *program);
int			ft_free_holes(t_map m, int i);
int			ft_free_env(t_program program);
int			ft_free_identifier(t_map m, char *msg);
int			ft_free_map_error(t_map m, char *msg);
int			ft_init_program(t_program program);
int			ft_init_player(t_program program);
int			ft_get_player_x(t_program program, unsigned int i, unsigned int j);
int			ft_get_player_y(t_program program, unsigned int i, unsigned int j);
int			ft_mini_player_x(t_map m, unsigned int i, unsigned int j);
int			ft_mini_player_y(t_map m, unsigned int i, unsigned int j);
int			ft_num_lines_mini(char **map, int size);
int			ft_check_mini_map(t_map m);
int			ft_check_around(t_map m, unsigned int i, unsigned int j);
int			ft_check_left(t_map m, unsigned int i, unsigned int j);
int			ft_check_right(t_map m, unsigned int i, unsigned int j);
int			ft_check_up(t_map m, unsigned int i, unsigned int j);
int			ft_check_down(t_map m, unsigned int i, unsigned int j);
int			ft_value_len(t_map m, unsigned int i, unsigned int jo);
int			ft_get_val(t_map m, char *value, char c);
int			ft_skip_empty_line(t_map m, unsigned int i, unsigned int j);
int			ft_skip_empty_space(t_map m, unsigned int i, unsigned int j);
int			ft_cast_ray(t_program *program, float ra);
int			ft_get_direction(t_program *program, float ra, float ty);
int			ft_get_direction2(t_program *program, float ra, float ty);
int			get_x_offset(float ray);
int			get_x_offset2(float ray);
void		ft_error(void);
void		ft_wrong_arg(void);
void		ft_free_exit(t_program program, char *msg, int is);
void		ft_free_path(t_program program);
void		ft_map_error(char *msg, unsigned int i, unsigned int j, char c);
void		ft_free_color(t_map m, char *value, char c, char *msg);
void		ft_check_pos_val(t_map m, int pos_val, char c);
void		ft_player_error(char *msg, t_map m);
void		ft_check_mapname(char *map);
void		ft_open_map(char *map);
void		ft_check_wall_hole1(t_map m, unsigned int i, unsigned int j);
void		ft_check_wall_hole2(t_map m, unsigned int i, unsigned int j);
void		ft_init_mlx(t_program program);
void		ft_img_init(t_program program);
void		ft_mlx(t_program program);
void		ft_player_movement(int keycode, t_program *program);
void		ft_player_up(t_program *program);
void		ft_player_down(t_program *program);
void		ft_player_left(t_program *program);
void		ft_player_right(t_program *program);
void		ft_look_left(t_program *program);
void		ft_look_right(t_program *program);
void		ft_draw_ray(t_program *program, int i, float distance);
void		ft_put_wall(t_program *program, int i, float wall_height, float ra);

t_map		ft_check_map(t_map m, unsigned int i, unsigned int j);
t_map		ft_check_identifier(t_map m, unsigned int i, unsigned int j);
t_map		ft_check_directions_colors(t_map m, unsigned int i, unsigned int j);
t_map		ft_check_xpm(t_map m, unsigned int i,
				unsigned int pos, unsigned int j);
t_map		ft_check_no(t_map m, unsigned int i, unsigned int j);
t_map		ft_check_so(t_map m, unsigned int i, unsigned int j);
t_map		ft_check_we(t_map m, unsigned int i, unsigned int j);
t_map		ft_check_ea(t_map m, unsigned int i, unsigned int j);
t_map		ft_check_f(t_map m, unsigned int i, unsigned int j);
t_map		ft_check_c(t_map m, unsigned int i, unsigned int j);
t_map		ft_get_texture_no(t_map m, unsigned int i, unsigned int j);
t_map		ft_get_texture_so(t_map m, unsigned int i, unsigned int j);
t_map		ft_get_texture_we(t_map m, unsigned int i, unsigned int j);
t_map		ft_get_texture_ea(t_map m, unsigned int i, unsigned int j);
t_map		ft_get_color_f(t_map m, unsigned int i, unsigned int j, int jo);
t_map		ft_get_color_f2(t_map m, unsigned int i, int jo, int pos_val);
t_map		ft_get_color_c(t_map m, unsigned int i, unsigned int j, int jo);
t_map		ft_get_map(t_map m, unsigned int i, unsigned int j, int check);
t_map		ft_dup_mini_map(t_map m, unsigned int i, int j, int k);
char		**ft_dup_map(int fd, char *map, char **map_tmp, int i);

#endif
