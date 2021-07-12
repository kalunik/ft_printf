#include "includes/ft_printf.h"

void	ft_var_output(t_conf_parser *var, va_list arg_ptr)
{
	if (var->type == 'c')
		ft_c_out(var, arg_ptr);
	else if (var->type == 's')
		ft_s_out(var, arg_ptr);
	else if (var->type == 'p')
		ft_p_out(var, arg_ptr);
	else if (var->type == 'd' || var->type == 'i')
		ft_di_out(var, arg_ptr);
	else if (var->type == 'u')
		ft_u_out(var, arg_ptr);
	else if (var->type == 'x' || var->type == 'X')
		ft_x_out(var, arg_ptr);
	else if (var->type == '%')
		ft_percent_out(var);
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
				var->type = *conv;
			i++;
		}
		i = 0;
		conv++;
	}
	free(temp);
}

void	ft_var_clean(t_conf_parser *var)
{
	var->type = 0;
	var->flags = 0;
	var->precision = -1;
	var->width = 0;
	var->count = 0;
	var->skip = 0;
}

void	ft_var_conf(const char *arg, t_conf_parser *var, va_list arg_ptr)
{
	ft_var_clean(var);
	ft_type_conf(arg, var);
	if (!var->type)
		exit(0);
	ft_flag_conf(arg, var);
	if (var->flags > (FLG_MINUS | FLG_ZERO))
	{
		ft_wdth_prcsn(arg, var, arg_ptr);
	}
	ft_var_output(var, arg_ptr);
}

int	ft_printf(const char *arg, ...)
{
	va_list			arg_ptr;
	t_conf_parser	var;
	int				count;

	count = 0;
	va_start(arg_ptr, arg);
	while (*arg)
	{
		if (*arg != '%')
		{
			ft_putchar_fd(*arg++, 1);
			count++;
		}
		else
		{
			arg++;
			ft_var_conf(arg, &var, arg_ptr);
			count += var.count;
			arg += var.skip;
		}
	}
	va_end(arg_ptr);
	return (count);
}
