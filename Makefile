# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xxxxxxxx <xxxxxxxx@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/17 11:21:32 by xxxxxxxx          #+#    #+#              #
#    Updated: 2020/12/10 18:25:00 by xxxxxxxx         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

DEB = deb

NAME = ft_ls

CC = gcc

LIB = ./libft/libft.a

FLAGS = -Wall -Werror -Wextra

VERT=\033[32m
NORMAL=\033[0m
ROUGE=\x1b[31m

SRC_DOSS_LS = ./fcts/

SRCS_LS = $(addprefix $(SRC_DOSS_LS),$(SRC_NAME_LS))

OBJ_LS = $(SRC_NAME_LS:.c=.o)

SRC_NAME_LS = check_errors.c fill_struct.c mess_error.c \
			  sort_lst2.c print_l.c fill_wid.c lst_fct.c \
			  ft_sortlst.c print_file_l.c free_lst.c ft_utils.c \
			  fill_doss_bis.c ft_print_dir.c ft_ls.c print_names.c \

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/ all
	@$(CC) $(FLAGS) -c $(SRCS_LS) $(SRC_NAME_TMP)
	@$(CC) $(FLAGS) $(LIB) $(SRCS_LS) -o $(NAME)
	@echo "$(VERT)FT_LS : Compilation terminee.\t\t$(NORMAL)"
	@mkdir TMP
	@mv $(OBJ_LS) TMP

clean:
	@make -C libft/ clean
	@rm -rf TMP
	@echo "$(ROUGE)FT_LS : Suppression des objets\t\t$(NORMAL)"

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)
	@echo "$(ROUGE)FT_LS : Suppression du fichier--> ./ft_ls\t\t$(NORMAL)"

re: fclean all
