#include <stdio.h>
#include <iostream>

#include "board.h"
#include "io.h"


int main(int argc, char** argv) {
  board *bo = (board *) malloc(sizeof(board));

  //uint32_t mines = 5;

  gen_board(bo);
  //get_mines(bo, mines);

  print_map_w_m(bo);


    return 0;

}
