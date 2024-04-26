/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:03:37 by maugusto          #+#    #+#             */
/*   Updated: 2024/04/26 10:18:19 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdio.h>

char	*get_next_line(int fd);

char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char const *str);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *str, size_t n);
char	*ft_strchr(const char *s, int c);
#endif