##
## EPITECH PROJECT, 2023
## Assembly
## File description:
## Makefile
##

NAME	=	libasm.so

ASM		=	nasm

LD		=	ld

CFLAGS	=	-fPIC -shared

ASFLAGS	=	-f elf64

SRC	=	src/strlen.asm	\
		src/strchr.asm 	\
		src/strrchr.asm	\
		src/memset.asm	\
		src/memcpy.asm	\
		src/strcmp.asm	\
		src/strncmp.asm	\
		src/strcasecmp.asm	\
		src/strstr.asm		\
		src/strpbrk.asm 	\
		src/strcspn.asm		\
		src/memmove.asm		\

BIN_TEST = unit_tests

SRC_TEST =	tests/strlen_test.c	\
			tests/strchr_test.c	\
			tests/strrchr_test.c	\
			tests/strstr_test.c 	\
			tests/strcmp_test.c 	\
			tests/strncmp_test.c 	\
			tests/strpbrk_test.c 	\
			tests/strcspn_test.c 	\
			tests/memmove_test.c	\

OBJ_TEST = $(SRC_TEST:.c=.o)

OBJ	=	$(SRC:.asm=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(LD) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.asm
	$(ASM) $(ASFLAGS) -o $@ $<

unit_tests:
	gcc -o $(BIN_TEST) $(SRC_TEST) -lcriterion --coverage -ldl

tests_run: $(NAME) unit_tests
	./$(BIN_TEST)
	gcovr --exclude tests/
	gcovr --branches --exclude tests/

clean:
	$(RM) -f $(OBJ)
	$(RM) -f *.gcno *.gcda

fclean: clean
	$(RM) -f $(NAME)
	$(RM) -f $(BIN_TEST)

re:	fclean all

.PHONY: all $(NAME) clean fclean