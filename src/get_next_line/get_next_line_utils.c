/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 23:46:08 by pli               #+#    #+#             */
/*   Updated: 2022/04/20 15:44:32 by pli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

size_t	ft_strlen_gnl(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr_gnl(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	if (c == '\0')
		return (str);
	while (str[i])
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin_gnl(char *lines, char *buff)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = -1;
	j = 0;
	if (!lines)
	{
		lines = malloc(sizeof(char) * 1);
		lines[0] = '\0';
	}
	if (!lines || !buff)
		return (NULL);
	line = malloc(sizeof(char)
			* (ft_strlen_gnl(lines) + ft_strlen_gnl(buff) + 1));
	if (line == NULL)
		return (NULL);
	while (lines[++i] != '\0')
		line[i] = lines[i];
	while (buff[j] != '\0')
		line[i++] = buff[j++];
	line[ft_strlen_gnl(lines) + ft_strlen_gnl(buff)] = '\0';
	free(lines);
	return (line);
}
