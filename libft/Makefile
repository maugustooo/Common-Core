# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maugusto <maugusto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 12:18:36 by gude-jes          #+#    #+#              #
#    Updated: 2024/04/16 12:41:37 by maugusto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_strlen.c ft_isalnum.c ft_isprint.c ft_memcmp.c \
					ft_strlcat.c ft_strncmp.c ft_atoi.c ft_isalpha.c \
					ft_memcpy.c  ft_strchr.c  ft_strlcpy.c \
					ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c  \
					ft_memmove.c  ft_strrchr.c ft_strdup.c \
					ft_toupper.c ft_isdigit.c ft_memchr.c  ft_memset.c  \
					ft_calloc.c ft_strjoin.c ft_substr.c ft_putchar_fd.c \
					ft_strtrim.c ft_split.c ft_putstr_fd.c \
					ft_itoa.c ft_putnbr_fd.c ft_putendl_fd.c \
					ft_strmapi.c \
					
CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= libft.a

OBJS = $(SRCS:.c=.o)

all:			$(NAME)

$(NAME):		
				$(CC) $(CFLAGS) -c $(SRCS)
				ar rcs $(NAME) $(OBJS)
				ranlib $(NAME)

debug: CFLAGS += -g
debug: $(NAME)
	gcc -g -o debug_$(basename $(FILE)) $(FILE) -L. -lft
	gdb -tui ./debug_$(basename $(FILE))

main : all
	$(CC) $(CFLAGS) -L. $(NAME) 
	
clean:
				$(RM) $(OBJS) 

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus