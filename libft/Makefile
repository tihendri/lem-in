# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tihendri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/05 14:09:03 by tihendri          #+#    #+#              #
#    Updated: 2019/09/05 18:03:31 by tihendri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= libft.a

# ar is an archiver that maintains groups of files as a single archive file
AR		= ar

CC 		= gcc

CFLAGS	= -Wall -Wextra -Werror

PART1	= Part_1/ft_memset.c Part_1/ft_bzero.c Part_1/ft_memcpy.c \
		  Part_1/ft_memccpy.c Part_1/ft_memmove.c Part_1/ft_memchr.c \
		  Part_1/ft_memcmp.c Part_1/ft_strlen.c Part_1/ft_strdup.c \
		  Part_1/ft_strcpy.c Part_1/ft_strncpy.c Part_1/ft_strcat.c \
		  Part_1/ft_strncat.c Part_1/ft_strlcat.c Part_1/ft_strchr.c \
		  Part_1/ft_strrchr.c Part_1/ft_strstr.c Part_1/ft_strnstr.c \
		  Part_1/ft_strcmp.c Part_1/ft_strncmp.c Part_1/ft_atoi.c \
		  Part_1/ft_isalpha.c Part_1/ft_isdigit.c Part_1/ft_isalnum.c \
		  Part_1/ft_isascii.c Part_1/ft_isprint.c Part_1/ft_toupper.c \
		  Part_1/ft_tolower.c

PART2	= Part_2/ft_memalloc.c Part_2/ft_memdel.c Part_2/ft_strnew.c \
		  Part_2/ft_strdel.c Part_2/ft_strclr.c Part_2/ft_striter.c \
		  Part_2/ft_striteri.c Part_2/ft_strmap.c Part_2/ft_strmapi.c \
		  Part_2/ft_strequ.c Part_2/ft_strnequ.c Part_2/ft_strsub.c \
		  Part_2/ft_strjoin.c Part_2/ft_strtrim.c Part_2/ft_strsplit.c \
		  Part_2/ft_itoa.c Part_2/ft_putchar.c Part_2/ft_putstr.c \
		  Part_2/ft_putendl.c Part_2/ft_putnbr.c Part_2/ft_putchar_fd.c \
		  Part_2/ft_putstr_fd.c Part_2/ft_putendl_fd.c Part_2/ft_putnbr_fd.c

BONUS	= Bonus/ft_lstadd.c Bonus/ft_lstnew.c Bonus/ft_lstdelone.c \
		  Bonus/ft_lstdel.c Bonus/ft_lstiter.c Bonus/ft_lstmap.c \
		  Bonus/ft_lstaddtail.c Bonus/ft_lstnew_str.c

EXTRA	= Extra/ft_wordcount.c Extra/ft_strndup.c Extra/ft_realloc.c \
		  Extra/ft_count_letters.c Extra/ft_iswhitespace.c \
		  Extra/ft_atol.c Extra/ft_free_str.c

GNL		= GNL/get_next_line.c

FILES 	= $(PART1) $(PART2) $(BONUS) $(EXTRA) $(GNL)

SRC		= $(FILES)
OBJ 	= $(FILES:.c=.o)

.PHONY: all clean fclean re
# .PHONY is used to protect the command recipes assigned to it
# in case there's a file with that name

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) rcs $(NAME) $(OBJ)
# here we are creating/modifying an archive by calling $(AR)
# rcs: Replace, Create, Sort
# https://www.mkssoftware.com/docs/man1/ar.1.asp

clean:
	@/bin/rm -rf $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
