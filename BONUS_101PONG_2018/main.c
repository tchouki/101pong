/*
** EPITECH PROJECT, 2018
** SOKOBAN
** File description:
** main.c
*/

#include "../include/my.h"

void map_print(game_t game)
{
	start_color();

	init_pair(1, COLOR_BLACK, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_GREEN);
	init_pair(3, COLOR_RED, COLOR_RED);
	init_pair(4, COLOR_WHITE, COLOR_WHITE);
	init_pair(5, COLOR_WHITE, COLOR_BLACK);
	for (int i = 19; i >= 0; i--) {
		for (int j = 0; j < 80; j++) {
			if (game.map[i][j] == ' ') {
				attron(COLOR_PAIR(1));
				printw(" ");
			}
			if (game.map[i][j] == '#') {
				attron(COLOR_PAIR(2));
				printw("#");
			}
			if (game.map[i][j] == 'O') {
				attron(COLOR_PAIR(3));
				printw("O");
			}
			if (game.map[i][j] == 'X') {
				attron(COLOR_PAIR(4));
				printw("X");
			}
		}
		printw("\n");
	}
}

game_t move_left(game_t game)
{
	game.map[game.pos_x][game.pos_y + 9] = ' ';
	game.pos_y--;
	game.map[game.pos_x][game.pos_y - 9] = 'X';
	return (game);
}

game_t move_right(game_t game)
{
	game.map[game.pos_x][game.pos_y - 9] = ' ';
	game.pos_y++;
	game.map[game.pos_x][game.pos_y + 9] = 'X';
	return (game);
}

game_t move_balle_line(game_t game)
{
	if (game.balle_fall == 1) {
		game.map[game.balle_x][game.balle_y] = ' ';
		game.balle_x--;
		game.map[game.balle_x][game.balle_y] = 'O';
	}
	if (game.balle_fall == 0) {
		game.map[game.balle_x][game.balle_y] = ' ';
		game.balle_x++;
		game.map[game.balle_x][game.balle_y] = 'O';
	}
	return (game);
}

game_t move_balle_diago_right(game_t game)
{
	if (game.balle_diago_right == 1) {
		game.map[game.balle_x][game.balle_y] = ' ';
		game.balle_y--;
		game.map[game.balle_x][game.balle_y] = 'O';
	}
	return (game);
}

game_t move_balle_diago_left(game_t game)
{
	if (game.balle_diago_left == 1) {
		game.map[game.balle_x][game.balle_y] = ' ';
		game.balle_y++;
		game.map[game.balle_x][game.balle_y] = 'O';
	}
	return (game);
}

game_t check_angle(game_t game)
{
	if (game.balle_x == game.pos_x + 1)
		game.balle_fall = 0;
	else if (game.balle_x == game.pos_x + 15)
		game.balle_fall = 1;
	if (game.balle_x == game.pos_x + 1 && game.balle_y > game.pos_y) {
		game.balle_diago_right = 0;
		game.balle_diago_left = 1;
	}
	else if (game.balle_x == game.pos_x + 1 && game.balle_y < game.pos_y) {
		game.balle_diago_left = 0;
		game.balle_diago_right = 1;
	}
	else if (game.balle_x == game.pos_x + 1 && game.balle_y == game.pos_y) {
		game.balle_diago_right = 0;
		game.balle_diago_left = 0;
	}
	else if (game.balle_y == 79 && game.balle_diago_left == 1) {
		game.balle_diago_right = 1;
		game.balle_diago_left = 0;
	}
	else if (game.balle_y == 1 && game.balle_diago_right == 1) {
		game.balle_diago_left = 1;
		game.balle_diago_right = 0;
	}
	return (game);
}

game_t check_score(game_t game)
{
	game.score = 0;

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 80; j++) {
			if (game.map[i][j] == '#')
				game.score++;
		}
	}
	return (game);
}

void display_tab(WINDOW *win)
{
	game_t game;
	int c;
	game.map = malloc(20 * sizeof(char*));
	for (int i = 0; i < 20; i++)
		game.map[i] = malloc(sizeof(char) * 80);
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 80; j++) {
			game.map[i][j] = ' ';
		}
	}
	game.map[0][40] = 'X';
	game.map[0][41] = 'X';
	game.map[0][42] = 'X';
	game.map[0][39] = 'X';
	game.map[0][38] = 'X';
	game.map[0][43] = 'X';
	game.map[0][37] = 'X';
	game.map[0][44] = 'X';
	game.map[0][45] = 'X';
	game.map[0][36] = 'X';
	game.map[0][35] = 'X';
	game.map[0][46] = 'X';
	game.map[0][47] = 'X';
	game.map[0][34] = 'X';
	game.map[0][33] = 'X';
	game.map[0][48] = 'X';
	game.map[0][49] = 'X';
	game.map[0][32] = 'X';
	game.map[0][31] = 'X';

	game.map[13][2] = '#';
	game.map[13][3] = '#';
	game.map[13][4] = '#';
	game.map[13][12] = '#';
	game.map[13][13] = '#';
	game.map[13][14] = '#';
	game.map[13][22] = '#';
	game.map[13][23] = '#';
	game.map[13][24] = '#';
	game.map[13][32] = '#';
	game.map[13][33] = '#';
	game.map[13][34] = '#';
	game.map[13][42] = '#';
	game.map[13][43] = '#';
	game.map[13][44] = '#';
	game.map[13][52] = '#';
	game.map[13][53] = '#';
	game.map[13][54] = '#';
	game.map[13][62] = '#';
	game.map[13][63] = '#';
	game.map[13][64] = '#';
	game.map[13][72] = '#';
	game.map[13][73] = '#';
	game.map[13][74] = '#';

	game.score = 24;

	game.map[10][40] = 'O';
	game.balle_x = 10;
	game.balle_y = 40;
	game.balle_fall = 1;
	game.balle_diago_right = 0;
	game.balle_diago_left = 0;

	game.pos_x = 0;
	game.pos_y = 40;
	curs_set(0);
	while (c != ' ' && game.score != 0) {
		attron(COLOR_PAIR(5));
		printw("LE SCORE EST : %d", 24 - game.score);
		map_print(game);
		game = move_balle_line(game);
		game = move_balle_diago_left(game);
		game = move_balle_diago_right(game);
		game = check_angle(game);
		game = check_score(game);
		refresh();
		clear();
		c = wgetch(win);
		if (c == KEY_LEFT && game.pos_y > 9)
			game = move_left(game);
		if (c == KEY_RIGHT && game.pos_y < 70)
			game = move_right(game);
	}
}

int main(int argc, char *argv[])
{
	WINDOW *win;

	initscr();
	clear();
	noecho();
	cbreak();
	win = newwin(HEIGHT, WIDTH, (24 - HEIGHT) / 2, (80 - WIDTH) / 2);
	wtimeout(win, 100);
	keypad(win, TRUE);
	refresh();
	display_tab(win);
	endwin();
	return (0);

}