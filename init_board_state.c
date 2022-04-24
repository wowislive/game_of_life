#include "main.h"

void init_board_state(void){  /*generate cells with random values (live and dead cells)*/
  for(int i=0; i<board_h; i++){
    for(int j=0; j<board_w; j++){
      board[i][j].current = rand() % 2;
    }
  }  
}
