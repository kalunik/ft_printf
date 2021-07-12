#include "../includes/ft_printf.h"

void	ft_di_out(t_conf_parser *var, va_list arg_ptr)
{
	int	d;

	d = va_arg(arg_ptr, int);
	var->count = ft_strlen(ft_itoa(d));
	ft_putnbr_fd(d, 1);
}
