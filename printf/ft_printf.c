#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int	print_char(int c)
{
	return write(1, &c, 1);
}

int	print_str(char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		print_char((int)*str);
		i++;
		str++;
	}
	return (i);
}

int	print_digit(long n, int base)
{
	int	i;
	char	sign;

	sign
	if (n < 0)
	{
		write(1, "-", 1);
		return print_digit (-n, base) + 1;
	}
	else
		
	
}

int	print_type(char type, va_list ap)
{
	int	i;

	i = 0;
	if (type == 'c')
		i += print_char(va_arg(ap, int));
	else if (type == 's')
		i += print_str(va_arg(ap, char *));
	else if (type == '%')
		write(1, "%", 1);
	else write(1, &type, 1);
	return (i);
}

int	ft_printf(const char *f, ...)
{
	va_list ap;
	int	i;

	va_start(ap, format);
	i = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			i += print_type(*(++format), ap);
		else
			i += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (i);
}

int	main()
{
	char	count [] = "Je suis %%  un test";

	ft_printf("Je suis a 100%%\n");
}
