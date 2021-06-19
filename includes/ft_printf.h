#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "libft.h"

typedef struct	s_parser{
	char	flags;
	int		width;
	int		precision;
	char	type;
}				conf_parser;

# define FLG_NONE	0b00000000
# define FLG_ONE	0b00000001
# define FLG_TWO	0b00000010
# define FLG_THREE	0b00000100
# define FLG_FOUR	0b00001000

void	ft_puthex_fd(unsigned long n, int fd);
void	ft_puthex_up_fd(unsigned long n, int fd);

#endif
