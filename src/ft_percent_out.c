#include "../includes/ft_printf.h"

void	ft_percent_out(t_conf_parser *var)
{
	ft_putstr_fd("%", 1);
	var->count++;
}
