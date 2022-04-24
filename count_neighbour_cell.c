#include "main.h"

int count_neighbour_cell(int h, int w){  /*returns the count of alive neighbours*/

  int count = 0;

  for(int i=h-1; i<=h+1; i++){
    for(int j=w-1; j<=w+1; j++){

      if(i==h && j==w)
        continue;
      
      if((i<board_h) && (j<board_w) && (i>=0) && (j>=0))
        count += board[i][j].current;
    }
  }
  
  return count;
}
