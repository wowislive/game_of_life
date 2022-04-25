#include "main.h"

void init_board_state(void){  /*generate cells with random values (live and dead cells)*/
  for(int i=0; i<BOARD_H; i++){
    for(int j=0; j<BOARD_W; j++){
      board[i][j].current = rand() % 2;
    }
  }  
}
