/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:36:55 by mtakiyos          #+#    #+#             */
/*   Updated: 2025/11/07 18:18:18 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*join_and_free(char *s1, char *s2)
{
	char	*res;

	res = ft_strjoin(s1, s2);
	free(s1);
	s1 = NULL;
	return (res);
}

char	*free_all(char *stash, char *buffer)
{
	free(stash);
	stash = NULL;
	free(buffer);
	buffer = NULL;
	return (NULL);
}

char	*read_fd(char *stash, int fd)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{	
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free_all(stash, buffer));
		buffer[bytes_read] = '\0';
		stash = join_and_free(stash, buffer);
		if (!stash)
			return (free_all(stash, buffer));
		if (ft_strchr(stash, '\n'))
		{
			free(buffer);
			return (stash);
		}
	}
	free(buffer);
	return (stash);
}

char	*next_line(char **line, char *stash)
{
	int		i;
	char	*leftover;

	if (ft_strlen(stash) <= 0)
	{
		free(stash);
		return (NULL);
	}
	i = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	*line = ft_substr(stash, 0, i + 1);
	if (!*line)
		return (free_all(*line, stash));
	leftover = ft_substr(stash, i + 1, ft_strlen(stash) - i - 1);
	if (!leftover)
		return (free_all(leftover, stash));
	free(stash);
	return (leftover);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
		stash = ft_strdup("");
	stash = read_fd(stash, fd);
	if (!stash || !*stash)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = next_line(&line, stash);
	return (line);
}
