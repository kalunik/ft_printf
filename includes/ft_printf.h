#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "libft.h"

typedef struct s_parser{
	char	flags;
	int		width;
	int		precision;
	char	type;
	int		count;
	int		skip;
}				t_conf_parser;

# define FLG_NONE	0b00000000
# define FLG_MINUS	0b00000001
# define FLG_ZERO	0b00000010
# define FLG_WDTH	0b00000100
# define FLG_PRCSN	0b00001000

void	ft_c_out(t_conf_parser *var, va_list arg_ptr);
void	ft_s_out(t_conf_parser *var, va_list arg_ptr);
void	ft_p_out(t_conf_parser *var, va_list arg_ptr);
void	ft_di_out(t_conf_parser *var, va_list arg_ptr);
void	ft_u_out(t_conf_parser *var, va_list arg_ptr);
void	ft_x_out(t_conf_parser *var, va_list arg_ptr);
void	ft_percent_out(t_conf_parser *var);

void	ft_putuns_fd(unsigned int n, int fd, t_conf_parser *var);
void	ft_puthex_fd(unsigned long n, int fd, t_conf_parser *var);

void	ft_wdth_prcsn(const char *conv, t_conf_parser *var, va_list arg_ptr);
void	ft_flag_conf(const char *arg, t_conf_parser *var);

int		ft_printf(const char *arg, ...);

#endif
