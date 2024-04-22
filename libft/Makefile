# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 12:18:36 by gude-jes          #+#    #+#              #
#    Updated: 2024/04/19 19:40:31 by maugusto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_strlen.c ft_isalnum.c ft_isprint.c ft_memcmp.c \
					ft_strlcat.c ft_strncmp.c ft_atoi.c ft_isalpha.c \
					ft_memcpy.c  ft_strchr.c  ft_strlcpy.c \
					ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c  \
					ft_memmove.c  ft_strrchr.c ft_strdup.c \
					ft_toupper.c ft_isdigit.c ft_memchr.c  ft_memset.c  \
					ft_calloc.c \
					ft_strjoin.c ft_substr.c ft_putchar_fd.c ft_striteri.c \
					ft_strtrim.c ft_split.c ft_putstr_fd.c \
					ft_itoa.c ft_putnbr_fd.c ft_putendl_fd.c \
					ft_strmapi.c \
					
BONUS			=	ft_lstnew.c ft_lstadd_front.c ft_lstlast.c \
					ft_lstadd_back.c ft_lstclear.c ft_lstdelone.c \
					ft_lstsize.c ft_lstiter.c ft_lstmap.c \

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= libft.a

all:			$(NAME)

$(NAME):		
				$(CC) $(CFLAGS) -c $(SRCS)
				ar rcs $(NAME) $(OBJS)

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS) $(BONUS)
	gcc -nostartfiles -shared -o libft.so $(OBJS) $(BONUS_OBJS)

main : all
	$(CC) $(CFLAGS) -L. $(NAME) 
	
clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

bonus:			$(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY:			all clean fclean re bonus
