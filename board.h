# ifndef BOARD_H
# define BOARD_H

# define MAP_X 16
# define MAP_Y 16 
#include "tile.h"

class board {

  public:
    tile map[MAP_X][MAP_Y];
    selector sel;
    uint32_t m_num[MAP_X][MAP_Y] = {0};
};


void gen_board(board *b, uint32_t num_mines);
void get_mines(board *b, uint32_t num_mines);
void gen_selector(board *b);
//uint32_t num_mines

# endif
