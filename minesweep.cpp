#include <stdio.h>
#include <iostream>

#include "board.h"
#include "io.h"
#include <time.h>


int main(int argc, char** argv) {
  char in;
  uint32_t num_mines;
  srand(time(NULL));
  board *bo = (board *) malloc(sizeof(board));

  //uint32_t mines = 5;

  std::cout << "1 for easy, 2 for medium, 3 for hard" << std::endl;
  std::cin >> in;

  if(in == '1') {

    num_mines = 5;
  }
  else if(in == '2') {

    num_mines = 8;
  }
  else {

    num_mines = 10;
  }

  gen_board(bo, num_mines);
  gen_selector(bo);

  init_curses();

  print_map_w_m(bo);

  while(true) {

    move_selector(bo);

  }

  return 0;

}
