CC	=	gcc
RM	=	rm -f
CFLAGS	=	-Wall -Wextra -Werror -I./includes
NAME	=	libftprintf.a
LIBFT	=	./libft
LIBR	=	ar rcs
SRCS	=	ft_printf.c \
            utils/ft_putuns_fd.c utils/ft_puthex_fd.c \
            src/ft_c_out.c src/ft_s_out.c src/ft_di_out.c src/ft_p_out.c src/ft_u_out.c src/ft_x_out.c src/ft_percent_out.c \

OBJS	=	$(SRCS:.c=.o)

all:
			$(MAKE) -C $(LIBFT)
			$(MAKE) $(NAME)

$(NAME):	$(OBJS) $(LIBFT)/libft.a
			@cp $(LIBFT)/libft.a ./$(NAME)
			@$(LIBR) $(NAME) $(OBJS)
			@echo "Success"

%.o: %.c
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@$(MAKE) -C $(LIBFT)/ clean
			@$(RM)	$(OBJS)
			@echo ".o Deleted"

fclean: 	clean
			@$(MAKE) -C $(LIBFT)/ fclean
			@$(RM)	$(NAME)
			@echo "Deleted"

re:			fclean all

.PHONY: all clean fclean re