/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:05:35 by maugusto          #+#    #+#             */
/*   Updated: 2024/04/29 12:14:51 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	unsigned int	i;
	char			cc;

	cc = (char) c;
	i = 0;
	while (s[i])
	{
		if (s[i] == cc)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == cc)
		return ((char *) &s[i]);
	return (NULL);
}

char	*read_file(int fd, char *result, char *buffer)
{
	int		bytes_read;
	char	*temp;
	
	bytes_read = 1;
	while (bytes_read != 0)	
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(result);
			return(NULL);			
		}
		else if(bytes_read == 0)
			break;
		buffer[bytes_read] = '\0';
		if(!result)
			result = ft_strdup("");
		temp = result;
		result = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (result);
}

char	*ft_line(char *line)
{
	char	*stash;
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == 0 || line[1] == 0)
		return (NULL);
	stash = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*stash == 0)
	{
		free(stash);
		stash = NULL;
	}
	line[i + 1] = 0;
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*buffer;
	
	buffer = malloc ((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || !buffer)
	{
		free(stash);
		free(buffer);
		buffer= NULL;
		stash = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = read_file(fd, stash, buffer);
	free(buffer);
	buffer = NULL;
	if(!line)
		return (NULL);
	stash = ft_line(line);
	return (line);
}

/*
#include <fcntl.h>

int main() {
    int fd = open("test", O_RDONLY); // Abrindo o arquivo "teste" para leitura
    if (fd == -1) {
		perror("Erro ao abrir o arquivo");
		return 1;
    }

	char *line = get_next_line(fd);
	while ((line != NULL)
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
// }*/
