#include "main.h"

int main(void){

  int neighbour;
  char input_command;
  struct cell board [BOARD_H] [BOARD_W] = {{{0, 0}}};
  int i,j;
  int start_run = 0;

  initscr();
  cbreak();
  start_color();
  init_pair(1, COLOR_CYAN, COLOR_MAGENTA);
  init_pair(2, COLOR_BLACK, COLOR_BLACK);

  srand(time(NULL));
  init_board_state(board);

  
  clear();


  do{

    if(start_run == 0){
      input_command = ask_command("S to start program\nN to run program step by step\nX to terminate program\n");
      clear();
    }

    else if(start_run == 2){
      mvaddstr(BOARD_H+2, 0,"N to print next step\nS to start auto switch\nX to terminate program\n");
      curs_set(1);
      input_command = ask_command("");
      curs_set(0);
    }

    else if(start_run == 1){
      mvaddstr(BOARD_H+2, 0,"CLOSE WINDOW to terminate program\n");
      curs_set(0);
      refresh();
      sleep(1);
    }  

    if(input_command == 'N' || input_command == 'S'){
      clear();

      if(input_command == 'S')
        start_run = 1;
      else if(input_command == 'N')
        start_run = 2;

      for(i=0; i<BOARD_H; i++){
        for(j=0; j<BOARD_W; j++){
          
          if(board[i][j].current == 0){
            attron(COLOR_PAIR(2));
            mvaddch(i, j, ' ');
            attroff(COLOR_PAIR(2));
          }
          else if(board[i][j].current == 1){
            attron(COLOR_PAIR(1));
            mvaddch(i, j, ' ');
            attroff(COLOR_PAIR(1));
          }
            
          refresh();
          neighbour = count_neighbour_cell(i, j,board);
          board[i][j].future = future_life_change(neighbour, board[i][j].current);
        }
      }
    
    board_status_exchange(board);
    }
  }while(input_command!= 'X');

  return 0;
}
