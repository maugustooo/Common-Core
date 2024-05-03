/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:05:35 by maugusto          #+#    #+#             */
/*   Updated: 2024/05/03 14:36:02 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_free(char *stash, char *buffer)
{
	free(stash);
	free(buffer);
	return(NULL);
}
char	*ft_strchr(char *s, int c)
{
	unsigned int	i;
	char			cc;

	if (!s)
		return (NULL);
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

char	*read_file(int fd, char *stash)
{
	int		bytes_read;
	char	*buffer;
	
	bytes_read = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if(!buffer)
		return(NULL);
	*buffer = 0;
	while (bytes_read != 0)	
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return(ft_free(stash, buffer));			
		buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if(*stash == '\0' || bytes_read == -1)
		return(ft_free(stash, buffer));
	free(buffer);
	return (stash);
}

char	*ft_outline(char *stash)
{
	char	*new_stash;
	int line_len;
	int stash_len;

	stash_len = ft_strlen(stash);
	line_len = ft_strlentoc(stash,'\n');
	new_stash = ft_strndup(stash + line_len + 1, stash_len - line_len);
	free(stash);
	if(!new_stash)
		return(NULL);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
		stash = NULL;
	stash = read_file(fd, stash);
	if(!stash)
		return (NULL);
	line = ft_strndup(stash, ft_strlentoc(stash, '\n') + 1);
	if(!line)
		return(NULL);
	stash = ft_outline(stash);
	if(!stash)
		free(stash);
	return (line);
}

#include <fcntl.h>

int main()
{
	int fd = open("teste", O_RDONLY);
	int	i = 1;
	char *s = get_next_line(fd);

	while (s)
	{
		printf("Linha %d: %s", i++, s);
		s = get_next_line(fd);
	}
}

/*


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
