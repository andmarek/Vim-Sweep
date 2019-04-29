# Vim-Sweep
### A Minesweeper-inspired game, with Vim-like controls.
## Use
* Requires GCC 7 or 8 (developed on GCC 8.3).  
* This probably won't compile on Clang, this can be tested later (you should be using GCC anyway).

## Controls
* gg - Moves to top of screen.
* G - Moves to the bottom of the screen.
* A - Moves to the end of current line.
* 0 - Moves to the beginning of the first line.
* i - to reveal a tile.
* m - to set a flag.
* n - to cheat and see where the bombs are.
* h, j, k,l - to move left, down, up, right respectively.
* : followed by q - to quit.
* : followed by w - to verify if you've won.

### To-do:
* Make bomb-placement more interesting.
* Update algorithm for computing adjacent bombs - it is a little buggy. 
