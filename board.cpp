# include <iostream>
# include <stdlib.h>
# include <cstring>
# include <math.h>

# include "board.h"

class board;

void gen_board(board *b, uint32_t num_mines);
void get_mines(board *b, uint32_t num_mines);

void gen_selector(board *b)
{
  b->sel.pos[0] = 5;
  b->sel.pos[1] = 5;
}

void gen_board(board *b, uint32_t num_mines)
{
  uint32_t i, j;

  for(i = 0; i < MAP_Y; i++) {
    for(j = 0; j < MAP_X; j++) {
      b->map[i][j].symb = '#';
    }
  }
  get_mines(b, num_mines);
}

bool is_mine(board *b, uint32_t y, uint32_t x) {
  if(b->map[y][x].is_mine != 0) {
    return true;
  }
  return false;
}


void get_mines(board *b, uint32_t num_mines)
{

  uint32_t count = 1;

  while(count <= num_mines) {

    uint32_t mine_y, mine_x;

    mine_y = 1 + rand() % 16;
    mine_x = 1 + rand() % 16;

    b->map[mine_y][mine_x].is_mine = 2;
    /* north */
    if( (mine_y - 1 >= 0) && ((mine_x) >= 0)) {
      b->m_num[mine_y - 1][mine_x]++;
    }
    /* south */
    if( (mine_y + 1 >= 0) && ((mine_x) >= 0)) {
      b->m_num[mine_y + 1][mine_x]++;
    }
    /* east */
    if( ((mine_y) >= 0) && ((mine_x + 1) >= 0)) {
      b->m_num[mine_y][mine_x + 1]++;
    }
    /* west */
    if( ((mine_y) >= 0) && ((mine_x - 1) >= 0)) {
      b->m_num[mine_y][mine_x - 1]++;
    }
    /* south-east */
    if( ((mine_y + 1) >= 0) && ((mine_x + 1) >= 0)) {
      b->m_num[mine_y + 1][mine_x + 1]++;
    }
    /*south-west */
    if( ((mine_y + 1) >= 0) && ((mine_x - 1) >= 0)) {
      b->m_num[mine_y + 1][mine_x - 1]++;
    }
    /* north-east */
    if( (mine_y - 1 >= 0) && (mine_x + 1 >= 0)) {
      b->m_num[mine_y - 1][mine_x + 1]++;
    }
    /* north-west */ 
    if( ((mine_y - 1) >= 0) && ((mine_x - 1) >= 0)) {
      b->m_num[mine_y - 1][mine_x - 1]++;
    }

    count++;
  }

}



