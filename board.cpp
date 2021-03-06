#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <math.h>
#include <ncurses.h>

#include "io.h"
#include "board.h"

#define TRUE 1
#define FALSE 0

class board;

void get_selector(board *b);
void gen_board(board *b, uint32_t num_mines);
bool is_mine(board *b, uint32_t y, uint32_t x);
void get_mines(board *b, uint32_t num_mines);
void reveal_tile(board *b, uint32_t y, uint32_t x, uint32_t count);

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
  if(b->map[y][x].is_mine != FALSE) {
    return true;
  }
  return false;
}


void get_mines(board *b, uint32_t num_mines)
{
  uint32_t count = 1;

  while(count < num_mines) {
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

void reveal_tile(board *b, uint32_t y, uint32_t x, uint32_t count)
{
  if(count % 2 == 0) {
    return;
  }
  if (y < 0 || y >= MAP_Y) {
    return;
  }
  if( x < 0 || x >= MAP_X) {
    return;
  }
  if(b->map[y][x].revealed != FALSE && b->map[y][x].is_mine == 0) {
    return;
  }
  if(b->map[y][x].flag == TRUE) return;
  if(b->map[b->sel.pos[0]][b->sel.pos[1]].is_mine == 2) {
    b->eog = true;
    clear();
    endwin();
    printf("\nYou hit a bomb! You lose. :(\n");
    exit(0);
  } else {
    b->map[y][x].revealed = TRUE;
    if(b->map[y][x].revealed == TRUE) {
      reveal_tile(b, y - 1, x, count++);
      reveal_tile(b, y, x - 1, count++);
      reveal_tile(b, y, x + 1, count++);
      reveal_tile(b, y + 1, x, count++);
    }
  }
}

