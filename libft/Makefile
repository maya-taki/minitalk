# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/22 13:33:20 by mtakiyos          #+#    #+#              #
#    Updated: 2025/11/07 18:33:09 by mtakiyos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

INCLUDE = include/

SRCS	= ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_strjoin.c \
	ft_striteri.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_printhex.c \
	ft_printuns.c \
	ft_putchar.c \
	ft_putnbr.c \
	ft_putstr.c \
	ft_printptr.c \
	ft_printf.c 

FLAGS = -I$(INCLUDE) -Wall -Werror -Wextra

OBJS =	$(SRCS:.c=.o)

RM = rm -f

# colors #

END = \033[0m
RED = \033[31m
GREEN = \033[32m

${NAME}: ${OBJS}
	ar rcs $@ $^

%.o:%.c
	@printf "$(GREEN)[Compiling]$(END) %s$(END)\n" "$(notdir $(<))"
	@cc ${FLAGS} -c $^ -o $@

all:	$(NAME)

clean:
	@printf "$(RED)[Removing files]$(END) %s$(END)\n" "$(notdir $(<))"
	@$(RM) $(OBJS)

fclean:	clean
	@$(RM) ${NAME}

re:	fclean all

.PHONY:	all	fclean	clean	re