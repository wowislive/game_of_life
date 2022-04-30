/*-------------------------------------------------------------------*
*    HEADER FILES                                                    *
*--------------------------------------------------------------------*/
#include "main.h"

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: init_board_state
 DESCRIPTION: generate cells with random values (live and dead cells)
	Input: struct cell b[BOARD_H][BOARD_W]
	Output: void
  Used global variables: BOARD_H, BOARD_W
 REMARKS when using this function: at the start of the program
*********************************************************************/
void init_board_state(struct cell b[BOARD_H][BOARD_W]){

  int i,j;

  for(i=0; i<BOARD_H; i++){
    for(j=0; j<BOARD_W; j++){
      b[i][j].current = rand() % 2;
    }
  }  
}
