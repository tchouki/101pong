/*
** EPITECH PROJECT, 2018
** SOKOBAN
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>
#include <math.h>

#define BUFFSIZE 9999
#define WIDTH 30
#define HEIGHT 10

typedef struct game {
	char **map;
	int pos_x;
	int pos_y;
	int balle_x;
	int balle_y;
	int balle_fall;
	int balle_diago_left;
	int balle_diago_right;
	int score;
} game_t;

#endif