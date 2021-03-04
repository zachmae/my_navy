##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

# ///// C variable /////

CFLAGS	+=	-Werror -Wextra -I./include

# ///// Path /////

IDIR	=	include

SDIR	=	sources

TDIR	=	tests

# ///// SRC /////

SRC		=	$(SDIR)/maps/blank_map.c\
			$(SDIR)/maps/printmap.c\
			$(SDIR)/maps/position_file.c\
			$(SDIR)/player1.c \
			$(SDIR)/sig_handler.c \
			$(SDIR)/player2.c\
			$(SDIR)/error_check/check_args.c\
			$(SDIR)/error_check/pos_check.c\
			$(SDIR)/game/game.c\
			$(SDIR)/game/attack.c

MAIN	=	$(SDIR)/main.c

OBJ		=	$(SRC:.c=.o) \
			$(MAIN:.c=.o)

# ///// Other var /////

NAME	=	navy

LIBFLAG	=	-L./sources/lib -lmy


# ///// Rules /////

all: lib_include $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LIBFLAG)

lib_include:
	@make -C $(SDIR)/lib/my
	@make -C $(SDIR)/lib/my clean
	@mkdir -p $(IDIR)
	@cp $(SDIR)/$(IDIR)/* $(IDIR)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: lib_include fclean $(NAME)

tests_run:
