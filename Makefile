##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile -- project
##

RM 		=	rm -f

RM_TRASH=	*.o *~ *.gcno *.gcda libmy.a *.gch *.out *.data

all:
	make -C asm/
	make -C corewar/

clean:
	make clean -C asm/
	make clean -C corewar/
	$(RM) $(RM_TRASH)

fclean: clean
	make fclean -C asm/
	make fclean -C corewar/
	$(RM) $(NAME)

re: fclean all
