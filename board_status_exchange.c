#include "main.h"

void board_status_exchange(struct cell b[BOARD_H][BOARD_W]){  /*assigns the values of the future board to the current board*/
  for(int i=0; i<BOARD_H; i++){
    for(int j=0; j<BOARD_W; j++)
      
      b[i][j].current = b[i][j].future;
  }
}
