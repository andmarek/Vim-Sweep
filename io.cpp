#include <stdlib.h>
#include <iostream>
#include <ncurses.h>
#include "board.h"

void init_curses(void) {
  initscr();
  raw();
  noecho();
  curs_set(0);
  keypad(stdscr, TRUE);
  start_color();

  init_pair(COLOR_RED, COLOR_RED, COLOR_BLACK);
  init_pair(COLOR_GREEN, COLOR_GREEN, COLOR_BLACK);
  init_pair(COLOR_YELLOW, COLOR_YELLOW, COLOR_BLACK);
  init_pair(COLOR_CYAN, COLOR_CYAN, COLOR_BLACK);

}

void io_reset(void) 
{
  endwin();
} 

void print_map_w_m(board *b)
{

  uint32_t i;
  uint32_t j;

  for(i = 0; i < MAP_Y; i++) {
    for(j = 0; j < MAP_X; j++) {
      if(( (b->sel.pos[0] != i) || b->sel.pos[1] != j)) {

        if(b->map[i][j].is_mine == 0 ) {

          if(b->map[i][j].flag == 1) {
            attron(COLOR_PAIR(COLOR_RED));
            mvaddch(i + 1, j + 1, b->map[i][j].symb);
            attroff(COLOR_PAIR(COLOR_RED));

          } else { 
            mvaddch(i + 1, j + 1, b->map[i][j].symb);
          } 
        } else if (b->map[i][j].is_mine == 2) {

          attron(COLOR_PAIR(COLOR_RED));

          mvaddch(i + 1, j + 1, 'M');

          attroff(COLOR_PAIR(COLOR_RED));

        }
      } else if( ( (b->sel.pos[0] == i) &&
            (b->sel.pos[1] == j) ) ) {
        attron(COLOR_PAIR(COLOR_GREEN));
        mvaddch(i + 1, j + 1, 'V'); 
        attroff(COLOR_PAIR(COLOR_GREEN)); 
      }
    }
  }
}

void io_numbers(board *b)
{
  clear();
  uint32_t i;
  uint32_t j;


  for(i = 0; i < MAP_Y; i++) {
    for(j = 0; j < MAP_X; j++) {
      /* If selector isn't at this position */
      if(( (b->sel.pos[0] != i) || b->sel.pos[1] != j)) {
        /* if it's not a mine */
        if(b->map[i][j].is_mine == 0 ) {

          /* if the number >= 1 */
          if(b->m_num[i][j] >= 1) {
            attron(COLOR_PAIR(COLOR_CYAN));
            /* Print its number */
            mvprintw(i+1, j+1, "%d", b->m_num[i][j]);
            attroff(COLOR_PAIR(COLOR_CYAN));
          }else {
            /* Otherwise, add a # */
            mvaddch(i+1, j+1, '#');
          }

        } else if (b->map[i][j].is_mine == 2) {
          /* If it is a mine, print it red with an M */
          attron(COLOR_PAIR(COLOR_RED));

          mvaddch(i + 1, j + 1, 'M');

          attroff(COLOR_PAIR(COLOR_RED));

        }
      } else if( ( (b->sel.pos[0] == i) &&
            (b->sel.pos[1] == j) ) ) {

        /* If it's the selector, print a green V */
        attron(COLOR_PAIR(COLOR_GREEN));
        mvaddch(i + 1, j + 1, 'V'); 
        attroff(COLOR_PAIR(COLOR_GREEN)); 
      }
    }
  }

  refresh();
}

bool validate_move(int pos) 
{
  if(pos <= -1 || pos >= 16) {
    mvprintw(0, 0, "Nothing to see here!");
    return false;
  } 
  return true;

}

void set_flag(board *b)
{
  uint32_t y_pos, x_pos;

  y_pos = b->sel.pos[0];
  x_pos = b->sel.pos[1];

  if(b->map[y_pos][x_pos].flag == 1) {
    b->map[y_pos][x_pos].flag = 0;
  } else {
    b->map[y_pos][x_pos].flag = 1;
  }

  if( (is_mine(b, y_pos, x_pos)) ) {
    b->flag_m++;
    mvprintw(0, 0, "right: %d", b->flag_m);
    refresh();
  }
  if(b->flag_m <= b->num_mines) {
    b->eog = true;
    endwin();
  }
}

void move_selector(board *b) {
  uint32_t key;

  while((key = getch())) {
    move(0, 0);
    clrtoeol();
    switch(key) {
      case '0':
        b->sel.pos[1] = 0;
        break;

      case 'g':
        if((key = getch()) == 'g') {
          b->sel.pos[0] = 0;
        } else {
          move_selector(b);
        }
        break;

      case 'G':
        b->sel.pos[0] = 15;
        break;

      case 'A':
        b->sel.pos[1] = 15;
        break;

      case 'h':
        if(!(validate_move(b->sel.pos[1]-1))) {
          break;
        } else {
          b->sel.pos[1]--;
        }
        refresh();
        break;

      case 'j':
        if(!(validate_move(b->sel.pos[0]+1))) {
          break;
        } else {
          b->sel.pos[0] += 1;
        }
        refresh();
        break;

      case 'k':
        if(!(validate_move(b->sel.pos[0]-1))) {
          break;
        } else {  
          b->sel.pos[0] -= 1;
        }
        refresh();
        break;

      case 'l':
        if(!(validate_move(b->sel.pos[1]+1))) {
          break;
        } else {
          b->sel.pos[1] += 1;
        }
        refresh();
        break;

      case 'm': /* Set a flag, ENTER */
        set_flag(b); 
        refresh();
        break;

      case 'i':
        //choose
        break; 

      case 'n': 
        io_numbers(b);
        refresh();
        move_selector(b);
        break;

      case 'r':
        print_map_w_m(b);
        refresh();
        break;

      case ':':
        mvprintw(17, 0, ":");
        if((key = getch()) == 'q') {
          endwin();
          printf("\n You quit.\n");
          b->eog = true;
          return;
        } else {
          move(17, 0);
          clrtoeol();
        }
        break;

      default:
        break;
    };

    print_map_w_m(b);

  }
}

