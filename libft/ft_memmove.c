/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:26:54 by mtakiyos          #+#    #+#             */
/*   Updated: 2025/08/04 20:30:03 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*byte_d;
	unsigned char	*byte_s;
	size_t			i;

	i = 0;
	if (!dest && !src)
		return ((void *) 0);
	byte_d = (unsigned char *)dest;
	byte_s = (unsigned char *)src;
	if (dest > src)
	{
		while (n--)
			byte_d[n] = byte_s[n];
	}
	else
	{
		while (i < n)
		{
			byte_d[i] = byte_s[i];
			i++;
		}
	}
	return (dest);
}
