#include "includes/ft_printf.h"

//TODO
//		conversions:	'c' 's' 'p' 'd' 'i' 'u' 'x' 'X' '%'
//		flags: 			'-' '0'
//		width:			'*'
//		precision:		'.'

void	ft_var_output(t_conf_parser *var, va_list arg_ptr)
{
	char			c;
	char			*s;
	unsigned long	p;
	long long		d;

	if (var->type == 'c')
		ft_putchar_fd(va_arg(arg_ptr, int), 1);
	else if (var->type == 's')
		ft_putstr_fd(va_arg(arg_ptr, char *), 1);
	else if (var->type == 'p')
	{
		ft_putstr_fd("0x", 1);
		ft_puthex_fd(va_arg(arg_ptr, unsigned long), 1);
	}
	else if (var->type == 'd' || var->type == 'i')
		ft_putnbr_fd(va_arg(arg_ptr, int), 1);
	else if (var->type == 'u') // FIXME input 2147483648 -- output -2147483648
		ft_putnbr_fd(va_arg(arg_ptr, unsigned int), 1);
	else if (var->type == 'x')
		ft_puthex_fd(va_arg(arg_ptr, unsigned int), 1);
	else if (var->type == 'X')
		ft_puthex_up_fd(va_arg(arg_ptr, unsigned int), 1);
	else if (var->type == '%')
		ft_putstr_fd("%", 1);
}

void	ft_wdth_prcsn(char *conv, t_conf_parser *var, va_list arg_ptr)
{
	va_list arg_clone;

	while (*conv == '-' || *conv == '0')
		conv++;
	if (*conv != '.' || *conv != var->type)
	{
		if (*conv == '*') //TODO delete '*' if useless in mandatory part
		{
			/*va_copy(arg_clone, arg_ptr);
			va_arg(arg_ptr,int);*/
			var->width = va_arg(arg_ptr,int);
		}
		else if (ft_isdigit(*conv))
			var->width = ft_atoi(conv);
	}
	while (*conv != '.')
		conv++;
	if (*conv == '.')
	{
		conv++;
		if (*conv == '*') //TODO delete '*' if useless in mandatory part
			var->precision = va_arg(arg_ptr,int);
		else if (ft_isdigit(*conv))
			var->precision = ft_atoi(conv);
	}
	//printf(" '%d' - '%d' - '%s'",  var.width, var.precision, conv);
}

void	ft_flag_conf(char *conv, t_conf_parser *var)
{
	while (*conv == '-' || *conv == '0')
	{
		if (*conv == '-')
		{
			var->flags |= FLG_MINUS;
			var->flags &= ~FLG_ZERO;
		}
		else if (*conv == '0' && (var->flags << 7) != 128)
			var->flags |= FLG_ZERO;
		conv++;
	}
	while (*conv != var->type)
	{
		if (var->flags < 8 && (ft_isdigit(*conv) || *conv == '*'))
			// *conv != '0'
			var->flags |= FLG_WDTH;
		else if (*conv == '.' && (ft_isdigit(*(conv + 1)) || *(conv + 1) ==
															 '*')) //TODO delete '*'
			var->flags |= FLG_PRCSN;
		conv++;
	}
}

void	ft_type_conf(char *conv, t_conf_parser *var)
{
	char	*type_set;
	char	*temp;
	int		i;

	i = 0;
	type_set = ft_strdup("cspdiuxX%");
	temp = type_set;
	while (*conv)
	{
		while (type_set[i])
		{
			if (*conv == type_set[i])
			{
				var->type = *conv;
				free(temp);
				break;
			}
			i++;
		}
		i = 0;
		conv++;
	}
}

void ft_var_clean(t_conf_parser *var)
{
	var->type = 0;
	var->flags &= FLG_NONE;
	var->precision = 0;
	var->width = 0;
	var->count = 0; //
}

void	ft_var_conf(char *conv, t_conf_parser *var, va_list arg_ptr)
{
	ft_var_clean(var);
	ft_type_conf(conv, var);	//todo find type first, skipping allflags
	if (!var->type)
		exit(0);
	ft_flag_conf(conv, var);
	//printf("\n'%d'-'%c'",var->flags, var->type);
	if (var->flags > (FLG_MINUS | FLG_ZERO))
	{
		ft_wdth_prcsn(conv, var, arg_ptr);
	}
	//conv++;
	//printf("\n'%c' --- var-type ", var.type);
	ft_var_output(var, arg_ptr);
	//ft_printf(conv, arg_ptr);
}

int	ft_printf(const char *arg, ...)
{
	va_list	arg_ptr;
	char	*conv;
	t_conf_parser	var;

	va_start(arg_ptr, arg);
	while (*arg != '%')
		ft_putchar_fd(*arg++, 1);
	conv = ft_strchr(arg, '%');
	conv++;
	//printf("\n'%s' --- conv\n", conv);
	ft_var_conf(conv, &var, arg_ptr); //TODO передавать conv как указатель
	//printf("\n'%c' --- type ", var.type);
	va_end (arg_ptr);
	//printf("\n*conv -- '%c'\n", *conv);
	return (var.count);
}
