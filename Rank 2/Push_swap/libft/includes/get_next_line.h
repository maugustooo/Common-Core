/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:40:17 by rerodrig          #+#    #+#             */
/*   Updated: 2024/05/09 11:35:48 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "./libft.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 24
# endif

typedef struct a_list
{
	char			buffer[BUFFER_SIZE + 1];
	struct a_list	*next;
}				t_gnl;

char		*get_next_line(int fd);
char		*ft_strchr_gnl(char *s, char c);
size_t		ft_strsize(const char *str);
size_t		ft_lstlen(t_gnl *stash);
void		*ft_reset_list(t_gnl *stash);
t_gnl		*ft_split_list_by_newline(t_gnl *stash, char *newline);
char		*ft_concanate_list_to_string(t_gnl *stash);
void		ft_gnl_init( t_gnl *s, t_gnl **st, char **nl, ssize_t *rd);
int			ft_create_new_list(t_gnl **stash, t_gnl **start_node);
int			ft_atoi_base(char *str, char *base);
size_t		ft_split_count(const char *s, char c);

#endif
