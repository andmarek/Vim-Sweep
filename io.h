# ifndef IO_H
# define IO_H

class board;

void init_curses(void);
void io_reset(void);
void print_map_w_m(board *b);
void move_selector(board *b);
void io_numbers(board *b);

# endif
