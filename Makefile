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
	$(MAKE) -C libft/
	$(CC) $(CFLAGS) $(LIB) $(SRC) -o $(NAME) $(AMULTI)

debug:
	$(MAKE) -C libft/
	$(CC) $(DFLAGS) $(LIB) $(SRC) -o $(DNAME)

dclean:
	rm -rf $(DNAME) $(DNAME).dSYM/

clean:
	make clean -C ./libft/
	rm -f $(OBJ)

fclean:
	make fclean -C ./libft/
	rm -f $(NAME)

re: fclean all
