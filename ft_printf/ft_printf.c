#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>


void putstr(char *s, int *len)
{
	if (!s)
		s = "(null)";
	int i = 0;
	while (s[i])
	{
		*len += write(1, &s[i], 1);
		i++;
	}
}

void putnbr(long long nbr, int base, int *len)
{
	char *hex = "0123456789abcdef";

	if (nbr < 0)
	{
		*len += write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= base)
		putnbr((nbr / base), base, len);
	*len += write(1, &hex[nbr % base], 1);
}



int ft_printf(const char *s, ... )
{
	va_list args;
	int i = 0;
	int len = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			i++;
			if (s[i] == 's')
				putstr(va_arg(args, char *), &len);
			else if (s[i] == 'd')
				putnbr(va_arg(args, int), 10, &len);
			else if (s[i] == 'x')
				putnbr(va_arg(args, unsigned int), 16, &len);
		}
		else
			len += write(1, &s[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}