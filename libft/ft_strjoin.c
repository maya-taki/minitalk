/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 21:22:23 by mtakiyos          #+#    #+#             */
/*   Updated: 2025/08/05 16:30:06 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		str1_len;
	size_t		str2_len;
	char		*nstr;

	str1_len = ft_strlen(s1);
	str2_len = ft_strlen(s2);
	nstr = malloc((str1_len + str2_len + 1) * sizeof(char));
	if (!nstr)
		return (NULL);
	ft_strlcpy(nstr, s1, str1_len + 1);
	ft_strlcat(&nstr[str1_len], s2, str2_len + 1);
	return (nstr);
}
