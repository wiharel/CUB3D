/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:23:22 by pli               #+#    #+#             */
/*   Updated: 2023/04/04 14:23:25 by pli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3D.h"

int	ft_num_lines(int fd)
{
	int		size;
	char	*line;

	size = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		size++;
		free(line);
		line = get_next_line(fd);
	}
	return (size);
}

char	**ft_dup_map(int fd, char *map, char **map_tmp, int i)
{
	char	*line;

	map_tmp = malloc(sizeof(char *) * (ft_num_lines(fd) + 1));
	if (!map_tmp)
		ft_error();
	close(fd);
	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_error();
	line = get_next_line(fd);
	while (line != NULL)
	{
		map_tmp[++i] = line;
		line = get_next_line(fd);
	}
	map_tmp[i + 1] = 0;
	close(fd);
	return (map_tmp);
}

t_map	ft_check_map(t_map m, unsigned int i, unsigned int j)
{
	m.check_no = 0;
	m.check_so = 0;
	m.check_we = 0;
	m.check_ea = 0;
	m.check_f = 0;
	m.check_c = 0;
	m.check_map = 0;
	m.mini_map = 0;
	m.path_no = NULL;
	m.path_so = NULL;
	m.path_we = NULL;
	m.path_ea = NULL;
	i = ft_skip_empty_line(m, i, 0);
	j = ft_skip_empty_space(m, i, 0);
	return (ft_check_identifier(m, i, j));
}

void	ft_open_map(char *map)
{
	int			fd;
	t_program	program;
	t_map		m;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_error();
	m.map = ft_dup_map(fd, map, 0, -1);
	program.map = ft_check_map(m, -1, -1);
	ft_init_mlx(program);
}

void	ft_check_mapname(char *map)
{
	int	len;

	len = ft_strlen(map);
	if (map[len - 1] == 'b' && map[len - 2] == 'u'
		&& map[len - 3] == 'c' && map[len - 4] == '.')
		ft_open_map(map);
	else
	{
		printf("Error\n" YYL "[Wrong map file name]\n" RET);
		exit(0);
	}
}
