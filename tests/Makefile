# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dliu <dliu@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/27 17:13:11 by dliu          #+#    #+#                  #
#    Updated: 2023/01/20 16:57:16 by dliu          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = test
CC = gcc
CFLAGS = #-Wall -Werror -Wextra
SRCS = other.c
LIBDIR = ../
LIBFT = $(LIBDIR)/libft.a

.PHONY = all clean fclean re 

all: $(NAME)

$(NAME): $(SRCS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -fsanitize=address -g -o $@

$(LIBFT):
	$(MAKE) -C $(LIBDIR)

clean:
	$(MAKE) clean -C $(LIBDIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBDIR)

re: fclean all