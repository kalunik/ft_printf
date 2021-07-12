#include "../includes/ft_printf.h"

void	ft_u_out(t_conf_parser *var, va_list arg_ptr)
{
	unsigned int	u;

	u = va_arg(arg_ptr, unsigned int);
	ft_putuns_fd(u, 1, var);
}
