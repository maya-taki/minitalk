/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 21:22:21 by mtakiyos          #+#    #+#             */
/*   Updated: 2025/08/05 20:59:50 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_set(const char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	int		trim_len;

	if (!s1 || !set)
		return (NULL);
	start = (char *)s1;
	end = (char *)s1 + ft_strlen(s1) - 1;
	if (*set == '\0')
		return (ft_strdup(s1));
	while (ft_is_set(set, *start))
			start++;
	if (*start == '\0')
		return (ft_substr(s1, 0, 0));
	while (end > start && ft_is_set(set, *end))
		end--;
	trim_len = end - start + 1;
	return (ft_substr(s1, start - s1, trim_len));
}
