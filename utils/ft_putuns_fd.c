#include "../includes/ft_printf.h"

void	ft_putuns_fd(unsigned int n, int fd, t_conf_parser *var)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		ft_putuns_fd(-n, fd, var);
	}
	else if (n > 9)
	{
		ft_putuns_fd(n / 10, fd, var);
		ft_putuns_fd(n % 10, fd, var);
	}
	else
	{
		ft_putchar_fd(n + '0', fd);
		var->count++;
	}
}
