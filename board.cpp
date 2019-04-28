# include <iostream>
# include <stdlib.h>
# include <cstring>

# include "board.h"

class board;

void gen_board(board *b) 
{
  uint32_t i, j;
  for(i = 0; i < MAP_Y; i++) {
    for(j = 0; j < MAP_X; j++) {
      map[i][j] = 'b';
      std::cout << map[i][j] << std::endl;
    }

    printf("\n");
  }
}

