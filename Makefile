##
## Makefile for rt in /root/projets/igraph/rt
## 
## Made by jalil dabbech
## Login   <dabbec_j@epitech.net>
## 
## Started on  Tue Oct 15 22:19:42 2013 jalil dabbech
## Last update Fri Oct 18 17:44:00 2013 jalil dabbech
##

NAME	=	rt

SRC	=	sources/main.c \
		sources/fill_mat_and_coord.c \
		sources/epur_str.c \
		sources/scene.c \
		sources/scene_bis.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

DEBUG	=	1

ifeq ($(DEBUG), 1)
  CFLAGS	+=	-W -Wall -Wextra -pedantic -ansi -Iincludes/ -I/usr/X11/include
else
  CFLAGS	+=	-Iincludes/ -I/usr/X11/include
endif

LIB_DIR	=	my

MK_LIB	=	@(cd $(LIB_DIR) && make)

MK_CLIB	=	@(cd $(LIB_DIR) && make clean)

MK_FLIB	=	@(cd $(LIB_DIR) && make fclean)

LDFLAGS	=	-L. -lmy -L/usr/X11/lib -lmlx -L/usr/lib64/X11 -lXext -lX11

RM	=	rm -f

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(MK_LIB)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean	:
		$(RM) $(OBJ)
		$(MK_CLIB)

fclean	:	clean
		$(RM) $(NAME)
		$(MK_FLIB)

re	:	fclean all

.PHONY	:	all clean fclean re
