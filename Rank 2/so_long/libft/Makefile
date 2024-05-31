# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 12:18:36 by gude-jes          #+#    #+#              #
#    Updated: 2024/05/17 11:55:40 by maugusto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
NAME = libft.a

LIB_SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c\
		   ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c\
	  	   ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c\
	  	   ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
		   printf/ft_printf.c printf/ft_itoa.c printf/ft_prints.c printf/ft_put_hex.c printf/ft_putpointer.c printf/ft_uitoa.c\
			get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
		   
LIB_OBJS =  $(LIB_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIB_OBJS)
	ar rc $(NAME) $(LIB_OBJS)

clean:
	$(RM) $(LIB_OBJS)
fclean: clean
	$(RM) $(NAME)
re: clean all

PHONY: all clean fclean re
