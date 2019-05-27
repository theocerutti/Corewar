##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile -- project
##

SRC 		= 	main.c \
				src/op.c \
				src/error.c \
				src/add/add.c \
				src/aff/aff.c \
				src/and/and.c \
				src/utility.c \
				src/fork_vm/fork_vm.c \
				src/ld/ld.c \
				src/ldi/ldi.c \
				src/lfork/lfork.c \
				src/live/live.c \
				src/lld/lld.c \
				src/lldi/lldi.c \
				src/or/or.c \
				src/st/st.c \
				src/sti/sti.c \
				src/sub/sub.c \
				src/xor/xor.c \
				src/zjmp/zjmp.c \
				src/get_player/get_all.c \
				src/condition/check_continue.c \
				src/dump/dump_memory.c \
				src/error/error_get.c \
				src/get_player/read_cor.c \
				src/coding_byte/param.c \
				src/carry/modify_carry.c \
				src/and/utils.c \
				src/ldi/utils.c \

OBJ		=	$(SRC:.c=.o)

NAME 		=	corewar

RM 		=	rm -f

RM_TRASH=	*.o *~ *.gcno *.gcda libmy.a *.gch *.out *.data

CFLAGS	= 	-Wall -Wextra -W -g -I ./include

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib && gcc $(OBJ) -o $(NAME) -L lib -lall $(CFLAGS)

clean:
	$(RM) $(OBJ)
	make clean -C lib

fclean: clean
	$(RM) $(NAME)
	make fclean -C lib

re: fclean all
