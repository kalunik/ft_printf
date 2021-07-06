#include "includes/ft_printf.h"

//TODO
//		conversions:	'c' 's' 'p' 'd' 'i' 'u' 'x' 'X' '%'
//		flags: 			'-' '0'
//		width:			'*'
//		precision:		'.'

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

t_conf_parser	ft_wdth_prcsn(char *conv, t_conf_parser var, va_list arg_ptr)
{
	va_list arg_clone;

	while (*conv == '-' || *conv == '0')
		conv++;
	if (*conv != '.' || *conv != var.type)
	{
		if (*conv == '*') //TODO delete '*' if useless in mandatory part
		{
			va_copy(arg_clone, arg_ptr);
			va_arg(arg_ptr,int);
			var.width = va_arg(arg_ptr,int);
		}
		else if (ft_isdigit(*conv))
			var.width = ft_atoi(conv);
	}
	while (*conv != '.')
		conv++;
	if (*conv == '.')
	{
		conv++;
		if (*conv == '*') //TODO delete '*' if useless in mandatory part
			var.precision = va_arg(arg_ptr,int);
		else if (ft_isdigit(*conv))
			var.precision = ft_atoi(conv);
	}
	printf(" '%d' - '%d' - '%s'",  var.width, var.precision, conv);
	return (var);
}

t_conf_parser	ft_flag_conf(char *conv, t_conf_parser var)
{
	var.flags = FLG_NONE;
	while (*conv == '-' || *conv == '0')
	{
		if (*conv == '-')
		{
			var.flags |= FLG_MINUS;
			var.flags &= ~FLG_ZERO;
		}
		else if (*conv == '0' && (var.flags << 7) != 128)
			var.flags |= FLG_ZERO;
		conv++;

	}
	while (*conv != var.type)
	{
		if (var.flags < 8 && (ft_isdigit(*conv) || *conv == '*'))
			// *conv != '0'
			var.flags |= FLG_WDTH;
		else if (*conv == '.' && (ft_isdigit(*(conv+1)) || *(conv+1) == '*'))//TODO delete '*'
			var.flags |= FLG_PRCSN;
		conv++;
	}
	return (var);
}

t_conf_parser	ft_type_conf(char *conv, t_conf_parser var)
{
	char	*type_set;
	char	*temp;
	int		i;

	i++;
	type_set = ft_strdup("cspdiuxX%");
	temp = type_set;
	while (*conv)
	{
		while (type_set[i])
		{
			if (*conv == type_set[i])
			{
				var.type = *conv;
				free(temp);
				return (var);
			}
			i++;
		}
		i = 0;
		conv++;
	}
	free(temp);
	return (var); //todo неопределнное поведение
}

int	ft_var_conf(char *conv, va_list arg_ptr)
{
	t_conf_parser	var;

	var = ft_type_conf(conv, var);	//todo find type first, skipping all flags
	var = ft_flag_conf(conv, var);
	printf("%d", var.flags);
	if (var.flags >= 3)
		var = ft_wdth_prcsn(conv, var, arg_ptr);
	//printf("'%s' --- conv ", conv);
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
	conv++;
	while (*arg != '%')
		ft_putchar_fd(*arg++, 1);
	count = ft_var_conf(conv, arg_ptr);
	va_end (arg_ptr);
	//printf("\n*conv -- '%c'\n", *conv);
	return (count);
}
