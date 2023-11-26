/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:24:52 by lvan-slu          #+#    #+#             */
/*   Updated: 2023/11/26 17:25:48 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	print_digit(long n, int base, char type)
{

	int	i;
	char	*symbol;

	i = 0;
	if (type == 'X')
		symbol = "0123456789ABCDEF";
	else
		symbol = "0123456789abcdef";
	if (n < 0 && (type == 'u' || type == 'X' || type == 'x'))
		return (print_digit (n += 4294967296, base, type));
	else if (n < 0)
	{
		write (1, "-", 1);
		n *= -1;
		return (print_digit (n, base, type));
	}
	else if (n < base)
		return (print_char (symbol[n]));
	else
	{
		i = print_digit ((n / base), base, type);
		return (i + print_digit ((n % base), base, type));
	}	
}

int	print_type(char type, va_list ap)
{
	int	i;

	i = 0;
	if (type == 'c')
		i += print_char(va_arg(ap, int));
	else if (type == 's')
		i += print_str(va_arg(ap, char *));
//	else if (type == 'p')
//		i += print_pointeur(va_arg(ap, void *));
	else if (type == 'd')
		i += print_digit((long)va_arg(ap, int), 10, type);
	else if (type == 'i')
		i += print_digit((long)va_arg(ap, int), 10, type);
	else if (type == 'u')
		i += print_digit((long)va_arg(ap, unsigned int), 10, type);
	else if (type == 'x')
		i += print_digit((long)va_arg(ap, unsigned int), 16, type);
	else if (type == 'X')
		i += print_digit((long)va_arg(ap, unsigned int), 16, type);
	else if (type == '%')
		write(1, "%", 1);
	else write(1, &type, 1);
	return (i);
}

int	ft_printf(const char *format, ...)
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
/*
int	main()
{
	ft_printf("%d\n", );
	//printf("%u", 429467292);
}*/
