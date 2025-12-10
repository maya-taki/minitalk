/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:27:05 by mtakiyos          #+#    #+#             */
/*   Updated: 2025/08/04 17:27:03 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		i;

	i = ft_strlen(s);
	while (i > 0)
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i--;
	}
	if ((char) c == '\0')
		return ((char *)&s[i]);
	if (s[i] == (char) c)
		return ((char *)&s[i]);
	return ((void *) 0);
}
