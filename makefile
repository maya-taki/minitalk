# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/20 19:39:17 by mtakiyos          #+#    #+#              #
#    Updated: 2025/11/09 14:24:06 by mtakiyos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server
LIBFT = ./libft/libft.a

SRC_SERVER = server.c
SRC_CLIENT = client.c 

OBJS_SERVER = $(SRC_SERVER:.c=.o)
OBJS_CLIENT = $(SRC_CLIENT:.c=.o)

INCLUDE = include/

FLAGS = -I$(INCLUDE) -Wall -Werror -Wextra
RM = rm -f

# COLORS

END = \033[0m
RED = \033[31m
GREEN = \033[32m

# BUILD


all: $(LIBFT) $(CLIENT) $(SERVER)

$(LIBFT):
	@$(MAKE) -C ./libft/

$(SERVER): $(OBJS_SERVER) $(LIBFT)
	@cc $(OBJS_SERVER) $(LIBFT) -o $@

$(CLIENT):$(OBJS_CLIENT) $(LIBFT)
	@cc $(OBJS_CLIENT) $(LIBFT) -o $@

%.o:%.c
	@printf "$(GREEN)[Compiling]$(END) %s$(END)\n" "$(notdir $(<))"
	@cc $(FLAGS) -c $< -o $@

# CLEAN

clean: 
	@printf "$(RED)[Removing .o files]$(END) %s$(END)\n" "$(notdir $(<))"
	@$(RM) $(OBJS_CLIENT) $(OBJS_SERVER)
	$(MAKE) -C ./libft clean

fclean:	clean
	@printf "$(RED)[Removing binaries and libft.a]$(END) %s$(END)\n" "$(notdir $(<))"
	@$(RM) $(CLIENT) $(SERVER)
	$(MAKE) -C ./libft fclean

re:	fclean all

.PHONY:	all	fclean	clean	re
