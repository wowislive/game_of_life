#include "main.h"

int count_neighbour_cell(int h, int w, struct cell b[BOARD_H][BOARD_W]){  /*returns the count of alive neighbours*/

  int count = 0;
  int i,j;

  for(i=h-1; i<=h+1; i++){
    for(j=w-1; j<=w+1; j++){

      if(i==h && j==w)
        continue;
      
      if((i<BOARD_H) && (j<BOARD_W) && (i>=0) && (j>=0))
        count += b[i][j].current;
    }
  }
  
  return count;
}
