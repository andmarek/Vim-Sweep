#include <stdio.h>
#include <iostream>

#include "board.h"
#include "io.h"
#include <time.h>


int main(int argc, char** argv) {
  srand(time(NULL));
  char in;
//  uint32_t num_mines;
    board *bo = (board *) malloc(sizeof(board));

  std::cout << "1 for easy, 2 for medium, 3 for hard" << std::endl;
  std::cin >> in;

  if(in == '1') {

    bo->num_mines = 5;
  }
  else if(in == '2') {

    bo->num_mines = 8;
  }
  else {

    bo->num_mines = 10;
  }
  printf("%d", bo->num_mines);
  gen_board(bo, bo->num_mines);
  gen_selector(bo);

  init_curses();

  print_map_w_m(bo);

  while(!bo->eog) {
    move_selector(bo);
  }

  if(bo->eog && bo->flag_m == bo->num_mines) {
    printf("\nYou win!\n");
    return 0;
  }

  free(bo);

  return 0;

}
