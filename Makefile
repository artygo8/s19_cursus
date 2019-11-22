SRCSC		= ft_printf.c\
				ft_atoi_printf.c\
				ft_isconvert.c\
				ft_strdup_char.c\
				ft_strjoin_char.c

SBONUS		= ft_printf_bonus.c

SRCSH		= ft_printf.h

OBJS		= $(SRCSC:%.c=%.o)

OBONUS		= $(SBONUS:%.c=%.o)

LIBFT		= libft/libft.a

NAME		= libftprintf.a

CC			= gcc

AR			= ar rc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

$(NAME):	${OBJS} libft
			${AR} ${NAME} ${OBJS} ${SRCSH} ${LIBFT}

libft:
			make -C libft all

all:		${NAME}

clean:
			${RM} ${OBJS} ${OBONUS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

bonus:		all ${OBONUS}
			${AR} ${NAME} ${OBONUS}

test:		all
			${CC} ${NAME} ${LIBFT} ${SRCSC} main.c libft/*.c

.PHONY:		all clean fclean re
