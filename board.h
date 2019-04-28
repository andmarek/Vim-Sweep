# ifndef BOARD_H
# define BOARD_H

# define MAP_X 8
# define MAP_Y 8

class board 
{
  public:
    board();
    char map[MAP_Y][MAP_X]; /* Default 8x8 */

};

void gen_board(board *b);

# endif
