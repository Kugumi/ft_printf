# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/20 15:31:55 by kdeloise          #+#    #+#              #
#    Updated: 2019/09/20 15:31:59 by kdeloise         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = clang

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror -c -O2

LIBFT = libft

DIR_S = .

DIR_O = temporary

HEADER = ft_printf.h

SOURCES = ft_cspec.c ft_itoa_base.c ft_fillta.c ft_printf.c ft_flag.c \
ft_flags.c ft_flagsproc.c ft_procspec.c ft_xoxspec.c ft_uspec.c \
ft_color.c ft_rspec.c dtoa.c ft_fspec.c ft_fflag.c ft_flag2.c ft_flags2.c \
ft_fflag2.c ft_flag3.c ft_procspec2.c ft_rspec2.c ft_lennbrdiuxox.c \
ft_flags3.c ft_pricont.c ft_pricont2.c ft_dispec.c ft_lastlenfl.c ft_lnh.c \

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p temporary
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all
