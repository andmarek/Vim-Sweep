# include <iostream>
# include <stdlib.h>
# include <cstring>
# include <math.h>

# include "board.h"

class board;

void gen_board(board *b);
void get_mines(board *b, uint32_t num_mines);

void gen_board(board *b)
{
  uint32_t i, j;
  for(i = 0; i < MAP_Y; i++) {
    for(j = 0; j < MAP_X; j++) {
      b->map[i][j].symb = '#';
      std::cout << b->map[i][j].symb;
    }

    printf("\n");
  }
  get_mines(b, 5);
}


void get_mines(board *b, uint32_t num_mines)
{
  printf("get mines was called \n");
  uint32_t count = 0;

  while(count <= num_mines) {
    uint32_t mine_y, mine_x;

    printf("mine created\n");
    mine_y = 1 + rand() % 8;
    mine_x = 1 + rand() % 8;

    b->map[mine_y][mine_x].is_mine = 2;
    count++;
  }

}

