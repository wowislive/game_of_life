/***************************************************************************
 *   Copyright (C) 2022 by Dmitrii Pavlov   *
 *   e2101942@vamk.fi   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

/*********************************************************************

 1.  NAME
     gameoflife.exe

 2.  DESCRIPTION
     Game of life is the simplest evolution theory model.
 
 3.  VERSIONS
       Original:
         1.0 / mimr

       Version history:

       1.0 release

**********************************************************************/

/*-------------------------------------------------------------------*
*    HEADER FILES                                                    *
*--------------------------------------------------------------------*/
#include "main.h"

/*********************************************************************
*    MAIN PROGRAM                                                      *
**********************************************************************/
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
/* end of main */
