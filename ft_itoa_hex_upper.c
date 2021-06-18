#include "includes/ft_printf.h"

static size_t	ft_abs(long long n)
{
	if (n < 0)
		return (-1 * n);
	return (n);
}

static int	ft_count_char(size_t t)
{
	short int	i;

	i = 1;
	while (t / 16 > 0)
	{
		t /= 16;
		i++;
	}
	if (t < 0)
		i++;
	return (i);
}

static char	ft_dec_in_hex(short int storage)
{
	char	r;

	if (storage == 10)
		r = 'A';
	else if (storage == 11)
		r = 'B';
	else if (storage == 12)
		r = 'C';
	else if (storage == 13)
		r = 'D';
	else if (storage == 14)
		r = 'E';
	else if (storage == 15)
		r = 'F';
	else if (storage < 10)
		r = storage + 48;
	return (r);
}

char	*ft_itoa_hex_upper(long long n)
{
	short int	d;
	char		*r;
	size_t		t;
	short int	storage;

	t = ft_abs(n);
	d = ft_count_char(t);
	r = (char *)malloc(d + 1);
	if (!r)
		return (NULL);
	r[d--] = 0;
	if (n < 0)
		r[0] = '-';
	while (t > 0)
	{
		storage = t % 16;
		r[d--] = ft_dec_in_hex(storage);
		t /= 16;
	}
	if (n == 0)
		r[0] = 48;
	return (r);
}
