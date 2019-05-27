##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile -- project
##

SRC 	= 	main.c \
			src/op.c \
			src/fill_file_assembly.c \
			src/exec_utils.c \
			src/parser.c \
			src/tokenizer.c \
			src/converter.c \
			src/linked_list.c \
			src/header/convert_header.c \
			src/header/convert_header_utils.c \
			src/writer/write_param.c \
			src/writer/write_utils.c \
			src/writer/writer_code_byte.c \
			src/writer/writer.c \
			src/check_error_assembly/check_error_assembly.c \
			src/check_error_assembly/check_error_assembly_utils.c \
			src/check_error_assembly/check_arg_type.c \
			src/check_error_assembly/line_clearing.c \
			src/check_error_assembly/line_clearing_utils.c \
			src/check_error_assembly/get_inst.c \
			src/prog_size_flag_pos/get_prog_size_and_flag_pos.c \
			src/prog_size_flag_pos/get_prog_size_utils.c \


OBJ		=	$(SRC:.c=.o)

NAME 	=	asm

RM 		=	rm -f

RM_TRASH=	*.o *~ *.gcno *.gcda libmy.a *.gch *.out *.data

CFLAGS	= 	-Wall -Wextra -W -g -I ./include -Wno-incompatible-pointer-types

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib && gcc $(OBJ) -o $(NAME) -L lib -lall $(CFLAGS)

unitest:
	./unitest.sh

clean:
	make clean -C lib
	$(RM) $(RM_TRASH) $(OBJ)

fclean: clean
	make fclean -C lib
	$(RM) $(NAME)

re: fclean all
