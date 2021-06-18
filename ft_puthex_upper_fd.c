#include "includes/ft_printf.h"

void	ft_puthex_upper_fd(long long n, int fd)
{
	char	*str;

	str = ft_itoa_hex_upper(n);
	ft_putstr_fd(str, fd);
}
