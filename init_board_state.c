#include "main.h"

void init_board_state(struct cell b[BOARD_H][BOARD_W]){  /*generate cells with random values (live and dead cells)*/
  for(int i=0; i<BOARD_H; i++){
    for(int j=0; j<BOARD_W; j++){
      b[i][j].current = rand() % 2;
    }
  }  
}
