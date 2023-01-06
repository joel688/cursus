NAME 			= push_swap.a

CC 			= gcc
RM			= rm -f
AR			= ar rc
RN			= ranlib


CFLAGS = -Wall -Werror -Wextra

SRC = is_error.c do_nothing_one_or_no_arg.c

OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME):	${OBJS}
			${AR} ${NAME} ${OBJS}
			${RN} ${NAME}

all:		$(NAME)

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} $(NAME)

re:			fclean all
