# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yachen <yachen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/23 10:21:12 by yachen            #+#    #+#              #
#    Updated: 2023/05/23 19:45:38 by yachen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFTNAME = libft.a 

LIBFTDIR = ./libft

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = ft_printf.c ft_printf_str.c ft_printf_nbr.c ft_printf_hexa.c ft_printf_char.c ft_printf_unsi.c ft_printf_ptr.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

makelibft: 
	@make -C $(LIBFTDIR)
	@cp $(LIBFTDIR)/$(LIBFTNAME) .
	@mv $(LIBFTNAME) $(NAME)

$(NAME): makelibft $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	cd $(LIBFTDIR) && make clean

fclean: clean
	$(RM) $(NAME)
	cd $(LIBFTDIR) && make fclean

re: fclean all

.PHONY: clean fclean all re
