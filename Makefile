##
## Makefile for  in /home/pinon_a/rendu/PSU_2013_malloc
## 
## Made by pinon
## Login   <pinon_a@epitech.net>
## 
## Started on  Mon Feb  3 15:40:11 2014 pinon
## Last update Wed Feb  5 18:02:47 2014 pinon
##

LIBNAME=	libmy_malloc_$(HOSTTYPE).so

LINKNAME=	libmy_malloc.so

SRC=		src/malloc.c		\
		src/free.c		\
		src/realloc.c		\
		src/get_block.c		\
		src/raise.c		\
		src/split_block.c	\

OBJ=		$(SRC:.c=.o)

CC=		cc

RM=		rm -f

CFLAGS=		-Wall		\
		-Werror		\
		-Wextra		\
		-ansi		\
		-pedantic	\
		-fPIC		\
		-I include

all:		$(LIBNAME)

$(LIBNAME):	$(OBJ)
		$(CC) -shared -o $(LIBNAME) $(OBJ) -lc
		ln -T -f $(LIBNAME) $(LINKNAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(LIBNAME) $(LINKNAME)

fclean_one:
		$(RM) $(LIBNAME) $(LINKNAME)

re:		fclean all

.PHONY:	all clean fclean re fclean_one
