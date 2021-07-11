CC	=	gcc
RM	=	rm -f
CFLAGS	=	-c -Wall -Wextra -Werror -I ./includes
NAME	=	libftprintf.a
LIBFT	=	./libft
LIBR	=	ar rcs
SRCS	=	ft_printf.c \
            ft_puthex_fd.c \
            ft_puthex_up_fd.c \

OBJS	=	$(SRCS:.c=.o)
$(NAME):	$(OBJS) $(LIBFT)/libft.a
			cp $(LIBFT)/libft.a ./$(NAME)
			$(CC) $(CFLAGS) $(SRCS) && $(LIBR) $(NAME) $(OBJS)

all:
			$(MAKE) -C $(LIBFT)
			$(MAKE) $(NAME)

clean:
			$(MAKE) -C $(LIBFT)/ clean
			$(RM)	$(OBJS)

fclean: 	clean
			$(MAKE) -C $(LIBFT)/ fclean
			$(RM)	$(NAME)

re:			fclean all

.PHONY: all clean fclean re