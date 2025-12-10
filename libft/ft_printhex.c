/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 17:04:17 by mtakiyos          #+#    #+#             */
/*   Updated: 2025/11/07 18:13:15 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printhex(unsigned int n, int flag)
{
	int	count;

	count = 0;
	if (flag == 'x')
	{
		count += ft_printuns(16, "0123456789abcdef", n);
	}
	else
	{
		count += ft_printuns(16, "0123456789ABCDEF", n);
	}
	return (count);
}
