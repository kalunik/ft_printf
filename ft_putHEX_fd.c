#include "includes/ft_printf.h"

/*void	ft_putptr_fd(long long n, int fd)
{
	char	*str;

	str = ft_itoa_hex(n);
	ft_putstr_fd("0x", fd);
	ft_putstr_fd(str, fd);
}*/

static void	ft_convert_fd(short int n, int fd)
{
	char *str = "ABCDEF";

	n = n % 10;
	ft_putchar_fd(str[n], fd);
}

void	ft_puthex_fd(long long n, int fd)
{
//	if (n == -2147483648)
//		write(fd, "-2147483648", 11);
	/*else*/ if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(-n, fd);
	}
	else if (n > 16)
	{
		ft_putnbr_fd(n / 16, fd);
		ft_putnbr_fd(n % 16, fd);
	}
	else if (10 <= n)
		ft_convert_fd(n, fd);
	else
		ft_putchar_fd(n + '0', fd);
}
