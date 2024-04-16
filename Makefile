# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/08 15:27:19 by mstefano          #+#    #+#              #
#    Updated: 2024/04/15 15:44:32 by mstefano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN=\033[0;32m
RESET=\033[0m
RED=\033[0;31m
CHECK=\xE2\x9C\x94
BROOM=\xF0\x9F\xA7\xB9
SERVER_NAME = server
CLIENT_NAME = client
BONUS_CLIENT_NAME = client_bonus
BONUS_SERVER_NAME = server_bonus
RM = rm -f
CC = cc 
CFLAGS = -Wall -Wextra -Werror
LIBRARIES_PATH = ./libraries
LIBRARIES = $(LIBRARIES_PATH)/libraries.a

SERVER_SRC = server.c
CLIENT_SRC = client.c

BONUS_SERVER_SRC = server_bonus.c
BONUS_CLIENT_SRC = client_bonus.c


SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o) 

BONUS_SERVER_OBJ = $(BONUS_SERVER_SRC:.c=.o)
BONUS_CLIENT_OBJ = $(BONUS_CLIENT_SRC:.c=.o)

all: $(SERVER_NAME) $(CLIENT_NAME)

bonus : $(BONUS_SERVER_NAME) $(BONUS_CLIENT_NAME)

$(LIBRARIES):
	@make -C $(LIBRARIES_PATH)
	@echo "$(GREEN)$(CHECK)Compiled Libraries Successfully$(CHECK)$(RESET)"

$(SERVER_NAME): $(LIBRARIES) $(SERVER_OBJ)  
	@cc $(CFLAGS) $(LIBRARIES) -o $(SERVER_NAME) $(SERVER_OBJ)
	@echo "$(GREEN)$(CHECK)Compiled Server Successfully$(CHECK)$(RESET)"
	
$(CLIENT_NAME): $(LIBRARIES) $(CLIENT_OBJ)  
	@cc $(CFLAGS) $(LIBRARIES) -o $(CLIENT_NAME) $(CLIENT_OBJ)
	@echo "$(GREEN)$(CHECK)Compiled Client Successfully$(CHECK)$(RESET)"
	
$(BONUS_SERVER_NAME): $(LIBRARIES) $(BONUS_SERVER_OBJ)
	@cc $(CFLAGS) $(LIBRARIES) -o $(BONUS_SERVER_NAME) $(BONUS_SERVER_OBJ)
	@echo "$(GREEN)$(CHECK)Compiled Bonus Server Successfully$(CHECK)$(RESET)"

$(BONUS_CLIENT_NAME): $(LIBRARIES) $(BONUS_CLIENT_OBJ)
	@cc $(CFLAGS) $(LIBRARIES) -o $(BONUS_CLIENT_NAME) $(BONUS_CLIENT_OBJ)
	@echo "$(GREEN)$(CHECK)Compiled Bonus Client Successfully$(CHECK)$(RESET)"

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@make -C $(LIBRARIES_PATH) clean
	@$(RM) $(SERVER_OBJ) $(CLIENT_OBJ) $(BONUS_SERVER_OBJ) $(BONUS_CLIENT_OBJ)

fclean : clean
	@$(RM) $(SERVER_NAME) $(CLIENT_NAME) $(BONUS_SERVER_NAME) $(BONUS_CLIENT_NAME)
	@make fclean -C $(LIBRARIES_PATH)
	@echo "$(RED)$(BROOM)Cleaned Successfully$(RESET)$(BROOM)"

re : fclean all bonus

.PHONY: all clean fclean re bonus
