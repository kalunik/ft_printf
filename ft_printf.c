#include "includes/ft_printf.h"

struct	s_parser{
	char	flags;
	int		width;
	int		precision;
	char	type;
};

/*
void	ft_parser(char *conv, va_list arg_ptr);
{
	if ()
}
*/

int	ft_printf(char *arg, ...)
{
	va_list arg_ptr;
	char *str;
	char *conv;
	char *text; // может и не надо

	va_start(arg_ptr, arg);
	conv = ft_strchr(arg, '%');
	while (*arg != '%')
		ft_putchar_fd(*arg++, 1);
	if (conv)
	{
		ft_parser(conv, arg_ptr);
		printf("'%s'", conv);
	}

	va_end (arg_ptr);
	return (ft_strlen(arg));
}

int main(void)
{
	ft_printf("Sum of series is %d");
	return 0;

}


/*
#include <stdio.h>

# define FLG_NONE	0b00000000
# define FLG_ONE	0b00000001
# define FLG_TWO	0b00000010
# define FLG_THREE	0b00000100
# define FLG_FOUR	0b00001000

int main()
{
	unsigned char	flags;

	flags = FLG_NONE;
	if (flags & FLG_ONE)
		printf("[-] FLG_ONE exist\n");
	else
		printf("[+] FLG_ONE not exist\n");

	flags = flags | FLG_ONE;
	if (flags & FLG_ONE)
		printf("[+] FLG_ONE exist\n");
	else
		printf("[-] FLG_ONE not exist\n");

	flags = flags | FLG_TWO;
	if ((flags & FLG_ONE) && (flags & FLG_TWO))
		printf("[+] FLG_ONE and FLG_TWO exist\n");
	else
		printf("[-] FLG_ONE or FLG_TWO not exist\n");

	flags = flags & (~FLG_TWO);
	if ((flags & FLG_ONE) && (flags & FLG_TWO))
		printf("[-] FLG_ONE and FLG_TWO exist\n");
	else
		printf("[+] FLG_ONE or FLG_TWO not exist\n");

	return (0);
}*/
