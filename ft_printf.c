#include "ft_printf.h"

/*int main(int argc, char** argv)
{

}*/

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

void var(char *format, ...)
{
	va_list ap;

	va_start(ap, format);
	if(!strcmp(format, "%d"))
	{
		int x = va_arg (ap, int);
		printf ("You passed decimal object with value %d\n", x);
	}

	if(!strcmp(format, "%s"))
	{
		char *p = va_arg (ap, char *);
		printf ("You passed c-string \"%s\"\n", p);
	}
	va_end (ap);
}

/*
int main(void)
{
	var("%d", 255, 2);
	var("%s", "test string");
	ft_printf("");
	return 0;
}
*/

#include <stdio.h>
#include <stdarg.h>
double sum_series(int, ...);

int main(void)
{
	double d;
	d = sum_series(5.0, 0.5, 0.25, 0.125, 0.0625, 0.03125);
	printf("Sum of series is %f\n",d);
	return 0;
}

double sum_series(int num, ...)
{
	double sum = 0.0, t;
	va_list argptr;

/* инициализация argptr */
	va_start (argptr, num);

/* сумма последовательности */
	for(; num; num--) {
		if (sum == 0.0)
			sum += num;
		t = va_arg(argptr,double);
		printf("%f\n", t);
		sum += t;
	}

/* завершение */
	va_end(argptr);
	return sum;
}