# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dliu <dliu@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/05 15:18:01 by dliu          #+#    #+#                  #
#    Updated: 2024/03/20 14:04:50 by dliu          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFLAGS = -Wall -Werror -Wextra
CC = gcc
HEADERS = -I ./include
VPATH = srcs/
SRCS = get_next_line.c \
ft_lstnew.c ft_lstadd.c ft_lstsize.c ft_lstlast.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
ft_printf.c ft_printf_helpers.c ft_printf_handle_types.c \
ft_printf_handle_flags.c ft_printf_handle_flags_nums.c \
ft_put_fd.c ft_put_strarray.c ft_is.c ft_converts.c \
ft_calloc.c ft_bzero.c ft_mem.c \
ft_strhelpers.c ft_strfinds.c ft_strmakers.c ft_strmanips.c ft_split.c ft_itoa.c \
ft_lltoa_base.c ft_ltoa_unsigned_base.c ft_atoi_validate.c ft_nums.c \
ft_split2.c ft_joinstrs.c ft_nopes.c ft_free.c
OBJDIR = obj/
OBJS := ${SRCS:%.c=$(OBJDIR)%.o}

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $@ $^

$(OBJDIR)%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all