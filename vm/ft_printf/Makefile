# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/25 17:31:13 by cdubuque          #+#    #+#              #
#    Updated: 2019/09/01 12:14:09 by cdubuque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c \
	  ft_int.c \
	  ft_string_and_char.c \
		unsigned.c \
		ft_int_parser.c \
		ft_uns_parser.c \
		ft_point_and_friends.c \
		ft_printf_and_all_all_all.c \
		ft_do_w_float.c \
		ft_do_w_ldouble.c \
		ft_pars_float.c \
		ft_pars_float2.c \
		ft_tools_float.c

SRCLIB = ./libft/*.o

FLAGS = -Wall -Wextra -Werror

HEADER = ./

OBJC = $(SRC:.c=.o)
LIBFT = ./libft/
LIB = ./libft/libft.a

LIBOBJS = $(wildcard ./libft/*.o)

$(NAME): $(OBJC)
	@make -C $(LIBFT)
	@ar -rc $(NAME) $(OBJC) $(SRCLIB)
	@ranlib $(NAME)

#cp $(LIB) ./$(NAME)

all: $(NAME)

$(OBJC): %.o : %.c
	@gcc -c  $(FLAGS) $<

clean:
	@/bin/rm -f $(OBJC)
	@make -C $(LIBFT) clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all

debug:
	echo $(SRC)
	echo
	echo $(OBJC)
	echo
	echo $(LIBOBJS)
