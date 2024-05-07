/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:11:34 by maugusto          #+#    #+#             */
/*   Updated: 2024/05/07 09:44:14 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *stash, char *buffer)
{
	free(stash);
	free(buffer);
	return (NULL);
}

char	*read_file(int fd, char *stash)
{
	int		bytes_read;
	char	*buffer;

	bytes_read = 1;
	buffer = malloc ((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	*buffer = 0;
	while (bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (ft_free(stash, buffer));
		buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (*stash == '\0' || bytes_read == -1)
		return (ft_free(stash, buffer));
	free(buffer);
	return (stash);
}

char	*ft_outline(char *stash)
{
	char	*new_stash;
	int		line_len;
	int		stash_len;

	stash_len = ft_strlen(stash);
	line_len = ft_strlentoc(stash, '\n');
	new_stash = ft_strndup(stash + line_len + 1, stash_len - line_len);
	free(stash);
	if (!new_stash)
		return (NULL);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_file(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_strndup(stash, ft_strlentoc(stash, '\n') + 1);
	if (!line)
		return (NULL);
	stash = ft_outline(stash);
	if (!stash)
		free(stash);
	return (line);
}

/* #include <fcntl.h>

int main()
{
	int fd = open("teste.txt", O_RDONLY);
	int	i = 1;
	char *s = get_next_line(fd);

	while (s)
	{
		printf("Linha %d: %s", i++, s);
		s = get_next_line(fd);
	}
} */