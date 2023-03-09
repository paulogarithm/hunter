##
## EPITECH PROJECT, 2022
## hunter_final
## File description:
## Makefile
##

CC			= gcc

LIB			= lib/my_chartostr.c\
			lib/my_comparestr.c\
			lib/my_countnb.c\
			lib/my_countstr.c\
			lib/my_showchar.c\
			lib/my_showstr.c\
			lib/my_strcat.c\
			lib/my_strdup.c\
			lib/my_strtonb.c\

SRC			= src/game_clock.c\
			src/game_clockobj.c\
			src/game_convert.c\
			src/game_event.c\
			src/game_levels.c\
			src/game_loop.c\
			src/game_mouse.c\
			src/game_music.c\
			src/game_object.c\
			src/game_renderobj.c\
			src/game_usefull.c\
			src/game_instance.c\
			src/game_attack.c\
			src/game_end.c\
			src/game_clear.c\

CFLAGS		= -W -Wall -Wextra

INCLUDE		= -lcsfml-graphics -lcsfml-audio -lcsfml-system

LIBNAME		= libhunter.a

SRCNAME		= my_hunter

RM    		= rm -f

LIBOBJ		= $(LIB:.c=.o)

SRCOBJ		= $(SRC:.c=.o)

MAIN		= src/main.c


all: build

build: $(LIBOBJ) $(SRCOBJ)
	ar rc $(LIBNAME) $(LIBOBJ) $(SRCOBJ)
	gcc $(CFLAGS) $(MAIN) -o $(SRCNAME) -L. -lhunter $(INCLUDE)

clean:
	rm -f $(LIBOBJ) $(SRCOBJ)
	$(RM) *.c~
	$(RM) $(LIBNAME)

fclean: clean
	$(RM) $(SRCNAME)

re: fclean all
	make clean
