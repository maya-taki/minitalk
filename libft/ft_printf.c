/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:29:16 by mtakiyos          #+#    #+#             */
/*   Updated: 2025/11/07 18:13:12 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_args(char c, va_list args)
{
	if (c == '%')
		return (ft_putchar('%'));
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_printuns(10, "0123456789", va_arg(args, unsigned int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_printptr(va_arg(args, unsigned long)));
	else if (c == 'x' || c == 'X')
		return (ft_printhex(va_arg(args, unsigned int), c));
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	size_t	i;
	va_list	args;

	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_printf_args(format[i], args);
			i++;
		}
		else
		{
			count += ft_putchar(format[i]);
			i++;
		}
	}
	return (count);
}
