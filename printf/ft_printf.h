/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-slu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:35:04 by lvan-slu          #+#    #+#             */
/*   Updated: 2023/11/26 17:39:44 by lvan-slu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
#include <stdarg.h>

int	print_char(int c);

int	print_str(char *str);

int	print_digit(long n, int base, char type);

int	print_type(char type, va_list ap);

int	ft_printf(const char *format, ...);

int	print_pointeur(unsigned long long n, unsigned long long base);

#endif
