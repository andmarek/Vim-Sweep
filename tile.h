# ifndef TILE_H
# define TILE_H

class tile {
  public:
   char symb;
   uint32_t is_mine = 0;
   uint32_t is_selector = 0;
   uint32_t flag = 0;
   uint32_t m_count;
   uint32_t revealed = 0;
};

class selector : public tile {
  public:
    uint32_t is_selector = 2;
    /* 1 is y, 2 is x */
    uint32_t pos[2];
};

# endif
