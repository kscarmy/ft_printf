NAME = libftprintf.a

CC = gcc

LBF = libft/libft.a

CFLAGS = -Wall -Wextra -Werror

SRC_F = src/ft_printf.c\
	src/ft_printf_disp.c\

OBJS = ft_printf.o\
	ft_printf_disp.o\

F_SRC = src/

SRC_O = $(SRC_F:.c=.o)

INCLUDES = -I libft/ -I src/

all : $(NAME)

$(NAME) : libft_a
	@$(CC) $(CFLAGS) $(SRC_F) -c
	@ar rc $(NAME) $(OBJS) $(LBF)
	@ranlib $(NAME)
	@mv $(OBJS) $(F_SRC)

libft_a :
	@make -C libft

clean :
	@make -C libft clean
	@rm -rf $(SRC_O)

fclean : clean
	@make -C libft fclean
	@rm -rf $(NAME)

re : fclean all

comp : re
	$(CC) $(CFLAGS) $(NAME) main.c
