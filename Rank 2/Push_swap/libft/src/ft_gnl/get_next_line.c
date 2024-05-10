/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:38:21 by rerodrig          #+#    #+#             */
/*   Updated: 2024/05/06 10:48:04 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

char	*get_next_line(int fd)
{
	static t_gnl	*stash = NULL;
	t_gnl			*start_node;
	char			*newline;
	ssize_t			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_gnl_init(stash, &start_node, &newline, &bytes_read);
	while (newline == NULL && bytes_read > 0)
	{
		if (ft_create_new_list(&stash, &start_node) == 0)
			return (NULL);
		bytes_read = read(fd, stash->buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			stash = NULL;
			return (ft_reset_list(start_node));
		}
		(stash->buffer)[bytes_read] = '\0';
		newline = ft_strchr_gnl(stash->buffer, '\n');
	}
	stash = ft_split_list_by_newline(stash, newline);
	return (ft_concanate_list_to_string(start_node));
}

void	ft_gnl_init( t_gnl *stash, t_gnl **start, char **nl, ssize_t *readed)
{
	*nl = NULL;
	*start = NULL;
	*readed = 1;
	if (stash != NULL)
	{
		*start = stash;
		*nl = ft_strchr_gnl(stash->buffer, '\n');
	}
}

int	ft_create_new_list(t_gnl **stash, t_gnl **start_node)
{
	t_gnl	*new;

	new = malloc(sizeof(*new));
	if (new == NULL)
		return ((long)ft_reset_list(*start_node));
	new->next = NULL;
	if (*stash == NULL)
		*start_node = new;
	else
		(*stash)->next = new;
	*stash = new;
	return (1);
}

t_gnl	*ft_split_list_by_newline(t_gnl *stash, char *newline)
{
	t_gnl			*new;
	unsigned int	i;

	if (stash == NULL || newline == NULL)
		return (NULL);
	new = malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	new->next = NULL;
	i = 0;
	newline++;
	while (newline[i] != '\0')
	{
		(new->buffer)[i] = newline[i];
		if (i == 0)
			newline[i] = '\0';
		i++;
	}
	(new->buffer)[i] = '\0';
	return (new);
}

char	*ft_concanate_list_to_string(t_gnl *stash)
{
	size_t	len;
	size_t	i;
	size_t	j;
	t_gnl	*lstcpy;
	char	*string;

	lstcpy = stash;
	len = ft_lstlen(stash);
	if (len <= 0)
		return (ft_reset_list(lstcpy));
	string = malloc(sizeof(*string) * (len + 1));
	if (string == NULL)
		return (ft_reset_list(lstcpy));
	stash = lstcpy;
	i = 0;
	while (stash != NULL && i < len)
	{
		j = 0;
		while ((stash->buffer)[j] != '\0')
			string[i++] = (stash->buffer)[j++];
		stash = stash->next;
	}
	string[i] = '\0';
	ft_reset_list(lstcpy);
	return (string);
}
// int main(void)
// {
// 	int fd;
// 	char *line;

// 	fd = open("example.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Error opening file");
// 		return 1;
// 	}
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s\n", line);
// 		free(line);
// 		// usleep(1000000);
// 	}
// 	close(fd);
// 	return 0;
// }
