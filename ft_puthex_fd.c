#include "includes/ft_printf.h"

static void	ft_convert_fd(short int n, int fd)
{
	char	*str;

	str = ft_strdup("abcdef");
	n = n % 10;
	ft_putchar_fd(str[n], fd);
	free(str);
}

void	ft_puthex_fd(unsigned long n, int fd, t_conf_parser *var)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		ft_puthex_fd(-n, fd, var);
	}
	else if (n > 16)
	{
		ft_puthex_fd(n / 16, fd, var);
		ft_puthex_fd(n % 16, fd, var);
	}
	else if (10 <= n)
	{
		ft_convert_fd(n, fd);
		var->count++;
	}
	else
	{
		ft_putchar_fd(n + '0', fd);
		var->count++;
	}
}
