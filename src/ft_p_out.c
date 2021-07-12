#include "../includes/ft_printf.h"

void	ft_p_out(t_conf_parser *var, va_list arg_ptr)
{
	unsigned long	p;

	p = va_arg(arg_ptr, unsigned long);
	ft_putstr_fd("0x", 1);
	var->count += 2;
	ft_puthex_fd(p, 1, var);
}
/*
 * bad return value for format "\\!/%p\\!/" and arg: 0x10dcc399 -> got: 17 expected 18
[ERROR] diff on output for format "\\!/%p\\!/" and arg: 0x10dcc399
expected: [\\!/0x10dcc399\\!/]
got: [\\!/0x\x00dcc399\\!/\x00]
 */
