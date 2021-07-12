#include "../includes/ft_printf.h"

void	ft_wdth_prcsn(const char *conv, t_conf_parser *var, va_list arg_ptr)
{
	while (*conv == '-' || *conv == '0')
		conv++;
	if (*conv != '.' || *conv != var->type)
	{
		if (*conv == '*')
			var->width = va_arg(arg_ptr, int);
		else if (ft_isdigit(*conv))
			var->width = ft_atoi(conv);
	}
	while (*conv != '.')
		conv++;
	if (*conv == '.')
	{
		conv++;
		if (*conv == '*')
			var->precision = va_arg(arg_ptr, int);
		else if (ft_isdigit(*conv))
			var->precision = ft_atoi(conv);
	}
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
		else if (*arg == '.')
			var->flags |= FLG_PRCSN;
		arg++;
		var->skip++;
	}
	var->skip++;
}
