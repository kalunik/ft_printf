#include "includes/ft_printf.h"

struct	s_parser{
	char	flags;  //
	int		width;
	int		precision;
	char	type;
};

//TODO
//		conversions: 'c' 's' 'p' 'd' 'i' 'u' 'x' 'X' '%'
//		flags: '-' '0' '.' '*'

void	var_conf()
{

}

char	ft_reader(char *conv, va_list arg_ptr)
{
	struct s_parser	fwpt;
	char			*types = "cspdiuxX%"; //FIXME можно назначать строку при инициализации?

	conv++;
	while (types)
	{
		printf("-%c\n", *types);
		if (*conv == *types)
		{
			fwpt.type = ft_strdup(types);
			return (fwpt.type);
		}
		types++;
	}
		//printf("'%s'", &fwpt.type);
}

int	ft_printf(const char *arg, ...)
{
	va_list	arg_ptr;
	char	*str;
	char	*conv;
	char	*text; // может и не надо

	va_start(arg_ptr, arg);
	conv = ft_strchr(arg, '%');
	while (*arg != '%')
		ft_putchar_fd(*arg++, 1);
	if (conv)
	{
		printf("'%c'", ft_reader(conv, arg_ptr));
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
