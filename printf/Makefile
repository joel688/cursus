# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joakoeni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 17:20:24 by joakoeni          #+#    #+#              #
#    Updated: 2022/11/30 22:43:45 by joakoeni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
RM = rm -f
AR = ar rc
RN = ranlib

CFLAGS = -Wall -Werror -Wextra

SRC= ft_printf.c ft_c.c ft_countdigit.c ft_d.c ft_itoa.c ft_itoa_unsigned.c ft_p.c ft_printf.c ft_s.c ft_u.c ft_x.c ft_x_maj.c ft_write.c

OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME): ${OBJS}
			${AR} ${NAME} ${OBJS}
			${RN} ${NAME}

all:		$(NAME)

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} $(NAME)

re:			fclean all

.PHONY:		all bonus clean fclean re
