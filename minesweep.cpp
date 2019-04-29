#include <stdio.h>
#include <iostream>
#include <ncurses.h>
#include "board.h"
#include "io.h"
#include <time.h>


int main(int argc, char** argv) {
  const char *vim =  
 "                 .                    "
 "   ##############..... ##############\n   "
 "   ##############......############## \n  "
 "     ##########..........##########   \n  "
 "     ##########........##########      \n "
 "     ##########.......##########       \n "
 "     ##########.....##########..       \n "
 "     ##########....##########.....     \n "
 "   ..##########..##########.........   \n "
 " ....##########.#########.............  \n"
 "   ..################JJJ............    \n"
 "     ################.............      \n"
 "     ##############.JJJ.JJJJJJJJJJ      \n"
 "     ############...JJ...JJ..JJ  JJ     \n"
 "     ##########....JJ...JJ..JJ  JJ      \n"
 "     ########......JJJ..JJJ JJJ JJJ     \n"
 "     ######    .........                \n"
 "                 .....                  \n"
". ";

  srand(time(NULL));
  char in;
  board *bo = (board *) malloc(sizeof(board));
  std::cout << "Enter your difficulty level: 1 (Easy), 2 (Medium), 3 (Hard)";
  std::cin >> in ;
  if(in == '1') {

    bo->num_mines = 10;
  }
  else if(in == '2') {

    bo->num_mines = 15;
  }
  else {

    bo->num_mines = 20;
  }
  printf("%d", bo->num_mines);
  gen_board(bo, bo->num_mines);
  gen_selector(bo);

  init_curses();
  uint32_t k;
  attron(COLOR_PAIR(COLOR_GREEN));
  mvprintw(1, 30, "%s", vim);
  attroff(COLOR_PAIR(COLOR_GREEN));
  mvprintw(0, 0, "Press P to play");
  while(true) {
  if((k = getch() == 'p')) {
    clear();
    refresh();
    break;
    } 

  }
  print_map_w_m(bo);

  while(!bo->eog) {
    move_selector(bo);
  }

  if(bo->eog && bo->flag_m == bo->num_mines) {
    printf("\nYou win!\n");
    return 0;
  }

  //free(bo);

  return 0;

}
