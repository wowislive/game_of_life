#include "main.h"

void board_status_exchange(void){  /*assigns the values of the future board to the current board*/
  for(int i=0; i<BOARD_H; i++){
    for(int j=0; j<BOARD_W; j++)
      
      board[i][j].current = board[i][j].future;
  }
}
