##
## EPITECH PROJECT, 2021
## B-ASM-400-NAN-4-1-asmminilibc-victor.trencic [WSL: Ubuntu]
## File description:
## Makefile
##

SRC		=	sources/strlen.asm		\
			sources/strchr.asm		\
			sources/memset.asm		\
			sources/memcpy.asm		\
			sources/strcmp.asm		\
			sources/memmove.asm		\
			sources/strncmp.asm		\
			sources/strcasecmp.asm	\
			sources/rindex.asm		\
			sources/strstr.asm		\
			sources/strpbrk.asm		\
			sources/strcspn.asm

OBJ		=	$(SRC:%.asm=%.o)

TESTS	=	tests/init_criterion.c	\
			tests/tests_strlen.c	\
			tests/tests_strchr.c	\
			tests/tests_memset.c	\
			tests/tests_memcpy.c	\
			tests/tests_strcmp.c	\
			tests/tests_memmove.c	\
			tests/tests_strncmp.c	\
			tests/tests_strcasecmp.c\
			tests/tests_rindex.c	\
			tests/tests_strstr.c	\
			tests/tests_strpbrk.c	\
			tests/tests_strcspn.c

TESTSOBJ=	$(TESTS:%.c=%.o)

NAME	=	libasm.so

AS		=	nasm

ASFLAGS	=	-f elf64

LD		=	ld

LDFLAGS	=	-shared

CC		=	gcc

INCLUDE	=	-I include/

CFLAGS	=	-W -Wall -Wextra -Wshadow $(INCLUDE)

COVERAGE=	--coverage -lcriterion -ldl

all: $(NAME)

%.o:	%.asm
	$(AS) $(ASFLAGS) -o $@ $<

$(NAME): $(OBJ)
	$(LD) $(LDFLAGS) -o $(NAME) $(OBJ)

dbg: ASFLAGS += -g
dbg: re

tests_run: all $(TESTSOBJ)
	$(CC) -o unit_tests $(TESTSOBJ) $(COVERAGE) $(CFLAGS)
	./unit_tests

clean:
	$(RM) $(OBJ)
	$(RM) $(TESTSOBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) unit_tests
	$(RM) *.gc*

re: fclean all

.PHONY: re fclean clean all tests_run