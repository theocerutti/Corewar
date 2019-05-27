##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## makefile my_printf Antoine MAILLARD
##

SRC = main.c print.c coma_print.c coma_print2.c compt.c flagzero.c \
flagzero2.c basics.c

OBJ = $(SRC:.c=.o)

CFLAGS = -W -Wall -Werror -Wextra

all: libmy.a

libmy.a: $(OBJ)
	ar rc libcnt.a $(OBJ)

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf libmy.a

re: clean fclean all
