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

NAME = libft.a

GCC = gcc

FLAGS = -Wall -Werror -Wextra

VERT=\033[32m
NORMAL=\033[0m
ROUGE=\x1b[31m

SRC_DOSS_PRTF = ./printflib/convs/
SRC_DOSS_LBFT = ./printflib/libft_fct/
SRC_DOSS_LIBFT = ./libft/

SRCS_PRTF = $(addprefix $(SRC_DOSS_PRTF),$(SRC_NAME_PRTF))
SRCS_LBFT = $(addprefix $(SRC_DOSS_LBFT),$(SRC_NAME_LBFT))
SRCS_LIBFT = $(addprefix $(SRC_DOSS_LIBFT),$(SRC_NAME_LIBFT))

OBJ_NAME_PRTF = $(SRC_NAME_PRTF:.c=.o)
OBJ_NAME_LBFT = $(SRC_NAME_LBFT:.c=.o)
OBJ_NAME_LIBFT = $(SRC_NAME_LIBFT:.c=.o)

SRC_NAME_PRTF = fct_princ.c ft_checker_nbr.c ft_checker_uint.c \
				ft_printchar.c ft_printf.c \
				ft_printhex.c ft_printnbr.c ft_printoct.c \
				ft_printstr.c ft_printunsint.c ft_printvoid_hex.c \
				ft_printwchar.c ft_printzero.c \
				ft_print_space_plus_minus.c ft_print_space_plus_minusnorm.c \
				ft_print_space_plus_minusv2.c ft_print_space_plus_minusnormv2.c \
				ft_checker_x.c ft_checker_x_maj.c ft_checker_o.c \
				affiche_hash_hex.c zero_hex.c zero_unsigned.c ft_print_isnoparam.c \
				ft_printwstr.c ft_flaginit.c ft_printoctbis.c ft_print_binaire.c \
				ft_checker_wstr.c ft_bonusn.c ft_checker_wchar.c \
				ft_test_unic.c \

SRC_NAME_LBFT = ft_atoi.c ft_isalpha.c ft_itoa.c ft_itoa_hhuint.c \
				ft_itoa_hnbr.c ft_itoa_llnbr.c ft_itoa_lluint.c \
				ft_itoa_lnbr.c ft_itoa_luint.c ft_itoabase.c ft_itoabasemaj.c \
				ft_itoaunsigned.c \
				ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putstr.c \
				ft_putstr_fd.c ft_putwstr.c ft_putwstr_fd.c ft_putwtchar.c \
				ft_putwtchar_fd.c ft_strdup.c ft_strlen.c ft_strnew.c \
				ft_strsub.c ft_itoa_hhnbr.c ft_itoa_huint.c ft_putstr_n.c \
				ft_strcmp.c ft_itoabaseh.c ft_itoabasehh.c ft_itoabasel.c \
				ft_itoabasemajh.c ft_itoabasemajhh.c \
				ft_itoabasemajl.c ft_strcpy.c ft_isparam.c ft_itoaoctalhh.c \
				ft_itoaoctalh.c ft_itoaoctalll.c ft_isconv.c ft_putstr_len.c \
				ft_putnwstr.c \

SRC_NAME_LIBFT = ft_strcat.c ft_strncat.c \
				 ft_strlcat.c ft_strncpy.c ft_strchr.c ft_strrchr.c ft_strstr.c \
				 ft_strnstr.c ft_strncmp.c ft_isdigit.c \
				 ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
				 ft_bzero.c ft_memcpy.c ft_memccpy.c \
				 ft_memchr.c ft_memcmp.c ft_memmove.c ft_memalloc.c ft_memdel.c \
				 ft_putendl.c ft_putnbr.c ft_strclr.c ft_strdel.c \
				 ft_strequ.c ft_striter.c ft_striteri.c \
				 ft_strjoin.c ft_strmap.c ft_strmapi.c \
				 ft_strnequ.c ft_strsplit.c ft_strtrim.c ft_putendl_fd.c \
				 ft_putnbr_fd.c ft_div_mod.c ft_foreach.c ft_swap.c ft_range.c \
				 ft_sqrt.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c \
				 ft_lstiter.c ft_lstmap.c get_next_line.c \

all: $(NAME)

$(NAME): $(OBJ)
	@$(GCC) $(FLAGS) -c $(SRCS_PRTF) $(SRCS_LBFT) $(SRCS_LIBFT)
	@ar -rc $(NAME) $(OBJ_NAME_PRTF) $(OBJ_NAME_LBFT) $(OBJ_NAME_LIBFT)
	@ranlib $(NAME)
	@echo "$(VERT)LIBFT : Compilation terminee.\t\t$(NORMAL)"
	@mkdir TMP
	@mv $(OBJ_NAME_PRTF) $(OBJ_NAME_LBFT) $(OBJ_NAME_LIBFT) TMP

clean:
	@rm -rf TMP
	@echo "$(ROUGE)LIBFT : Suppression des objets\t\t$(NORMAL)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(ROUGE)LIBFT : Suppression du fichier--> libft.a\t\t$(NORMAL)"

re: fclean all
