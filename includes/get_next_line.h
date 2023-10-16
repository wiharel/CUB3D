/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:14:24 by pli               #+#    #+#             */
/*   Updated: 2022/03/20 20:33:59 by pli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 42
# include <stdlib.h>
# include <unistd.h>
# include <sys/syscall.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_read_save(int fd, char *lines);
char	*ft_get_line(char *lines);
char	*ft_get_lines(char *lines);
char	*ft_strjoin_gnl(char *lines, char *buff);
char	*ft_strchr_gnl(char *str, int c);
size_t	ft_strlen_gnl(char *str);

#endif
