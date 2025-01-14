SCRS	=	ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_printf.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_utoa.c

ifeq ($(BONUS), 1)
	SCRS += $(SRCS_BON)
endif

DIR_OBJ = obj/

OBJS = $(addprefix $(DIR_OBJ), $(SCRS:.c=.o))

OBJS_BON = $(addprefix $(DIR_OBJ), $(SCRS_BON:.c=.o))

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
# SAN = -fsanitize=address,bounds,undefined -g3

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

$(DIR_OBJ)%.o : %.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -c -o $@ $<

bonus:
	@$(MAKE) BONUS=1 --no-print-directory

clean:
			rm -frd $(DIR_OBJ)

fclean:		clean
			rm -f a.out *.txt $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus
