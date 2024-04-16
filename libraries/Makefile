# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/05 13:14:15 by mstefano          #+#    #+#              #
#    Updated: 2024/03/30 17:03:21 by mstefano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libraries.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -std=c99
RM = rm -f

GNL_DIR = get_next_line
PRINTF_DIR = ft_printf
LIBFT_DIR = Libft

LIBFT_SRC = $(addprefix $(LIBFT_DIR)/, \
	  ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c\
	  ft_atoi.c ft_bzero.c ft_isprint.c ft_memset.c ft_strchr.c\
	  ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c\
	  ft_toupper.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c\
	  ft_strlcat.c ft_strlcpy.c ft_strdup.c ft_calloc.c ft_putchar_fd.c\
	  ft_putstr_fd.c ft_putendl_fd.c ft_strmapi.c ft_putnbr_fd.c\
	  ft_striteri.c ft_substr.c ft_strjoin.c ft_strtrim.c\
	  ft_itoa.c ft_split.c ft_lstnew.c ft_lstadd_front.c \
	  ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
	  ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c) 

GNL_SRC = $(addprefix $(GNL_DIR)/, \
	  get_next_line_bonus.c get_next_line_utils_bonus.c)
	  
PRINTF_SRC = $(addprefix $(PRINTF_DIR)/, \
	  ft_printf.c ft_print_character.c ft_print_decimal.c ft_print_hexa.c ft_print_formats.c \
	  ft_print_percent.c ft_print_ptr.c ft_print_str.c ft_print_unsigneddecimal.c)

SRC = $(LIBFT_SRC) $(GNL_SRC) $(PRINTF_SRC)

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all 

.PHONY :clean fclean  all re
