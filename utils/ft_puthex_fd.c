#include "../includes/ft_printf.h"

static void	ft_convert_fd(short int n, int fd, char var)
{
	char	*str;

	if (var == 'X')
		str = "0123456789ABCDEF";
	else
		str = "0123456789abcdef";
	ft_putchar_fd(str[n], fd);
}

void	ft_puthex_fd(unsigned long n, int fd, t_conf_parser *var)
{
	if (n >= 16)
	{
		ft_puthex_fd(n / 16, fd, var);
		ft_puthex_fd(n % 16, fd, var);
	}
	else
	{
		ft_convert_fd(n, 1, var->type);
		var->count++;
	}
}
