#include "../includes/ft_printf.h"

void	ft_c_out(t_conf_parser *var, va_list arg_ptr)
{
	int				i;
	char			c;

	i = 1;
	c = va_arg(arg_ptr, int);
	if (var->width > 1)
	{
		while (i <= var->width)
		{
			ft_putchar_fd(' ', 1);
			i++;
		}
	}
	else
		i++;
	ft_putchar_fd(c, 1);
	var->count = i - 1;
}
