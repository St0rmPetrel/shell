RED		=	\033[0;31m
NC		=	\033[0m

CC		=	gcc

NAME	=	libft.a

CFLAGS	=	-Wall -Wextra -Werror

SRCS	:=	$(wildcard	ft_*.c)

HDRS	=	libft.h

OBJS	=	$(SRCS:.c=.o)

RM		=	rm -f

all:	$(NAME)

$(NAME):	$(OBJS) $(HDRS)
		@ar	rcs	$(NAME)	$(OBJS)

.c.o:
		@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
		@echo "$(RED)Delete libft objs$(NC)"
		@$(RM) $(OBJS)

fclean:	clean
		@$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
