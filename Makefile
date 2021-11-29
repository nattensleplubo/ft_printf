NAME		=	libftprintf.a

SRCS		=	len_nums.c main.c parse_nums.c print_nums.c print_strs.c

OBJS		=	$(SRCS:.c=.o)

CC			=	gcc
RM			=	rm -rf
CFLAGS		=	-Wall -Wextra -Werror -I.

all:			$(NAME)

$(NAME):	$(OBJS) $(HEAD)
			ar rcs $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS) $(BONUS_OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)