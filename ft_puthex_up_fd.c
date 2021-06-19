#include "includes/ft_printf.h"

static void	ft_convert_up_fd(short int n, int fd)
{
	char *str = "ABCDEF";

	n = n % 10;
	ft_putchar_fd(str[n], fd);
}

void	ft_puthex_up_fd(unsigned long n, int fd)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		ft_puthex_up_fd(-n, fd);
	}
	else if (n > 16)
	{
		ft_puthex_up_fd(n / 16, fd);
		ft_puthex_up_fd(n % 16, fd);
	}
	else if (10 <= n)
		ft_convert_up_fd(n, fd);
	else
		ft_putchar_fd(n + '0', fd);
}
