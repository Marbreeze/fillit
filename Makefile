NAME	:= fillit
DNAME	:= d_$(NAME)
SRC		:= main.c \
			validation.c\
			extract_fig.c\
			map.c\
			solution.c

OBJ		:= $(SRC:.c=.o)

CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror
DFLAGS	:= -Wall -Wextra -g
AFLAGS	:= -fsanitize=address
AMULTI  := -lpthread
## Libraries
LIBFT = libft/libft.a
LIB = -I libft/ $(LIBFT)

.PHONY: all clean fclean re debug dclean libft mlx

all: $(NAME)

libft:
	make -sC libft/

$(NAME): 
	$(CC) $(CFLAGS) $(LIB) $(SRC) -o $(NAME) $(AMULTI)

debug:
	$(CC) $(DFLAGS) $(AFLAGS) $(LIB) $(SRC) -o $(DNAME)

dclean:
	rm -rf $(DNAME) $(DNAME).dSYM/

clean:
	rm -f $(OBJ)

fclean: 
	rm -f $(NAME)

re: fclean all
