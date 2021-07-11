//
// Created by Waif Jonathon on 6/22/21.
//

#include "includes/ft_printf.h"

int	main(void)
{
	int size;
	char			c = '0';
	char			*s = "Abdulah Sun !";
	int				d = 3002;
	unsigned int	u = 214748364;


/*
	size = ft_printf("\nMine     -- '%c'", c);
	printf("\n%d mine", size);
	size = printf("\nOriginal -- '%c'", c);
	printf("\n%d original", size);
	printf("\n'c'");
*/
	size = ft_printf("\nMine     -- '%14s' '%c'", s, c);
	printf("\n%d mine", size);
	size = printf("\nOriginal -- '%14s' '%c'", s, c);
	printf("\n%d original", size);
	printf("\n's'");
	/*
	ft_printf("\n'p'\nMine	 -- '%0p'", &s);
	printf("\nOriginal -- '%p'\n", &s);

	ft_printf("\n'd'\nMine	 -- '%0d'", d);
	printf("\nOriginal -- '%d'\n", d);

	ft_printf("\n'i'\nMine	 -- '%-i'", d);
	printf("\nOriginal -- '%i'\n", d);

	ft_printf("\n'u'\nMine	 -- '%0u'", u);
	printf("\nOriginal -- '%u'\n", u);

	ft_printf("\n'x'\nMine	 -- '%-x'", u);
	printf("\nOriginal -- '%x'\n", u);

	ft_printf("\n'X'\nMine	 -- '%0X'", d);
	printf("\nOriginal -- '%X'\n", d);

	ft_printf("\nMine	 -- '%%'");
	printf("\nOriginal  -- '%-%'\n");*/
	return 0;
}