/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:05:35 by maugusto          #+#    #+#             */
/*   Updated: 2024/04/26 14:08:34 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_buffer(char *res, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(res, buffer);
	return (temp);
}

char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

char	*read_file(int fd, char *res)
{
	char	*buffer;
	int		bytes_read;

	if (!res)
		res = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buffer == NULL)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = 0;
		res = free_buffer(res, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (res);
}

char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (buffer == NULL)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_next(buffer);
	return (line);
}


#include <fcntl.h>

int main() {
    int fd = open("test", O_RDONLY); // Abrindo o arquivo "teste" para leitura
    if (fd == -1) {
		perror("Erro ao abrir o arquivo");
		return 1;
    }

	char *line;
	while ((line = get_next_line(fd)) != NULL)
	{ 
        printf("%s\n", line);    
	}
    return 0;
}


// char	*ft_strjoin(char  *s1, char  *s2)
// {
// 	int		sizetotal;
// 	char	*res;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	sizetotal = ft_strlen(s1) + ft_strlen(s2);
// 	res = malloc(sizeof(char) * (sizetotal + 1));
// 	if (!res || !s1 || !s2)
// 		return (NULL);
// 	while (s1[i] != 0)
// 	{
// 		res[i] = s1[i];
// 		i++;
// 	}
// 	j = 0;
// 	while (s2[j] != 0)
// 	{
// 		res[i] = s2[j];
// 		i++;
// 		j++;
// 	}
// 	res[sizetotal] = 0;
// 	return (res);
// }

// char	*ft_strchr(const char *s, int c)
// {
// 	while (*s && *s != (char )c)
// 		s++;
// 	if (*s == (char )c || !c)
// 		return ((char *) s);
// 	return (NULL);
// }

// size_t	ft_strlen(char const *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }
// void	ft_bzero(void *str, size_t n)
// {
// 	size_t			i;
// 	unsigned char	*s;

// 	s = (unsigned char *)str;
// 	i = 0;
// 	while (i < n)
// 	{
// 		s[i] = 0;
// 		i++;
// 	}
// }

// void	*ft_calloc(size_t nmemb, size_t size)
// {
// 	void	*ptr;

// 	if ((nmemb > 2147483647 && size != 0) || (size > 2147483647 && nmemb != 0))
// 		return (0);
// 	ptr = (void *)malloc(nmemb * size);
// 	if (!ptr)
// 		return (NULL);
		
// 	ft_bzero (ptr, nmemb * size);
// 	return (ptr);
// }
