/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 17:04:07 by mtakiyos          #+#    #+#             */
/*   Updated: 2025/11/07 18:13:31 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printuns(unsigned int base, char *basestr, unsigned int n)
{
	int	count;

	count = 0;
	if (n / base)
		count += ft_printuns(base, basestr, n / base);
	count += ft_putchar(basestr[n % base]);
	return (count);
}
