# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dliu <dliu@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/27 17:13:11 by dliu          #+#    #+#                  #
#    Updated: 2023/02/20 14:08:48 by dliu          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = test
CC = gcc
CFLAGS = #-Wall -Werror -Wextra
SRCS = other.c
LIBDIR = ..
HEADERS = -I $(LIBDIR)/include
LIBFT = $(LIBDIR)/libft.a

.PHONY = all clean fclean re 

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBDIR)

$(NAME): $(SRCS) $(LIBFT)
	$(CC) $(CFLAGS) $(HEADERS) $(LIBFT) $^ -fsanitize=address -g -o $@

clean:
	$(MAKE) clean -C $(LIBDIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBDIR)

re: fclean all