#include "includes/ft_printf.h"

//TODO
//		conversions: 'c' 's' 'p' 'd' 'i' 'u' 'x' 'X' '%'
//		flags: '-' '0' '.' '*'

void	ft_var_output(t_conf_parser var, va_list arg_ptr)
{
	char			c;
	char			*s;
	unsigned long	p;
	long long		d;

	if (var.type == 'c')
		ft_putchar_fd(va_arg(arg_ptr, int), 1);
	else if (var.type == 's')
		ft_putstr_fd(va_arg(arg_ptr, char *), 1);
	else if (var.type == 'p')
	{
		ft_putstr_fd("0x", 1);
		ft_puthex_fd(va_arg(arg_ptr, unsigned long), 1);
	}
	else if (var.type == 'd' || var.type == 'i')
		ft_putnbr_fd(va_arg(arg_ptr, int), 1);
	else if (var.type == 'u')
		ft_putnbr_fd(va_arg(arg_ptr, unsigned int), 1);
	else if (var.type == 'x')
		ft_puthex_fd(va_arg(arg_ptr, unsigned int), 1);
	else if (var.type == 'X')
		ft_puthex_up_fd(va_arg(arg_ptr, unsigned int), 1);
	else if (var.type == '%')
		ft_putstr_fd("%", 1);
}

t_conf_parser	ft_flag_conf(char *conv, t_conf_parser var)
{
	unsigned char	flags;
	//char	*flag_set;


	//flag_set = ft_strdup("-0.*");
	flags = FLG_NONE;
	while (*conv != '.' )
	{
		while (*conv != '.' )
		{
			if (*conv == '-')
				flags |= FLG_FOUR;
		}
	}
	printf("%c", flags);
	return (var);
}

t_conf_parser	ft_type_conf(char *conv, t_conf_parser var)
{
	char	*type_set;
	char	*temp;

	conv++;
	type_set = ft_strdup("cspdiuxX%");
	temp = type_set;
	while (*conv)
	{
		while (*type_set)
		{
			if (*conv == *type_set)
				var.type = *conv;
			type_set++;
		}
		conv++;
	}
	free(temp);
	return (var);
}

int	ft_var_conf(char *conv, va_list arg_ptr)
{
	t_conf_parser	var;

	var = ft_type_conf(conv, var);
	//var = ft_flag_conf(conv, var);
	ft_var_output(var, arg_ptr);
	//ft_printf(conv, arg_ptr);
	return (var.count);
}

int	ft_printf(const char *arg, ...)
{
	va_list	arg_ptr;
	int		count;
	char	*conv;
	char	*text;

	va_start(arg_ptr, arg);
	conv = ft_strchr(arg, '%');
	while (*arg != '%')
		ft_putchar_fd(*arg++, 1);
	count = ft_var_conf(conv, arg_ptr);
	conv += 2;
	va_end (arg_ptr);
	//printf("\n*conv -- '%c'\n", *conv);
	return (count);
}
