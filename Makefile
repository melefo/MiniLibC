##
## EPITECH PROJECT, 2021
## B-ASM-400-NAN-4-1-asmminilibc-victor.trencic [WSL: Ubuntu]
## File description:
## Makefile
##

SRC		=	sources/strlen.asm	\
			sources/strchr.asm	\
			sources/memset.asm	\
			sources/memcpy.asm	\
			sources/strcmp.asm	\
			sources/memmove.asm	\
			sources/strncmp.asm

OBJ		=	$(SRC:%.asm=%.o)

NAME	=	libasm.so

AS		=	nasm

ASFLAGS	=	-f elf64

LD		=	ld

LDFLAGS	=	

all: $(NAME)

%.o:	%.asm
	$(AS) $(ASFLAGS) -o $@ $<

$(NAME): $(OBJ)
	$(LD) $(LDFLAGS) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re fclean clean all