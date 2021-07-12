#include "../includes/ft_printf.h"

static void	ft_convert_up_fd(short int n, int fd)
{
	char	*str;

	str = ft_strdup("ABCDEF");
	n = n % 10;
	ft_putchar_fd(str[n], fd);
}

void	ft_puthex_up_fd(unsigned long n, int fd, t_conf_parser *var)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		ft_puthex_up_fd(-n, fd, var);
	}
	else if (n > 16)
	{
		ft_puthex_up_fd(n / 16, fd, var);
		ft_puthex_up_fd(n % 16, fd, var);
	}
	else if (10 <= n)
	{
		ft_convert_up_fd(n, fd);
		var->count++;
	}
	else
	{
		ft_putchar_fd(n + '0', fd);
		var->count++;
	}
}
