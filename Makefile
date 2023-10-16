# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: parallels <parallels@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 21:13:17 by pli               #+#    #+#              #
#    Updated: 2023/03/28 15:44:56 by parallels        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#ls -l | awk '{print $9}'

SRCS =	src/libft/ft_atoi.c \
	src/libft/ft_bzero.c \
	src/libft/ft_calloc.c \
	src/libft/ft_isalnum.c \
	src/libft/ft_isalpha.c \
	src/libft/ft_isascii.c \
	src/libft/ft_isdigit.c \
	src/libft/ft_isprint.c \
	src/libft/ft_itoa.c \
	src/libft/ft_lstadd_back.c \
	src/libft/ft_lstadd_front.c \
	src/libft/ft_lstclear.c \
	src/libft/ft_lstdelone.c \
	src/libft/ft_lstiter.c \
	src/libft/ft_lstlast.c \
	src/libft/ft_lstmap.c \
	src/libft/ft_lstnew.c \
	src/libft/ft_lstsize.c \
	src/libft/ft_memchr.c \
	src/libft/ft_memcmp.c \
	src/libft/ft_memcpy.c \
	src/libft/ft_memmove.c \
	src/libft/ft_memset.c \
	src/libft/ft_putchar_fd.c \
	src/libft/ft_putendl_fd.c \
	src/libft/ft_putnbr_fd.c \
	src/libft/ft_putstr_fd.c \
	src/libft/ft_split.c \
	src/libft/ft_strchr.c \
	src/libft/ft_strdup.c \
	src/libft/ft_striteri.c \
	src/libft/ft_strjoin.c \
	src/libft/ft_strlcat.c \
	src/libft/ft_strlcpy.c \
	src/libft/ft_strlen.c \
	src/libft/ft_strmapi.c \
	src/libft/ft_strncmp.c \
	src/libft/ft_strnstr.c \
	src/libft/ft_strrchr.c \
	src/libft/ft_strtrim.c \
	src/libft/ft_substr.c \
	src/libft/ft_tolower.c \
	src/libft/ft_toupper.c \
	src/ft_printf/ft_printf.c \
	src/ft_printf/ft_print_hex.c \
	src/ft_printf/ft_print_nbr.c \
	src/ft_printf/ft_print_ptr.c \
	src/ft_printf/ft_print_str.c \
	src/ft_printf/ft_print_unsigned.c \
	src/get_next_line/get_next_line.c \
	src/get_next_line/get_next_line_utils.c \
	src/Cub3D/main.c \
	src/Cub3D/ft_map_init.c \
	src/Cub3D/ft_img_init.c \
	src/Cub3D/ft_check_identifier.c \
	src/Cub3D/ft_check_id_color.c \
	src/Cub3D/ft_check_id_direction.c \
	src/Cub3D/ft_get_texture.c \
	src/Cub3D/ft_get_color.c \
	src/Cub3D/ft_get_color_f.c \
	src/Cub3D/ft_get_color_c.c \
	src/Cub3D/ft_get_map.c \
	src/Cub3D/ft_check_map.c \
	src/Cub3D/ft_check_map_hole.c \
	src/Cub3D/ft_player_pos.c \
	src/Cub3D/ft_mlx_init.c \
	src/Cub3D/ft_mlx.c \
	src/Cub3D/ft_player_move.c \
	src/Cub3D/ft_player_look.c \
	src/Cub3D/ft_raycasting.c \
	src/Cub3D/ft_raycasting2.c \
	src/Cub3D/ft_exit.c \
	src/Cub3D/ft_free.c \

INC =	includes/libft.h \
	includes/ft_printf.h \
	includes/get_next_line.h \
	includes/Cub3D.h \
	mlx/mlx.h \

OBJS = $(SRCS:.c=.o)

CC = gcc
AR = ar rcs
RM = rm -rf
CFLAGS = -Wall -Werror -Wextra
LFLAGS = -lX11 -lXext -lm

NAME = ./cub3D

NAME_MLX = ./mlx/libmlx_Linux.a

.c:.o
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(SRCS) $(NAME_MLX) $(LFLAGS) -o $(NAME) 
	@printf "\e[1;32m >>>>>> Compiled successfully!😛\n\033[0m"

clean:
	@$(RM) $(OBJS)
	@clear
	@printf "\e[1;33m >>>>>> all .o files deleted!!😼\n\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@printf "\e[1;35m All files deleted!!🐶\n\033[0m"

re: fclean all $(NAME)

.PHONY : all clean fclean re
