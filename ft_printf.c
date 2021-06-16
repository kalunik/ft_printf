#include "includes/ft_printf.h"



//TODO
//		conversions: 'c' 's' 'p' 'd' 'i' 'u' 'x' 'X' '%'
//		flags: '-' '0' '.' '*'

void	ft_var_output(conf_parser var, va_list arg_ptr)
{
	char c;
	char *s;
	char *p;

	if (var.type == 'c')
	{
		c = va_arg(arg_ptr, int);
		ft_putchar_fd(c, 1);
	}
	else if (var.type == 's')
	{
		s = va_arg(arg_ptr, char *);
		ft_putstr_fd(s, 1);
	}
	else if (var.type == 'p')
	{
		p = va_arg(arg_ptr, char *);
		ft_putstr_fd(p, 1);
	}
}

/*
conf_parser	ft_flag_conf(char *conv, conf_parser var)
{

}
*/

conf_parser	ft_type_conf(char *conv, conf_parser var)
{
	char	*types;
	char	*temp;

	conv++;
	types = ft_strdup("cspdiuxX%");
	temp = types;
	while (*types)
	{
		if (*conv == *types)
			var.type = *conv;
		types++;
	}
	free(temp);
	return (var);
}

void	ft_var_conf(char *conv, va_list arg_ptr)
{
	conf_parser	var;

	var = ft_type_conf(conv, var);
	//printf("\ntype :: '%s'", &var.type);
	ft_var_output(var, arg_ptr);
}

int		ft_printf(const char *arg, ...)
{
	va_list	arg_ptr;
	char	*str;
	char	*conv;
	char	*text; // может и не надо

	va_start(arg_ptr, arg);
	conv = ft_strchr(arg, '%');
	while (*arg != '%')
		ft_putchar_fd(*arg++, 1);
	ft_var_conf(conv, arg_ptr);
	va_end (arg_ptr);
	return (ft_strlen(arg));
}

int main(void)
{
	char p = 'r';

	ft_printf("Sum of series is %p%", &p);
	printf("\n%p", &p);
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
