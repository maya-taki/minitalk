/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 17:06:31 by mtakiyos          #+#    #+#             */
/*   Updated: 2025/11/07 18:13:19 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printunl(int base, char *basestr, unsigned long n)
{
	int	count;

	count = 0;
	if (n / base)
		count += ft_printunl(base, basestr, n / base);
	count += ft_putchar(basestr[n % base]);
	return (count);
}

int	ft_printptr(unsigned long ptr)
{
	int	count;

	if (!ptr)
		return (write(1, "(nil)", 5));
	count = 0;
	count += write(1, "0x", 2);
	count += ft_printunl(16, "0123456789abcdef", ptr);
	return (count);
}
