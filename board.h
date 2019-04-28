# ifndef BOARD_H
# define BOARD_H

# define MAP_X 8
# define MAP_Y 8

#include "tile.h"

struct board {
  tile map[MAP_Y][MAP_X]; /* Default 8x8 */
};

void gen_board(board *b);
void get_mines(board *b, uint32_t num_mines);

//uint32_t num_mines

# endif
