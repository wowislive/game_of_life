/*-------------------------------------------------------------------*
*    HEADER FILES                                                    *
*--------------------------------------------------------------------*/
#include "main.h"

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: board_status_exchange
 DESCRIPTION: assigns the values of the future board to the current board
	Input: struct cell b[BOARD_H][BOARD_W]
	Output: void
  Used global variables: BOARD_H, BOARD_W
 REMARKS when using this function:
*********************************************************************/
void board_status_exchange(struct cell b[BOARD_H][BOARD_W]){

  int i,j;

  for(i=0; i<BOARD_H; i++){
    for(j=0; j<BOARD_W; j++)
      
      b[i][j].current = b[i][j].future;
  }
}
