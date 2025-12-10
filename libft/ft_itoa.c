/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 21:22:31 by mtakiyos          #+#    #+#             */
/*   Updated: 2025/08/08 20:31:48 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getsize(int number)
{
	size_t	size;

	size = 0;
	if (number <= 0)
	{
		size++;
		number = number * (-1);
	}
	while (number != 0)
	{
		number = number / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	long int	num;
	char		*nbr;
	size_t		size;

	num = n;
	size = ft_getsize(num);
	nbr = malloc((size + 1) * sizeof(char));
	if (!nbr)
		return (NULL);
	nbr[size] = '\0';
	if (num == 0)
		nbr[--size] = '0';
	if (num < 0)
	{
		nbr[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		nbr[size - 1] = (num % 10) + '0';
		num /= 10;
		size--;
	}
	return (nbr);
}
