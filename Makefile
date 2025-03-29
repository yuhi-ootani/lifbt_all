# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knemcova <knemcova@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/26 13:46:22 by oyuhi             #+#    #+#              #
#    Updated: 2025/03/29 15:34:18 by knemcova         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -fPIC

#r: Add or replace object files in the archive.
#c: Create the archive if it doesn’t already exist.
#s: Create an index of symbols to speed up linking.
ARS = ar rcs



SRCS = ft_atoi.c ft_array_count_str.c ft_bzero.c ft_calloc.c ft_isspace.c ft_isnumber.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
		ft_isprint.c ft_itoa.c ft_fprintf.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
		ft_putchar_fd.c ft_putendl_fd.c ft_putendl.c ft_putnbr_fd.c ft_putstr_fd.c ft_realloc.c ft_split.c ft_strchr.c \
		ft_strdup.c ft_strndup.c ft_striteri.c ft_strjoin_three.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
		ft_strncmp.c ft_strcmp.c ft_strncpy.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
		ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
		ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c \
		ft_lstnew.c ft_lstsize.c \
		ft_get_next_line.c ft_get_next_line_utils.c \
		ft_printf.c ft_printf_utils.c \
		ft_array_dup.c ft_array_free.c ft_error.c ft_strlen_newline.c \
		ft_array_join.c \
		

OBJ_DIR = objs
OBJS = $(SRCS:.c=.o)
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

all: $(NAME) 

$(NAME): $(OBJS)
	@echo "🔧 Building libft..."
	@$(ARS) $(NAME) $(OBJS)
	
# Compile each .c file into its corresponding .o file.
# %: matches any string (used for pattern matching).
# $<: the first dependency (source .c file).
# $@: the target file (.o file to be created).
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	@rm -f $(OBJS) 
	@echo "🧹 Cleaning libft objects..."

fclean: clean
	@rm -f $(NAME)
	@rm -fd $(OBJ_DIR)
	@echo "🧹 Removing libft.a..."

re: fclean all


.PHONY: all bonus clean fclean re