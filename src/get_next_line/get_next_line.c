/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:35:21 by pli               #+#    #+#             */
/*   Updated: 2022/04/25 16:56:12 by pli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"
#include <time.h>
#include <stdio.h>

char	*ft_get_lines(char *lines)
{
	int		pos_lines;
	int		pos_line;
	char	*line;

	pos_lines = 0;
	pos_line = 0;
	while (lines[pos_lines] && lines[pos_lines] != '\n')
		pos_lines++;
	if (!lines[pos_lines])
	{
		free(lines);
		return (NULL);
	}
	line = malloc(sizeof(char) * ft_strlen_gnl(lines) - pos_lines + 1);
	if (!line)
		return (NULL);
	pos_lines++;
	while (lines[pos_lines])
		line[pos_line++] = lines[pos_lines++];
	line[pos_line] = '\0';
	free(lines);
	return (line);
}

char	*ft_get_line(char *lines)
{
	int		i;
	char	*line;

	i = 0;
	if (!lines[i])
		return (NULL);
	while (lines[i] && lines[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (lines[i] && lines[i] != '\n')
	{
		line[i] = lines[i];
		i++;
	}
	if (lines[i] == '\n')
	{
		line[i] = lines[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_read_save(int fd, char *lines)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr_gnl(lines, '\n') && rd_bytes != 0)
	{	
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		lines = ft_strjoin_gnl(lines, buff);
	}
	free(buff);
	return (lines);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*lines;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	lines = ft_read_save(fd, lines);
	if (!lines)
		return (NULL);
	line = ft_get_line(lines);
	lines = ft_get_lines(lines);
	return (line);
}

/**
int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    char *line;
    while((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
		//sleep(1);
		usleep(1000);
        free(line);
    }
	return (0);
}
**/
