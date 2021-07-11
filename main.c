//
// Created by Waif Jonathon on 6/22/21.
//

#include "includes/ft_printf.h"

int	main(void)
{
	int size;
	char			c = 'a';
	char			*s = "Abdulah Sun !";
	int				d = 3002;
	unsigned int	u = 214748364;

	printf("\n'c'");
	size = ft_printf("\nMine     -- '%5c' '%d'", c, d);
	printf("\n%d mine", size);
	size = printf("\nOriginal -- '%5c' '%d'", c, d);
	printf("\n%d original\n", size);

	/*ft_printf("\n's'\nMine	 -- '%-s'",  s);
	printf("\nOriginal -- '%s'\n", s);

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