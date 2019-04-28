#include <stdlib.h>
#include <iostream>
#include "board.h"

void print_map_w_m(board *b)
{
  printf("prin map w m was accessed \n");

  uint32_t i;
  uint32_t j;

  /*  char map[MAP_Y][MAP_X];   char mines[MAP_Y][MAP_X];*/
  printf("------\n");

  for(i = 0; i < 8; i++) {
    for(j = 0; j < 8; j++) {
      if(b->map[i][j].is_mine == 0 ) {
        printf("%c", b->map[i][j].symb);
      } else if (b->map[i][j].is_mine == 2) {
        printf("%c", 'M');
      }
    }
    printf("\n");

  }
}


