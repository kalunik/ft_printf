#include "includes/ft_printf.h"

void	ft_puthex_fd(long long n, int fd)
{
	char	*str;

	str = ft_itoa_hex(n);
	ft_putstr_fd(str, fd);
}
