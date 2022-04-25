#include "main.h"

struct cell board [BOARD_H] [BOARD_W] = {0, 0};

int main(void){

  int neighbour;
  char input_command;

  srand(time(NULL));
  init_board_state();
  printf("N to print next step\nX to terminate programm\n");

  do{
    input_command = ask_command();

    if(input_command == 'N'){
      for(int i=0; i<BOARD_H; i++){
        printf("\n");
        for(int j=0; j<BOARD_W; j++){
          
          if(board[i][j].current == 0)
            printf("O");
          else if(board[i][j].current == 1)
            printf("X");

          neighbour = count_neighbour_cell(i, j,board);
          board[i][j].future = future_life_change(neighbour, board[i][j].current);
        }
      }
    printf("\n");
    board_status_exchange();
    }
  }while(input_command!= 'X');

  return 0;
}
