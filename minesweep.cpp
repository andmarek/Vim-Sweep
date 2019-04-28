#include <stdio.h>
#include <iostream>

#include "board.h"

class board;
int main(int argc, char** argv) {

  board *b = (board *) malloc(sizeof(board));
  gen_board(b);

  return 0;
  
}
