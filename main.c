//
// Created by Waif Jonathon on 6/22/21.
//

#include "includes/ft_printf.h"

int	main(void)
{
	char			c = 'a';
	char			*s = "Abdulah Sun !";
	int				d = 2;
	unsigned int	u = 2147483648;

//	ft_printf("\n'c'\nMine	 -- '%c'", c);
//	printf("\nOriginal -- '%c'\n", c);
//
//	ft_printf("\n's'\nMine	 -- '%s'", s);
//	printf("\nOriginal -- '%-1000s'\n", s);
//
//	ft_printf("\n'p'\nMine	 -- '%p'", &s);
//	printf("\nOriginal -- '%p'\n", &s);
//
	ft_printf("\n'd'\nMine	 -- '%5.8%%d'", d, 10);
	printf("\nOriginal -- '%10%%d'\n", d);
//
//	ft_printf("\n'i'\nMine	 -- '%i'", d);
//	printf("\nOriginal -- '%i'\n", d);
//
//	ft_printf("\n'u'\nMine	 -- '%u'", u);
//	printf("\nOriginal -- '%u'\n", u);
//
//	ft_printf("\n'x'\nMine	 -- '%x'", u);
//	printf("\nOriginal -- '%x'\n", u);
//
//	ft_printf("\n'X'\nMine	 -- '%X'", d);
//	printf("\nOriginal -- '%X'\n", d);
//
//	ft_printf("\nMine	 -- '%%'");
//	printf("\nOriginal  -- '%%'\n");
	return 0;
}