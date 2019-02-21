##
## EPITECH PROJECT, 2018
## makefile
## File description:
## compilation
##

SRC =     	main.c

OBJ =   $(SRC:.c=.o)

NAME =  101pong

RM = rm -f -r

all:    $(NAME)

$(NAME):    $(OBJ)
		gcc -g $(OBJ) -o $(NAME) -lm
		rm -f $(OBJ)
clean:
	@$(RM) *~
	@$(RM) *.o
	@printf "Les fichiers ~ et .o ont été supprimé\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "Le fichier cat a été supprimé\n"

re: fclean all
