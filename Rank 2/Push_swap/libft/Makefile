# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rerodrig <rerodrig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/23 18:04:16 by rerodrig          #+#    #+#              #
#    Updated: 2024/05/06 17:38:59 by rerodrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I
AR = ar rc
RN = ranlib
RM = rm -f
INC_DIR = includes/
OBJ_DIR = obj/
SRC_DIR = src/
OBJ_CREATE = .obj_check

LIBFT_DIR = ft_libft/
LIBFT_SRC = ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_strlen ft_memset ft_bzero ft_memcpy\
    		ft_memmove ft_strlcpy ft_strlcat ft_toupper ft_tolower ft_strchr ft_strrchr ft_strncmp ft_memchr\
    		ft_memcmp ft_strnstr ft_atoi ft_calloc ft_strdup ft_substr ft_strjoin ft_strtrim ft_split\
    		ft_itoa ft_strmapi ft_striteri ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd ft_strtoupper\
			ft_putnstr_fd ft_lstadd_back ft_lstadd_front ft_lstclear ft_lstdelone ft_lstiter ft_lstlast ft_lstmap\
			ft_lstnew ft_lstsize ft_atoi_base 

GNL_DIR = ft_gnl/
GNL_SRC = get_next_line get_next_line_utils

PRINTF_DIR = ft_printf/
PRINTF_SRC = ft_printf ft_print_c ft_print_s ft_print_i ft_print_u ft_print_p ft_print_x ft_utils ft_utils_i ft_flags

SRC_FILES+=$(addprefix $(LIBFT_DIR),$(LIBFT_SRC))
SRC_FILES+=$(addprefix $(PRINTF_DIR),$(PRINTF_SRC))
SRC_FILES+=$(addprefix $(GNL_DIR),$(GNL_SRC))

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))


all:		$(NAME)

$(NAME):	$(OBJ)
			@$(AR) $(NAME) $(OBJ)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJ_CREATE)
			@$(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@

$(OBJ_CREATE):
			@mkdir -p $(OBJ_DIR)
			@mkdir -p $(OBJ_DIR)$(LIBFT_DIR)
			@mkdir -p $(OBJ_DIR)$(PRINTF_DIR)
			@mkdir -p $(OBJ_DIR)$(GNL_DIR)

leaks:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./test_program

clean:
	@$(RM) -r $(OBJ_DIR)
	@$(RM) $(OBJ_CREATE)

fclean: clean
	$(RM) $(NAME)

re: fclean all


.PHONY: all clean fclean re leaks
