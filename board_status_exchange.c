#include "main.h"

void board_status_exchange(void){  /*assigns the values of the future board to the current board*/
  for(int i=0; i<board_h; i++){
    for(int j=0; j<board_w; j++)
      
      board[i][j].current = board[i][j].future;
  }
}
