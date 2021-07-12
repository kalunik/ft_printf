#include "../includes/ft_printf.h"

void	ft_x_out(t_conf_parser *var, va_list arg_ptr)
{
	unsigned int	x;

	x = va_arg(arg_ptr, unsigned int);
	ft_puthex_fd(x, 1, var);
}
