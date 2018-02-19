# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scorbion <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 13:13:07 by scorbion          #+#    #+#              #
#    Updated: 2017/06/21 12:16:24 by cesnault         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
LIB = libfdf.a
OBJS = main.o \
	   correct.o \
		red_cross.o\
		dda_verti.o\
		gestion_dda.o\
		key.o\
		dda_hori.o\
		draw.o\
		init.o\
		raycasting.o\



INCLUDES =  -I minilibx_macos/ minilibx_macos/libmlx.a
FLAGS = -Wall -Werror -Wextra 
FRM = -framework openGL -framework Appkit
.PHONY:all clean
all : $(NAME)

$(NAME) : $(OBJS) 
	make -C minilibx_macos
	ar rc $(LIB) $(OBJS)
	gcc $(FLAGS) $(INCLUDES) $(LIB) -o $(NAME) $(FRM)
%.o: %.c
	gcc $(FLAGS) -c $^

clean :
	rm -f $(OBJS)
	make clean -C minilibx_macos

fclean : clean
	rm -f $(NAME)
	rm -f $(LIB)

re : fclean all

