/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dani_mm__ <dani_mm__@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:13:21 by dani_mm__         #+#    #+#             */
/*   Updated: 2024/05/15 12:13:23 by dani_mm__        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd, char **to)
{
	static char	*buffer;
	char		*read_res;
	char		*result;

	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	read_res = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!read_res)
		return (NULL);
	if (!buffer)
		buffer = gn_strdup("");
	result = gn_reader(fd, read_res, &buffer);
	free_str(&read_res);
	*to = result;
	return (result);
}

char	*gn_reader(int fd, char *read_res, char **buffer)
{
	ssize_t	bytes_read;
	int		nl;
	char	*temp;

	bytes_read = 0;
	nl = gn_strchr(*buffer, '\n');
	while (!nl)
	{
		bytes_read = read(fd, read_res, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (append_line(nl, buffer));
		read_res[bytes_read] = 0;
		temp = gn_strjoin(*buffer, read_res);
		free_str(buffer);
		*buffer = temp;
		nl = gn_strchr(*buffer, '\n');
	}
	return (append_line(nl, buffer));
}

char	*append_line(int nl_index, char **buffer)
{
	char	*result;
	char	*temp;

	temp = NULL;
	if (nl_index <= 0)
	{
		if (**buffer == '\0')
		{
			free(*buffer);
			*buffer = NULL;
			return (NULL);
		}
		result = *buffer;
		*buffer = NULL;
		return (result);
	}
	temp = gn_substr(*buffer, nl_index, BUFFER_SIZE);
	result = *buffer;
	result[nl_index] = 0;
	*buffer = temp;
	return (result);
}

void	free_str(char **ptr)
{
	if (*ptr != NULL)
	{
		free(*ptr);
		ptr = NULL;
	}
}
