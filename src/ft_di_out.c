#include "../includes/ft_printf.h"

void	ft_di_out(t_conf_parser *var, va_list arg_ptr)
{
	int		d;
	char	*len;
	char	*tmp;

	d = va_arg(arg_ptr, int);
	len = ft_itoa(d);
	tmp = len;
	var->count = ft_strlen(len);
	ft_putnbr_fd(d, 1);
	free(tmp);
}
