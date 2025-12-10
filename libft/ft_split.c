/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:03:38 by mtakiyos          #+#    #+#             */
/*   Updated: 2025/08/08 12:57:36 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(const char *str, char c)
{
	size_t	i;
	size_t	counter;
	size_t	start;
	int		inword;

	inword = 0;
	i = 0;
	counter = 0;
	start = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c && inword == 1)
		{
			inword = 0;
		}
		if (str[i] != c && inword == 0)
		{
			counter++;
			inword = 1;
		}
		i++;
	}
	return (counter);
}

static void	ft_freearr(char **arr)
{
	size_t	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

static void	ft_addstr(const char *str, char c, char **arr)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
		{
			start = i;
			while (str[i] != '\0' && str[i] != c)
				i++;
			arr[j] = ft_substr(str, start, i - start);
			if (!arr[j])
				return (ft_freearr(arr));
			j++;
		}
	}
	arr[j] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**str_arr;

	if (!s)
		return (NULL);
	str_arr = malloc((ft_wordcount(s, c) + 1) * sizeof (char *));
	if (!str_arr)
		return (NULL);
	ft_addstr(s, c, str_arr);
	return (str_arr);
}
