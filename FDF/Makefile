# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/07 18:51:42 by yskrypny          #+#    #+#              #
#    Updated: 2017/05/07 20:51:17 by yskrypny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

LDFLAG = rcs
LIBFT = libft/libft.a
LIBS = -lmlx -framework OpenGL -framework AppKit
CFLAGS = -Wall -Werror -Wextra

SOURCE = additional_stuff.c \
	 compass.c \
	 config.c \
	 config_parse.c \
	 controls.c \
	 controls_keycode_functions.c \
	 images_and_xmp.c \
	 initialize.c \
	 intro_and_help.c \
	 main.c \
	 map_parser.c \
	 map_parser_check_read.c \
	 map_recalculation.c \
	 point_check_vision.c \
	 point_draw.c \
	 point_draw_line.c \
	 point_rotation.c \
	 point_scale.c \
	 point_shift.c \
	 point_transformation.c

OBJECT = $(SOURCE:.c=.o)

.c.o:
	$(CC) -c -o $@ $< $(CFLAGS)

$(NAME): $(OBJECT)
	make -C libft/
	$(CC) -o $@ $^ $(CFLAGS) $(LIBFT) $(LIBS)

all: $(SOURCE) $(NAME)

clean:
	make clean -C libft/
	rm -rf $(OBJECT)

fclean: clean
	make fclean -C libft/
	rm -rf $(NAME)

re: clean all
