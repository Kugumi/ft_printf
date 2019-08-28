C = clang

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror -c -O2

LIBFT = libft

DIR_S = .

DIR_O = temporary

HEADER = ft_printf.h

TEST = main.c

SOURCES = ft_cspec.c ft_itoa_base.c ft_fillta.c ft_printf.c ft_flag.c \
ft_flags.c ft_flagsproc.c ft_procspec.c

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

test:
	gcc $(TEST) $(NAME)	-I $(HEADER)
