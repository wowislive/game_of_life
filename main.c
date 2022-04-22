#include <stdio.h>

#define board_h 9  /* board height */
#define board_w 9  /* board width */

struct cell{
int current;  /* current situation, which is visible on screen */
int future;   /* temporary calculation area for next round */
};

struct cell board [board_h] [board_w] = {0, 0};

int count_neighbour_cell(int x, int y);
int future_life_change(int i, int k);
void board_status_exchange();

int main(void){

  int neighbour;

  for(int i=0; i<board_h; i++){
    for(int j=0; j<board_w; j++){
      
      neighbour = count_neighbour_cell(i, j);
      board[i][j].future = future_life_change(neighbour, board[i][j].current);
    }
  }

  board_status_exchange();

  return 0;
}

int count_neighbour_cell(int h, int w){  /*returns the count of alive neighbours*/

  int count = 0;

  for(int i=h-1; i<=h+1; i++){
    for(int j=w-1; j<=w+1; j++){

      if(i==h && j==w)
        continue;
      
      if(i<h && j<w && i>=0 && j>=0)
        count += board[i][j].current;
    }
  }
  return count;
}

int future_life_change(int i, int k){  /*changes the life status of a cell depending on the number of neighbors*/

  int life_state = k;

  if(i>3 || i<2)
    life_state = 0;
  
  else if(i==3)
    life_state = 1;

  return life_state;
}

void board_status_exchange(){  /*assigns the values of the future board to the current board*/
  for(int i=0; i<board_h; i++){
    for(int j=0; j<board_w; j++)
      
      board[i][j].current = board[i][j].future;
  }
}