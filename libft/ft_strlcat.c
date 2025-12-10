/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:26:58 by mtakiyos          #+#    #+#             */
/*   Updated: 2025/07/31 17:41:14 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_l;
	size_t	src_l;
	size_t	i;

	dest_l = ft_strlen(dest);
	src_l = ft_strlen(src);
	if (dest_l >= size)
		return (src_l + size);
	i = 0;
	while (src[i] && (dest_l + i < size - 1))
	{
		dest[dest_l + i] = src[i];
		i++;
	}
	dest[dest_l + i] = '\0';
	return (dest_l + src_l);
}
