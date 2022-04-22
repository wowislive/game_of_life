#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define board_h 9  /* board height */
#define board_w 9  /* board width */
#define MAX_USER_INPUT 2000

struct cell{
int current;  /* current situation, which is visible on screen */
int future;   /* temporary calculation area for next round */
};

struct cell board [board_h] [board_w] = {0, 0};

int count_neighbour_cell(int x, int y);
int future_life_change(int i, int k);
void board_status_exchange(void);
char ask_command(void);
void print_current_board(void);
void init_board_state(void);

int main(void){

  int neighbour;
  char input_command;

  srand (time(NULL)); 
  init_board_state();
  printf("N to print next step\nX to terminate programm\n");

  do{
    input_command = ask_command();

    if(input_command == 'N'){
      for(int i=0; i<board_h; i++){
        printf("\n");
        for(int j=0; j<board_w; j++){
          
          if(board[i][j].current == 0)
            printf("O");
          else if(board[i][j].current == 1)
            printf("X");

          neighbour = count_neighbour_cell(i, j);
          board[i][j].future = future_life_change(neighbour, board[i][j].current);
        }
      }
    printf("\n");
    board_status_exchange();
    }
  }while(input_command!= 'X');

  return 0;
}

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

int future_life_change(int i, int k){  /*changes the life status of a cell depending on the number of neighbors*/

  int life_state = k;

  if(i>3 || i<2)
    life_state = 0;
  
  else if(i==3)
    life_state = 1;

  return life_state;
}

void board_status_exchange(void){  /*assigns the values of the future board to the current board*/
  for(int i=0; i<board_h; i++){
    for(int j=0; j<board_w; j++)
      
      board[i][j].current = board[i][j].future;
  }
}

char ask_command(void){  /*Ask char from user*/

  char s[MAX_USER_INPUT];
  //printf("\nEnter command: ");

  do{
    fgets(s,MAX_USER_INPUT,stdin);

    if(s[0] > 96 && s[0] < 123)
      s[0] -= 32;
  }while(s[0] < 65 && s[0] > 90);
  return s[0];
}

void init_board_state(void){  /*generate cells with random values (live and dead cells)*/
  for(int i=0; i<board_h; i++){
    for(int j=0; j<board_w; j++){
      board[i][j].current = rand() % 2;
    }
  }  
}
