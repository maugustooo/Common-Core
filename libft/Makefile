# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/23 18:04:16 by rerodrig          #+#    #+#              #
#    Updated: 2024/05/11 16:24:42 by maugusto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I$(INC_DIR)
AR = ar rc
RN = ranlib
RM = rm -f
INC_DIR = includes/
OBJ_DIR = obj/
SRC_DIR = src/
OBJ_CREATE = .obj_check

LIBFT_DIR = libft/

LIBFT_SRC = $(addprefix $(LIBFT_DIR), ft_strlen.c ft_isalnum.c ft_isprint.c ft_memcmp.c \
					ft_strlcat.c ft_strncmp.c ft_atoi.c ft_isalpha.c \
					ft_memcpy.c  ft_strchr.c  ft_strlcpy.c \
					ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c  \
					ft_memmove.c  ft_strrchr.c ft_strdup.c \
					ft_toupper.c ft_isdigit.c ft_memchr.c  ft_memset.c  \
					ft_calloc.c \
					ft_strjoin.c ft_substr.c ft_putchar_fd.c ft_striteri.c \
					ft_strtrim.c ft_split.c ft_putstr_fd.c \
					ft_itoa.c ft_putnbr_fd.c ft_putendl_fd.c \
					ft_strmapi.c ft_lstnew.c ft_lstadd_front.c ft_lstlast.c \
					ft_lstadd_back.c ft_lstclear.c ft_lstdelone.c \
					ft_lstsize.c ft_lstiter.c ft_lstmap.c)

GNL_DIR = get_next_line/
GNL_SRC = $(addprefix $(GNL_DIR), get_next_line.c get_next_line_utils.c)

PRINTF_DIR = printf/
PRINTF_SRC = $(addprefix $(PRINTF_DIR), ft_printf.c ft_prints.c ft_put_hex.c ft_itoa.c ft_uitoa.c \
			ft_putpointer.c)

			

SRC_FILES =  $(GNL_SRC) $(PRINTF_SRC) $(LIBFT_SRC) 
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

all: $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@$(RN) $(NAME)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@


leaks:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./libft.a

clean:
	@$(RM) -r $(OBJ_DIR)
	@$(RM) $(OBJ_CREATE)

fclean:
	@$(RM) $(OBJ)
	@$(RM) $(NAME)


re: fclean all

.PHONY: all clean fclean re leaks
