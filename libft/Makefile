NAME = libft.a

SRC_F = ft_atoi.c\
		ft_bzero.c\
		ft_calloc.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_itoa.c\
		ft_memccpy.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memset.c\
		ft_putchar_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_putstr_fd.c\
		ft_split.c\
		ft_strchr.c\
		ft_strdup.c\
		ft_strjoin.c\
		ft_strlcat.c\
		ft_strlcpy.c\
		ft_strlen.c\
		ft_strmapi.c\
		ft_strncmp.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_strtrim.c\
		ft_substr.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_get_next_line.c\
		ft_get_next_line_utils.c\

SRC_C = src/ft_atoi.c\
		src/ft_bzero.c\
		src/ft_calloc.c\
		src/ft_isalnum.c\
		src/ft_isalpha.c\
		src/ft_isascii.c\
		src/ft_isdigit.c\
		src/ft_isprint.c\
		src/ft_itoa.c\
		src/ft_memccpy.c\
		src/ft_memchr.c\
		src/ft_memcmp.c\
		src/ft_memcpy.c\
		src/ft_memmove.c\
		src/ft_memset.c\
		src/ft_putchar_fd.c\
		src/ft_putendl_fd.c\
		src/ft_putnbr_fd.c\
		src/ft_putstr_fd.c\
		src/ft_split.c\
		src/ft_strchr.c\
		src/ft_strdup.c\
		src/ft_strjoin.c\
		src/ft_strlcat.c\
		src/ft_strlcpy.c\
		src/ft_strlen.c\
		src/ft_strmapi.c\
		src/ft_strncmp.c\
		src/ft_strnstr.c\
		src/ft_strrchr.c\
		src/ft_strtrim.c\
		src/ft_substr.c\
		src/ft_tolower.c\
		src/ft_toupper.c\
		src/ft_get_next_line.c\
		src/ft_get_next_line_utils.c\


SRC_O = $(SRC_F:.c=.o)

SRC_MO = $(SRC_C:.c=.o)

SRC_FILES = src/

$(NAME):
	@gcc -Wall -Werror -Wextra -c $(SRC_C)
	@ar rc $(NAME) $(SRC_O)
	@ranlib $(NAME)
	@mv $(SRC_O) $(SRC_FILES)

all: $(NAME)

clean:
	@rm -rf $(SRC_MO)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
