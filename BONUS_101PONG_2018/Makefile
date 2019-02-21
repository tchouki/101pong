##
## EPITECH PROJECT, 2018
## BSQ
## File description:
## compilation
##

SRC =       $(wildcard *.c)

OBJ =   $(SRC:.c=.o)

NAME =  101pong

RM = rm -f -r

CFLAGS += -I./include -lncurses

$(NAME):    $(OBJ)
		gcc $(OBJ) $(CFLAGS) -o $(NAME) -g
		rm -f $(OBJ)

all:    $(NAME)

clean:
	@$(RM) *~
	@$(RM) *.o
	@printf "Les fichiers ~ et .o ont été supprimé\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "Le fichier cat a été supprimé\n"

re: fclean all
