
SCRS	=	so_long.c

ifeq ($(BONUS), 1)
	SCRS += $(SRCS_BON)
endif

DIR_OBJ = obj/

OBJS = $(addprefix $(DIR_OBJ), $(SCRS:.c=.o))
# OBJS = $(SCRS:.c=.o)
OBJS_BON = $(addprefix $(DIR_OBJ), $(SCRS_BON:.c=.o))
# OBJS_BON = $(SCRS_BON:.c=.o)

NAME = so_long.a
LIBFT = libft/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
# SAN = -fsanitize=address,bounds,undefined -g3


all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar -rcs $(NAME) $(OBJS)

$(DIR_OBJ)%.o : %.c
	# @mkdir -p obj
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT):
	$(MAKE) -C libft

bonus:
	@$(MAKE) BONUS=1 --no-print-directory

clean:
			rm -frd $(DIR_OBJ)
			$(MAKE) clean -C libft

# clean:
# 			rm -frd $(OBJS)
# 			$(MAKE) clean -C libft

fclean:		clean
			rm -f a.out $(NAME)
			$(MAKE) fclean -C libft

re:			fclean all

.PHONY:		all clean fclean re bonus
