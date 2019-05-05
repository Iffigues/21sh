# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/01 14:39:20 by bordenoy          #+#    #+#              #
#    Updated: 2019/05/05 17:05:26 by bordenoy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=21sh

INCLUDE=-I include

CC=gcc -c -Wall -Wextra -Werror -g
GO=gcc -o 

SRC=main.c
ENV=ft_env.c ft_envs.c
PROMPT=ft_prompt.c ft_type.c ft_action.c
INIT=ft_init.c
SIGN=ft_signaux.c

SRCS=$(addprefix src/, $(SRC))
EE=$(addprefix builtin/env/, $(ENV))
PROMPTS=$(addprefix prompt/, $(PROMPT))
INITS=$(addprefix init/, $(INIT))
SIGNS=$(addprefix signaux/, $(SIGN));

OBJ=$(SRC:.c=.o)
ENVS=$(ENV:.c=.o)
PRON=$(PROMPT:.c=.o)
INI=$(INIT:.c=.o)
SIG=$(SIGN:.c=.o)

all:$(NAME)

$(NAME):
	make -C libft/
	$(CC)  $(INCLUDE) $(SRCS) $(EE) $(PROMPTS) $(INITS) $(SIGNS)
	$(GO) $(NAME) -L libft/  -lft  -ltermcap  $(OBJ) $(ENVS) $(PRON) $(INI) $(SIG)
%.o:%.c
		$(CC) $(INCLUDE) -c $< 
clean:
		rm -f *.o
		@make clean -C  libft/
fclean:clean
		rm -f $(NAME)
		make fclean -C libft/
re:fclean all
.PHONY:all clean fclean re
