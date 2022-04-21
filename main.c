#include <stdio.h>

#define board_w 9  /* board height */
#define board_h 9  /* board width */

struct cell{
int current;  /* current situation, which is visible on screen */
int future;   /* temporary calculation area for next round */
};

struct cell board [board_w] [board_h] = {0, 0};

int count_neighbour_cell(int x, int y);

int main(void){

}

int count_neighbour_cell(int w, int h){  /*returns the count of alive neighbours*/

  int count = 0;

  for(int i=w-1; i<=w+1; i++){
    for(int j=h-1; j<=h+1; j++){

      if(i==w && j==h)
        continue;
      
      if(i<w && j<h && i>=0 && j>=0)
        count += board[i][j].current;
    }
  }
  return count;
}