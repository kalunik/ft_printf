#include "includes/ft_printf.h"

void	ft_s_out(t_conf_parser *var, va_list arg_ptr)
{
	int		i;
	int		len;
	char	*s;

	i = 1;
	s = va_arg(arg_ptr, char *);
	len = ft_strlen(s);
	if (var->width > len)
	{
		while (i <= var->width - len)
		{
			ft_putchar_fd(' ', 1);
			i++;
		}
	}
	else
		i = len;
	ft_putstr_fd(s, 1);
	var->count = i + len - 1;
}
