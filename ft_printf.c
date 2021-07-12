#include "includes/ft_printf.h"

//TODO
//		conversions:	'c' 's' 'p' 'd' 'i' 'u' 'x' 'X' '%'
//		flags: 			'-' '0'
//		width:			'*'
//		precision:		'.'





void	ft_var_output(t_conf_parser *var, va_list arg_ptr)
{
	//int				i;
	//char			c;
	//char			*s;
	//unsigned long	p;
	long long		d;

	//printf("\n\n%d -- var_output -- width", var->width);
	if (var->type == 'c') //TODO fail w/h width %10c
		ft_c_out(var, arg_ptr);
	else if (var->type == 's')
		ft_s_out(var, arg_ptr);
	else if (var->type == 'p')
		ft_p_out(var, arg_ptr);
	else if (var->type == 'd' || var->type == 'i')
	{
		d = va_arg(arg_ptr, int);
		var->count = ft_strlen(ft_itoa(d));
		ft_putnbr_fd(d, 1);
	}
	else if (var->type == 'u') // FIXME input 2147483648 -- output -2147483648
		ft_u_out(var, arg_ptr);
/*	else if (var->type == 'x')
		ft_puthex_fd(va_arg(arg_ptr, unsigned int), 1);
	else if (var->type == 'X')
		ft_puthex_up_fd(va_arg(arg_ptr, unsigned int), 1);*/
	else if (var->type == '%')
		ft_putstr_fd("%", 1);
}

void	ft_wdth_prcsn(const char *conv, t_conf_parser *var, va_list arg_ptr)
{
	//va_list arg_clone;

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
	//printf("\n%d -- width-1", var->width);
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

void	ft_flag_conf(const char *arg, t_conf_parser *var)
{
	while (*arg == '-' || *arg == '0')
	{
		if (*arg == '-')
		{
			var->flags |= FLG_MINUS;
			var->flags &= ~FLG_ZERO;
		}
		else if (*arg == '0' && (var->flags << 7) != 128)
			var->flags |= FLG_ZERO;
		arg++;
		var->skip++;
	}
	while (*arg != var->type)
	{
		if (var->flags < 8 && (ft_isdigit(*arg) || *arg == '*'))
			var->flags |= FLG_WDTH;
		else if (*arg == '.' && (ft_isdigit(*(arg + 1)) || *(arg + 1) ==
															 '*')) //TODO delete '*'
			var->flags |= FLG_PRCSN;
		arg++;
		var->skip++;
	}
	var->skip++;
}

void	ft_type_conf(const char *conv, t_conf_parser *var)
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
			if (*conv == type_set[i] && var->type == 0)
			{
				var->type = *conv;
			}
			i++;
		}
		i = 0;
		conv++;
	}
	free(temp);
}

void ft_var_clean(t_conf_parser *var)
{
	var->type = 0;
	var->flags = 0;
	var->precision = 0;
	var->width = 0;
	var->count = 0;
	var->skip = 0;
}

void	ft_var_conf(const char *arg, t_conf_parser *var, va_list arg_ptr)
{
	ft_var_clean(var);
	ft_type_conf(arg, var);
	//printf("\n%d -- type", var->type);
	if (!var->type)
		exit(0);
	ft_flag_conf(arg, var);
	if (var->flags > (FLG_MINUS | FLG_ZERO))
	{
		ft_wdth_prcsn(arg, var, arg_ptr);
		//printf("\n%d -- width0", var->width);
	}
	ft_var_output(var, arg_ptr);
}

int	ft_printf(const char *arg, ...)
{
	va_list	arg_ptr;
	t_conf_parser	var;
	int		count;

	count = 0;
	va_start(arg_ptr, arg);
	while (*arg)
	{
		if(*arg != '%')
		{
			ft_putchar_fd(*arg++, 1);
			count++;
		}
		else
		{
			arg++;
			ft_var_conf(arg, &var, arg_ptr);
			count += var.count; //подсчёт выведеных символов
			arg += var.skip; //подсчет расстояния от % до типа

		}
		//printf("\n -- count '%d' // var.count '%d'", count, var.count);
	}
	va_end(arg_ptr);
	//count--;
	return (count);
}
