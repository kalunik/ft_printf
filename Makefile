CC	=	gcc
RM	=	rm -f
CFLAGS	=	-c -Wall -Wextra -Werror -I ./includes
NAME	=	libftprintf.a
LIBFT	=	./libft
LIBR	=	ar rcs
SRCS	=	ft_printf.c \
            utils/ft_putuns_fd.c utils/ft_puthex_fd.c utils/ft_puthex_up_fd.c \
            src/ft_c_out.c src/ft_s_out.c src/ft_di_out.c src/ft_p_out.c src/ft_u_out.c src/ft_x_out.c src/ft_x_up_out.c src/ft_percent_out.c \

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